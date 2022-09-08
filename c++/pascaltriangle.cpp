#include<bits/stdc++.h>
using namespace std;
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

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output{{1}};
        if(numRows==1) return output;
        for(int i=1; i<numRows; i++){
            vector<int> arr{1};
            for(int j=1; j<i; j++)
                arr.push_back(output.at(i-1).at(j-1) + output.at(i-1).at(j));
            arr.push_back(1);
            output.push_back(arr);
        }
        return output;
        
    }

int main(){
    int n;
    cin>>n;
    vector<vector<int>> output = generate(n);
    print2D(output);
    return 0;
}
