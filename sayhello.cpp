#include <cstring>
#include <cstdio>

#include "sayhello.h"
#include "version.h"

static char *_string;
static char *_endLine;

int initSayHello(const char *str, const char *endLine)
{
    size_t lenStr = strlen(str);
    size_t lenEnd = strlen(endLine);

    _string  = new char[sizeof(lenStr)];
    _endLine = new char[sizeof(lenEnd)];

    strncpy(_string,  str,     lenStr);
    strncpy(_endLine, endLine, lenEnd);

    return (int)lenStr;
}

void closeSayHello()
{
    delete[] _string;
    delete[] _endLine;
}

void sayHello()
{
    printf("%s%s", _string, _endLine);
}

int version()
{
    return PROJECT_VERSION_PATCH;
}
