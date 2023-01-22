#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v.at(i);
        reverse(v.begin(), v.end());
        int k=v.at(0);
        int s=0;
        for(int i=1; i<n; i++){
            if(v.at(i)==k){
                s=0;
            }
        }

    }
    return 0;
}
