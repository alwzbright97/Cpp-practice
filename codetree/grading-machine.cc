/*
코드트리 채점기

N개의 채점기가 준비
u0 : 초기 문제 URL
문제에서 URL = 도메인/문제ID(string)
도메인 : 알파벳 소문자 + '.'
문제 ID : 1 이상 10억 이하 정수값(int)

1. 준비
N개의 채점기
1번부터 N번까지의 번호

0초에 채점 우선 순위가 1인 URL이 u0인 초기 문제에 대한 채점 요청
채점 TASK는 채점 대기큐에 들어감

2. 채점 요청
t초에 채점 우선 순위가 p이면서 URL이 u인 문제에 대한 채점 요청
채점 TASK는 채점 대기 큐에 들어간다
채점 대기 큐에 있는 task 중 정확히 u와 일치하는 url이 단 하나라도 존재한다면
 큐에 추가하지 않고 넘어간다.

3. 채점 시도
t초에 채점 대기큐에서 즉시 채점이 가능한 경우 중
우선 순위가 가장 높은 task를 골라 채점을 진행

        task가 채점 될 수 없는 조건
        - 해당 task 도메인이 현재 채점을 진행 중인 도메인 중 하나
        - 해당 task 도메인과 일치하는 도메인에 대해
          최근에 진행된 채점 시작 시간이 start, 종료 시간이 start + gap
          현재 시간 t가 start + (3 x gap)보다 작다면, 부적절한 채점

        즉시 채점이 가능한 경우 중 우선순위가 가장 높은 task는 아래 조건
        - 채점 우선순위 p의 번호가 작을수록 우선순위가 높다
        - task가 채점 대기 큐에 들어온 시간이 더 빠를수록 수록 높다.

t초에 채점이 가능한 task가 단 하나라도 있다면,
        쉬고 있는 채점기 중 가장 번호가 작은 채점기가
        우선순위가 가장 높은 채점 task에 대한 채점을 시작

        쉬고 있는 채점기가 없다면 요청을 무시

4. 채점 종료
t초에 J_id번 채점기가 진행하던 채점이 종료된다.
J_id 채점기는 다시 쉬는 상태가 된다.
J_id 채점기가 진행하던 채점이 없다면 명령은 무시

5. 채점 대기 큐 조회
t초에 채점 대기 큐에 있는 채점 task 수를 출력


입력

Q
        Q : 명령의 수

        1. 채점기 준비
        100 N u0
                100 : command
                N : N개의 채점기
                u0 : 문제 URL

        2. 채점 요청
        200 t p u
                200 : command
                t : 시간(초)
                p : 우선 순위
                u : URL 문제

        3. 채점 시도
        300 t
                300 : command
                t : 시간

        4. 채점 종료
        400 t J_id
                400 : command
                t : 초
                J_id : 채점기 ID

        5. 채점 대기 큐 조회
        500 t
                500 : command
                t : 시간

입력으로 주어지는 t값은 모두 다르며, 오름차순으로 정렬되어 주어짐을 가정
*/

#define MAX_N 50000
#define MAX_D 300

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Task {
  int t, p, id;

  bool operator<(Task right) const {
    if (p > right.p) return true;
    if (p < right.p) return false;

    if (t > right.t) return true;
    if (t < right.t) return false;

    return false;
  }

  bool operator>(Task right) const {
    if (p < right.p) return true;
    if (p > right.p) return false;

    if (t < right.t) return true;
    if (t > right.t) return false;

    return false;
  }
};

struct History {
  int start, end;
};

struct Judge {
  int start;
  int domain_index;
};

struct Url {
  string domain;
  int id;
};

int debug_countNum = 0;

int Q;
int command;
int N;
int p, t;
string u;
int J_id;

int domain_count = 0;
unordered_map<string, int> domain_idx;
bool machine[MAX_N];

int wait_count = 0;
unordered_set<int> waiting_domainid_set[MAX_D];
priority_queue<Task> waiting_pq[MAX_D];

Judge judging_machine[MAX_N];
bool judging_domain[MAX_D];

History judging_recent[MAX_D];

Url stringToUrl(string u) {
  int slash_pos = u.find('/');

  string domain = u.substr(0, slash_pos);
  int id = stoi(u.substr(slash_pos + 1));

  return {domain, id};
}

void addDomain(string domain) {
  if (domain_idx.find(domain) != domain_idx.end()) return;

  domain_idx[domain] = domain_count;
  domain_count++;

  return;
}

void initMachine() {
  cin >> N >> u;

  Url url = stringToUrl(u);

  addDomain(url.domain);

  int index = domain_idx[url.domain];
  int pid = url.id;

  waiting_domainid_set[index].insert(pid);
  waiting_pq[index].push({0, 1, pid});

  wait_count++;

  return;
}

void addTask() {
  cin >> t >> p >> u;

  Url url = stringToUrl(u);

  addDomain(url.domain);

  int index = domain_idx[url.domain];
  int pid = url.id;

  if (waiting_domainid_set[index].find(pid) !=
      waiting_domainid_set[index].end())
    return;

  waiting_domainid_set[index].insert(pid);
  waiting_pq[index].push({t, p, pid});

  wait_count++;

  return;
}

void tryJudge() {
  cin >> t;

  int machine_index = MAX_N + 1;
  for (int i = 0; i < N; i++) {
    if (!machine[i]) {
      machine_index = i;
      break;
    }
  }

  if (machine_index == MAX_N + 1) return;

  bool found = false;

  int domain_index;
  Task selected_task = {0, 50001, 0};

  for (int i = 0; i < domain_count; i++) {
    if (waiting_pq[i].empty()) continue;

    if (judging_domain[i]) continue;

    Task task = waiting_pq[i].top();

    if (task < selected_task) continue;

    int start = judging_recent[i].start;
    int end = judging_recent[i].end;
    int gap = end - start;

    int task_value = start + 3 * gap;

    if (t < task_value) continue;

    if (selected_task < task) {
      selected_task = task;
      domain_index = i;
      found = true;
    }
  }

  if (!found) return;

  machine[machine_index] = true;

  waiting_pq[domain_index].pop();
  waiting_domainid_set[domain_index].erase(selected_task.id);

  judging_machine[machine_index] = {t, domain_index};
  judging_domain[domain_index] = true;

  wait_count--;

  return;
}

void exitJudge() {
  cin >> t >> J_id;
  J_id -= 1;

  if (!machine[J_id]) return;

  Judge judging = judging_machine[J_id];

  int domain_index = judging.domain_index;
  int start = judging.start;
  int end = t;

  machine[J_id] = false;

  judging_recent[domain_index] = {start, end};
  judging_domain[domain_index] = false;

  return;
}

void countWait() {
  cin >> t;

  cout << wait_count << "\n";
  return;
}

int main(int argc, char** argv) {
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    cin >> command;
    switch (command) {
      case 100:
        initMachine();
        break;
      case 200:
        addTask();
        break;
      case 300:
        tryJudge();
        break;
      case 400:
        exitJudge();
        break;
      case 500:
        countWait();
        debug_countNum++;
        break;
      default:
        break;
    }
  }

  return 0;
}