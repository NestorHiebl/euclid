#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(void)
{
    printf("Usage placeholder\n");
}

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

int main_gcd(int argc, char **argv)
{
    switch (argc)
    {
        case 0:
            printf("Usage: Provide arbitrary natural numbers to find GCD of\n");
            break;
        case 1:
            printf("%s\n", argv[0]);
            break;
        default:
            printf("%ld\n", gcdFold(argc, argv));
            break;
    }
    return 0;
    
}

/**
 * Naive, primitive implementation of the Euler phi function. Returns number
 * of positive integers smaller than n that are coprime with n. Passing zero
 * to this functions results in undefined behavior.
 */
uint64_t euler_phi(uint64_t n)
{
    uint64_t retval = 0;
    for (uint64_t i = 1; i < n; i++)
    {
        if (1 == gcd(n, i))
        {
            retval++;
        }
    }
    return retval;
}

int main_phi(int argc, char **argv)
{
    uint64_t n = 1;
    switch (argc)
    {
        case 1:
            n = strtoll(argv[0], NULL, 10);
            if ((0 != errno) || (0 == n))
            {
                fprintf(stderr, "Parse error\n");
                exit(1);
            }
            printf("%ld\n", euler_phi(n));
            break;
        case 0:
        default:
            printf(
                "Usage: "
                "Provide a single natural number to compute the "
                "Euler phi function of\n"
                );
            break;
    }
    return 0;
    
}

void shift_args(int *argc, char ***argv)
{
    (*argc)--;
    (*argv)++;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        print_usage();
        exit(1);
    }

    shift_args(&argc, &argv);
    
    if (0 == strcmp(argv[0], "gcd"))
    {
        shift_args(&argc, &argv);
        main_gcd(argc, argv);
    }
    else if (0 == strcmp(argv[0], "phi"))
    {
        shift_args(&argc, &argv);
        main_phi(argc, argv);
    }
    else
    {
        fprintf(stderr, "Unrecognized subcommand: %s\n", argv[0]);
        exit(1);
    }
    return 0;
}

