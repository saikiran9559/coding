#include<bits/stdc++.h>
using namespace std;
// min cost path in a grid 

//recursion
int mincostpath(vector<vector<int>> &grid, int n, int m){
    if(n<0 or m<0) return INT_MAX;
    if(n==0 and m==0) return grid.at(n).at(m);
    return grid.at(n).at(m) + min( mincostpath(grid, n-1, m), mincostpath(grid, n, m-1) );
}


//recursion with memorization
int mincostpath(vector<vector<int>> &grid, int n, int m, vector<vector<int>> &dp){
    if(n<0 or m<0) return INT_MAX;
    if(dp.at(n).at(m)!=-1) return dp.at(n).at(m);
    return dp.at(n).at(m) = grid.at(n).at(m) + min( mincostpath(grid, n-1, m, dp), mincostpath(grid, n, m-1, dp) );

}

//tabulation

int mincostpath(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid.at(0).size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    for(int i=0; i<n; i++ ){
        for(int j=0; j<m ; j++){
            dp.at(i).at(j) = grid.at(i).at(j);
            if(i==0 and j==0){
                continue;
            }
            if(i==0){
                dp.at(i).at(j) +=  dp.at(i).at(j-1);
                continue;
            }
            if(j==0){
                dp.at(i).at(j) += dp.at(i-1).at(j);
                continue;
            }
            dp.at(i).at(j) += min( dp.at(i).at(j-1), dp.at(i-1).at(j) );
        }
    }
    return dp.at(n-1).at(m-1);

}

//without tabulation
int mincostpath2(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid.at(0).size();

    vector<int> prev(m,0);
    prev.at(0) = grid.at(0).at(0);
    for(int i=1; i<m; i++){
        prev.at(i) = grid.at(0).at(i) + prev.at(i-1);
    }
    
    for(int i=1; i<n; i++ ){
        prev.at(0) += grid.at(i).at(0);
        for(int j=1; j<m ; j++){
            prev.at(j) = grid.at(i).at(j) + min( prev.at(j-1), prev.at(j));
        }
    }
    return prev.at(m-1);

}

int main(){
    vector<vector<int>> grid{
        {5,9,6},
        {11,5,2},
    };
    int n = grid.size();
    int m = grid.at(0).size();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    dp.at(0).at(0) = grid.at(0).at(0);
    cout<<mincostpath(grid,n-1, m-1)<<endl;
    cout<<mincostpath(grid,n-1,m-1,dp)<<endl;
    cout<<mincostpath(grid)<<endl;
    cout<<mincostpath2(grid)<<endl;

    return 0;
}

