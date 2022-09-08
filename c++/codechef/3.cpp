#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,k;
        cin>>n>>k;
        if(n<=k){
            cout<<"NO"<<endl;
            continue;
        }
        long long int sum = ((k)*(k+1))/2;
        if(sum<=n){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
