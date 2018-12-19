#include <cstdio>

#include "sayhello.h"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        initSayHello(argv[1]);
    }
    else
    {
        initSayHello("Hello, World!");
    }

    printf("build %d\n", version());

    sayHello();

    closeSayHello();

    return 0;
}
