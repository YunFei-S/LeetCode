#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
using namespace std;


/** Function
 * [1,1,2,3,3,4,4,8,8]
 * 2
 * O(log n) 时间复杂度和 O(1) 空间复杂度
 * */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = 1;
        while(left < nums.size() && right < nums.size()) {
            if(nums[left] == nums[right]){
                left+=2;
                right+=2;
            }
            else break;
            
        }
        return nums[left];
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left < right) {
            int mid = (left + right)/2;
            if(nums[mid] == nums[mid-1]){
                if((mid - left)%2 == 0){
                    right = mid-2;
                }
                else{
                    left = mid+1;
                }
            }
            else if(nums[mid] == nums[mid+1]){
                if((right - mid)% 2 == 0){
                    left = mid+2;
                }
                else right = mid-1;
            }
            else return nums[mid];
        }
        return nums[left];
    }
};

void show(vector<int> vec){
    cout<<vec.size()<<endl;
    for(int i = 0;i < vec.size();i++){
        cout<<vec[i]<<"   ";
    }
    cout<<endl;
}

int main(){
    Solution s;
    vector<int> vec={1,1,2,3,3,4,4,8,8};
    // show(vec);
    cout<<s.singleNonDuplicate(vec)<<endl;
}