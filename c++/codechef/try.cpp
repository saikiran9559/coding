#include<bits/stdc++.h>
using namespace std;
void fun(int n, int k, vector<int> &v){
    int h=0;
    for(int i=0; i<n; i++){
        int val = pow(k,i);
        if(v.at(i)%val!=0){
            h=1;
            cout<<"NO"<<endl;
            break;
        }
    }
    if(h==0)
        cout<<"YES"<<endl;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v.at(i);
    fun(n,k,v);

}
