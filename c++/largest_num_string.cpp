#include<vector>
#include<climits>
#include<string>
#include <iostream>
using namespace std;

int solve(string st , int k){
    int n = st.size();
    int init = 0;
    string output = "";// adding highest values here
    int count = n-k;// we need only n-k characters in output
    while(k>0 and count>0){
        int maxi=init;
        for(int i=init+1; i <= init+k; i++){
            if((int)st[i]>(int)st[maxi])
                maxi =i;
        }
        k -= (maxi-init);
        output += st[maxi];
        init = maxi+1;
        count--;
    }
    if(count>0) output += st.substr(init,n);
    return stoi(output);
}

int main(){
    string a;
    int k;
    cin>>a>>k;
    cout<<solve(a,k)<<endl;
    return 0;
}



