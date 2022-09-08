#include<vector>
#include<iostream>
using namespace std;
void printvector(vector<int> v){
    cout<<"{";
    for(auto i:v) cout<<i<<",";
    cout<<"}"<<endl;
}

int partition(vector<int> &v, int low, int high){
    int i = low;
    int pivot = v[low];
    for(int j=low+1; j<=high;j++){
        if(v.at(j)<pivot){
            i++;
            swap(v.at(j),v.at(i));
        }
    }
    swap(v.at(i),v.at(low));
    return i;
}

int quicksort(vector<int> &v, int low, int high){
    if(low<high){
        int pivot = partition(v,low,high);
        quicksort(v,low,pivot-1);
        quicksort(v,pivot+1,high);
    }
}

int main(){
    vector<int> v = {8,2,5,9,1,3};
 //   vector<int> v = {1,2,3,5,8,9};
    quicksort(v,0,v.size()-1);
    printvector(v);
}


