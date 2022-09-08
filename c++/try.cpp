#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <unordered_map>
// #include <string>
using namespace std;

void printvector(vector<int> &v){
    cout<<"{";
    for(auto i:v) cout<<i<<",";
    cout<<"}"<<endl;
}
void fun(vector<int> &v){
    v[0]=4;
}
    int fun(int n,vector<int> &dp){
        if(n<0) return 0;
        if(n<=0) return 1;
        if(dp.at(n)!=-1) return dp.at(n);
        return dp.at(n) = fun(n-1, dp) + fun(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
 
int main()
{
    // pair<int, string> var;
    // var.first = 1;
    // var.second = "saiiran";
    // cout << var.second;
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
/*
    vector<int> v = {1,2,3};
    fun(v);
    for(auto i:v) cout<<i<<" ";
*/
    //cout<<climbStairs(2)<<endl;
    int a = 9;
    cout<<a/2;
}
 
