build:
	cc calc_main.c getop.c ../../utils/getch.c stack.c

test:
	cat samples.txt | ./a.out | diff expected_answers.txt -
