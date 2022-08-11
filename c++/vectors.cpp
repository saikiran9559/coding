#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int main(){
    int n;
    int val;
    vector<int> arr ={1,3,4,7,2,10};
    /*
    for (auto i=ar.begin(); i!=ar.end();i++){
        cout<<*i<<",";
    }
    */
    sort(arr.begin(),arr.end());
    for (auto i=arr.begin(); i!=arr.end();i++){
        cout<<*i<<",";
    }
    cout<<endl;
    cout<<binary_search(arr.begin(),arr.end(),7);
    if(binary_search(arr.begin(),arr.end(),10)){
        cout<<"Yes";
    }
    else{
        cout<<"NO";
    }
}
