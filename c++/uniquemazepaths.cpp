#include<bits/stdc++.h>
using namespace std;

//recursion
int unique_maze_paths(int n, int m, vector<vector<int>> &grid){
    if(n==0 and m==0) return 1;
    if(m<0 || n<0 || grid.at(n).at(m)==-1) return 0;
    return unique_maze_paths(n-1,m,grid) + unique_maze_paths(n,m-1,grid);
}

//memorization
int unique_maze_paths(int n, int m , vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(n==0 and m==0) return 1;
    if(m<0 || n<0 || grid.at(n).at(m)==-1 ) return 0;
    if(dp.at(n).at(m) != -1) return dp.at(n).at(m);
    return dp.at(n).at(m) = unique_maze_paths(n-1,m,grid,dp) + unique_maze_paths(n,m-1,grid,dp);
}

//tabulation
int unique_maze_paths_tab(int n, int m, vector<vector<int>> &grid){
    vector<vector<int>> dp(n,vector<int>(m,-1));
    dp.at(0).at(0) = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 and j==0) continue;
            if(grid.at(i).at(j) == -1){
                dp.at(i).at(j) = 0;
                continue;
            }
            int c=0;
            if(j>0) c+=dp.at(i).at(j-1);
            if(i>0) c+=dp.at(i-1).at(j);
            dp.at(i).at(j) = c;
        }
    }
    return dp.at(n-1).at(m-1);
}

int unique_maze_paths_space(int n, int m, vector<vector<int>> &grid){
    vector<int> prev(m);
    prev.at(0) = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 and j==0) continue;
            if(grid.at(i).at(j) == -1){
                prev.at(j) = 0;
                continue;
            }
            int c=0;
            if(j>0) c+= prev.at(j-1);
            if(i>0) c+= prev.at(j);
            prev.at(j) = c;
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

        cout<<unique_maze_paths(n-1,m-1,grid)<<endl;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        cout<<unique_maze_paths(n-1,m-1,grid,dp)<<endl;
        cout<<unique_maze_paths_tab(n,m,grid)<<endl;
        cout<<unique_maze_paths_space(n,m,grid)<<endl;
    }

/*
2
3 3
0 0 -1
0 -1 0
0 0 0
4 4
0 0 0 0
0 0 -1 0
-1 0 -1 0
0 0 0 0


*/
}