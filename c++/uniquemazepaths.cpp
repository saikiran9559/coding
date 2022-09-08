#include<bits/stdc++.h>
using namespace std;
// recursion
int fun(int n, int m, vector<vector<int>> &mat){
    if(m<0 or n<0 or mat.at(n).at(m)==-1) return 0;
    if(m==0 and n==0) return 1;
    return fun(n-1,m,mat) + fun(n,m-1, mat);
}


int mod = (int)(1e9 + 7);

// recursion with memorisation
int fun(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(m<0 or n<0 or mat.at(n).at(m) == -1) return 0;
    if(n==0 and m==0) return 1;
    if(dp.at(n).at(m) != -1) return dp.at(n).at(m);
    return  dp.at(n).at(m) = (fun(n-1,m, mat,dp) + fun(n,m-1,mat,dp)) % mod;
}

//tabulation
int fun2(int n, int m, vector<vector<int>> &mat){
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp.at(0).at(0)=1;
    for(int i=1; i<m; i++){
        if(mat.at(0).at(i) == -1){
            break;
        }else{
            dp.at(0).at(i) = 1;
        }
    }
    for(int i=1; i<n; i++){
        if(mat.at(i).at(0) == -1){
            dp.at(i).at(0) = 0;
        }else{
            dp.at(i).at(0) = dp.at(i-1).at(0);
        }
        for(int j=1; j<m; j++){
            if(mat.at(i).at(j) == -1){
                dp.at(i).at(j) = 0;
                continue;
            }
            dp.at(i).at(j) = dp.at(i-1).at(j) +  dp.at(i).at(j-1); 
        }
    }
    return dp.at(n-1).at(m-1);
}

// without tabulation
int fun3(int n, int m, vector<vector<int>> &mat){
    vector<int> prev(m,0);
    prev.at(0)=1;
    for(int i=1; i<m; i++){
        if(mat.at(0).at(i)==-1) break;
        prev.at(i) = 1;
    }
    for(int i=1; i<n; i++){
        vector<int> temp(m,0);
        if(mat.at(i).at(0) != -1) temp.at(0) = prev.at(0);
        for(int j=1; j<m; j++){
            if(mat.at(i).at(j) == -1){
                temp.at(j) = 0;
                continue;
            }
            temp.at(j) = (prev.at(j) + temp.at(j-1)) % mod;
        }
        prev = temp;
    }
    return prev.at(m-1);
}



int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return fun2(n,m,mat);
}

int main(){

    /*
    vector<vector<int>> mat{
        {0,0,0,0,0,0,0,-1,-1,-1,-1,0,0,-1 },
        {0,0,0,-1,0,0,0,0,0,0,0,0,-1,-1},
        {0,0,0,0,0,0,0,-1,0,0,0,0,0,0 },
        {0,0,0,0,0,-1,0,0,0,0,-1,-1,0,0 },
    };
    */

    vector<vector<int>> mat{
        {0,0,0,0},
        {-1,0,0,0},
        {0,0,0,-1},
        {0,-1,0,0},
    };
    int n =mat.size();
    int m = mat.at(0).size();

    cout<<fun2(n,m,mat)<<endl;
    cout<<fun3(n,m,mat)<<endl;

    return 0;
    
}
