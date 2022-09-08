#include<bits/stdc++.h>
using namespace std;

bool ispresent(unordered_map<int,vector<int>> &map, int a, int b ){
    if(map.find(a)!=map.end()){

        for(auto i: map.at(a)){
            if(i==b) return true;
        }
    }
    return false;
}

int countPairsWithDiffK(int arr[], int n, int k)
{
    int count = 0;
    unordered_map<int,vector<int>> map;
    // Pick all elements one by one
    for (int i = 0; i < n; i++) {
        // See if there is a pair of this picked element
        for (int j = i + 1; j < n; j++)
            if(arr[i] - arr[j] == k
                || arr[j] - arr[i] == k)
            {
                if(ispresent(map, arr[i], arr[j]) ==0 ){
                    cout<<arr[i]<<","<<arr[j]<<endl;
                    count++;
                    map.at(arr[i]).push_back(arr[j]);
                    map.at(arr[j]).push_back(arr[i]);
                }
            }
                
    }
    return count;
}
 
// Driver program to test above function
int main()
{
    int arr[] = { 1, 1, 1, 2 };
    int n = 4;
    int k = 1;
    cout << "Count of pairs with given diff is "
         << countPairsWithDiffK(arr, n, k);
    return 0;
}
