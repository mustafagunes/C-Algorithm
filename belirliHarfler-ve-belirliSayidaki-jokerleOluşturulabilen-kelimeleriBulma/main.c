#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 80

int count_chr(const char *pattern, int ch);
int check_word(const char *word, const char *pattern);
void sort_list(char **p, int size);
void display_list(char **p, int size);

int main(void)
{
  FILE *in_file;
  char pattern[SIZE];
  char line[SIZE];
  int num_of_star;
  int status, i;
  char *match_list[100];

  if ((in_file = fopen("dict.txt", "r")) == NULL)
  {
    printf("can not open dict.txt");
    return 0;
  }

  printf("enter the letters (* for joker): ");
  gets(pattern);

  i = 0;
  while (fgets(line, SIZE, in_file) != NULL)
  {
    line[strlen(line) - 1] = '\0';
    num_of_star = count_chr(pattern, '*');
    status = check_word(line, pattern);

    if (num_of_star + status >= 0)
    {
      match_list[i] = malloc(strlen(line) + 1);

      if (match_list[i] == NULL)
      {
        printf("not enough memory!");
        return 0;
      }
      strcpy(match_list[i++], line);
    }
  }

  sort_list(match_list, i);
  display_list(match_list, i);
  fclose(in_file);
  return 0;
}

/*****************************************************************
pattern karakter dizisinde bulunan ch karakterlerini sayar ve bu
degeri dondurur.
*****************************************************************/

int count_chr(const char *pattern, int ch)
{
  int count = 0;

  while (*pattern != '\0')
  {
    if (*pattern == ch)
    {
      count++;
    }
    pattern++;
  }
  return count;
}

/*****************************************************************
word adresindendeki karakter dizisinde bulunan fakat pattern
adresindeki karakter dizisinde bulunmayan karakterlerin saysn
dondurur. Geri donus degeri 0 ise word karakter dizisi pattern
karakter dizisinde bulunan karakterlerle olusturulabiliyor demektir.
*****************************************************************/

int check_word(const char *word, const char *pattern)
{
  int count = 0;
  char temp[SIZE], *p;

  strcpy(temp, pattern);

  while (*word != '\0')
  {
    p = temp;

    while (*p != '\0')
    {
      if (*p == *word)
        break;
      p++;
    }

    if (*p == '\0')
      count--;
    else
      *p = '*'; /* pattern icinde bulunan karakter * ile eziliyor. */

    word++;
  }
  return count;
}

/*****************************************************************/

void sort_list(char **p, int size)
{
  int i, j, max;
  char temp[SIZE];

  for (i = 0; i < size; i++)
  {
    max = i;
    for (j = i + 1; j < size; j++)
    {
      if (strlen(p[j]) > strlen(p[max]))
      {
        max = j;
      }
    }
    strcpy(temp, p[i]);
    strcpy(p[i], p[max]);
    strcpy(p[max], temp);
  }
}

/*****************************************************************/

void display_list(char **p, int size)
{
  int i;

  for (i = 0; i < size; i++)
  {
    printf("%s\n", p[i]);
  }
}