#include<iostream>
#include<vector>
using namespace std;

void printvector(vector<int> v){
    cout<<"{";
    for(auto i:v) cout<<i<<",";
    cout<<"}"<<endl;
}

void heapify(vector<int> &v,int i, int n){
    int largest = i;
    int left = i*2+1;
    int right = left+1;
    if(left<n and v.at(left)> v.at(largest)){
        largest = left;
    }
    if(right<n and v.at(right) > v.at(largest)){
        largest = right;
    }
    if(i!=largest){
        swap(v.at(largest),v.at(i));
        heapify(v,largest,n);
    }
}

void heapsort(vector<int> &v){
    int n = v.size();
    int start = (n/2)-1;
    for(int i=start; i>=0; i--){
        heapify(v,i,n);
    }

    for(int j=n-1; j>0; j--){
        swap(v.at(j),v.at(0));
        heapify(v,0,j);
    }
}

int main(){
    vector<int> v = {8,2,5,9,1,3};
 //   vector<int> v = {1,2,3,5,8,9};
    heapsort(v);
    printvector(v);
}


