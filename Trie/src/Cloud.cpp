#include "../include/Cloud.h"

Cloud::Cloud():id_generate(0){}

Cloud::~Cloud(){}

int Cloud::insert(set<tuple<int, int>, greater<tuple<int,int>>> nodo_tuplas){
    if(nodo_tuplas.size()>0){
        tuple<int, int> element;
        id_generate++;
        for (set<tuple<int, int>>::iterator i = nodo_tuplas.begin(); i != nodo_tuplas.end(); i++) 
        {
            element = *i;
            Row row;
            row.id = id_generate;
            row.docs.push_back(get<1>(element));
            rows.push_back(row);
        
            // cout<< get<0>(element) <<" - " << get<1>(element)<<endl;
        }
        return id_generate;
    }
    return -1;
}