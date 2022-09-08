'''
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    long long int x,y;
	    cin>>x>>y;
	    if(x==y){
	        cout<<"ANY"<<endl;
	    }
	    if(x<y) cout<<"REPAIR"<<endl;
	    else cout<<"NEW PHONE"<<endl;
	}
	return 0;
}
'''
t = int(input())
while(t!=0):
    t-=1
    x,y = map(int, input().split())
    if x<y:
        print("REPAIR")
    elif x>y:
        print("NEW PHONE")
    else:
        print("ANY")
