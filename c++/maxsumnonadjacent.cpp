#include<bits/stdc++.h>
using namespace std;

//recursive
int max_adjacent_sum(int n, vector<int> &v){
    if(n<0) return 0;
    if(n==0) return v.at(n);
    return max(v.at(n) + max_adjacent_sum(n-2,v), max_adjacent_sum(n-1,v));
}

//memorization
int max_adjacent_sum(int n, vector<int> &v, vector<int> &dp){
    if(n<0) return 0;
    if(n==0) return v.at(n);
    if(dp.at(n)!=-1) return dp.at(n);
    return dp.at(n) = max(v.at(n) +max_adjacent_sum(n-2,v,dp), max_adjacent_sum(n-1, v, dp) ) ;
}

//tabulation
int max_adjacent_sum_tab(int n, vector<int> &v){
    vector<int> dp(n,-1);
    dp.at(0) = v.at(0);
    dp.at(1) = max(v.at(0), v.at(1));
    for(int i=2; i<n; i++){
        dp.at(i) = max(v.at(i)+dp.at(i-2), dp.at(i-1));
    }
    return dp.at(n-1);
}


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n; //4
    vector<int> v(n); // 2 1 4 9
    vector<int> dp(n, -1);
    for(int i=0; i<n; i++){
        cin>>v.at(i);
    }

    cout<<max_adjacent_sum(n-1,v)<<endl; //11
    cout<<max_adjacent_sum(n-1,v,dp)<<endl;
    cout<<max_adjacent_sum_tab(n,v)<<endl;
}