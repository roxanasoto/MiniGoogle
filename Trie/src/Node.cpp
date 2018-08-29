#include "../include/Node.h"

Node::Node() : counter(0) {
	this->child=NULL;
	this->slibing=NULL;
	this->documents=NULL;
	// idDoc=0;
}

Node::Node(string new_key, int set_lenght, int set_counter): 
        key(new_key), 
        length(set_lenght), 
        counter(set_counter) {
			this->child=NULL;
			this->slibing=NULL;
			this->documents=new vector<int>();
			// idDoc=0;
		};

Node::~Node() {}

// vector<int>*& Node::getIdsDocuments(){
// 	return this->documents;
// }
void Node::addDocument(int w){
	documents->push_back(w);
}
string & Node::GetKey() {
	return key;
}
string Node::printDocuments(){
	string cad = "[";
	int size = documents->size();
	for(int i=0;i<size;i++){
		cad = cad+"("+to_string((*documents)[i].id)+","+to_string((*documents)[i].freq)+")"+"-";
	}
	cad+="]";
	return cad;
}
void Node::cleanDocuments(){
	this->documents->clear();
	this->documents->resize(0);
}
int Node::getContador(){
	return counter;
}

bool Node::Setkey(string new_key) {
	key = new_key;
	return true;
}

int Node::GetLength() {
	return length;
}

bool Node::SetLength(int new_length) {
	length = new_length;
	return true;
}

int &Node::GetCounter() {
	return counter;
}

Node*& Node::Child() {
	return this->child;
}

Node*& Node::Brother() {
	return this->slibing;
}
int Node::noDocuments(){
	return this->documents->size();
}
// void Node::setFlacLeaf(char flac){
//     flacLeaf = flac;
// }
// char Node::getFlacLeaf(){
//     return flacLeaf;    
// }