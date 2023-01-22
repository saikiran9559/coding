#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a,vector<int> &b){
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]<b[1];
}

int final(vector<vector<int>>& prop) {
    sort(prop.begin(),prop.end(),comp);
    vector<vector<int>> :: iterator  it;
    int maxtillnow = INT_MIN;
    int ans=0;
    for(auto p:prop){
        cout<<p[0]<<","<<p[1]<<","<<maxtillnow<<endl;
        if(maxtillnow>p[1]) ans++;
        else maxtillnow=p[1];
    }
    return ans;
}

int main(){
    //vector<vector<int>> v{{5,5},{6,3},{3,6}};
    //vector<vector<int>> v{{2,2},{3,3}};
    //vector<vector<int>> v{{7,7},{1,2},{9,7},{7,3},{3,10},{9,8},{8,10},{4,3},{1,5},{1,5}};
 //   vector<vector<int>> v{{10,1},{5,1},{7,10},{4,1},{5,9},{6,9},{7,2},{1,10}};
   vector<vector<int>> v{{7,9},{10,7},{6,9},{10,4},{7,5},{7,10}};
  //  vector<vector<int>>  v{{1,1},{2,1},{2,2},{1,2}};
  //vector<vector<int>> v{{10,1},{10,2},{5,7},{5,3}};
    cout<<final(v)<<endl;
    return 0;
}
