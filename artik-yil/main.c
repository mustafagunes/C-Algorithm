#include <stdio.h>

int isleap(int y)
{
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

int main ()
{
    int year;

    printf("Bir yıl giriniz : ");
    scanf("%d", &year);

    if (isleap(year))
        printf("%d yılı artık yıldır!\n", year);
    else
        printf("%d yılı artık yıl değildir!\n", year);
    
    return 0;
}