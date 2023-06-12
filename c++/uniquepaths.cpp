#include<bits/stdc++.h>
using namespace std;

//recursion
int unique_paths(int n, int m){
    if(n==0) return 1;
    if(m<0) return 0;
    return unique_paths(n-1, m)+ unique_paths(n,m-1);
}

//memorization
int unique_paths(int n, int m, vector<vector<int>> &dp){
    if(n==0) return 1;
    if(m<0) return 0;
    if(dp.at(n).at(m) != -1) return dp.at(n).at(m);
    return dp.at(n).at(m) = unique_paths(n-1,m,dp) + unique_paths(n,m-1,dp);
}

//tabulation
int unique_paths_tab(int n, int m){
    vector<vector<int>> dp(n,vector<int>(m,-1));
    dp.at(0) = vector<int>(m,1);
    for(int i=1; i<n; i++){
        dp.at(i).at(0) = dp.at(i-1).at(0);
        for(int j=1; j<m; j++){
            dp.at(i).at(j) = dp.at(i-1).at(j) +dp.at(i).at(j-1);
        }
    }
    return dp.at(n-1).at(m-1);
}

//space optimization
int unique_paths_space(int n, int m){
    vector<int> prev(m,1);
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++) prev.at(j) += prev.at(j-1);
    }
    return prev.at(m-1);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m; //5 6
    cin>>n>>m;
    cout<<unique_paths(n-1, m-1)<<endl; //126
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<unique_paths(n-1, m-1, dp)<<endl;
    cout<<unique_paths_tab(n,m)<<endl;
    cout<<unique_paths_space(n,m)<<endl;
}