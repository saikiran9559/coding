#include <iostream>
#include<vector>
#include<climits>
using namespace std;


void solve(vector<int> &v,int n){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(auto i:v){
        mini = min(mini, i);
        maxi = max(maxi, i);
    }
    cout<<mini*mini<<" "<<maxi*maxi<<endl;
}

int main() {
    int t; 
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v.at(i);
        solve(v,n);
    }
	return 0;
}
