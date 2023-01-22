#include<vector>
#include<climits>
#include<string>
#include <iostream>
using namespace std;

void printvector(vector<int> &v){
    cout<<"{";
    for(auto i:v) cout<<i<<",";
    cout<<"}"<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v.at(i);


        int prev=0;
        int output=1;
        v.at(0) = -v.at(0);
        for(int i=1; i<n; i++){
            if(v.at(i-1) <  -v.at(i)){
                v.at(i) = -v.at(i);
            }
            else if ( v.at(i-1) < v.at(i)){
                continue;
            }
            else{
            //    printvector(v);
          //      cout<<"i="<<i<<" prev="<<prev<<endl;
                int cur = i-prev;
                output += cur*(cur+1)/2 -1;
                prev = i-1;
                v.at(i-1) = -v.at(i-1);
            }

        }
        //cout<<"n="<<n<<" prev="<<prev<<endl;
        int cur = n -prev;
        output += cur*(cur+1)/2 - 1;

        cout<<output<<endl;
        //printvector(v);

    }
	return 0;
}



