#include<bits/stdc++.h>
using namespace std;


void printvector(vector<int> &v){
    cout<<"\t\t{";
    for(auto i:v)cout<<i<<",";
    cout<<"},"<<endl;
}
void print2D(vector<vector<int>> &v){
    
    cout<<"\t{"<<endl;;
    for(auto i:v) printvector(i);
    cout<<"}"<<endl;
}

void print3D(vector<vector<vector<int>>> &v){
    cout<<"{"<<endl;
    for(auto i:v) print2D(i);
    cout<<"}"<<endl;
}

// recursion
int max_sum(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid)
{
    if (j1 < 0 or j1 > m - 1 or j2 < 0 or j2 > m - 1 or j2 == j1)
        return INT_MIN;
    if (i == n - 1)
        return grid.at(i).at(j1) + grid.at(i).at(j2);
    vector<vector<int>> pos = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int maxi = INT_MIN;
    for (int k = 0; k < 9; k++)
        maxi = max(maxi, max_sum(i + 1, j1 + pos.at(k).at(0), j2 + pos.at(k).at(1), n, m, grid));

    return grid.at(i).at(j1) + grid.at(i).at(j2) + maxi;
}

// memorization
int max_sum(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 or j1 > m - 1 or j2 < 0 or j2 > m - 1 or j2 == j1)
        return INT_MIN;
    if (i == n - 1)
        return grid.at(i).at(j1) + grid.at(i).at(j2);
    if (dp.at(i).at(j1).at(j2) != -1)
        return dp.at(i).at(j1).at(j2);
    vector<vector<int>> pos = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int maxi = INT_MIN;
    for (int k = 0; k < 9; k++)
        maxi = max(maxi, max_sum(i + 1, j1 + pos.at(k).at(0), j2 + pos.at(k).at(1), n, m, grid, dp));

    return dp.at(i).at(j1).at(j2) = grid.at(i).at(j1) + grid.at(i).at(j2) + maxi;
}

// tabulation
// int max_sum_tab(int n, int m, vector<vector<int>> &grid)
// {
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
//     vector<vector<int>> pos = {
//         {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
//     for (int i = n - 1; i > 0; i--)
//     {
//         for (int j1 = 0; j1 < m; j1++)
//         {
//             if (i == 0)
//             {
//                 dp.at(i).at(j1) = grid.at(i);
//                 continue;
//             }
//             int maxi = INT_MIN;
//             for (int j2 = 0; j2 < m; j2++)
//             {

//                 if(i==n-1){
//                     dp.at(n - 1).at(j1).at(j2) = grid.at(n - 1).at(j1) + grid.at(n - 1).at(j2);
//                     continue;
//                 }
//                 for (int k = 0; k < 9; k++)
//                 {
//                     if (
//                         j1 + pos.at(k).at(0) >= 0 and
//                         j1 + pos.at(k).at(0) < m and
//                         j2 + pos.at(k).at(1) >= 0 and
//                         j2 + pos.at(k).at(1) < m )
//                         maxi = max(maxi, dp.at(i + 1).at(j1 + pos.at(k).at(0)).at(j2 + pos.at(k).at(1)));
//                 }
//                 dp.at(i).at(j1).at(j2) = maxi;
//             }
//         }
//     }
//     vector<vector<int>> p = {
//         {0, m-2}, {0, 0}, {1, 0}, {1, m-2}};
//     int maxi = INT_MIN;
//     for (int i = 0; i < 4; i++)
//     {
//         maxi = max(maxi, dp.at(1).at(p.at(i).at(0)).at(p.at(i).at(1)));
//     }
//     cout<<endl;
//     print3D(dp);
//     return grid.at(0).at(0) + grid.at(0).at(m - 1) + maxi;
// }
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

