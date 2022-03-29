#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
using namespace std;


/** 交替位二进制数
 * 传入一个值,判断其是否时进制 0 1 交替
 * n = 5  [true]   101
 * n = 5  [false]  111
 * */

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag = (n-1)%2;
        while(n > 0){
            if(flag == n%2)
                return false;
            flag = n%2;
            n /= 2;
        } 
        return true;
    }
};


int main(){
    Solution s;
    cout<<s.hasAlternatingBits(2147483647)<<endl;
}