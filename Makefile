all: BST_Node.cpp BinarySearchTree.cpp GenericQueue.cpp
	g++ -c BST_Node.cpp 
	g++ -o BinarySearchTree BinarySearchTree.cpp BST_Node.o 

clean:
	rm -f BST_Node.o GenericQueue.o BinarySearchTree

.PHONY: all clean
