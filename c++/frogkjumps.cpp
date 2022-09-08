#include<bits/stdc++.h>
using namespace std;

int minenergy(vector<int> &v, int index, int k){
    if(index==0) return 0;
    int mini=INT_MAX;
    for(int i=1; i<=k; i++){
        if(i<=index)
            mini = min(mini, minenergy(v, index-i, k) + abs(v.at(index) - v.at(index-i)));
        else
            break;
    }
    return mini;
}

int minenergy(vector<int> &v, int index, int k){
    if(index==0) return 0;
    int mini=INT_MAX;
    for(int i=1; i<=k; i++){
        if(i<=index)
            mini = min(mini, minenergy(v, index-i, k) + abs(v.at(index) - v.at(index-i)));
        else
            break;
    }
    return mini;
}

int main(){
    vector<int> v{30,10,60,10,60,50};
    cout<<minenergy(v,v.size()-1,5)<<endl;
}
