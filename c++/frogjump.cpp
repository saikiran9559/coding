#include<bits/stdc++.h>
using namespace std;

int abs(int a, int b){
    if(a<b)return b-a;
    return a-b;
}

//recursive
int min_energy(int n, vector<int> &v){
    if(n==0) 
        return 0;
    int left = min_energy(n-1,v) + abs(v.at(n), v.at(n-1));
    if(n>1)
        return min(left, min_energy(n-2,v) + abs(v.at(n), v.at(n-2)));
    return left;
}

//memorization
int min_energy(int n, vector<int> &v, vector<int> &dp){
    if(n==0) return 0;
    if(dp.at(n) != -1) return dp.at(n);
    int left = min_energy(n-1,v, dp) + abs(v.at(n), v.at(n-1));
    if(n>1)
        return dp.at(n) =  min(left, min_energy(n-2,v,dp) + abs(v.at(n), v.at(n-2)));
    return dp.at(n) = left;
}

//tabulation
int min_energy_tab(int n, vector<int> &v){
    vector<int> dp(n, -1);
    dp.at(0) = 0;
    dp.at(1) = abs(v.at(1), v.at(0));
    for(int i=2; i<n; i++)
        dp.at(i) = min( 
            dp.at(i-1)+abs(v.at(i), v.at(i-1)), 
            dp.at(i-2) + abs(v.at(i), v.at(i-2)) 
        );
    
    return dp.at(n-1);
}

//space optimization

int min_energy_space(int n, vector<int> &v){
    int prev2 = 0;
    int prev = abs(v.at(1), v.at(0));
    for(int i=2; i<n; i++){
        int cur = min(prev+abs(v.at(i), v.at(i-1)), prev2+abs(v.at(i), v.at(i-2)));
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> dp(n, -1);
    for(int i=0; i<n; i++){
        cin>>v.at(i);
    }
    cout<<min_energy(n-1,v)<<endl;
    cout<<min_energy(n-1, v, dp)<<endl;
    cout<<min_energy_tab(n, v)<<endl;
    cout<<min_energy_space(n,v)<<endl;

}