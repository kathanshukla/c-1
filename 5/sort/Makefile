build:
	cc sort.c qsort.c ../../utils/readline.c ../../utils/alloc.c ../../utils/get_line.c -o sort.out

test-alpha: build
	cat fixture.txt | ./sort.out

test-numeric: build
	cat num_fixture.txt | ./sort.out -n
