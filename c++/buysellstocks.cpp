#include <bits/stdc++.h> 
#include <vector>
int getMin(int a,int b){
    if(a<b){
        return a;
    }
    return b;
};

int getMax(int a, int b){
    if(a>b){
        return a;
    }
    return b;
};
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int min=prices[0];
    int maxprofit = 0;
    for(int i=0;i<prices.size();i++){
        min = getMin(min, prices[i]);
        maxprofit = getMax(maxprofit, prices[i]-min);
    }
    return maxprofit;
}


