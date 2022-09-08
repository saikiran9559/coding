// min path in triagle 2d array
// top row to any cell in bottom row

#include<bits/stdc++.h>
using namespace std;

void printvector(vector<int> &v){
    cout<<"\t{";
    for(auto i:v)cout<<i<<",";
    cout<<"},"<<endl;
}
void print2D(vector<vector<int>> &v){
    cout<<"{"<<endl;
    for(auto i:v) printvector(i);
    cout<<"}"<<endl;
}

// recursion
int minpath(vector<vector<int>> &grid, int n, int m){
    if(m<0) return INT_MAX;
    if(m>n) return INT_MAX;
    if(n==0 and m==0) return grid.at(n).at(m);
    return grid.at(n).at(m) + min( minpath(grid, n-1, m-1), minpath(grid,n-1,m));
}

// recursion with dp
int minpath(vector<vector<int>> &grid, int n, int m, vector<vector<int>> &dp){
    if(m<0) return INT_MAX;
    if(m>n) return INT_MAX;
    if(dp.at(n).at(m) != INT_MAX) return dp.at(n).at(m);
    return dp.at(n).at(m) = grid.at(n).at(m) + min( minpath(grid, n-1, m-1, dp), minpath(grid,n-1, m, dp));
}

// tabulation
int minpath(vector<vector<int>> &grid){
    int n = grid.size();
    vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
    dp.at(0).at(0) = grid.at(0).at(0);
    for(int i=1; i<n; i++){
        dp.at(i).at(0) = grid.at(i).at(0) + dp.at(i-1).at(0);
        for(int j=1; j<i; j++){
            dp.at(i).at(j) = grid.at(i).at(j) + min( dp.at(i-1).at(j), dp.at(i-1).at(j-1));
        }
        dp.at(i).at(i) = grid.at(i).at(i) + dp.at(i-1).at(i-1);
    }
    int maxi = INT_MAX;
    for(int i=0; i<n; i++) maxi = min( maxi, dp.at(n-1).at(i));
    return maxi;
}

int minpath2(vector<vector<int>> &grid){
    int n = grid.size();
    vector<int> prev(1,grid.at(0).at(0));
    for(int i=1; i<n; i++){
        vector<int> temp;
        temp.push_back(grid.at(i).at(0) + prev.at(0));
        for(int j=1; j<i; j++){
            temp.push_back( grid.at(i).at(j) + min( prev.at(j), prev.at(j-1)));
        }
        temp.push_back( grid.at(i).at(i) + prev.at(i-1));
        prev = temp;
    }
    int maxi = INT_MAX;
    for(int i=0; i<n; i++) maxi = min( maxi, prev.at(i));
    return maxi;
}

int main(){
    vector<vector<int>> grid{
        {1},
        {2,3},
        {4,5,6},
        {7,8,9,10},
    };
    /*
    vector<vector<int>> grid{
        {5},
        {-1,3},
        {22,1,-9},
    };
    */
    int n = grid.size();
    int mini = INT_MAX;
    vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
    dp.at(0).at(0) = grid.at(0).at(0);
    print2D(grid);
    for(int i=0; i<n; i++){
        mini = min( mini, minpath(grid, n-1, i,dp));
    }
    cout<<mini<<endl;
    cout<<minpath(grid)<<endl;
    cout<<minpath2(grid)<<endl;
    return 0;
}
