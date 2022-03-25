#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
using namespace std;


/** Function
 * 差的绝对值为 K 的数对数目
 * 
 * */

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        if(nums.size()<2)
            return 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        int res = 0;
        while(i < nums.size()-1){
            int j = i + 1;
            int flag = 1; // 相同数字个数
            int num = 0; // 满足要求的数字个数
            while(j < nums.size()){
                // cout<<nums[j]<<"-"<<nums[i]<<"="<<nums[j]-nums[i]<<endl;
                if(nums[j] == nums[i]){
                    // cout<<"=="<<nums[j]<<endl;
                    flag++;
                } 
                else if(nums[j]-nums[i] == k)
                {
                    num++;
                }
                else if(nums[j]-nums[i] > k)
                    break;
                j++;
            }
            if(flag > 0)
                res += num * flag;
            i += flag;
        }
        return res;
    }
};
// [3,2,1,5,4]
// 2

int main(){
    Solution s;
    vector<int> vec = {3,2,1,5,4};
    cout<<s.countKDifference(vec,2)<<endl;
}