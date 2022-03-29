#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
using namespace std;


/** Function
 * 
 * 整数 x - 表示本回合新获得分数 x
"+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
"D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
"C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。

 * 
 * */
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> nums;
        for(string str : ops){
            if(str == "+")
            {
                int size = nums.size();
                int num = nums[size-1]+nums[size-2];
                nums.push_back(num);
            }
            else if(str == "D"){
                int size = nums.size();
                int num = nums[size-1]*2;
                nums.push_back(num);
            }
            else if(str == "C"){
                nums.pop_back();
            }
            else{
                int num = atoi(str.c_str());
                nums.push_back(num);
            }
        }
        int res = 0;
        for(int i : nums){
            res += i;
        }
        return res;
    }
};


int main(){
    Solution s;
}