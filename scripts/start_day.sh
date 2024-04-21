lines=$(find . -maxdepth 3 -wholename "./tests/$1" | wc -l)
if [ $lines -eq 1 ]; then
	source scripts/test_c_function.sh $1 tests
	return
fi
lines=$(find . -maxdepth 3 -wholename "./bonus/$1" | wc -l)
if [ $lines -eq 1 ]; then
	source scripts/test_c_function.sh $1 bonus
	return
fi
printf "Testing $1                          : NA [ No tests turned in ]\n"