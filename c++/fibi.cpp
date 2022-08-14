#include <bits/stdc++.h> 
using namespace std;

int fibi(int n, vector<int> &v){
    if(v.at(n)!=-1){
        return v[n];
    }
    v.at(n)=fibi(n-1,v)+fibi(n-2,v);
    return v.at(n);
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n+1,-1);
    v.at(0)=0;
    v.at(1)=1;
    cout<<fibi(n,v);
    return 0;
}
