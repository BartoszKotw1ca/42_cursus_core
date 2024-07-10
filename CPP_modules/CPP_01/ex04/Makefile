all:
	@ c++ main.cpp utils.cpp -std=c++98 -Wall -Wextra -Werror -o sed
	-./sed test.txt tak nie
	@ rm sed
test:
	@ c++ utils.cpp tests.cpp -std=c++98 -Wall -Wextra -Werror -o test
	./test
	@ rm test

