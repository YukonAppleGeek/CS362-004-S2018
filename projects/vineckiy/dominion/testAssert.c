#include "testAssert.h"
#include <stdio.h>

int shouldEqual(int expected, int value, const char* violationMsg) {
    if (value != expected) {
        printf("Expected %d, found %d: %s\n", expected, value, violationMsg);
        return 0;
    }

    return 1;
}