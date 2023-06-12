#include<bits/stdc++.h>
using namespace std;

int abs(int a, int b){
    if(a<b)return b-a;
    return a-b;
}

//recursive
int min_energy(int n, vector<int> &v, int k){
    if(n==0) 
        return 0;
    int mini = INT_MAX;
    for(int i=1; i<=(n<k?n:k); i++){
        mini = min(mini, min_energy(n-i, v, k) + abs(v.at(n), v.at(n-i)));
    }
    return mini;
}

//memorization
int min_energy(int n, vector<int> &v, int k, vector<int> &dp){
    if(n==0) return 0;
    if(dp.at(n) != -1) return dp.at(n);
    int mini = INT_MAX;
    for(int i=1; i<=(n<k?n:k); i++){
        mini = min(mini, min_energy(n-i, v, k, dp) + abs(v.at(n), v.at(n-i)));
    }
    return dp.at(n) =  mini;
}


//tabulation
int min_energy_tab(int n, vector<int> &v, int k){
    vector<int> dp(n, -1);
    dp.at(0) = 0;
    for(int i=1; i<n; i++){
        int mini = INT_MAX;
        for(int j=1; j<=(i<k?i:k); j++){
            mini  = min(mini, dp.at(i-j) + abs(v.at(i), v.at(i-j)));
        }
        dp.at(i) = mini;
    }
    return dp.at(n-1);
}



int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 
    int n, k;  // 10 4
    cin>>n;
    cin>>k;
    vector<int> v(n); // 40 10 20 70 80 10 20 70 80 60
    vector<int> dp(n, -1);
    for(int i=0; i<n; i++){
        cin>>v.at(i);
    }
    cout<<min_energy(n-1,v, k)<<endl;
    cout<<min_energy(n-1, v,k, dp)<<endl;
    cout<<min_energy_tab(n,v, k)<<endl;
}