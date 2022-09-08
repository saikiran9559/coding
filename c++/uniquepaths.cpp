#include <bits/stdc++.h> 
using namespace std;
void printvector(vector<int> &v){
    cout<<"{";
    for(auto i:v)cout<<i<<",";
    cout<<"},"<<endl;
}
int fun(int m, int n){
    if(m==0 and n==0) return 1;
    if(m<0 or n<0) return 0;
    return fun(m-1, n) + fun(m, n-1);
}
int fun(int m, int n,vector<vector<int>> &dp){
    if(m==0 and n==0) return 1;
    if(m<0 or n<0) return 0;
    if(dp.at(m).at(n)!=-1) return dp.at(m).at(n);
    return dp.at(m).at(n) = fun(m-1, n) + fun(m, n-1);
}

/*
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
}

int fun(int m, int n, vector<vector<int>> &dp){
    if(m==0 or n==0) return 1;
    if(dp.at(m).at(n) != -1) return dp.at(m).at(n);
    dp.at(m).at(n) = fun(m-1, n, dp) + fun(m,n-1,dp);
    return dp.at(m).at(n);
}

int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>> dp(m,vector<int>(n,1));
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            dp.at(i).at(j) =dp.at(i-1).at(j) + dp.at(i).at(j-1);
        }
    }
    return dp.at(m-1).at(n-1);
    //return fun(m-1,n-1,dp);
}

*/
int uniquePaths(int m, int n){
    vector<int> prev(n,1);
    printvector(prev);
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++) prev.at(j) += prev.at(j-1);
    }
    return prev.at(n-1);
}
int main(){
    //vector<vector<int>> dp(3,vector<int> (2,-1));
    //cout<<fun(3-1,2-1, dp)<<endl;
    int m;
    int n;
    cin>>m>>n;
    cout<<uniquePaths(m,n)<<endl;
    return 0;
}
