#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <memman.h>

#define PASTE(a, b) PAST_(a, b)
#define PAST_(a, b) PAS__(a, b)
#define PAS__(a, b) a##b
