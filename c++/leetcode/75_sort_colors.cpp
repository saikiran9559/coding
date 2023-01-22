#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // void sortColors(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> zeros, ones, twos;
    //     for(auto i:nums){
    //         if(i==0){
    //             zeros.push_back(i);
                
    //         } 
    //         else if(i==1){
    //             ones.push_back(i);
    //         }
             
    //         else twos.push_back(i);
    //     }
    //     int index=0;
    //     for(auto i:zeros) nums.at(index++)=i;
    //     for(auto i:ones) nums.at(index++)=i;
    //     for(auto i:twos) nums.at(index++)=i;


    // }

    void sortColors(vector<int> &nums){
        int begin = 0 , mid=0, end=(int)nums.size();
        while(mid<end){
            if(nums.at(mid)==1){
                mid++;
            }
            else if(nums.at(mid)==0){
                swap(nums.at(begin++),nums.at(mid++));
            }
            else{
                swap(nums.at(mid),nums.at(--end));
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> h{2,0,2,1,1,0};
    s.sortColors(h);
    for(auto i:h) cout<<i<<",";
}