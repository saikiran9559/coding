#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int> v{6,2,5,5,4,5,6,3,7,7};
    while(t--){
        int a, b;
        cin>>a>>b;
        int sum = a+b;
        if(sum==0){
            cout<<v.at(0)<<endl;
            continue;
        }
        int count=0;
        while(sum!=0){
            int re = sum%10;
            sum/=10;
            count+=v.at(re);
        }
        cout<<count<<endl;
    }
    return 0;
}
