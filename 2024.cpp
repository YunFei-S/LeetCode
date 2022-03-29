#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
using namespace std;


/** Function
 * answerKey = "TTFF", k = 2
 * 4
 * 
 * 
 * answerKey = "TFFT", k = 1
 * 
 * */
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int len = answerKey.size();
        int sum_t = 0, sum_f = 0; // 记录t,f的总数
        int left_t = 0, left_f = 0,sum_max = 0; // 遍历过程中 t数列 和 f数列的左边界
        for(int i = 0; i < len;i++){
            if(answerKey[i] == 'T')
                sum_t++;
            else sum_f++;
            while(sum_f > k){
                if(answerKey[left_t] == 'F')
                    sum_f--;
                left_t++;
            }
            while(sum_t > k){
                if(answerKey[left_f] == 'T')
                    sum_t--;
                left_f++;
            }
            sum_max = max(sum_max,max(i-left_t,i-left_f)+1);
        }
        return sum_max;
    }
};


int main(){
    Solution s;
    string str = "TFFT";
    cout<<s.maxConsecutiveAnswers(str,2)<<endl;
}