#include <bits/stdc++.h> 
#include <vector>
using namespace std;
int fun(vector<int> &cost, vector<int> &wt, int n, int k){
    if(n==0){
        if(wt.at(n)<=k) return cost.at(n);
        else return 0;
    }
    if(wt.at(n) <=k) return max( cost.at(n) + fun(cost, wt, n-1, k-wt.at(n)), fun(cost, wt, n-1, k));
    return fun(cost, wt, n-1, k);
}

int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mini =prices[0];
    int maxprofit = 0 ;
    for(int i=0;i<prices.size();i++){
        mini = min(mini, prices[i]);
        maxprofit = max(maxprofit, prices[i]-mini);
    }
    return maxprofit;
}


int main(){
    vector<int> cost{100,200, 150, 10};
    vector<int> wt{20,30,10,15};
    int k = 30;
    cout<<fun(cost,wt, cost.size()-1, k)<<endl;
    return 0;
}

