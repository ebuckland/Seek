#
# Makefile
#
# CS50 AP
# Problem 3-6
#

all: seek generate

seek: seek.c helpers.c helpers.h
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o seek seek.c helpers.c -lcs50 -lm

generate: generate.c
	clang -ggdb3 -O0 -std=c11 -Wall -Werror -o generate generate.c

clean:
	rm -f *.o a.out core seek generate