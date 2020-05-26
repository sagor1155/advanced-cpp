
/*
TOPIC: Map In C++
-----------------
NOTES:
0. Syntax: map<T1, T2> obj; // where T1 is key type and T2 is value type 
1. std::map is associative container that store elements in key value combination
   where key should be unique, otherwise it overrides the previous value.
2. It is implement using Self-Balance Binary Search Tree (AVL/Red Black Tree) .
3. It store key value pair in sorted order on the basis of key (assending/decending).
4. std::map is generally used in Dictionay type problems.
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    std::map<string, int, std::greater<>> myMap;
    myMap["akey"] = 10;
    myMap["bkey"] = 20;
    myMap["ckey"] = 30;
    myMap.insert(std::make_pair("dkey", 40));

    for(auto &element:myMap){
        //cout << element.first << ": " << element.second << endl;
    }

    std::map<string, vector<int>> myMap2;
    myMap2["akey"].push_back(10);
    myMap2["bkey"].push_back(20);
    myMap2["bkey"].push_back(21);
    myMap2["bkey"].push_back(22);

    for(auto &element:myMap2){
        for(auto &element2:element.second){
            cout << element.first << ": " << element2 << endl;
        }
    }

}