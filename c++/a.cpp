#include<bits/stdc++.h>
using namespace std;
void printvector(vector<int> &v){
    cout<<"\t{";
    for(auto i:v)cout<<i<<",";
    cout<<"},"<<endl;
}

int maxpositive(vector<int> &arr, int n ){
    vector<int> neg;
    int possum=0;
    int output =0;
    for(auto i: arr){
        if(i<=0) neg.push_back(i);
        else{
            possum+=i;
            output +=1;
        }
    }
    sort(neg.begin(), neg.end());
    n = n-output;
    for(int i=n-1; i>=0; i--){
        possum+=neg.at(i);
        if(possum<=0){
            break;
        }
        output+=1;
    }

    return output;
}


int main(){
    int n; 
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    cout<<maxpositive(arr,n);
    return 0;
}
