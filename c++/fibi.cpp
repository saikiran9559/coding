#include<bits/stdc++.h>
using namespace std;

//recursive
int fibi(int n){
    if(n<=1) return n;
    return fibi(n-1) + fibi(n-2);
}

//memorization
int fibi(int n, vector<int> &dp){
    if(n<=1) return n;
    if(dp.at(n)!=-1) return dp.at(n);
    return dp.at(n) = fibi(n-1, dp) + fibi(n-2, dp);
}

//tabulation
int fibiTabulation(int n){
    vector<int> dp(n+1,-1);
    dp.at(0) = 0;
    dp.at(1) = 1;
    for(int i=2; i<=n; i++){
        dp.at(i) = dp.at(i-1) + dp.at(i-2);
    }
    return dp.at(n);
}

//space complexity
int fibiSpaceComplexity(int n){
    int prev2 = 0;
    int prev = 1;
    for(int i=2; i<=n; i++){
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int main(){
    //0,1,1,2,3,5,8,13
    //0,1,2,3,4,5,6, 7
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fibi(n)<<endl;
    cout<<fibi(n,dp)<<endl;
    cout<<fibiTabulation(n)<<endl;
    cout<<fibiSpaceComplexity(n)<<endl;
    return 0;
}