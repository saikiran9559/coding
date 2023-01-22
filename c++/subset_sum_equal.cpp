#include <bits/stdc++.h>
using namespace std;

void printvector(vector<int> v){
    cout<<"{";
    for(auto i:v) cout<<i<<",";
    cout<<"}"<<endl;
}

bool fun(vector<int> &v, int n, int k){
    if(k== 0) return true;
    if(n==0) return k==v.at(0);
    bool val =  fun(v,n-1,k);
    if(k>= v.at(n))
        return val or fun(v,n-1, k-v.at(n));
    return val;
}



//applying dp

int fun(vector<int> &v, int n, int k, vector<vector<int>> &dp){
    if(dp.at(n).at(k) != -1) return dp.at(n).at(k);
    if(k==0) return dp.at(n).at(k) = true;
    if(n==0) return dp.at(n).at(k) = k==v.at(n);
    bool val = fun(v, n-1, k, dp);
    if(k>=v.at(n))
        return dp.at(n).at(k) = val or fun(v,n-1,k-v.at(n), dp);
    return dp.at(n).at(k) = val;
}


int fun2(vector<int> &v, int n, int k){
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    for(int i=0; i<n; i++){
        dp.at(i).at(0)= 1;
        for(int j=1; j<=k; j++){
            if(i==0)
                dp.at(i).at(j) = j==v.at(i);
            else if(j>=v.at(i))
                dp.at(i).at(j) = dp.at(i-1).at(j) or dp.at(i-1).at(j-v.at(i));
            else
                dp.at(i).at(j) = dp.at(i-1).at(j);
        }
    }
    return dp.at(n-1).at(k);
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v.at(i);
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        cout<<fun(v,n-1,k)<<endl;
        cout<<fun(v,n-1,k,dp)<<endl;;
        cout<<fun2(v,n,k)<<endl;
    }
}
