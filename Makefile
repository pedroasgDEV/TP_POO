all:
	g++ main.cpp -c -Wall
	g++ impresso.cpp -c -Wall
	g++ audiobook.cpp -c -Wall
	g++ eletronico.cpp -c -Wall
	g++ livro.cpp -c -Wall
	g++ *.o -o exec -Wall

run:
	make
	./exec

clear:
	rm *.o exec
	clear