#include "../include/Tree.h"


Tree::Tree() {
	this->root = NULL;
}

Tree::~Tree() {
}

Node* Tree::GetRoot() {
	return root;
}
// bool Tree::Insert(Word word){
// 	Node* p = Insert(root, word.cadena, word.freq);

// 	if (!root) {
// 		root = p;
// 	}

// 	return true;
// }

bool Tree::SetRoot(Node* new_root) {
	/* Aca faltaa try catch o algooo */
	root = new_root;
	return true;
}

bool Tree::InsertWord(string new_word) {
	return true;
}

int Tree::Prefix(string key_a, string key_b) { // length of the biggest common prefix of x and key strings
	for (unsigned int i = 0; i < key_a.length(); ++i) {
		if (i == key_b.length() || key_a[i] != key_b[i]) {
			return i;
		}
	}
	return key_a.length();
}

Node* Tree::Find(string key) {
	return Find(root, key);
}

Node* Tree::Find(Node* node, string key) {
	if (!node) {
		return 0;
	}
	unsigned int k = Prefix(key, node->GetKey());
	if (k == 0) {//cadenas diferentes
		return Find(node->Brother(), key); // let�s look for the child�s node
	} if (k < node->GetLength()) {//el nodo actual no esta particionado para el prefijo buscado
		return 0;
	} if (k == key.length()) {
		return node;
	}
	return Find(node->Child(), key.substr(k, key.length()));
}

void Tree::Split(Node* node, int k) { // dividing node according to k key symbol
//crear un nuevo nodo con el sufijo no repetido
// cout<<"dividiendo"<<endl;
	Node* p = new Node(node->GetKey().substr(k, node->GetLength()), node->GetLength() - k, node->GetCounter());
	// p->setFlacLeaf(leaf);
	p->setChild(node->Child());
	node->setChild(p);
	node->GetKey().erase(k, node->GetLength()); //recortar string en nodo padre
	node->SetLength(k);
	node->setCounter(0);
}

bool Tree::indexDocument(vector<string> words){
	// if(words){
		// Node* p;
		for(int i=0;i<5;i++){
			
			Node* p = Insert(root, words[i], 1);
			if (!root) {
				root = p;
			}
			cout<<words[i]<<endl;
		}
		return true;
	// }
	// return false;
	
	
}
bool Tree::Insert(string key, int number) {
	// cout<<"se inserto00000:"<<key<<endl;
	Node* p = Insert(root, key, number);

	if (!root) {
		root = p;
	}

	return true;
}


Node* Tree::Insert(Node* node, string key, int number) { // inserting key in tree
// cout<<"se inserto"<<endl;
	if (!node) {
		return new Node(key, key.length(), number);
	}
	unsigned int k = Prefix(key, node->GetKey());
	if (k == 0) {
		// cout<<"se insertara en hermano"<<endl;
		node->setBroter(Insert(node->Brother(), key, number));

		return node;
	} if (k < node->GetLength()) { // cut or not to cut?
		Split(node, k);
		if (k < key.length()) {
			node->setChild(Insert(node->Child(), key.substr(k, key.length()), number));
		}
		else{
			int counter = node->GetCounter() +number;
			node->setCounter(counter);
		}
		return node;
	} if (k < key.length()) {
		node->setChild(Insert(node->Child(), key.substr(k, key.length()), number));
	}
	else {
		int counter = node->GetCounter() +number;
		node->setCounter(counter);
	}
	return node;
}
void Tree::printTree() {
	cout<<"_____________________"<<endl;
	if(!root){
		cout<<"trie vacio"<<endl; 
		return;
	} 
	printNode(this->root);
}

void Tree::printNode(Node* node) {
	// cout<<"clave: ";
	if(node!=NULL){
		cout<<node->GetKey()<<", "<<node->GetCounter()<<"/"<<endl;;
		printNode(node->Child());
		printNode(node->Brother());
	}
}

// 
// void Tree::TraversalSave(Node *node, ofstream &out) {
// 	if (!node) {
// 		out<< ";";
// 	}
// 	else {
// 		out << node->GetKey() << '/' << node->GetCounter();
// 		if (node->Child()) {
// 			out << ",";
// 		}
// 		TraversalSave(node->Child(), out);
// 		TraversalSave(node->Brother(), out);
// 	}
// }

// 
// void Tree::Save(string directory) {
// 	ofstream file;

// 	file.open(directory);

// 	TraversalSave(root, file);

// 	file.close();
// }

// 
// void Tree::TraversalLoad(Node *&node, ifstream &file, istringstream &iss) {

// 	string content, data, key;
// 	int number;

// 	istringstream issdata;

// 	if (iss.rdbuf()->in_avail()) {

// 		getline(iss, data, ',');

// 		issdata.str(data);

// 		getline(issdata, key, '/');

// 		issdata >> number;

// 		issdata.clear();

// 		node = new Node(key, key.length(), number);

// 		TraversalLoad(node->Child(), file, iss);

// 		if (!file.eof()) {

// 			getline(file, content, ';');
// 			iss.str(content);

// 			TraversalLoad(node->Brother(), file, iss);
// 			iss.clear();
// 		}
// 	}
// 	iss.clear();
// }

// 
// void Tree::Load(string directory) {

// 	ifstream file;
// 	istringstream iss;
// 	string content;

// 	Node *&node = root;
// 	file.open(directory);

// 	getline(file, content, ';');
// 	iss.str(content);

// 	TraversalLoad(node, file, iss);

// 	file.close();

// }