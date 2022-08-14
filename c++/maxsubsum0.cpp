#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
/*
 * method 1
int LongestSubsetWithZeroSum(vector<int> arr ){
    int n = arr.size();
    int sum=0;
    int maxlen =0;
    for(int i=0; i<n;i++){
        sum=0;
        for(int j=i; j<n;j++){
            sum+=arr[j];
            if(sum==0){
                maxlen = max(maxlen, j-i+1);
            }
        }
    }
    return maxlen;
}
*/
int LongestSubsetWithZeroSum(vector<int> arr){
    int n = arr.size();
    int sum =0;
    int maxlen =0;
    unordered_map<int, int> map; 
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum==0){
            maxlen=i+1;
        }
        else if(map.find(sum)!=map.end()){
            maxlen=max(maxlen, i-map[sum]);
        }
        else{
            map[sum]=i;
        }
    }
    return maxlen;
}

int main(){
    vector<int> v = {9, -3, 3, -1, 6, -5};
    cout<<LongestSubsetWithZeroSum(v);
    return 0;
}
