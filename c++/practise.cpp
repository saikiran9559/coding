#include<bits/stdc++.h>
using namespace std;

// recursion
int min_energy(vector<int> &values, int n){
    if(n==0) return 0;
    int two = INT_MAX;
    if(n>1) two = min_energy(values, n-2) + abs(values.at(n) - values.at(n-2));
    return min(min_energy(values,n-1) + abs(values.at(n) - values.at(n-1)), two );
}

//memorization
int min_energy(vector<int> &values, int n , vector<int> &dp){
    if(n==0) return 0;
    else if(dp.at(n)!=-1)  return dp.at(n);
    int two = INT_MAX;
    if(n>1) two = min_energy(values, n-2, dp) + abs(values.at(n) - values.at(n-2));
    return dp.at(n) =  min(min_energy(values,n-1, dp) + abs(values.at(n) - values.at(n-1)), two );
}


//tabulation
int min_energy_table(vector<int> &values, int n){ //n actual length
    vector<int> dp(n,-1);
    dp.at(0)=0;
    dp.at(1)= abs(values.at(0) - values.at(1));
    for(int i=2; i<n; i++) dp.at(i) = min(dp.at(i-1)+ abs(values.at(i) - values.at(i-1)), dp.at(i-2) + abs(values.at(i) - values.at(i-2)));
    return dp.at(n-1);
}

// int min_energy_variable(vector<int> &values, int n){
//     int one = 0;
//     int two = abs(values.at(0) - values.at(1));
//     for(int i=2; i<n; i++){
//         int temp = min(one + abs(values.at(i) - values.at(i-1)), two + abs(values.at(i) - values.at(i-2)));
//         one = two;
//         two = temp;
//     }
//     return one;
// }






int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v.at(i);
    }
    cout<<min_energy(v,n-1)<<endl;
    vector<int> dp(n,-1);
    cout<<min_energy(v,n-1, dp)<<endl;
    cout<<min_energy_table(v,n)<<endl;
    cout<<min_energy_variable(v,n)<<endl;
}