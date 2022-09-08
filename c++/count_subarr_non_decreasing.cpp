
#include <iostream>
#include<vector>
using namespace std;

int fun(vector<int> &arr, int n){
    int count=0;
    int reset=1;
    if(n==0) return 0;
    for(int i=0; i<n-1; i++ ){
        if(arr.at(i)<=arr.at(i+1)){
            reset+=1;
        }
        else{
            count += (reset*(reset+1)/2);
            reset=1;
        }
    }
   return count += (reset*(reset+1)/2);
}


int main() {
	// your code goes here
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int j=0; j<n; j++){
            cin>>arr.at(j);
        }
        cout<<fun(arr,n)<<endl;
    }
	return 0;
}
