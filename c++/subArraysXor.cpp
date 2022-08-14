#include<vector>
#include<iostream>
using namespace std;
int subarraysXor(vector<int>  &arr, int x)
{
    //    Write your code here.
    int n = arr.size(),sum,count=0;
    for(int i=0; i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum = sum^arr[j];
            if(sum==x){
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<int> v = {4,3,1,2,4};
    cout<<subarraysXor(v,4)<<endl;
}
