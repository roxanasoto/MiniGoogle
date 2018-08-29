#include <iostream>
#include "include/parser.h"
#include "include/Tree.h"

using namespace std;

void InsertWords(WordList *wl)
{
	cout<<"Doc Id: "<<wl->docId<<endl;
	cout<<"Words: ";
	for(int i = 0; i<wl->wordList.size(); ++i){
		cout << " " <<wl->wordList[i];
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
	for(int i = 1; i<3; ++i)
	{		
		wordlist->docId = i;	
		wordlist->wordList = parser->ParseFile("../Docs/"+to_string(i)+".txt");
		InsertWords(wordlist);
		trie.indexDocument(wordlist->wordList);
		trie.indexDocument(wordlist);
		wordlist->docId = 0;
		wordlist->wordList = {};
	}
	// trie.Insert("himno",1,1);
	// trie.printTree();

	// trie.Insert("hermandad",1,1);
	// trie.printTree();

	// trie.Insert("himno",1,1);
	// trie.printTree();

	// trie.Insert("himno",1,1);
	// trie.printTree();
	// trie.Insert("hermano",1,1);
	// trie.printTree();
	// trie.Insert("honesto",1,1);
	// trie.printTree();
	// trie.Insert("himno",1,1);
	trie.printTree();


	// trie.setIdLastDocument(1);
	trie.restarCounters();
	// trie.Insert("himno",1,2);
	// trie.printTree();
	// trie.Insert("himno",1,2);
	trie.printTree();
	

	return 0;
}