#include<iostream>
#include<vector>
#include "types.h"
using namespace std;

class Node{

private:
	string key;
	int counter;
	int length;
	Node* child;
	Node* slibing;
	vector<int>* documents;
	// int idDoc;
	// char flacLeaf;

public:
	Node();
	Node(string, int, int = 0);
	~Node();

	string& GetKey();
	bool Setkey(string);
	int GetLength();
	bool SetLength(int);
	int& GetCounter();
	Node*& Child();
	Node*& Brother();
	vector<int>*& getIdsDocuments();
	void addDocument(int);
	string printDocuments();
	void cleanDocuments();
	int noDocuments();
	int getContador();
	// void setFlacLeaf(char);
	// char getFlacLeaf();

};