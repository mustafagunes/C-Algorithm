/*****************************************************************/
/*                                                               */
/*  Craps Oyunu Kuralları: https://tr.wikipedia.org/wiki/Craps   */
/*                                                               */
/*****************************************************************/

#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define OYUN_SAYISI 1000000

int oyun(void);
int zarAt(void);
int oyun_devami(int);

int zarAt()
{
    int zar1 = rand() % 6 + 1;
    int zar2 = rand() % 6 + 1;

    return zar1 + zar2;
}

int oyun()
{
    int zar = zarAt();

    switch (zar)
    {
    case 2:
    case 3:
    case 12:
        return 0;
    case 7:
    case 11:
        return 1;
    default:
        return oyun_devami(zar);
    }
}

int oyun_devami(int zar)
{
    int yenizar;

    while (1)
    {
        yenizar = zarAt();

        if (yenizar == zar)
            return 1;
        if (yenizar == 7)
            return 0;
    }
}

int main()
{
    int k;
    int kazanc_sayaci = 0;

    srand(time(0));

    for (k = 0; k < OYUN_SAYISI; ++k)
        kazanc_sayaci += oyun();

    printf("Kazanma olasılığı = %lf\n", (double)kazanc_sayaci / OYUN_SAYISI); // double'a cast ediliyor.

    return 0;
}