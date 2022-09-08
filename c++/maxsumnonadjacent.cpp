#include<bits/stdc++.h>
using namespace std;

void printvector(vector<int> &v){
    cout<<"{";
    for(auto i:v) cout<<i<<",";
    cout<<"}"<<endl;
}

//recursion
int maxnonadjacentsum(vector<int> &v,int n){
    if(n<0) return 0;
    if(n==0) return v[n];
    return max(
        v[n] + maxnonadjacentsum(v,n-2),
        maxnonadjacentsum(v,n-1)
    );
}

//recursion with memorization

int maxi(int a, int b){
    if(a>b) return a;
    return b;
}
//recursion with memorization
int maxnonadjacentsum(vector<int> &v, int n , vector<int> &dp){
    printvector(dp);
    if(dp[n]!=-1) return dp[n];
    if(n<0) return 0;
    if(n==0) return v[n];
    return dp[n] = maxi(
        v[n] + maxnonadjacentsum(v,n-2,dp),
        maxnonadjacentsum(v,n-1,dp)
    );
}

// tabulation
int fun(vector<int> &v){

    int n = v.size();
    vector<int> dp(n,-1);
    dp.at(0)=v.at(0);

    for(int i=1; i<n;i++){

        int take = v.at(i);

        if(i>1) take+=dp.at(i-2);

        int not_take = dp.at(i-1);

        dp.at(i) = max(take, not_take);

    }

    return dp.at(n-1);
}

// without tabulation .. only using two variables

int fun2(vector<int> &v){

    int n = v.size();

    int prev2 = v.at(0);
    int prev = v.at(1);

    if(v.at(1) > prev2) prev = prev2;

    for(int i=2; i<n;i++){

        int take = v.at(i) + prev2;
        int not_take = prev;
        prev2 = prev;
        prev = max(take, not_take);
    }
    return prev;

}
int main(){
    vector<int> v{3,5,3,4,7};
    vector<int> dp(v.size(),-1);
    cout<<maxnonadjacentsum(v,v.size()-1)<<endl;
    //cout<<maxnonadjacentsum(v,v.size()-1,dp)<<endl;
    cout<<fun(v)<<endl;
    cout<<fun2(v)<<endl;

    return 0;
}
