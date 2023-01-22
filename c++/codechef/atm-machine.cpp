
#include<vector>
#include<climits>
#include<string>
#include <iostream>
using namespace std;

int solve(){
    
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int val;
        for(int i=0; i<n; i++){
            cin>>val;
            if(val<=k){
                k-=val;
                cout<<1;
            }else cout<<0;
        }
        cout<<endl;
    }
	return 0;
}



