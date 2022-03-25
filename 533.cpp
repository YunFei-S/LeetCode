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

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string res = "";
        int i = 0;
        while(i < nums.size()) {
            cout<<"i = "<<i<<", nums.size() = "<<nums.size()<<endl;
            if(i = 1){
                res += '(';
                cout<<res<<endl;
            }
            res += to_string(nums[i]);
            res += '/';
            i++;
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec = {1000,100,10,2};
    cout<<vec.size()<<endl;
    cout<<s.optimalDivision(vec)<<endl;
    return 0;
}