#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

int rand_number(void);
int is_valid(int number);

int main(void)
{
    int i, a[SIZE];

    srand(time(NULL));

    for (i = 0; i < SIZE; i++)
        while (!is_valid(a[i] = rand_number()))
            ;
    for (i = 0; i < SIZE; i++)
        printf("%d ", a[i]);
    putchar('\n');

    return 0;
}

/*****************************************************************
1000 ile 9999 arasinda rasgele sayi ureten fonksiyon
*****************************************************************/

int rand_number(void)
{
    return rand() % 9000 + 1000;
}

/****************************************************************
kendisine gonderilen sayinin kosula uygun, basamaklari tekrar
etmeyen bir sayi olup olmadigini test eden fonksiyon. uygunsa 1
degilse 0 degirini uretiyor.
*****************************************************************/

int is_valid(int number)
{
    int temp, i, j;

    for (i = 0; i < 10; i++) {
        j = 0;
        temp = number;
        while (temp > 0) {
            if (temp % 10 == i)
                j++;
            if (j > 1)
                return
            temp /= 10;
        }
    }
    return -1;
}