#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int me,md;
        cin>>me>>md;
        if(me==md){
            cout<<me<<" "<<me<<" "<<me<<" "<<endl;
            continue;
        }
        int su = 3*(me)-md;
        if(su>0)
            cout<<"0 "<<md<<" "<<su<<endl;
        else 
            cout<<su<<" "<<md<<" "<<"0 "<<endl;

    }
}
