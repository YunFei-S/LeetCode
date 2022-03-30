#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
using namespace std;


/** 交替位二进制数
 * 在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。

返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望下标数字 i 和 j 满足  i < j 且有 (time[i] + time[j]) % 60 == 0。

 * */

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        int nums[60] = {0}; 
        for(int t : time){
            t %= 60;
            if(t != 0)
                count += nums[60-t];
            else count += nums[t];
            nums[t]++;
        }
        return count;
    }
};


/** 
 * 思路:
 * 定义一个大小为60,值为0的数组
 * 获取每个值对其求60的余数,获取与其相加没60的值
 * 余数为0时获取0位置的值
*/