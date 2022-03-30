#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include <unistd.h>
#include <atomic>
#include <mutex>
#include <assert.h>
#include <cassert>
#include<stdio.h>

using namespace std;

/** Function
 * 

输入：num1 = "1+1i", num2 = "1+1i"
输出："0+2i"
解释：(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。

输入：num1 = "1+-1i", num2 = "1+-1i"
输出："0+-2i"
解释：(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。

 * */

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1,a2,b1,b2;
        sscanf(num1.c_str(),"%d+%di",&a1,&a2);
        sscanf(num2.c_str(),"%d+%di",&b1,&b2);

        int a = a1*b1 - a2*b2;
        int b = a1*b2 + a2*b1;

        return string(to_string(a)+"+"+to_string(b)+"i");
    }  
};

// num1 = "1+1i", num2 = "1+1i"
int main(){
    Solution s;
    string num1 = "1+1i";
    string num2 = "1+1i";
    cout<<s.complexNumberMultiply(num1,num2)<<endl;
}