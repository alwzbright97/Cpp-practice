#include <iostream>

struct Foo
{
    int i;   // 4 byte
    float f; // 4 byte
    char c;  // 1 byte
};

struct alignas(alignof(long double)) Foo2 {};
struct Empty {};
struct alignas(64) Empty64 {};

int main()
{
    std::cout << "Alignment of" "\n"
        "- char            : " << alignof(char)         << "\n"
        "- int             : " << alignof(int)          << "\n"
        "- pointer         : " << alignof(int*)         << "\n"
        "- long double     : " << alignof(long double)  << "\n"
        "- class Foo       : " << alignof(Foo)          << "\n"
        "- class Foo2      : " << alignof(Foo2)         << "\n"
        "- empty class     : " << alignof(Empty)        << "\n"
        "- empty class\n"
        "  with alignas(64): " << alignof(Empty64)      << "\n";
    std::cout << "Size of" "\n"
        "- char            : " << sizeof(char)         << "\n"
        "- int             : " << sizeof(int)          << "\n"
        "- pointer         : " << sizeof(int*)         << "\n"
        "- long double     : " << sizeof(long double)  << "\n"
        "- class Foo       : " << sizeof(Foo)          << "\n"
        "- class Foo2      : " << sizeof(Foo2)         << "\n"
        "- empty class     : " << sizeof(Empty)        << "\n"
        "- empty class\n"
        "  with alignas(64): " << sizeof(Empty64)      << "\n";
}
