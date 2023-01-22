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
        string str;
        cin>>n;
        cin>>str;
        int count=0;
        for(int i=0; i<n-1; i++){
            if(str[i]==str[i+1]){
                count++;
            }
        }
        cout<<count<<endl;
    }
	return 0;
}



