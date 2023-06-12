#include <bits/stdc++.h>
using namespace std;

//recursion
bool subsetSumToK1(int n, int k, vector<int> &arr){
    if(k==0) return true;
    if(n==0) return arr.at(n) == k;
    if(arr.at(n)>k) return subsetSumToK1(n-1,k,arr);
    return subsetSumToK1(n-1,k-arr.at(n), arr) or subsetSumToK1(n-1, k,arr);
}

//memorization
int fun(int n, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(k==0) return 1;
    if(n==0) return arr.at(n) == k;
    if(dp.at(n).at(k) != -1) return dp.at(n).at(k);
    if(arr.at(n)>k) return dp.at(n).at(k) = fun(n-1,k,arr,dp);
    return dp.at(n).at(k) = fun(n-1, k-arr.at(n), arr, dp) || fun(n-1, k, arr, dp);
}

//tabulation

int fun(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(n,vector<int>(k+1), -1);
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
        }
    }
}



int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, t;
        cin >> n>>t;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr.at(i);
        cout<<subsetSumToK1(n-1,t,arr)<<endl;
        vector<vector<int>> dp(n,vector<int>(t+1, -1));
        cout<<fun(n-1, t, arr, dp)<<endl;
    }
}