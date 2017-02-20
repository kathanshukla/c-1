build:
	cc get_word.c ../utils/get_word.c ../utils/getch.c -o _get_word.out
	cc sget_word.c ../utils/get_word.c ../utils/getch.c -o _sget_word.out

test-get-word: build
	echo " asd asd asd" | ./_get_word.out
	echo "123 asd" | ./_get_word.out
	echo "123 asd" | ./_get_word.out
	echo "#define TEST 1" | ./_get_word.out
	echo "##define TEST 1" | ./_get_word.out
	echo "# a comment" | ./_get_word.out
	echo "my_var = 1" | ./_get_word.out
	echo "new\nline" | ./_get_word.out

test-sget-word: build
	./_sget_word.out
