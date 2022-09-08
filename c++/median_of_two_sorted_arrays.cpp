#include<bits/stdc++.h>
using namespace std;
// find median of two sorted arrays

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

float median(vector<int> &arr1, vector<int> &arr2, int n, int m){
    int mid = (n+m)/2;
    int i=n/2, j= m/2;
    int count =0;
    while(count < mid){
        if(arr1.at(i) < arr2.at(j)){
            count+=i;
            i = (i+1+n-1)/2;
        }
    }
}

