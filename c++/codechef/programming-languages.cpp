
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
        int a,b,a1,b1,a2,b2;
        cin>>a>>b>>a1>>b1>>a2>>b2;
        int c1=0,c2=0;
        if(a1==a or a1==b) c1+=1;
        if(b1==a or b1==b) c1+=1;
        if(a2==a or a2==b) c2+=1;
        if(b2==a or b2==b) c2+=1;
        if(c1==2) cout<<1<<endl;
        else if(c2==2) cout<<2<<endl;
        else cout<<0<<endl;

    }
	return 0;
}



