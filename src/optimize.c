// optimize test demo.
// without -O2 or -O3 this can't work : Segmentation fault in @recursion()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

// #define PREDIRECT_BRANCH

#ifdef PREDIRECT_BRANCH
#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)
#else
#define likely(x) (x)
#define unlikely(x) (x)
#endif

// recursion with @limit iteration.
static unsigned long int recursion(unsigned long int n)
{
    unsigned long int limit = 1000000000;
    if (likely(n < limit))
    {
        return recursion(++n);
    }

    // breakpoint for debug
    raise(SIGINT);

    return n;
}

static unsigned long int bruh(unsigned long int n)
{
    if (likely(n != 0))
        return recursion(n);

    return 0;
}

int main()
{
    printf("%lu", bruh(1));
}
