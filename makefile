all: npm

npm: main.o BinaryTree.o Node.o Market.o
	g++ -o npm main.o BinaryTree.o Node.o Market.o

main.o: main.cpp
	g++ -c main.cpp

BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -c BinaryTree.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Market.o: Market.cpp Market.h
	g++ -c Market.cpp

clean:
	rm *.o npm