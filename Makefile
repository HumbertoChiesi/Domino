all: 
	gcc -o domino *.c -Wall -Werror -pedantic 

run: 
	./domino