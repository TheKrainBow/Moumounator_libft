print_exercice_name ()
{
	PRINT_LEN=$3
	PRINT_LEN=$(($PRINT_LEN * 2))
	START_LINE=$(printf "Testing %-15s: __ [ " "$1")
	CHECKBOX_LINE=$(printf "%*s]" "$PRINT_LEN" "")
	printf "$START_LINE$CHECKBOX_LINE"
	for i in $(seq -w 00 $((${#CHECKBOX_LINE} - 1)))
	do
		printf "\b"
	done
}

print_result ()
{
	PRINT_LEN=$1
	PRINT_LEN=$(($PRINT_LEN * 2))
	CHECKBOX_LINE=$(printf "%*s]" "$PRINT_LEN" "")
	for i in $(seq -w 00 $((${#CHECKBOX_LINE} + 3)))
	do
		printf "\b"
	done
	if [ $NUMBER_OF_SUCCESS == $NUMBER_OF_TESTS ]; then
		printf "\033[32;1;1mOK\033[0m\n"
	else
		printf "\033[31;1;1mKO\033[0m\n"
	fi
}

