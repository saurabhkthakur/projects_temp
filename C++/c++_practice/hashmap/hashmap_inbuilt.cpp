#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

vector <int> removeduplicates(int* arr, int size){
    
    vector<int> output;
    unordered_map<int,bool> seen;

    for(int i=0; i< size; i++){
        if(seen.count(arr[i])>0){
            continue;
        }

        seen[arr[i]] = true;
        output.push_back(arr[i]);

    }

    return output;
}


int main(){

    // int arr[] = {1,2,3,1,1,4,5,5,6,9,7,9};

    // vector<int> output = removeduplicates(arr, 12);

    // for(int i=0;i<output.size();i++){
    //     cout << output[i] << endl;
    // }


    unordered_map<string, int> ourmap;
    ourmap["abc"] =1;
    ourmap["abc1"]=2;
    ourmap["abc2"]=3;
    ourmap["abc3"]=4;
    ourmap["abc4"]=5;
    ourmap["abc5"]=6;

    unordered_map<string, int> :: iterator it = ourmap.begin();

    while(it!= ourmap.end()){
        cout << "Key :" << it->first << "Value :" << it->second << endl;
        it++;
    }

    // find gives iterator in unordered map
    unordered_map<string, int> :: iterator it2 = ourmap.find("abc");
    ourmap.erase(it2, it2+4);


    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    vector<int> :: iterator it1 = v.begin();

    while(it1!=v.end()){
        cout << *it1 << endl;
        it1++;
    } 





   
   
   /* unordered_map<string, int> ourmap;

    //insert;
    pair<string, int> p("abc", 2);
    // p.first = "abc";
    // p.second = 2;
    ourmap.insert(p);
    ourmap["dbz"] = 3;


    //find or access
    cout << ourmap["dbz"] << endl;
    cout << ourmap.at("abc") << endl;
    // if key is not present and we try to access key using (at method) that are not present in map it will give error.
    // if key is not present and we try to access key using (normal method) then a value 0 is assigned to corresponding key.


    cout << "Size :" << ourmap.size() << endl;
    cout << ourmap["ghi"] << endl;
    cout << "Size :" << ourmap.size() << endl;

    //check presence
    // either give 0 or 1
    if(ourmap.count("ghi")>0){
        cout << "ghi is present" << endl;
    }

    //erase 
    ourmap.erase("ghi");

    if(ourmap.count("ghi")>0){
        cout << "ghi is present" << endl;
    }
    */
}