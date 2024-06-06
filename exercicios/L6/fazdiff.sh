gcc L6_4e5_1a.c -o teste

./teste < input/test_1 >output/out_1

diff output/out_1 output/test_1 --color -u

