CFLAG = -Wall -Werror -std=gnu++98 -ggdb3

test: bsttest.cpp bstmap.h map.h
	g++ bsttest.cpp -o test

.PHONY:clean
clean:
	rm -rf *.cpp~ *.h~ test
