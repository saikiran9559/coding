#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v.at(i);
    cout<<n/2<<endl;
    for(int i=0; i<n/2; i++){
        int temp = v.at(i);
        v.at(i)=v.at(n-i-1);
        v.at(n-i-1) = temp;
    }
    for(auto i:v) cout<<i<<",";
    return 0;
}