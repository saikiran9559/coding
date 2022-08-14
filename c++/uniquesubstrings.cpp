#include <bits/stdc++.h> 
using namespace std;
void print(vector<int> v){
    cout<<"[";
    for(auto i:v)cout<<i<<",";
    cout<<"]"<<endl;
}
/*
 * method 1
int uniqueSubstrings(string input)
{
    //Write your code here
    int n = input.length(), maxlen=0;
    int j=0;
    for(int i=0; i<n; i++){
        unordered_set<char> set;
        for(j=i; j<n; j++){
            if(set.find(input[j])!=set.end()){
                maxlen = max(maxlen, j-i);
                break;
            }
            set.insert(input[j]);
        }
        if(j==n){
            maxlen = max(maxlen, j-i);
        }
        if(maxlen==n){
            return maxlen;
        }
    }
    return maxlen;
}
*/
int uniqueSubstrings(string s){
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);
        mpp[s[right]] = right;
        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }


int main(){
    /*
    vector<int>::iterator itr = find(mpp.begin(),mpp.end(),1);
    if(itr!=mpp.end()){
        cout<<"index="<<itr-mpp.begin()<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    */
    cout<<uniqueSubstrings("ababcdede");
    return 0;
}
