#include <stdio.h>
#include <conio.h>


#define BASE_YEAR 1900

int is_leap(int year);
long date_to_num(int day, int month, int year);
int which_day(int day, int month, int year);
void display_calender(int month, int year);

int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *month_name[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};


int main(void)
{
    int i, year;

    for (;;)
    {
        printf("enter year :");
        scanf("%d", &year);
        if (year < BASE_YEAR)
            printf("year must be grater than %d\n", BASE_YEAR);
        else
            break;
    }

    for (i = 1; i < 13; i++)
    {
        display_calender(i, year);
        if (i % 3 == 0)
        {
            printf("\npress any key to continue\n");
            getchar();
            //clrscr();
        }
    }
    return 0;
}

/**************************************************/

int is_leap(int year)
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

/**************************************************/

long date_to_number(int day, int month, int year)
{
    int i;
    long total = day;

    for (i = BASE_YEAR; i < year; i++)
        total += 365 + is_leap(i);

    for (i = 0; i < month - 1; i++)
        total += month_day[i] + (i == 1 && is_leap(year));
    return total;
}

/**************************************************/

int which_day(int day, int month, int year)
{
    long i = date_to_number(day, month, year);

    return (int)(i % 7);
}

/**************************************************/

void display_calender(int month, int year)
{
    int first_day = which_day(1, month, year);
    int total_day = month_day[month - 1];
    int i;

    if (month - 1 == 1)
        total_day += is_leap(year);

    printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat");
    printf("   %s  %4d\n", month_name[month - 1], year);
    printf("---------------------------------\n");

    for (i = 0; i < first_day; i++)
        printf("     ");

    for (i = 1; i <= total_day; i++)
    {
        printf("%-5d", i);
        if ((i + first_day) % 7 == 0)
            putchar('\n');
    }
    printf("\n");
}