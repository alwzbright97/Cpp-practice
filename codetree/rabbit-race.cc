/*
P마리 토끼가 N x M 크기의 격자 위에서 경주를 준비

1. 준비
  토끼
    고유 번호
    이동 거리
    좌표
  초기 토끼들은 모두 1행, 1열

2. 경주 진행
  가장 우선 순위가 높은 토끼를 선택, K번 반복

  우선 순위는 순서대로
  1. 현재까지 총 점프 횟수가 적은 토끼
  2. 현재 서있는 행 + 열 번호 작은 토끼
  3. 행 번호 작은 토끼
  4. 열 번호 작은 토끼
  5. 고유 번호 작은 토끼

  우선 순위가 가장 높은 토끼 > i번 토끼
  상하좌우 네 방향으로 각각 d만큼 이동했을 때 위치
  이동하는 도중 그 다음칸이 격자를 벗어나게 된다면 방향을 반대로 바꿔 이동

  이렇게 구해진 4개 위치 중 우선 순위로 결정
  1. 행 + 열 번호가 큰 칸
  2. 행 번호가 큰 칸
  3. 열 번호가 큰 칸
  그 위치로 해당 토끼를 이동
  이 칸의 위치를 r, c라 했을 때
  i번 토끼를 제외한 나머지 P - 1마리 토끼들을 전부 r+c 점수 획득

  1. 위 과정을 K번 동안 반복
  2. 우선 순위로 두었을 때 가장 우선 순위가 높은 토끼를 골라 점수 += S
    이 경우엔 적어도 한번 뽑힌 적 있는 토끼

3. 이동 거리 변경
  고유번호 pid 토끼의 이동 거리 L배, d < 10억

4. 최고의 토끼 선정

입력

명령의 수 Q
Q줄에 걸처 명령 정보
  1. 경주 시작 준비
    100 N M pid_1 d1 pid_2 d_2 ... pid_p d_p
      항상 첫 번째 명령, 항상 주어짐

  2. 경주 진행
    200 K S
      최대 2000번

  3. 이동거리 변경
    300 pid_t L
      최대 2000번

  4. 최고의 토끼
    400
      정확히 마지막 명령, 항상 주어짐

*/

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct Coord {
  int y, x;

  bool operator<(Coord right) const {
    if (y + x < right.y + right.x) return true;
    if (y + x > right.y + right.x) return false;

    if (y < right.y) return true;
    if (y > right.y) return false;

    if (x < right.x) return true;
    if (x > right.x) return false;

    return false;
  }

  bool operator>(Coord right) const {
    if (y + x > right.y + right.x) return true;
    if (y + x < right.y + right.x) return false;

    if (y > right.y) return true;
    if (y < right.y) return false;

    if (x > right.x) return true;
    if (x < right.x) return false;

    return false;
  }
};

struct Rabbit {
  int id;
  int count;
  Coord coord;

  /*
  우선 순위는 순서대로
    1. 현재까지 총 점프 횟수가 적은 토끼
    2. 현재 서있는 행 + 열 번호 작은 토끼
    3. 행 번호 작은 토끼
    4. 열 번호 작은 토끼
    5. 고유 번호 작은 토끼
  */
  bool operator<(Rabbit right) const {
    if (count > right.count) return true;
    if (count < right.count) return false;

    if (coord > right.coord) return true;
    if (coord < right.coord) return false;

    if (id > right.id) return true;
    if (id < right.id) return false;

    return false;
  }
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int Q;
int command;
int N, M, P;
unordered_map<int, long long> hash_score;
unordered_map<int, int> hash_dist;
unordered_map<int, bool> hash_jumped;

priority_queue<Rabbit> pq_rabbit;
long long answer;
/*
1. 준비
  토끼
    고유 번호
    이동 거리
    좌표
  초기 토끼들은 모두 1행, 1열
*/
void prepareRace() {
  cin >> N >> M >> P;

  for (int i = 0; i < P; i++) {
    int id_i, dist_i;
    cin >> id_i >> dist_i;

    pq_rabbit.push({id_i, 0, {0, 0}});
    hash_score.insert({id_i, 0});
    hash_dist.insert({id_i, dist_i});
    hash_jumped.insert({id_i, false});
  }

  return;
}
/*
우선 순위가 가장 높은 토끼 > i번 토끼
  상하좌우 네 방향으로 각각 d만큼 이동했을 때 위치
  이동하는 도중 그 다음칸이 격자를 벗어나게 된다면 방향을 반대로 바꿔 이동

  이렇게 구해진 4개 위치 중 우선 순위로 결정
  1. 행 + 열 번호가 큰 칸
  2. 행 번호가 큰 칸
  3. 열 번호가 큰 칸
  그 위치로 해당 토끼를 이동
  이 칸의 위치를 r, c라 했을 때
  i번 토끼를 제외한 나머지 P - 1마리 토끼들을 전부 r+c 점수 획득

  1. 위 과정을 K번 동안 반복
  2. 우선 순위로 두었을 때 가장 우선 순위가 높은 토끼를 골라 점수 += S
    이 경우엔 적어도 한번 뽑힌 적 있는 토끼
*/
Coord getNextCoord(Coord current, int dist) {
  Coord retval = {0, 0};

  for (int i = 0; i < 4; i++) {
    int y = current.y + (dy[i] * dist);
    int x = current.x + (dx[i] * dist);

    int ry = y % (2 * (N - 1));
    int rx = x % (2 * (M - 1));

    if (ry < 0) ry += (2 * (N - 1));
    if (rx < 0) rx += (2 * (M - 1));

    int ny = (ry < N) ? ry : (2 * (N - 1)) - ry;
    int nx = (rx < M) ? rx : (2 * (M - 1)) - rx;

    Coord next = {ny, nx};

    if (retval < next) retval = next;
  }

  return retval;
}

void addScoreExceptId(int id, int score) {
  for (auto iter = hash_score.begin(); iter != hash_score.end(); iter++) {
    if ((*iter).first == id) continue;

    (*iter).second += score;
  }

  return;
}

void addBonusScore(int score) {
  priority_queue<Rabbit> pq_temp;

  int target_id = 0;
  Rabbit target_rabbit = {0, 0, {0, 0}};

  while (!pq_rabbit.empty()) {
    Rabbit cur_rabbit = pq_rabbit.top();

    pq_rabbit.pop();

    pq_temp.push(cur_rabbit);

    cur_rabbit.count = 0;

    if (!hash_jumped[cur_rabbit.id]) continue;

    if (cur_rabbit < target_rabbit) {
      target_rabbit.coord = cur_rabbit.coord;
      target_rabbit.id = cur_rabbit.id;
    }
  }

  hash_score[target_rabbit.id] += score;

  pq_rabbit = pq_temp;

  return;
}

void processRace() {
  int K, S;
  cin >> K >> S;

  for (int k = 0; k < K; k++) {
    Rabbit rabbit = pq_rabbit.top();

    pq_rabbit.pop();

    Coord next_coord = getNextCoord(rabbit.coord, hash_dist[rabbit.id]);
    int add_score = next_coord.y + next_coord.x + 2;
    if (!hash_jumped[rabbit.id]) hash_jumped[rabbit.id] = true;

    rabbit.coord = next_coord;
    rabbit.count += 1;

    addScoreExceptId(rabbit.id, add_score);

    pq_rabbit.push(rabbit);
  }

  addBonusScore(S);

  for (auto iter = hash_jumped.begin(); iter != hash_jumped.end(); iter++) {
    (*iter).second = false;
  }

  return;
}

void changeDist() {
  int pid, L;

  cin >> pid >> L;

  hash_dist[pid] *= L;

  return;
}

void getMaxScore() {
  answer = 0;

  for (auto iter = hash_score.begin(); iter != hash_score.end(); iter++) {
    if ((*iter).second > answer) answer = (*iter).second;
  }

  return;
}

int main(int argc, char** argv) {
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    cin >> command;

    if (command == 100) {
      prepareRace();
      continue;
    } else if (command == 200) {
      processRace();
      continue;
    } else if (command == 300) {
      changeDist();
      continue;
    } else if (command == 400) {
      getMaxScore();
      continue;
    }
  }

  cout << answer << "\n";

  return 0;
}