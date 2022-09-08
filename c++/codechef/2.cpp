
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
        int n,k;
        cin>>n;
        vector<int> vec(n);
        for(int i=0; i<n; i++){
            cin>>vec.at(i);
        }
        cin>>k;
        vector<int> arr2(k);
        vector<int> map(n+1,1);
        for(int i=0; i<k; i++){
            cin>>arr2.at(i);
            map.at(arr2.at(i))=0;
        }
        for(auto i:vec){
            if(map.at(i)==1) cout<<i<<" ";
        }
        cout<<endl;
        
    }
	return 0;
}


