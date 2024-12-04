#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Find GCD of a and b. a is presumed to be greater than b. Violating this
 * premise results in undefined behavior.
 */
uint64_t gcd(uint64_t a, uint64_t b)
{
    uint64_t retval = 0;
    if (0 == b)
    {
        retval = a;
    }
    else
    {
        retval = gcd(b, a % b);
    }
    return  retval;
}

/**
 * Either argument being NULL results in undefined behavior.
 */
void swap(uint64_t *a, uint64_t *b)
{
    uint64_t s = *a;
    *a = *b;
    *b = s;
}

uint64_t gcdFold(size_t len, char **args)
{
    /* len is known to be at least 2 */
    size_t i = 1;
    uint64_t acc = strtoll(args[i - 1], NULL, 10);
    while (i < len)
    {
        uint64_t b = strtoll(args[i], NULL, 10);
        if (0 != errno)
        {
            fprintf(stderr, "Parse error\n");
            exit(1);
        }
        if (b > acc)
        {
            swap(&acc, &b);
        }
        acc = gcd(acc, b);
        i++;
    }
    return acc;
}

int main(int argc, char **argv)
{
    switch (argc)
    {
        case 1:
            printf("Usage: Provide arbitrary natural numbers to find GCD of\n");
            break;
        case 2:
            printf("%s\n", argv[1]);
            break;
        default:
            printf("%ld\n", gcdFold(argc - 1, argv + 1));
            break;
    }
    return 0;
}

