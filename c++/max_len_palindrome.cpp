#include<bits/stdc++.h>
using namespace std;

vector<int> mid(int n){
    int mid = n/2;
    if(n%2==0){
        {mid-1, mid};
    }
    {mid-1, mid+1};
}

string longestPalindrome(string s) {
    vector<int> ar = mid(s.size());
    int i= ar.at(0);
    int j = ar.at(1);
    while(s.at(i)==s.at(j)){
    }
}

int main(){
    string a = "afaa";
    cout<<a.size()<<endl;
    return 0;
}
