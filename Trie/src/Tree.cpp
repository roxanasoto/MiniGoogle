#include "../include/Tree.h"


Tree::Tree() {
	this->root = NULL;
	this->idLastDoc = 0;this->cloud = new Cloud();
}

Tree::~Tree() {
}

Node* Tree::GetRoot() {
	return root;
}

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
set<tuple<int, int>, greater<tuple<int,int>>> Tree::search(string key){
	cout<<"Buscando: "<<key<<"..."<<endl;
	Node* rpta = Find(root, key);
	set<tuple<int, int>, greater<tuple<int,int>>> docs;
	if(rpta != 0){
		cout<<" results done..."<<rpta->printTuples()<<endl;
		// set<tuple<int, int>, greater<tuple<int,int>>> docs = rpta->getTuples();
		return rpta->getTuples();
	}
	cout<<" not results..."<<endl;
	return docs;
}
bool Tree::search(vector<string> keys){
	vector<set<tuple<int, int>, greater<tuple<int,int>>>> docs;
	// set<tuple<int, int>, greater<tuple<int,int>>> docs;
	Node* rpta;
	for(int i=0;i<keys.size();i++){
		rpta = Find(root, keys[i]);
		if(rpta != 0){
			cout<<" is done..."<<endl;
			docs.push_back(rpta->getTuples());
		}
		else{
			cout<<" not results..."<<endl;
		}
	}
	if(docs.size()>0){
		int index_min_set=0;
		int minsize = docs[0].size();
		for(int i=1;i<docs.size();i++){ //buscar el set con menos conjuntos de elementos
			if(docs[i].size()<minsize){
				minsize = docs[i].size();
				index_min_set = i;
			}
		}
		cout<<" minsize: "<<minsize<<" index: "<<index_min_set<<endl;
		map<int,int> intersecciones;
		tuple<int, int> element;
		map<int, int>::iterator map_it;
		int idDoc;
		vector<int> idsDoc;
		for (set<tuple<int, int>>::iterator i = docs[index_min_set].begin(); i != docs[index_min_set].end(); i++) 
		{
			element = *i;
			// idDoc = get<0>(element);
			// map_it = intersecciones.find(idDoc);
			// if(map_it!=intersecciones.end()){
			// 	intersecciones.insert(pair<int,int>(get<0>(element),0));
			// 	cout<< get<0>(element) <<" - " << get<1>(element)<<endl;
			// }	
			// cout<<" 0 element: "<<get<1>(element)<<endl;
			intersecciones.insert(pair<int,int>(get<1>(element),0));
		}

		//recorrer set de tamaño minimo
		for (set<tuple<int, int>>::iterator i = docs[index_min_set].begin(); i != docs[index_min_set].end(); i++) 
		{
			element = *i;
			for(int i=1;i<docs.size() && i!=index_min_set;i++){ //acceder a los demas sets para buscar interseccion de ids.
				// busqueda binaria: buscar la tupla del set minimo en los demas sets.
				set<tuple<int, int>>::iterator it = find_if(docs[i].begin(), docs[i].end(), [&element](const tuple<int, int>& item) 
				{
					return get<1>(element) == get<1>(item);
				});
				if(it!=docs[i].end()){
					intersecciones[get<1>(element)]+=1;
					// idsDoc.push_back();
					// cout<<"fallo buscando un documento con todas las palabras "<<intersecciones.size()<<endl;
				}
			}
		}
		for (map_it=intersecciones.begin(); map_it!=intersecciones.end(); map_it++){
			cout<<map_it->first<<": "<<map_it->second<<endl;
		}
		// cout<<" map size: "<<intersecciones.size()<<endl;
	}
	else{
		cout<<"ningun documento contiene toda la oracion..."<<endl;
	}
	return true;
}

// vector<int> intersection(map<int,int>& mapa, vector<vector<int>>& docs_by_word, int idx_min){
// 	vector<int> result;
// 	map<int,int>::iterator map_it;
// 	for(int i=0;i<docs_by_word.size() && i!= idx_min;i++){//recorrer los demas resultados
// 		vector<int> docs = docs_by_word[i];
// 		for(int j=0;j<docs.size();j++){//recorrer
// 			map_it = mapa.find(docs[j]);
// 			if(map_it!=mapa.end()){
// 				mapa[docs[j]] ++;
// 			}
// 		}
// 	}
// 	return result;
// }
void print_vector(vector<int> vec){
	cout <<"======================= "<<endl;
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<endl;
	}
}
vector<int> intersection(vector<vector<int>>& docs_by_word, int idx_min){
	// oredenar vectores por tamaño
	std::sort(docs_by_word.begin(), docs_by_word.end(), [](const vector<int> & a, const vector<int> & b){ return a.size() < b.size(); });
	// print_vector(docs_by_word[0]);
	// print_vector(docs_by_word[1]);
	// print_vector(docs_by_word[2]);

	vector<int> result;
	vector<int> docs_minimo = docs_by_word[0];
	vector<int> copy;
	sort(docs_minimo.begin(), docs_minimo.end());
	// print_vector(docs_by_word[idx_min]);
	vector<int>::iterator it;
	bool flac = false;
    // cout <<"buscando interseccion... "<<idx_min<<" "<<docs_by_word.size()<<endl;
	for(int i=1;i<docs_by_word.size() ;i++){//recorrer los demas resultados
		// if(i!= idx_min){
			// cout <<"wntrooooooooooo "<<endl;
			copy = docs_by_word[i];
			sort(copy.begin(), copy.end());
			// print_vector(docs_by_word[i]);
			result.resize(docs_minimo.size());
			it = set_intersection(docs_minimo.begin(),docs_minimo.end(),copy.begin(),copy.end(),result.begin());
			result.resize(it-result.begin()); 
			

			if(result.size()==docs_minimo.size()){ //existen todas las intersecciones
				// cout <<"hay: "<<result.size()<<" intersecciones"<<endl;
				
				flac = true;
			}
			else{
				flac=false;
				cout <<"no hay interseccion completa..."<<endl;
				return result;
			}
			print_vector(result);
			result.clear();
			result.resize(0);
		// }
		
	}
	
	return result;
}

vector<int> Tree::search_sentence(vector<string> keys){
	vector<int> results;
	vector<vector<int>> docs_by_word;
	Node* rpta=0;
	int id_row_in_cloud = 0;
	for(int i=0;i<keys.size();i++){ //buscar cada palabra en el trie y guardar vector de resultados en un vector de vectores
		rpta = Find(root, keys[i]); //buscar palabra en el arbol
		if(rpta != 0){ //encontro la palabra
			
			id_row_in_cloud = rpta->GetCounter()-1;
			cout<<" is done...id in cloud: "<<id_row_in_cloud+1<<endl;
			docs_by_word.push_back(this->cloud->getRow(id_row_in_cloud).docs);
			// print_vector(this->cloud->getRow(id_row_in_cloud).docs);
		}
		else{
			cout<<" not results..."<<endl;
		}
	}
	if(docs_by_word.size()==0){
		cout<<"0 coincidencias..."<<endl;
	}
	if(docs_by_word.size()>0){
		int index_min_set=0;
		int minsize = docs_by_word[0].size();
		for(int i=1;i<docs_by_word.size();i++){ //buscar el vector con menos elementos
			if(docs_by_word[i].size()<minsize){
				minsize = docs_by_word[i].size();
				index_min_set = i;
			}
		}
		cout<<" minsize: "<<minsize<<" index: "<<index_min_set<<endl;
		//crear mapa <int,int> para almacenar interseccions/ la clave del mapa sera los ids del vector mas pequeño de la
		//busqueda anterior
		// map<int,int> map_intersec;
		// map<int, int>::iterator map_it;
		// int idDoc;
		// //recorrer set de tamaño minimo
		// for(int i=0;i<docs_by_word[index_min_set].size();i++){
		// 	map_intersec.insert ( pair<int,int>(docs_by_word[index_min_set][i],1) );
		// 	cout<<"mapa: "<<docs_by_word[index_min_set][i]<<": "<<map_intersec[docs_by_word[index_min_set][i]]<<endl;
		// }
		intersection(docs_by_word,index_min_set);
	}
	return results;
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
		// if(node->noTuples()>0)
		if(node->GetCounter()!=-1)
			return node;
		return 0;
	}
	return Find(node->Child(), key.substr(k, key.length()));
}

void Tree::Split(Node* node, int k, int freq,int idDoc) { // dividing node according to k key symbol
//crear un nuevo nodo con el sufijo no repetido
	Node* p = new Node(node->GetKey().substr(k, node->GetLength()), node->GetLength() - k, node->GetCounter());
	// p->setFlacLeaf(leaf);
	p->Child() = node->Child();

	// Word word; word.id=idDoc;
	// p->addDocument(idDoc);
	// if(node->GetCounter()>0){
	// if(k>node->GetKey().length()){
		p->setTuples(node->getTuples());
	// }
	if(node->noTuples()<0)
		p->addTuple(freq,idDoc);

	node->Child() = p;
	node->GetKey().erase(k, node->GetLength()); //recortar string en nodo padre
	node->SetLength(k);
	
	node->GetCounter() = 0;
	// node->cleanDocuments();

	node->cleanTuples();
}

bool Tree::indexDocument(WordList* words){
	map<string,int> map = words->wordList;
	cout<<"=========indexando doc N°: "<<words->docId<<endl;
	// for(int i=0;i<words->wordList.size();i++){
		int i=1;
	for (std::map<string,int>::iterator it=map.begin(); it!=map.end(); ++it){
		// cout<<"============palabra a insertar: "<<i<<" "<<it->first<<endl;
		i++;
		Node* p = Insert(root,it->first,1 ,it->second,words->docId);
		if (!root) {
			root = p;
		}
		// printTree();
	}
	return true;
}

bool Tree::Insert(string key, int number,int freq,int idDoc) {
	// cout<<"se inserto"<<endl;
	Node* p = Insert(root, key, number,freq,idDoc);

	if (!root) {
		root = p;
	}

	return true;
}


Node* Tree::Insert(Node* node, string key, int number, int freq,int idDoc) { // inserting key in tree
	if (!node) {
		Node* n = new Node(key, key.length(), number);
		n->addTuple(freq,idDoc);
		return n;
	}
	unsigned int k = Prefix(key, node->GetKey());
	if (k == 0) {
		node->Brother() = Insert(node->Brother(), key, number,freq,idDoc);
		return node;
	} if (k < node->GetLength()) { // cut or not to cut?
		Split(node, k,freq,idDoc);
		if (k < key.length()) {
			node->Child() = Insert(node->Child(), key.substr(k, key.length()), number,freq,idDoc);
		}
		else{
			
			node->GetCounter() += number;
			node->addTuple(freq,idDoc);
			// if(node->GetCounter() !=0 && idLastDoc >0 && idLastDoc!=idDoc){
			// if(node->GetCounter() !=0 && node->GetCounter()<=1){
			// 	// Word word; word.id=idDoc;
			// 	node->addDocument(idDoc);
			// // if(node->GetCounter()!=0 && node->noDocuments()>0){

			// }
				
		}
		return node;
	} if (k < key.length()) {
		node->Child() = Insert(node->Child(), key.substr(k, key.length()), number,freq,idDoc);
	}
	else {
		node->GetCounter() += number;
		node->addTuple(freq,idDoc);
		// if(node->GetCounter()!=0&& node->GetCounter()<2)
		// if(node->GetCounter()!=0 && node->GetCounter()<=1){
		// 	// Word word; word.id=idDoc;
		// 	node->addDocument(idDoc);
		// }
			
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
		cout<<node->GetKey()<<", "<<node->GetCounter()<<node->printTuples()<<endl;;
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
void Tree::TraversalSave(Node *node, ofstream &out) {
	if (!node) {
		out<< ";";
	}
	else {
		int id = cloud->insert(node->getTuples());
		// out << node->GetKey() << '/' << node->GetCounter();
		out << node->GetKey() << '/' << id;


		if (node->Child()) {
			out << ",";
		}
		TraversalSave(node->Child(), out);
		TraversalSave(node->Brother(), out);
	}
}


void Tree::Save(string directory) {
	ofstream file;

	file.open(directory);

	TraversalSave(root, file);

	file.close();
}

// 
void Tree::TraversalLoad(Node *&node, ifstream &file, istringstream &iss) {

	string content, data, key;
	int number;

	istringstream issdata;

	if (iss.rdbuf()->in_avail()) {

		getline(iss, data, ',');

		issdata.str(data);

		getline(issdata, key, '/');

		issdata >> number;

		issdata.clear();

		node = new Node(key, key.length(), number);

		TraversalLoad(node->Child(), file, iss);

		if (!file.eof()) {

			getline(file, content, ';');
			iss.str(content);

			TraversalLoad(node->Brother(), file, iss);
			iss.clear();
		}
	}
	iss.clear();
}

void Tree::Load(string directory) {

	ifstream file;
	istringstream iss;
	string content;

	Node *&node = root;
	file.open(directory);

	getline(file, content, ';');
	iss.str(content);

	TraversalLoad(node, file, iss);

	file.close();

}
void Tree::SaveCloud(string directory){
	ofstream file;

	file.open(directory);
	if(this->cloud != 0){
		Row row;
		int cloud_size = this->cloud->cloudSize();
		int i =2;
		for(int i=0;i<cloud_size;i++){
			row = this->cloud->getRow(i);
			file<<row.id<<'/'<<this->cloud->string_ids_of_row(i);
		}
	}
	// TraversalSave(root, file);

	file.close();
}
 
void Tree::LoadCloud(string directory){
	ifstream file;
	istringstream iss;
	string content;
	file.open(directory);
	string id; int id_row;
	int idDoc;
	string linea;
	while(getline(file, linea, '\n')){
		
		Row row;
		iss.str(linea);
		getline(iss, id, '/');
		id_row = stoi(id);
		row.id  = id_row;
		while(iss>>idDoc){
			row.docs.push_back(idDoc);
		}
		this->cloud->insert(row);
		iss.clear();
	}
	file.close();
	// cloud->printCloud();
}
void Tree::printCloud(){
	cloud->printCloud();
}