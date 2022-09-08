#include<bits/stdc++.h>
using namespace std;


void printvector(vector<int> &v){
    cout<<"{";
    for(auto i:v) cout<<i<<",";
    cout<<"}"<<endl;
}

int main(){

    unordered_map<int, vector<int>> map;
    map[0].push_back(5);
    map[0].push_back(6);
   // printvector(map.at(0));
   printvector(map.at(0));
    return 0;
}
