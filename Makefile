all:
	g++ main.cpp -c -Wall
	g++ impresso.cpp -c -Wall
	g++ audiobook.cpp -c -Wall
	g++ eletronico.cpp -c -Wall
	g++ livro.cpp -c -Wall
	g++ funcoes.cpp -c -Wall
	g++ *.o -o exec -Wall

run:
	make
	./exec

clear:
	clear
	rm *.o exec saida.txt