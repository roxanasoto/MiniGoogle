#include <iostream>
#include <vector>
#include <tuple> 
#include <set> 
#include <algorithm>

using namespace std;

//Tupla frecuencia - idDoc
set<tuple<int, int>, greater<tuple<int,int>> > v1;
set<tuple<int, int>, greater<tuple<int,int>> > v2;
set<tuple<int, int>, greater<tuple<int,int>> > v3;
set<tuple<int, int>, greater<tuple<int,int>> > vr;

void InsertRandomData()
{
    int frecuencia = 0;
    int id = 0;
    for(int i = 0; i < 10; ++i){
        frecuencia =  rand() % (7 - 2+1);
        id = rand() % (10 + 1);

        v1.insert(make_tuple(frecuencia, id));

        frecuencia =  rand() % (8 - 2+1);
        id = rand() % (10 + 1);

        v2.insert(make_tuple(frecuencia, id));

        frecuencia =  rand() % (9 - 2+1);
        id = rand() % (10 + 1);

        v3.insert(make_tuple(frecuencia, id));
    }
}

void PrintData()
{
    tuple<int, int> element;
    for (set<tuple<int, int>>::iterator i = v1.begin(); i != v1.end(); i++) 
    {
        element = *i;
        cout<< get<0>(element) <<" - " << get<1>(element)<<endl;
    }
    cout<< "--------" <<endl;
    for (set<tuple<int, int>>::iterator j = v2.begin(); j != v2.end(); j++) 
    {
        element = *j;
        cout<< get<0>(element) <<" - " << get<1>(element)<<endl;
    }
    cout<< "--------" <<endl;
    for (set<tuple<int, int>>::iterator k = v3.begin(); k != v3.end(); k++) 
    {
        element = *k;
        cout<< get<0>(element) <<" - " << get<1>(element)<<endl;
    }
}

void LookForIntersection(tuple<int,int> t)
{       
    int count = 0;
    cout << "---" << endl;
    set<tuple<int, int>>::iterator it = find_if(v2.begin(), v2.end(), [&t](const auto& item) 
    {
        return get<1>(t) == get<1>(item);
    });

    if(it!=v2.end())
      cout << "found" << endl;
}

int main()
{
    InsertRandomData();
    PrintData();
    tuple<int, int> element;
    for (set<tuple<int, int>>::iterator i = v1.begin(); i != v1.end(); i++) 
    {
        element = *i;
        LookForIntersection(element);
    }    
    
}