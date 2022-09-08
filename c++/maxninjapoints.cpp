#include<bits/stdc++.h>
using namespace std;
// max ninja points

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
int fun(vector<vector<int>> &v, int last, int n){
    if(n==-1) return 0;
    int maxi = 0;
    if( last != 0) maxi = max(maxi, v.at(n).at(0) + fun(v,0, n-1));
    if( last != 1) maxi = max(maxi, v.at(n).at(1) + fun(v,1, n-1));
    if( last != 2) maxi = max(maxi, v.at(n).at(2) + fun(v,2, n-1));
    return maxi;
}

//recursion with memorization
int fun(vector<vector<int>> &v, int last, int n, vector<vector<int>> &dp){
    if(n==-1) return 0;
    if (dp.at(n).at(last) != -1) return dp.at(n).at(last);
    int maxi = 0;
    if( last != 0) maxi = max(maxi, v.at(n).at(0) + fun(v, 0, n-1, dp));
    if( last != 1) maxi = max(maxi, v.at(n).at(1) + fun(v, 1, n-1, dp));
    if( last != 2) maxi = max(maxi, v.at(n).at(2) + fun(v, 2, n-1, dp));
    dp.at(n).at(last) =  maxi;
    return dp.at(n).at(last);
}

int maxofvector(vector<int> &v){
    int maxi = 0;
    for(auto i:v) maxi = max(maxi, i);
    return maxi;
}

//tabulation to remove recursion stack space.. to reduce space complexity
int fun(vector<vector<int>> &v){
    int n = v.size();
    vector<vector<int>> dp(n,vector<int>(3,-1));
    dp.at(0).at(0) = max(v.at(0).at(1), v.at(0).at(2));
    dp.at(0).at(1) = max(v.at(0).at(0), v.at(0).at(2));
    dp.at(0).at(2) = max(v.at(0).at(0), v.at(0).at(1));
    for(int day=1; day<n; day++){
        for(int last=0; last<3; last++){
            int maxi = 0;
            for(int task=0; task<3; task++){
                if( last!=task){
                    maxi = max(maxi, v.at(day).at(task) + dp.at(day-1).at(task));
                }
            }
            dp.at(day).at(last) = maxi;
        }
    }
    print2D(dp);
    return maxofvector(dp.at(n-1));
}

// space optimization by removing dp table

int fun2(vector<vector<int>> &v){
    int n = v.size();
    vector<int> prevday(3,-1);

    prevday.at(0) = max(v.at(0).at(1), v.at(0).at(2));
    prevday.at(1) = max(v.at(0).at(0), v.at(0).at(2));
    prevday.at(2) = max(v.at(0).at(0), v.at(0).at(1));

    for(int day=1; day<n; day++){
        vector<int> temp(3,-1);
        for(int last=0; last<3; last++){
            for(int task=0; task<3; task++){
                if( last!=task) temp.at(last) = max(temp.at(last), v.at(day).at(task) + prevday.at(task));
            }
        }
        prevday = temp;
    }
    printvector(prevday);
    return maxofvector(prevday);
}


int main(){
    vector<vector<int>> v{
        {2,1,3},
        {3,4,6},
        {10,1,6},
        {8,3,7},
    };
    vector<vector<int>> dp(v.size(),vector<int>(4,-1));
    int n = v.size();
    cout<<fun(v,3,n-1)<<endl;
    cout<<fun(v,3,n-1,dp)<<endl;
    print2D(dp);
    cout<<fun(v)<<endl;
    cout<<fun2(v)<<endl;
    return 0;
}
