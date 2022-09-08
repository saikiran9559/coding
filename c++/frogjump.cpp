#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

void printvector(vector<int> &v){
    cout<<"{";
    for(auto i:v) cout<<i<<",";
    cout<<"}"<<endl;
}

//recursion
int minenergy(int index, vector<int> &v){
    if(index ==0){
        return 0;
    }
    int left = minenergy(index-1,v)+abs(v.at(index) - v.at(index-1));
    
    if(index>1){
        int right = minenergy(index-2,v)+abs(v.at(index)-v.at(index-2));
        return min(left, right);
    }
    return left;
}

//memorization
int minenergy(int index, vector<int> &v,vector<int> &dp){
    if(dp.at(index)!=-1){
        return dp.at(index);
    }
    int left = minenergy(index-1,v,dp)+abs(v.at(index) - v.at(index-1));
    
    if(index>1){
        int right = minenergy(index-2,v,dp)+abs(v.at(index)-v.at(index-2));
        dp.at(index) = min(left,right);
        return min(left, right);
    }
    dp.at(index)=left;
    return left;
}


//tabulation
int minenergy(vector<int> &v){
    int n = v.size();
    vector<int> dp(n,0);
    for(int i=1; i<n; i++){
        int fs = dp.at(i-1)+ abs(v.at(i-1) - v.at(i));
        int ss = INT_MAX;
        if(i>1) ss = dp.at(i-2)+ abs(v.at(i)-v.at(i-2));
        dp.at(i)=min(fs,ss);
    }
    return dp.at(n-1);
}

// it is possible only for i-1 and i-2 kind of problems 
int minenergy2(vector<int> &v){
    int n = v.size();
    int prev = 0;
    int prev2 = 0;
    for(int i=1; i<n; i++){
        int fs = prev+ abs(v.at(i-1) - v.at(i));
        int ss = INT_MAX;
        if(i>1) ss = prev2 + abs(v.at(i)-v.at(i-2));
        int curi =min(fs,ss);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}


int main(){
    vector<int> v{30,10,60,10,60,50};
    vector<int> dp(v.size(),-1);
    dp.at(0)=0;
    cout<<minenergy(v.size()-1,v,dp)<<endl;
    cout<<minenergy(v.size()-1,v)<<endl;
    cout<<minenergy(v)<<endl;
    cout<<minenergy2(v)<<endl;
}
