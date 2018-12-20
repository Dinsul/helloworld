#include <cstring>
#include <cstdio>

#include "sayhello.h"
#include "version.h"

static char *_string;

int initSayHello(const char *str)
{
    size_t lenStr = strlen(str);

    _string  = new char[lenStr];

    strncpy(_string,  str,     lenStr);

    return (int)lenStr;
}

void closeSayHello()
{
    delete[] _string;
}

void sayHello()
{
    printf("%s\n", _string);
}

int version()
{
    return PROJECT_VERSION_PATCH;
}
