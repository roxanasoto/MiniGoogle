#include "../include/Tree.h"


Tree::Tree() {
	this->root = NULL;
	this->idLastDoc = 0;
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
void Tree::setIdLastDocument(int id){
	this->idLastDoc = id;
}
void Tree::restarCounters(){
	restarCounters(root);
}
void Tree::restarCounters(Node* n){
	if(n!=NULL){
		n->GetCounter()=0;
		restarCounters(n->Brother());
		restarCounters(n->Child());
	}
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

void Tree::Split(Node* node, int k, int idDoc) { // dividing node according to k key symbol
//crear un nuevo nodo con el sufijo no repetido
	Node* p = new Node(node->GetKey().substr(k, node->GetLength()), node->GetLength() - k, node->GetCounter());
	// p->setFlacLeaf(leaf);
	p->Child() = node->Child();

	Word word; word.id=idDoc;
	p->addDocument(word);
	node->Child() = p;
	node->GetKey().erase(k, node->GetLength()); //recortar string en nodo padre
	node->SetLength(k);
	node->GetCounter() = 0;
	node->cleanDocuments();
	// (node->getIdsDocuments())->push_back(idDoc);
	// node->setFlacLeaf(noleaf);
}

bool Tree::indexDocument(vector<string> words){
	if(root!=NULL){
		this->restarCounters();
	}
	// if(words){
		// Node* p;
		for(int i=0;i<words.size();i++){
			
			Node* p = Insert(root, words[i], 1, 1);
			if (!root) {
				root = p;
			}
			// cout<<words[i]<<endl;
		}
		return true;
	// }
	// return false;
	
	
}
bool Tree::indexDocument(WordList* words){
		for(int i=0;i<words->wordList.size();i++){
			Node* p = Insert(root, words->wordList[i], 1, words->docId);
			if (!root) {
				root = p;
			}
		}
		return true;
}

bool Tree::Insert(string key, int number,int idDoc) {
	// cout<<"se inserto"<<endl;
	Node* p = Insert(root, key, number,idDoc);

	if (!root) {
		root = p;
	}

	return true;
}


Node* Tree::Insert(Node* node, string key, int number, int idDoc) { // inserting key in tree
	// int counter_anterior;
	// if(node != NULL)
	// 	counter_anterior = node->GetCounter();
	if (!node) {
		Node* n = new Node(key, key.length(), number);
		Word word; word.id=idDoc;
		n->addDocument(word);
		return n;
	}
	unsigned int k = Prefix(key, node->GetKey());
	if (k == 0) {
		node->Brother() = Insert(node->Brother(), key, number,idDoc);
		return node;
	} if (k < node->GetLength()) { // cut or not to cut?
		Split(node, k,idDoc);
		if (k < key.length()) {
			node->Child() = Insert(node->Child(), key.substr(k, key.length()), number,idDoc);
		}
		else{
			
			node->GetCounter() += number;
			// if(node->GetCounter() !=0 && idLastDoc >0 && idLastDoc!=idDoc){
			if(node->GetCounter() !=0 && node->GetCounter()<=1){
				Word word; word.id=idDoc;
				node->addDocument(word);
			// if(node->GetCounter()!=0 && node->noDocuments()>0){

			}
				
		}
		return node;
	} if (k < key.length()) {
		node->Child() = Insert(node->Child(), key.substr(k, key.length()), number,idDoc);
	}
	else {
		node->GetCounter() += number;
		// if(node->GetCounter()!=0&& node->GetCounter()<2)
		if(node->GetCounter()!=0 && node->GetCounter()<=1){
			Word word; word.id=idDoc;
			node->addDocument(word);
		}
			
	}
	return node;
}
void Tree::printTree() {
	cout<<"_____________________"<<endl;
	if(!this->root){
		cout<<"trie vacio"<<endl; return;
	} 
	printNode(this->root);
}

void Tree::printNode(Node* node) {
	// cout<<"clave: ";
	if(node){
		cout<<node->GetKey()<<", "<<node->GetCounter()<<node->printDocuments()<<endl;;
		printNode(node->Child());
		printNode(node->Brother());
	}
}
string Tree::printIdsDocuments(Node* node){
	
	string cad = "[";
	// vector<int>* ids = node->getIdsDocuments();
	// int size = ids->size();
	// cout<<"ntnt: "<<size<<endl;
	// for(int i=0;i<size;i++){
	// 	cad+to_string((*ids)[i])+",";
	// }
	// cad+="]";
	return cad;
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