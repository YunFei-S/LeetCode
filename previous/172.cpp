#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
using namespace std;


/** Function
 * 给定一个整数,返回n!结果中的尾随零的数量
    输入：n = 3
    输出：0
    解释：3! = 6 ，不含尾随 0


    输入：n = 5
    输出：1
    解释：5! = 120 ，有一个尾随 0

    输入：n = 0
    输出：0
 * 
 *
 * 计算5的因子有多少就可以得出包含了多杀的0
 * 
 * */

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n > 0) {
            count += n/5;
            n /= 5;
        }
        return count;
    }
};


int main(){
    Solution s;
    cout<<s.trailingZeroes(3)<<endl;
    cout<<s.trailingZeroes(6)<<endl;
    cout<<s.trailingZeroes(10)<<endl;
}

