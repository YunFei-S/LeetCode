#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
using namespace std;

/** 求最大连续1的个数
 * 本身加当前数乘当前数,当前数为1时,就是连续1的个数,当前数为0时则清零
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int tmp = 0;
        for(int num : nums){
            tmp = (tmp+num)*num;
            if( tmp > res)
                res = tmp;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec ={1,1,0,1};
    cout<<s.findMaxConsecutiveOnes(vec)<<endl;
}