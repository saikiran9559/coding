#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        n = nums2.size();
        m = nums1.size()-nums2.size();
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1.at(i)<=nums2.at(j)){
                v.push_back(nums1.at(i++));
            }
            else v.push_back(nums2.at(j++));
        }
        if(i<m){
            for(int k=i;k<m;k++){
                v.push_back(nums1.at(k));
            }
        }
        else if(j<n){
            for(int k=j; k<n; k++){
                v.push_back(nums2.at(k));
            }
        }
        for(int k=0; k<m+n; k++){
            nums1.at(k)=v.at(k);
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m+n-1;
        while(m>0 && n>0){
            if(nums1.at(m-1) > nums2.at(n-1)){
                nums1.at(len--) = nums1.at(--m);
            }
            else{
                nums1.at(len--) = nums2.at(--n);
            }
        }
        while(n>0){
            nums1.at(len--) = nums2.at(--n);
        }
    }
};

int main(){
    Solution s;
    vector<int> nums1{1,2,3,0,0,0}, nums2{2,5,6};
    s.merge(nums1, 3, nums2, 3);
    for(auto i:nums1) cout<<i<<",";
}