#include<bits/stdc++.h>
using namespace std;
void printvector(vector<int> &v){
    cout<<"\t{";
    for(auto i:v)cout<<i<<",";
    cout<<"},"<<endl;
}

int minenergy(vector<int> &arr, int n){
    if(n==0) return 0;
    int onestep = minenergy(arr, n-1) + abs(arr.at(n) - arr.at(n-1));
    int twostep= INT_MAX;
    if(n>1)
        twostep = minenergy(arr, n-2) + abs(arr.at(n) - arr.at(n-2));
    return min(onestep, twostep);
}

int minenergy(vector<int> &arr, int n, vector<int> &dp){
    if(n==0) return 0;
    if(dp.at(n)!=-1) return dpa.at(n);
    int onestep = minenergy(arr, n-1,dp) + abs(arr.at(n) - arr.at(n-1));
    int twostep= INT_MAX;
    if(n>1)
        twostep = minenergy(arr, n-2,dp) + abs(arr.at(n) - arr.at(n-2));
    return dp.at(n) = min(onestep, twostep);
}

