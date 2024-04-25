source settings.sh

if ! test -d "outputs"; then
	mkdir "outputs"
fi

if [ -n "$(ls -A outputs/)" ]; then
	rm -rf outputs/*
fi
TOTAL_SUCCESS=0
TOTAL_TESTS=0
PATH_TO_LIBFT=$(echo $PATH_TO_LIBFT | sed "s/\/$//")
cd $PATH_TO_LIBFT
make > /dev/null
cd - > /dev/null
cp $PATH_TO_LIBFT/libft.a ./libs 2> /dev/null
cd - > /dev/null
make fclean > /dev/null
cd - > /dev/null
if [ $? -ne 0 ]; then
	echo "Couldn't make libft"
	exit
fi
if [ "$1" == "bonus" ]; then
	echo "Testing Bonus:"
	echo "No test added yet"
	exit
fi

if [ -z "$1" ]; then
	echo "No exercice number specified. Starting all tests:"
	for DAY_NUMBER in $(find tests/ -mindepth 1 -maxdepth 1 -type d | sed "s/.*\///" | sort)
	do
		source scripts/start_day.sh $DAY_NUMBER tests
	done
else
	INPUT=$(echo $1 | sed "s/ex//")
	source scripts/start_day.sh $DAY_NUMBER
fi

if [ $TOTAL_SUCCESS == $TOTAL_TESTS ]; then
	printf "\n\033[32;1;1m╭───────────────────────────────╮\n"
	printf "│\033[0m %3d/%-3d tests                 \033[32;1;1m│\n" $TOTAL_SUCCESS $TOTAL_TESTS
	printf "│\033[0m Everything is good for me! :) \033[32;1;1m│\n"
	printf "╰───────────────────────────────╯\033[0m\n"
else
	printf "\n\033[31;1;1m╭───────────────────────────────╮\n"
	printf "│\033[0m %3d/%-3d tests                 \033[31;1;1m│\n" $TOTAL_SUCCESS $TOTAL_TESTS
	printf "│\033[0m Check outputs for details :(  \033[31;1;1m│\n"
	printf "╰───────────────────────────────╯\033[0m\n"
fi
