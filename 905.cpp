#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<unordered_map>
#include<set>
#include<unordered_set>
using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size() < 2)
            return nums;
        sort(nums.begin(), nums.end());
        vector<int> res(nums.size());
        for(int i = 0,left = 0,right = nums.size()-1; i < nums.size();i++){
            if(nums[i]%2)
            {
                res[right--] = nums[i];
            }
            else res[left++] = nums[i];
        }
        return res;
    }
};

/** Function
 *  奇淫巧技
 * 
 * 
 * */
bool cmp(int a,int b){
    return a%2 < b%2;
}

class Solution2{
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(),cmp);
        return nums; 
    }
};

void show(vector<int> vec){
    for(int i = 0; i < vec.size();i++)
        cout<<vec[i]<<"   ";
    cout<<endl;
}

int main() {
    Solution2 s;
    vector<int> nums = {3,1,2,4};
    show(s.sortArrayByParity(nums));
}