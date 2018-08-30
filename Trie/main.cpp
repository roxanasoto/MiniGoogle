#include <iostream>
#include "include/parser.h"
#include "include/Tree.h"

using namespace std;

void printWordList(WordList *wl)
{
	cout<<"Doc Id: "<<wl->docId<<endl;
	cout<<"Words: ";
	map<string,int>::iterator it;
	for (it=wl->wordList.begin(); it!=wl->wordList.end(); ++it){
    	cout << it->first << " => " << it->second << '\n';
	}
	cout<<endl;
}

int main()
{
	Tree trie = Tree();
	Parser *parser = new Parser();
	WordList *wordlist = new WordList();
	parser->LoadStopWords("../stopWords.txt");	
	int i=1;
	bool newDoc = true;
	for(int i = 1; i<2; ++i)
	{		
		wordlist->docId = i;	
		wordlist->wordList = parser->ParseFile("../Docs/"+to_string(i)+".txt");
		printWordList(wordlist);
		
		// trie.indexDocument(wordlist->wordList);
		trie.indexDocument(wordlist);
		// trie.printTree();
		wordlist->docId = 0;
		wordlist->wordList.clear();
	}
	trie.printTree();
	cout<<"----test busqueda(1 palabra)---------"<<endl;
	trie.search("venezuela");
	trie.search("ve");

	

// 	wordlist->docId = i;	
// 	wordlist->wordList = parser->ParseFile("../Docs/d1.txt");
// 	printWordList(wordlist);
// 	trie.indexDocument(wordlist);
	
// cout<<"---------------------------------"<<endl;
// 	wordlist->docId = 0;
// 	wordlist->wordList = {};
// 	wordlist->wordList = parser->ParseFile("../Docs/d2.txt");
// 	printWordList(wordlist);
// 	trie.indexDocument(wordlist);
	

	// trie.Insert("hermandad",1,3,1);
	// trie.printTree();

	// // trie.Insert("himno",1,2,1);
	// // trie.printTree();

	// trie.Insert("himno",1,9,2);
	// trie.printTree();
	// trie.Insert("hermano",1,7,3);
	// trie.printTree();
	// trie.Insert("h",1,6,3);
	// trie.printTree();
	// trie.Insert("himno",1,1,4);
	// trie.printTree();
	// trie.Insert("honesto",1,1);
	// trie.printTree();
	// trie.Insert("himno",1,1);
	// trie.printTree();


	// trie.setIdLastDocument(1);
	// trie.restarCounters();
	// trie.Insert("himno",1,2);
	// trie.printTree();
	// trie.Insert("himno",1,2);
	// trie.printTree();
	

	return 0;
}