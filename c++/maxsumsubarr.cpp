#include<bits/stdc++.h>
using namespace std;

void printvector(vector<int> v){
    cout<<"{";
    for(auto i:v) cout<<i<<",";
    cout<<"}"<<endl;
}

//recursion
int maxsum(vector<int> &arr, int n){
    if(n==0) return arr.at(n);
    if(arr.at(n)>= maxsum(arr, n-1)+arr.at(n)){
        return arr.at(n);
    }
    return arr.at(n)+maxsum(arr,n-1);
}

// recursion with memorization
int maxsum(vector<int> &arr, int n, vector<int> &dp){
    if(dp.at(n)!=-1) return dp.at(n);
    if(arr.at(n)>=maxsum(arr,n-1, dp) + arr.at(n)){
        return dp.at(n) = arr.at(n);
    }
    return dp.at(n) = arr.at(n) + maxsum(arr,n-1,dp);

}


//tabulation
int maxsum2(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n,-1);
    dp.at(0) = arr.at(0);
    for(int i=1; i<n; i++){
        if(arr.at(i) >= dp.at(i-1) + arr.at(i)){
            dp.at(i) = arr.at(i);
            continue;
        }
        dp.at(i) = arr.at(i) + dp.at(i-1);
    }
    return dp.at(n-1);
}


// without tabulation
int maxsum3(vector<int> &arr){
    int n = arr.size();
    int prev = arr.at(0);
    int maxi = prev;
    for (int i=1; i<n; i++){
        prev+=arr.at(i);
        if(arr.at(i)>=prev){
            prev=arr.at(i);
        }
        maxi = max(maxi, prev);
    }
    return maxi;
}

int maxsum(vector<int> &arr){
    int n = arr.size();
    int subsum = arr.at(0);
    int maxi = subsum;
    for(int i=1; i<n; i++){
        subsum+=arr.at(i);
        if(arr.at(i) >= subsum){
            subsum = arr.at(i);
        }
        maxi = max( maxi, subsum);
    }
    return maxi;
}

int main(){
    vector<int> arr{1,2,7,-4,3,2,-10,10,1};
    int n = arr.size();
    vector<int> dp(n,-1);
    dp.at(0) = arr.at(0);
    cout<<maxsum(arr,n-1)<<endl;
    cout<<maxsum(arr,n-1,dp)<<endl;
    cout<<maxsum2(arr)<<endl;
    cout<<maxsum3(arr)<<endl;
    cout<<maxsum(arr)<<endl;
    printvector(arr);
    printvector(dp);
    return 0;
}

