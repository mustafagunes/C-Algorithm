#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define   NO_OF_WORDS   20
#define   MIN_LEN       9
#define   MAX_LEN       15
#define   MAX_VOWEL     2
#define   MAX_CONS      3

int is_vowel(int a);

int main()
{
    int i, l, ch, vowelCounter, consCounter, counter;

    vowelCounter = consCounter = 0;

    for (i = 0; i < NO_OF_WORDS; i++) {
        counter = 0;
        l = rand() % (MAX_LEN - MIN_LEN + 1) + MIN_LEN;

        while (counter < l) {
            ch = (rand() % 26 + 'A');
            if (is_vowel(ch)) {
                vowelCounter++;
                if (vowelCounter < MAX_VOWEL) {
                    printf("%c", ch);
                    counter++;
                }
                consCounter = 0;
            }
            else {
                consCounter++;
                if (consCounter < MAX_CONS) {
                    printf("%c", ch);
                    counter++;
                }
                vowelCounter = 0;
            }
        }
        putchar('\n');
    }
    return 0;
}

int is_vowel(int a)
{
    return (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U');
}