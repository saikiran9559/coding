#include<bits/stdc++.h>
using namespace std;
    int fun(int n,vector<int> &dp){
        if(n<0) return 0;
        if(n<=0) return 1;
        if(dp.at(n)!=-1) return dp.at(n);
        return dp.at(n) = fun(n-1, dp) + fun(n-2,dp);
    }
    int climbStairs2(int n) {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
    int climbStairs(int n){
        int prev = 1;
        int prev2 = 1;
        if(n==0) return 1;
        if(n==1) return 1;
        for(int i=2; i<=n; i++){
            int temp = prev2;
            prev2 = prev+prev2;
            prev = temp;
        }
        return prev2;
    }

int main(){
    cout<<climbStairs(2)<<endl;
    return 0;
}
