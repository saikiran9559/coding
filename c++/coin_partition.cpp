
#include <iostream>
#include<vector>
#include<climits>

using namespace std;
void printvector(vector<int> &arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

void permutate(vector<int> &coins, int l, int n, int chefu, int chefa, int &maxi, vector<int> &arrange, vector<int> &output){
    if(l==n){
        if(l==0 or chefu<=chefa) chefu += coins.at(l);
        else chefa += coins.at(l);
        if(chefu>=chefa){
            if(chefu> maxi){
                maxi = chefu;
                output = arrange;
            }
        }
        return;
    }
    for(int i=l; i<=n; i++){
        int a=0, b=0;
        if(i==0 or chefu<=chefa) a = coins.at(i);
        else b = coins.at(i);
        swap(coins.at(i), coins.at(l));
        swap(arrange.at(i), arrange.at(l));
        permutate(coins, l+1, n, chefu + a, chefa + b, maxi, arrange, output);
        swap(arrange.at(i), arrange.at(l));
        swap(coins.at(i), coins.at(l));
    }
    
}


int main() {
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        vector<int> coins(n);
        vector<int> arrange(n);
        for(int j=0; j<n; j++){
            cin>>coins.at(j);
            arrange.at(j)=j+1;
        }
        vector<int> output;
        int maxi = INT_MIN;
        permutate(coins, 0, n-1, 0, 0, maxi, arrange, output);
        printvector(output);
    }
    return 0;
}
