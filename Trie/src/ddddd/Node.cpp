#include "../include/Node.h"

Node::Node() : counter(0) {
	this->slibing=NULL;
	this->child = NULL;
}

Node::Node(string new_key, int set_lenght, int set_counter): 
        key(new_key), 
        length(set_lenght), 
        counter(set_counter) {
			this->slibing=NULL;
			this->child = NULL;
		};

Node::~Node() {}

string Node::GetKey() {
	return key;
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
void Node::setCounter(int c){
	this->counter=c;
}
int Node::GetCounter() {
	return counter;
}

Node* Node::Child() {
	return this->child;
}

Node* Node::Brother() {
	return this->slibing;
}
void Node::setChild(Node* n){
	this->child = n;
}
void Node::setBroter(Node* n){
	this->slibing=n;
}
// void Node::setFlacLeaf(char flac){
//     flacLeaf = flac;
// }
// char Node::getFlacLeaf(){
//     return flacLeaf;    
// }