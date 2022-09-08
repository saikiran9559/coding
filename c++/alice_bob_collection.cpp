#include<bits/stdc++.h>
using namespace std;

//recursion
int maxcollection(vector<vector<int>> &grid, int i, int j, int k, int m, vector<vector<int>> pair){
    if(i==0 and j==0 and k==m){
        return grid.at(i).at(j) + grid.at(i).at(k);
    }
    if( j<0 or k>m or j==k or (i==0 and ( j!=0 or k!=m)) ) return INT_MIN;
    int maxi = INT_MIN;
    int alice_at = grid.at(i).at(j);
    int bob_at = grid.at(i).at(k);
    for(int a=0; a<9; a++){
        int next = alice_at + bob_at +  maxcollection( grid, i-1, j + pair.at(a).at(0), k + pair.at(a).at(1), m, pair );
        maxi = max( maxi, next );
    }
    return maxi;
}

//recursion with dp
int maxcollection(vector<vector<int>> &grid, int i, int j, int k, int m, vector<vector<int>> pair, vector<vector<vector<int>>> &dp){
    if( j<0 or k>m or j==k or (i==0 and ( j!=0 or k!=m)) ) return INT_MIN;
    if(dp.at(i).at(j).at(k) != -1) return dp.at(i).at(j).at(k);
    int maxi = INT_MIN;
    int alice_at = grid.at(i).at(j);
    int bob_at = grid.at(i).at(k);
    for(int a=0; a<9; a++){
        int next = alice_at + bob_at +  maxcollection( grid, i-1, j + pair.at(a).at(0), k + pair.at(a).at(1), m, pair ,dp );
        maxi = max( maxi, next );
    }
    return dp.at(i).at(j).at(k) = maxi;
}

int main(){
    
    vector<vector<int>> pair{
        {-1,-1},
        {-1,0},
        {-1,1},
        {0,-1},
        {0,0},
        {0,1},
        {1,-1},
        {1,0},
        {1,-1},
    };

    vector<vector<int>> grid{
        {2,3,1,2},
        {3,4,2,2},
        {5,6,3,5},
    };

    int n = grid.size();
    int m = grid.at(0).size();
    vector<vector<vector<int>>> dp(
            n,vector<vector<int>>(m,vector<int>(m,-1))
    );
    
    dp.at(0).at(0).at(m-1) = grid.at(0).at(0) + grid.at(0).at(m-1);

    int maxi = INT_MIN;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<m; j++){
            maxi = max( maxi, maxcollection(grid,n-1, i, j, m-1, pair, dp ) );
        }
    }
    cout<<maxi<<endl;
    return 0;
}

