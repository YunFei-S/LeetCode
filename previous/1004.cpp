#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
using namespace std;


/** Function
 * nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
 * 6
 * [1,1,1,0,0,1,1,1,1,1,1]
 * 
 * */
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        for(int left =0,right = 0,temp = 0;right < n;right++){
            if(nums[right] == 0)
                temp++;
            while(temp > k){
                if(nums[left] == 0)
                    temp--;
                left++;
            }
            res = max(res,right-left+1);
        }
        return res;
    }
};



int main(){
    Solution s;
    vector<int> vec = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    vector<int> vec2 = {1,1,1,0,0,0,1,1,1,1,0};
    cout<<s.longestOnes(vec2,2)<<endl;
}