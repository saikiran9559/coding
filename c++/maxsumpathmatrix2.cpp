#include <bits/stdc++.h>
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

int maximum(int a, int b, int c)
{
    if (a > b and a > c)
        return a;
    if (b > a and b > c)
        return b;
    else
        return c;
}

// recursion
int max_path(int n, int m, int i, vector<vector<int>> &grid)
{
    if (i < 0 or i > m)
        return INT_MIN;
    if (n == 0)
        return grid.at(n).at(i);
    return grid.at(n).at(i) + maximum(max_path(n - 1, m, i - 1, grid), max_path(n - 1, m, i, grid), max_path(n - 1, m, i + 1, grid));
}

// memorization
int max_path(int n, int m, int i, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i < 0 or i > m)
        return INT_MIN;
    if (n == 0)
        return grid.at(n).at(i);
    if (dp.at(n).at(i) != -1)
        return dp.at(n).at(i);
    return dp.at(n).at(i) = grid.at(n).at(i) + maximum(max_path(n - 1, m, i - 1, grid, dp), max_path(n - 1, m, i, grid, dp), max_path(n - 1, m, i + 1, grid, dp));
}

// tabulation
int max_path_tab(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp.at(0) = grid.at(0);
    int maxi = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int one = INT_MIN, two = INT_MIN, three = INT_MIN;
            if (j > 0)
                one = dp.at(i - 1).at(j - 1);
            two = dp.at(i - 1).at(j);
            if (j < m-1)
                three = dp.at(i - 1).at(j + 1);
            dp.at(i).at(j) = grid.at(i).at(j) + maximum(one, two, three);
            if (i == n - 1)
                maxi = max(maxi, dp.at(i).at(j));
        }
    }
    return maxi;
}

//space optimization
int max_path_space(int n, int m, vector<vector<int>> &grid){
    vector<int> prev = grid.at(0);
    int maxi = INT_MIN;
    for(int i=1; i<n; i++){
        vector<int> cur(m);
        for(int j=0; j<m; j++){
            int one = INT_MIN, two = INT_MIN, three = INT_MIN;
            if(j>0) one = prev.at(j-1);
            two = prev.at(j);
            if(j<m-1) three = prev.at(j+1);
            cur.at(j) = grid.at(i).at(j) + maximum(one, two, three);
            if(i==n-1) maxi = max(maxi, cur.at(j));
        }
        prev = cur;
    }
    return maxi;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n);
        for (int i = 0; i < n; i++)
        {
            vector<int> row(m);
            for (int j = 0; j < m; j++)
                cin >> row.at(j);
            grid.at(i) = row;
        }

        int maxi = INT_MIN;
        for (int i = 0; i < m; i++)
            maxi = max(maxi, max_path(n - 1, m - 1, i, grid));
        cout << maxi << endl;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        maxi = INT_MIN;
        for (int i = 0; i < m; i++)
            maxi = max(maxi, max_path(n - 1, m - 1, i, grid, dp));
        cout << maxi << endl;
        cout << max_path_tab(n, m, grid) << endl;
        cout << max_path_space(n,m,grid) << endl;
    }
}

/*

1
4 4
1 2 10 4
100 3 2 1
1 1 20 2
1 2 2 1

*/

// 105