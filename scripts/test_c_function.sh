DAY_NUMBER=$1
DAY_PATH=$2

source scripts/print.sh

TEST_LIST=$(find $DAY_PATH/$DAY_NUMBER/ -mindepth 1 -maxdepth 1 -type f -name "*.c" | sed "s/$DAY_PATH\///" | sed "s/\..*//" | sort)

# Skip if no tests turned in
if [ -z "$TEST_LIST" ]
then
    return
fi

if ! test -d "$DAY_PATH/$DAY_NUMBER"; then
	printf "No tests for $DAY_NUMBER\n"
	return
fi

if ! test -d "outputs/$DAY_NUMBER/"; then
	mkdir "outputs/$DAY_NUMBER/"
fi

# Print exercice name with empty bracket
print_exercice_name $DAY_NUMBER "" $(find $DAY_PATH/$DAY_NUMBER/ -mindepth 1 -type f -name "*.c" | sed "s/.*\/test//" | sed "s/.*_//" | wc -l) ${#TEST_LIST[@]}

NUMBER_OF_SUCCESS=0
NUMBER_OF_TESTS=0

test_function()
{
	TEST_NAME=$(echo $FULL_TEST_NAME | sed "s/.*test//")
	# Create output folder if doesn't exist
	OUTPUT_PATH="outputs/$DAY_NUMBER/${TEST_NAME}"
	if ! test -d $OUTPUT_PATH; then
		mkdir $OUTPUT_PATH
	fi
	# Compile test with working library
	cc ./$DAY_PATH/${FULL_TEST_NAME}.c libs/Moumounator.a -Wl,--wrap,malloc -Wl,--wrap,free -lm -lbsd -o $OUTPUT_PATH/answer.out
	if [ $? -ne 0 ]; then
		continue
	fi
	# Compile test with user library
	cc -Wall -Wextra -Werror -fsanitize=address -g ./$DAY_PATH/${FULL_TEST_NAME}.c libs/libft.a -Wl,--wrap,malloc -Wl,--wrap,free -o $OUTPUT_PATH/user.out 2> $OUTPUT_PATH/user.compilation_error.out
	if [ $? -ne 0 ]; then
		printf "\033[31;1;1m✗ \033[0m"
		rm ./$OUTPUT_PATH/answer.out
		cp ./$DAY_PATH/${FULL_TEST_NAME}.c $OUTPUT_PATH/main.c
		NUMBER_OF_TESTS=$(($NUMBER_OF_TESTS + 1))
		return
	else
		rm $OUTPUT_PATH/user.compilation_error.out
	fi
	# Execute both executable and redirect outputs in txt files
	./$OUTPUT_PATH/answer.out > $OUTPUT_PATH/answer.txt
	timeout 3 ./$OUTPUT_PATH/user.out > $OUTPUT_PATH/user.txt 2> $OUTPUT_PATH/user_errors.txt
	if [ $? -eq 124 ]; then
		printf "Timed out after 3 secondes!" > $OUTPUT_PATH/user_errors.txt
	fi
	if [[ -z $(grep '[^[:space:]]' $OUTPUT_PATH/user_errors.txt) ]]; then
		rm $OUTPUT_PATH/user_errors.txt
	fi
	rm ./$OUTPUT_PATH/answer.out ./$OUTPUT_PATH/user.out
	# Diff the txt files
	diff $OUTPUT_PATH/answer.txt $OUTPUT_PATH/user.txt > $OUTPUT_PATH/diff.txt
	if [ $? -eq 1 ] || [ -s "$OUTPUT_PATH/user_errors.txt" ]; then
		printf "\033[31;1;1m✗ \033[0m"
		cp ./$DAY_PATH/${FULL_TEST_NAME}.c $OUTPUT_PATH/main.c
	else
		printf "\033[32;1;1m✓ \033[0m"
		NUMBER_OF_SUCCESS=$(($NUMBER_OF_SUCCESS + 1))
		if [ $RM_ON_SUCCESS -ne 0 ]; then
			rm -r $OUTPUT_PATH
		fi
	fi
	NUMBER_OF_TESTS=$(($NUMBER_OF_TESTS + 1))
}

# Execute each tests
for FULL_TEST_NAME in $TEST_LIST
do
	test_function
done
wait
if [ $NUMBER_OF_SUCCESS == $NUMBER_OF_TESTS ]; then
	print_result $(find $DAY_PATH/$DAY_NUMBER/ -mindepth 1 -type f -name "*.c" | sed "s/.*\/test//" | sed "s/_.*//" | wc -l)
else
	print_result $(find $DAY_PATH/$DAY_NUMBER/ -mindepth 1 -type f -name "*.c" | sed "s/.*\/test//" | sed "s/_.*//" | wc -l)
fi

if [ -z "$(ls -A outputs/$DAY_NUMBER/)" ]; then
	rm -rf outputs/$DAY_NUMBER/
fi

if [ -z "$TOTAL_SUCCESS" ]; then
	TOTAL_SUCCESS=$NUMBER_OF_SUCCESS
else
	TOTAL_SUCCESS=$(($TOTAL_SUCCESS + $NUMBER_OF_SUCCESS))
fi

if [ -z "$TOTAL_TESTS" ]; then
	TOTAL_TESTS=$NUMBER_OF_TESTS
else
	TOTAL_TESTS=$(($TOTAL_TESTS + $NUMBER_OF_TESTS))
fi