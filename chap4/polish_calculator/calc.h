#define NUMBER '0'
#define UNKNOWN '?'
#define SIN 'S'
#define COS 'C'
#define TAN 'T'
#define POW 'P'
#define EXP 'E'

int getop(char []);
void push(double);
void clear(void);
double pop(void);
int getch(void);
void ungetch(int);
