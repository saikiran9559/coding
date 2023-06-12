#include<bits/stdc++.h>
using namespace std;
void printArr(vector<int> &v){
    for(auto i:v) cout<<i<<",";
    cout<<endl;
}
void selectionSort(vector<int> &v){
    int n = v.size();
    cout<<n<<endl;
    for(int i=0; i<n-1; i++){
        int min_index = i;
        for(int j=i+1; j<n; j++){
            if(v.at(j) < v.at(min_index)){
                min_index = j;
            }
        }
        if(min_index !=i)
            swap(v.at(min_index), v.at(i));
    }
}

int main(){
    freopen("input.txt","r", stdin);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v.at(i);
    }
    selectionSort(v);
    printArr(v);
    return 0;
}