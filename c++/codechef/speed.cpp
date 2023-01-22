
#include <iostream>
using namespace std;

int main() {
    int t; 
    cin>>t;
    while(t--){
        double a,x,b,y;
        cin>>a>>x>>b>>y;
        double alice = a/x;
        double bob = b/y;
        if(alice>bob) cout<<"Alice"<<endl;
        else if(bob>alice) cout<<"Bob"<<endl;
        else cout<<"Equal"<<endl;
    }
	return 0;
}
