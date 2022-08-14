#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <unordered_map>
// #include <string>
using namespace std;

void fun(vector<int> &v){
    v[0]=4;
}
 
int main()
{
    // pair<int, string> var;
    // var.first = 1;
    // var.second = "saiiran";
    // cout << var.second;
    //string str;
    //getline(cin, str);
    //cout << str;
/*
    unordered_map<int,int> hp;
    hp[1]=2;
    hp[8]=3;
    hp[89]=4;
    if(hp.find(8)!=hp.end()){
        cout<<hp[8]<<endl;

    }else{
        cout<<"not found"<<endl;
    }
    return 0;
*/
    vector<int> v = {1,2,3};
    fun(v);
    for(auto i:v) cout<<i<<" ";
}
 
