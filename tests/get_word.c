#include <stdio.h>

int get_word(char *word, int lim);

int main()
{
  char word_array[100];
  while (get_word(word_array, 100) != EOF) {
    printf("(%s) ", word_array);
  }
  printf("\n");
}
