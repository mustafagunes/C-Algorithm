#include <stdio.h>

#define MAX 100000

int get_sumf(int val)
{
    int sum = 1;
    int k;

    for (k = 2; k <= val / 2; ++k)
        if (val % k == 0)
            sum += k;
    return sum;
}

int main()
{
    int i, k;

    for (i = 2; i < MAX; ++i) {
        int val = get_sumf(i);
        for (k = 0; k < i; ++k)
            if (val == k && get_sumf(k) == i)
                printf("%d %d\n", i, k);
    }
    return 0;
}