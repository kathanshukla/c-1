build:
	cc get_int.c ../utils/getch.c -o getint.out

build-float:
	cc get_float.c ../utils/getch.c -o getfloat.out

test: build
	echo "1 2 3 12 123 -1 -12 -123 + 8" | ./getint.out

test-float: build-float
	echo "1 2 3 1.234 12.3 -123.456" | ./getfloat.out
