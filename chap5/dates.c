#include <stdio.h>
#include <stdlib.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

int main(int argc, char **argv) {
  int year = atoi(*++argv);
  int yearday = atoi(*++argv);
  int month, monthday;

  month_day(year, yearday, &month, &monthday);
  printf("Month: %d, Day: %d\n", month, monthday);
}

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// make inline int?
int is_leap(int year) {
  return (year%4 == 0 && year%100 !=0) || year%400 == 0;
}

int day_of_year(int year, int month, int day) {
  int i, leap;

  leap = is_leap(year);
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;
  leap = is_leap(year);
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}
