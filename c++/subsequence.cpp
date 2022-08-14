#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    cout<<"[";
    for(auto i:v)cout<<i<<",";
    cout<<"]"<<endl;
}

void subsequence(vector<int> v, int i, int n,vector<int> out){
    if(i>=n){
        print(out);
        return;
    }
    out.push_back(v[i]);
    subsequence(v,i+1,n,out);
    out.erase(out.begin()+out.size()-1);
    subsequence(v, i+1, n, out);

}

int main(){
    vector<int> v = {3,2,1};
    vector<int> out;
    subsequence(v,0,v.size(),out);
    return 0;
}
