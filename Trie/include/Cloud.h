#include<iostream>
#include "types.h"
#include <tuple> 
#include <set> 
#include <algorithm>
using namespace std;

class Cloud{
    int id_generate;
    vector<Row> rows;
public:
    Cloud();
    ~Cloud();
    int insert(set<tuple<int, int>, greater<tuple<int,int>>> nodo_tuplas);
};