#include <stdio.h>

int sget_word(char* s, char* word, int lim);

int main()
{
  char word_array[100];
  char* string = "a name is a ? thing like . bob";
  int advanced = 0;

  printf("\n\nsget_word tests:\n");
  while ((advanced = sget_word(string = string + advanced, word_array, 100)) > 0) {
    printf("(%s) ", word_array);
  }
  printf("\n");
}
