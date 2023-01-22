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
        int n;
        cin>>n;
        string a;
        cin>>a;
        int c=0;
        for(auto i:a){
            if(c>=4){
                break;
            }
            switch(i){
                case 'a':
                    c=0;
                    break;
                case 'e':
                    c=0;
                    break;
                case 'i':
                    c=0;
                    break;
                case 'o':
                    c=0;
                    break;
                case 'u':
                    c=0;
                    break;
                default:
                    c+=1;
            }
        }
        if(c>=4) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
    }
	return 0;
}



