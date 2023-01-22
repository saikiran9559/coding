#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int at=1, candiff=1, doubled=0;
        int prev=nums.at(0);
        int can=1;
        for(int i=1; i<n; i++){
            if(nums.at(i)==prev){
                if(can==1){
                    nums.at(at++)=nums.at(i);
                    can=0;
                }
                continue;
            }
            can=1;
            prev=nums.at(i);
            nums.at(at++)=nums.at(i);
        }
        return at;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,1,1,2,2,3};
    cout<<s.removeDuplicates(nums)<<endl;
    for(auto i:nums) cout<<i<<",";
}