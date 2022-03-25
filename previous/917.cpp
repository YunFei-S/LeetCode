#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
#include <ctype.h>
using namespace std;

/** Function
 *  反转字符串
 * a-bC-dEf-ghIj
 * j-Ih-gfE-dCba 
*/
class Solution {
public:
    string reverseOnlyLetters(string s) {
        string res = s;
        int left = 0;
        int right = s.length()-1;
        while(left < right) {
            while(!isalpha(res[left]) & left < right)
                left++;
            while(!isalpha(res[right]) & left < right)
                right--;
            if( left < right)
            swap(res[left++], res[right--]);
        }
        return res;
    }
};


int main(){
    Solution s;
    cout<<s.reverseOnlyLetters("7_28]")<<endl;
}