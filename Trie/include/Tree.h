#include "Node.h"
#include<iostream>
#include<string>
// #include <sstream>  
#include <fstream>
// #include "types.h"
#include <vector>
#include "wordlist.h"
using namespace std;


class Tree{
private:
	Node* root;
	int idLastDoc;

public:
	Tree();
	~Tree();

	Node* GetRoot();
	bool SetRoot(Node*);
	bool InsertWord(string);
	int Prefix(string, string);
    Node* Find(string);
	Node* Find(Node*, string);
	void Split(Node*, int, int);
	bool Insert(string, int,int);
	
	Node* Insert(Node*,string , int, int);
	void TraversalSave(Node*, ofstream&);
	void Save(string);
	void TraversalLoad(Node*&, ifstream&, istringstream&);
	void Load(string);
	void printTree();
	void printNode(Node*);

	bool indexDocument(vector<string> );
	bool indexDocument(WordList* );
	string printIdsDocuments(Node* );
	void setIdLastDocument(int);
	void restarCounters();
	void restarCounters(Node*);
	// bool Insert(Word);
};