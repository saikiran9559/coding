#include<bits/stdc++.h>
using namespace std;

//recursion
int min_path(int n, int m, vector<vector<int>> &grid){
    if(n==0 and m==0) return grid.at(n).at(m);
    if(n<0 or m<0) return INT_MAX;
    return grid.at(n).at(m) + min(min_path(n-1,m,grid), min_path(n,m-1,grid));
}

//memorization
int min_path(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(n==0 and m==0) return grid.at(n).at(m);
    if(n<0 or m<0) return INT_MAX;
    if(dp.at(n).at(m) != -1) return dp.at(n).at(m);
    return dp.at(n).at(m) =  grid.at(n).at(m) + min(min_path(n-1,m,grid,dp), min_path(n,m-1,grid,dp));
}

//tabulation
int min_path_tab(int n, int m, vector<vector<int>> &grid){
    vector<vector<int>> dp(n,vector<int>(m,-1));
    dp.at(0).at(0) = grid.at(0).at(0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 and j==0) continue;
            int up = INT_MAX;
            int left = INT_MAX;
            if(j>0) left = dp.at(i).at(j-1);
            if(i>0) up = dp.at(i-1).at(j);
            dp.at(i).at(j) = grid.at(i).at(j) + min(up,left);
        }
    }
    return dp.at(n-1).at(m-1);
}

//space optimization
int min_path_space(int n, int m, vector<vector<int>> &grid){
    vector<int> prev(m);
    prev.at(0) = grid.at(0).at(0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 and j==0) continue;
            int up = INT_MAX;
            int left = INT_MAX;
            if(j>0) left = prev.at(j-1);
            if(i>0) up = prev.at(j);
            prev.at(j) = grid.at(i).at(j) + min(up,left);
        }
    }
    return prev.at(m-1);

}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){

        int n, m;
        cin>>n>>m;
        vector<vector<int>> grid(n);
        for(int i=0; i<n; i++){
            vector<int> row(m);
            for(int j=0; j<m; j++){
                cin>>row.at(j);
            }
            grid.at(i) = row;
        }

        cout<<min_path(n-1,m-1,grid)<<endl;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        cout<<min_path(n-1,m-1,grid,dp)<<endl;
        cout<<min_path_tab(n,m,grid)<<endl;
        cout<<min_path_space(n,m,grid)<<endl;

    }
}
/*
2
2 2
5 6
1 2
3 3
1 2 3
4 5 4
7 5 9

*/