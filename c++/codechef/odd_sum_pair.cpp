
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
        long long int a,b,c;
        cin>>a>>b>>c;
        if( (a+b)%2==1 or (a+c)%2==1 or (b+c)%2==1 ){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
	return 0;
}



