#include <cstdio>

#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)

struct offset
{
    int a;      // 4 byte
    int b;      // 4 byte
    char c;     // 1 byte
    double d;   // 8 byte
    int e;      // 4 byte
};

int main()
{
    printf("Size of struct : %d\n", sizeof(struct offset));
    printf("Align of struct : %d\n", alignof(struct offset));

    printf("a : %d\n", offsetof(struct offset, a));
    printf("b : %d\n", offsetof(struct offset, b));
    printf("c : %d\n", offsetof(struct offset, c));
    printf("d : %d\n", offsetof(struct offset, d));
    printf("e : %d\n", offsetof(struct offset, e));

    return 0;
}

// A - 4, B - 4
// C - 1, pad - 7
// D - 8
// e - 4, pad - 4
