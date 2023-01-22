#include<vector>
#include<climits>
#include <iostream>
using namespace std;


void solve(int n, int m, vector<long long int> &v){
    long long int sum=0;
    for(auto val: v){
        sum += max( abs(1-val) , abs(m-val) );
    }
    cout<<sum<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<long long int> v(n);
        for(int i=0; i<n; i++) cin>>v.at(i);
        solve(n,m,v);
    }
    return 0;
}
