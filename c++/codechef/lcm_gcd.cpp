#include <vector>
#include <iostream>
using namespace std;

int hcf(int n1, int n2){
    if(n1>n2){
        if(n1%n2==0) return n2;
        return hcf(n1%n2,n2);
    }
    if(n2%n1==0) return n2;
    return hcf(n2%n1,n1);
}

bool lcm_gcd(int n1, int n2 ){
    int  gcd, lcm;
    gcd = hcf(n2,n1);
    return n1*n2 == gcd*gcd;
}

void solve(vector<int> &v, int n){
    int ans=0;
    for(int i=0 ; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(lcm_gcd(v.at(i),v.at(j))) ans++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    int t; 
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0 ;i<n; i++) cin>>v.at(i);
        solve(v,n);
    }
	return 0;
}
