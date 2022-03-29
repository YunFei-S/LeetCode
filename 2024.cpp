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
        int n = answerKey.size();
        int cntT = 0, cntF = 0, ans = 0;
        for (int left = 0, right = 0; right < n; ++right) {
            if(answerKey[right] == 'T') cntT++;
            else cntF++;
            if (cntT > k && cntF > k) {
                if (answerKey[left] == 'T') cntT--;
                else cntF--;
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};



int main(){
    Solution s;
    string str = "TFFT";
    cout<<s.maxConsecutiveAnswers(str,1)<<endl;
}