build-get-word:
	cc get_word.c ../utils/get_word.c ../utils/getch.c -o _get_word.out

test-get-word: build-get-word
	echo " asd asd asd" | ./_get_word.out
	echo "123 asd" | ./_get_word.out
	echo "123 asd" | ./_get_word.out
	echo "#define TEST 1" | ./_get_word.out
	echo "##define TEST 1" | ./_get_word.out
	echo "# a comment" | ./_get_word.out
	echo "my_var = 1" | ./_get_word.out
