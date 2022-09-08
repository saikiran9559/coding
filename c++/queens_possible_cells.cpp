#include<bits/stdc++.h>
using namespace std;
//vector<vector<int>> &obstacles,
void printvector(vector<int> v){
    cout<<"{";
    for(auto i:v) cout<<i<<",";
    cout<<"}"<<endl;
}
int abs(int &val){
    if(val<0) return -val;
    return val;
}

void checkandcut(int &to,int todi, int dire, int dis, &total){
    if(dire == todi){
        if(dis<to){
            to = dis;
            total-=dis;
        }
    }
}

int sameornot(int i, int j, int n, int m, int dim){
    if(i==n){
        dis = abs(m-j);
        if(m<j) return {dis, 7, dim-m};
        else return {dis,3 , n+1};
    };
    if(j==m){
        dis = abs(n-i);
        if(n<i) return {dis, 5, dim-n};
        else return {dis, 1, n+1};
    }
    if(abs(i-n)==abs(j-m)){
        dis = abs(i-n);
        if(n>i){
            if(m>j){
                if(m+n<dim) return {dis, 2, n};
                else return {dis, 2, m};
            }
            else{
                if(n-m <=0) return {dis, 8, dim-m};
                else return {dis, 8, n};
            }

        }
        else if(m>j) return {dis, 4};{
            if(dim-n < dim-m) return {dis, 4, dim-n};
            else return {dis, 4, dim-m};
        }
        else if(dim-n-1 < m){
            return {dis, 6, dim-n};
        }
        return {dis, 6, m+1};
    }
    return {-1,-1,-1};
}

vector<int> sameat(int val){
    return {1,2};
}

int maxcells(vector<vector<int>> &obs, int ith, int jth, int n){
    int k = obs.size();
    int straights = 2*n;
    int mid = n/2;
    int d1,d2;
    if(ith+jth <n) d1 = ith+jth+1;
    else d1 = n - jth - (n-1-ith);
    if(ith-jth <= 0) d2 = -(ith-jth);
    else d2 = jth+(n-1-ith)+1;
    //cout<<d1<<","<<d2<<","<<straights<<endl;
    /*
    int up=INT_MAX;
    int down=0;
    int left=0;
    int right =0;
    int upright=0;
    int upleft=0;
    int downright=0;
    int downleft=0;
    */
    vector<int> directions(9,INT_MAX);
    int total = straights + d1 + d2 -4;
    for(int i=0; i<k; i++){
        vector<int> output = sameornot(ith, jth, obs.at(i).at(0), obs.at(i).at(1));
        int dire = output.at(1);
        int dis = output.at(0);
        int cut = output.at(2);
        if(dire == -1) continue;
        for(int i=1; i<=8; i++){
            if(dis<directions.at(i)){
                directions.at(i) = dis;
                total-=cut;
            }
        }
    }
    return total;

    return straights + d1 + d2 -4;
}

int main(){
    //cout<<maxcells(1,5,7)<<endl;
    //cout<<sameornot(3,2,4,0);
    cout<<sameat(7).at(1)<<endl;
    return 0;
}
