#include<bits/stdc++.h>
using namespace std;
// max sum path 
// start point is any cell from the first row
// end point is any cell from the last row

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
int maxsum(vector<vector<int>> &mat, int n, int m, int r){
    if(m>r or m<0) return INT_MIN;
    if(n==0) return mat.at(n).at(m);
    int maxi = mat.at(n).at(m) + maxsum(mat,n-1,m-1,r);
    maxi = max( maxi, mat.at(n).at(m) + maxsum(mat,n-1,m, r) );
    maxi = max( maxi, mat.at(n).at(m) + maxsum(mat,n-1,m+1,r) );
    return maxi;
}

//recursion with memorization
int maxsum(vector<vector<int>> &mat, int n, int m, int r, vector<vector<int>> &dp){
    if(m>r or m<0) return INT_MIN;

    if(dp.at(n).at(m)!= INT_MIN) return dp.at(n).at(m);

    if(n==0) return dp.at(n).at(m)= mat.at(n).at(m);

    int maxi = mat.at(n).at(m) + maxsum(mat,n-1,m-1,r,dp);
    maxi = max( maxi, mat.at(n).at(m) + maxsum(mat,n-1,m, r,dp) );
    maxi = max( maxi, mat.at(n).at(m) + maxsum(mat,n-1,m+1,r,dp) );

    return dp.at(n).at(m) =  maxi;
}

//tabulation

int maxsum(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat.at(0).size();
    vector<vector<int>> dp(n,vector<int>(m,INT_MIN));
    dp.at(0) = mat.at(0);
    int maxi=INT_MIN;
    for(int i =1; i<n; i++){
        dp.at(i).at(0) = mat.at(i).at(0) + max( dp.at(i-1).at(0) , dp.at(i-1).at(1) );
        for(int j=1; j<m-1; j++){
            int temp = dp.at(i-1).at(j-1);
            temp = max(temp, dp.at(i-1).at(j));
            temp = max(temp, dp.at(i-1).at(j+1));
            temp += mat.at(i).at(j);
            dp.at(i).at(j) = temp;
        }
        dp.at(i).at(m-1) = mat.at(i).at(m-1) + max( dp.at(i-1).at(m-1), dp.at(i-1).at(m-2) );
    }
    print2D(dp);
    for(int j=0; j<m; j++ ) maxi = max( maxi, dp.at(n-1).at(j));
    return maxi;
}

int maxsum2(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat.at(0).size();
    vector<int> prev;
    prev = mat.at(0);
    int maxi=INT_MIN;
    for(int i =1; i<n; i++){
        vector<int> prevtemp;
        prevtemp.push_back( mat.at(i).at(0) + max( prev.at(0) , prev.at(1) ) );
        for(int j=1; j<m-1; j++){
            int temp = prev.at(j-1);
            temp = max(temp, prev.at(j));
            temp = max(temp, prev.at(j+1));
            temp += mat.at(i).at(j);
            prevtemp.push_back(temp);
        }
        prevtemp.push_back( mat.at(i).at(m-1) + max( prev.at(m-1), prev.at(m-2) ) );
        prev = prevtemp;
    }
    printvector(prev);
    for(int j=0; j<m; j++ ) maxi = max( maxi, prev.at(j));
    return maxi;
}


int main(){
    vector<vector<int>> mat{
        {1,2,10,4},
        {100,3,2,1},
        {1,1,20,2},
        {1,2,2,1},
    };
    int n = mat.size();
    int m = mat.at(0).size();
    int maxi = INT_MIN;
    print2D(mat);
    vector<vector<int>> dp(n,vector<int>(m,INT_MIN));
    for(int i=m-1; i>=0; i--){
        maxi = max( maxi, maxsum(mat,n-1,i,m-1,dp));
    }
    print2D(dp);
    cout<<maxi<<endl;
    cout<<maxsum(mat)<<endl;
    cout<<maxsum2(mat)<<endl;
}
