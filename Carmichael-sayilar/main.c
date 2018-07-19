#include <stdio.h>
#include <string.h>

typedef enum
{
    FALSE,
    TRUE
} BOOL;

BOOL is_prime(long int number);
BOOL is_composite(long int number);
BOOL is_carmichael(long int number);
long int gcd(long int a, long int b);
long int fermat_formula(long int a, long int b);

int main()
{
    long int i;

    printf("Enter a number: ");
    scanf("%ld", &i);

    if (is_prime(i))
        printf("%ld is a prime number.\n", i);
    else
        printf("%ld is a composite number.\n", i);

    if (is_carmichael(i))
        printf("%ld is a carmichael number.\n", i);
    else
        printf("%ld is not a carmichael number.\n", i);

    return 0;
}

/*************************************************************/

BOOL is_prime(long int number)
{
    long int i;

    if (number == 0 || number == 1)
        return FALSE;
    if (number % 2 == 0)
        return number == 2;
    if (number % 3 == 3)
        return number == 3;
    if (number % 5 == 5)
        return number == 5;

    for (i = 7; i * i <= number; i += 2)
        if (number % i == 0)
            return FALSE;

    return TRUE;
}

/*************************************************************/

BOOL is_carmichael(long int number)
{
    long int i;

    if (is_prime(number) || number == 0)
        return FALSE;

    for (i = 2; i < number; i++)
    {
        if (gcd(i, number) != 1) /* finding a relative prime to number */
            continue;
        if (fermat_formula(i, number) != 1)
            return FALSE;
    }
    return TRUE;
}

/*************************************************************/

long int gcd(long int a, long int b)
{
    if (b != 0)
        return gcd(b, a % b);
    return a;
}

/*************************************************************/

long int fermat_formula(long int a, long int b)
{
    long int i;
    long int remainder = 1;

    if (b == 1)
        return 0;

    for (i = 0; i < b - 1; i++)
    {
        remainder = remainder * a % b;
        if (remainder == 0)
            return 0;
    }
    return remainder;
}