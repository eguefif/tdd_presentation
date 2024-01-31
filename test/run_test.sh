# test parser output map
cat ../map.ber > d1
./test_parser > d2
diff d1 d2 > result
echo "Test map parsing: "
if [ -z "$(VAR)" ]; then
	echo "\e[32mTest passed\n"
elif
	echo "\e[031Test failed.\n"
	cat result
fi

echo "\e[0m"

rm d1 d2 result
