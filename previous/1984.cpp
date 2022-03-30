#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h> // INT_MAX INT_MIN
using namespace std;


/** Function
 * 
 * 
 * */
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1 || n < k)
            return 0;
        
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = k-1;
        int res = INT_MAX;
        while(j < n) {
            res = min(nums[j]-nums[i],res);
            i++;
            j++;
        }
        return res;
    }
};

//nums = [9,4,1,7], k = 2
int main(){
    vector<int> nums = {64407,3036};
    int k = 2;
    Solution s;
    cout<<s.minimumDifference(nums,k);
}