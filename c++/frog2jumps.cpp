#include<bits/stdc++.h>
using namespace std;
//recursion
int jump_counts(int n){
    if(n==0) return 1;
    else if(n<0) return 0;
    return jump_counts(n-1) + jump_counts(n-2);
}

//dp
int jump_counts(int n, vector<int> &dp){
    if(n==0) return 1;
    else if(n<0) return 0;
    else if(dp.at(n)!=-1) return dp.at(n);
    return dp.at(n) = jump_counts(n-1, dp) + jump_counts(n-2, dp);
}

//memorization

int jump_counts_mem(int n){
    vector<int> dp(n,-1);
    if(n>=1){
        dp.at(0)=1;
    }
    if(n>=2){
        dp.at(1) = 1;
    }
    // 0,1,1,2,3,5,8,13,21,
    for(int i=2; i<n; i++){
        dp.at(i) = dp.at(i-1) + dp.at(i-2);
    }
    return dp.at(n-1);
}



int main(){
    int n;
    cin>>n;
    cout<<jump_counts(n-1)<<endl;
    vector<int> dp(n,-1);
    cout<<jump_counts(n-1, dp)<<endl;
    cout<<jump_counts_mem(n)<<endl;
}