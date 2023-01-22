
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
        long long int T,n,sum;
        cin>>T>>n>>sum;
        long long int q = sum/n;
        long long int r = sum%n;
        if(T<q) q=T;
        cout<<q*(n*n)+(r*r)<<endl;
    }
	return 0;
}



