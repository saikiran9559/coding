#include<vector>
#include<climits>
#include<string>
#include <iostream>
using namespace std;

int maxSubarrayXOR(vector<int> &arr, int n)
{
    int ans = INT_MIN;  
    for (int i=0; i<n; i++)
    {
        int curr_xor = 0; 
        for (int j=i; j<n; j++)
        {
            curr_xor = curr_xor ^ arr[j];
            ans = max(ans, curr_xor);
        }
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++)cin>>v.at(i);
        cout<<maxSubarrayXOR(v,n)<<endl;
    }
	return 0;
}


