#include<bits/stdc++.h>
using namespace std;

int minimum(int a, int b, int c){
    if(a<b and a<c) return a;
    if(b<a and b<c) return b;
    else return c;
}

//recursion
int min_path_tri(int n, int m, vector<vector<int>> &grid){
    if(n==0 and m==0) return grid.at(0).at(0);
    if(m<0 or m>n) return INT_MAX;
    return grid.at(n).at(m) + minimum( min_path_tri(n-1,m-1,grid), min_path_tri(n-1,m,grid), min_path_tri(n-1,m+1,grid));
}

//memorization
int min_path_tri(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(n==0 and m==0) return grid.at(0).at(0);
    if(m<0 or m>n) return INT_MAX;
    if(dp.at(n).at(m) != -1) return dp.at(n).at(m);
    return dp.at(n).at(m) = grid.at(n).at(m) + minimum(min_path_tri(n-1,m-1,grid,dp), min_path_tri(n-1,m,grid,dp), min_path_tri(n-1,m+1,grid,dp));
}

//tabulation
int min_path_tri_tab(int n, vector<vector<int>> &grid){
    vector<vector<int>> dp(n,vector<int>(n,-1));
    dp.at(0).at(0) = grid.at(0).at(0);
    int mini = INT_MAX;
    for(int  i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            int one = INT_MAX, two = INT_MAX, three = INT_MAX;
            if(j>0) one = dp.at(i-1).at(j-1);
            if(j!=i) two = dp.at(i-1).at(j);
            if(j<i-1) three = dp.at(i-1).at(j+1);
            dp.at(i).at(j) = grid.at(i).at(j) + minimum(one,two,three);
            if(i==n-1) mini = min(mini, dp.at(i).at(j));
        }
    }
    return mini;
}

//space optimization
int  min_path_tri_space(int n, vector<vector<int>> &grid){
    vector<int> prev(n,-1);
    prev.at(0) = grid.at(0).at(0);
    int mini = INT_MAX;
    for(int i=1; i<n; i++){
        vector<int> cur(n);
        for(int j=0; j<=i; j++){
            int one = INT_MAX, two = INT_MAX, three = INT_MAX;
            if(j>0) one = prev.at(j-1);
            if(j!=i) two = prev.at(j);
            if(j<i-1) three = prev.at(j+1);
            cur.at(j) = grid.at(i).at(j) + minimum(one, two, three);
            if(i==n-1) mini = min(mini, cur.at(j));
        }
        prev = cur;
    }
    return mini;
}


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> grid(n);
        for(int i=0; i<n; i++){
            vector<int> row(i+1);
            for(int j=0; j<=i; j++){
                cin>>row.at(j);
            }
            grid.at(i) = row;
        }
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            mini = min(min_path_tri(n-1,i,grid), mini);
        }
        cout<<mini<<endl;
        mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0 ;i<n; i++){
            mini = min(min_path_tri(n-1,i,grid,dp), mini);
        }
        cout<<mini<<endl;
        cout<<min_path_tri_tab(n,grid)<<endl;
        cout<<min_path_tri_space(n,grid)<<endl;
    }
}

/*

4
1
2 3
3 6 7
8 9 6 10
*/

// 14