
#include<vector>
#include<climits>
#include<string>
#include <iostream>
using namespace std;

int solve(vector<int> &blue, vector<int> &red, int x, int y, int n){
    if(n==0) return max(min(x+blue.at(n), y), min(x,y+red.at(n)));
    return max( 
        min(
            x + blue.at(n),
            y
        ) + solve(blue, red, x+blue.at(n), y, n-1),
        min(
            x,
            y + red.at(n)
        ) + solve(blue, red, x, y+red.at(n), n-1)
    );

}

int main() {
    /*
    int t;
    cin>>t;
    while(t--){
        
    }
    */
    vector<int> a{1,2,3,10};
    vector<int> b{3,1,3,5};
    cout<<solve(a,b,0,0,a.size()-1);

	return 0;
}



