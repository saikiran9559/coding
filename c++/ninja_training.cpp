#include<bits/stdc++.h>
using namespace std;

void printvector(vector<int> &v){
    cout<<"\t{";
    for(auto i:v)cout<<i<<",";
    cout<<"},"<<endl;
}
void print2D(vector<vector<int>> &v){
    
    cout<<"{";
    for(auto i:v) printvector(i);
    cout<<"}"<<endl;

}

//recursion
int max_points(int n,int i, vector<vector<int>> &v){
    if(n==0) return v.at(n).at(i);
    return v.at(n).at(i)+ max( max_points(n-1,(i+1)%3,v), max_points(n-1,(i+2)%3, v));
}

//memorization
int max_points(int n, int i, vector<vector<int>> &v, vector<vector<int>> &dp){
    if(n==0) return v.at(n).at(i);
    if(dp.at(n).at(i) != -1) return dp.at(n).at(i);
    return dp.at(n).at(i) = v.at(n).at(i)+ max( max_points(n-1,(i+1)%3,v, dp), max_points(n-1,(i+2)%3, v, dp));
}

//tabulation
int max_points_tab(int n, vector<vector<int>> &v){
    
    vector<vector<int>> dp(n, {-1,-1,-1});
    int maxi = INT_MIN;
    dp.at(0) = v.at(0);
    
    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            dp.at(i).at(j) = v.at(i).at(j) + 
            max( 
                dp.at(i-1).at((j+1)%3), 
                dp.at(i-1).at((j+2)%3)
            );
        }
    }
    maxi = INT_MIN;
    for(int i=0; i<3; i++){
        maxi = max(dp.at(n-1).at(i), maxi);
    }
    return maxi;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    int n; 
    cin>>n;
    vector<vector<int>> v(n);

/*
3
10 40 70
20 50 80
30 60 90
*/
    for(int i=0; i<n; i++) {
        vector<int> p(3);
        for(int j=0; j<3; j++){
            cin>>p.at(j);
        }
        v.at(i) = p;
    }

    int maxi = INT_MIN;
    for(int i=0; i<3; i++){
        maxi = max(max_points(n-1, i, v), maxi);
    }
    cout<<maxi<<endl; //210

    vector<vector<int>> dp(n,{-1,-1,-1});
    maxi = INT_MIN;
    for(int i=0; i<3; i++){
        maxi = max(max_points(n-1, i, v, dp), maxi);
    }
    cout<<maxi<<endl;
    cout<<max_points_tab(n,v)<<endl;
    return 0;
}