#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
using namespace std;


/** Function
 * 
 * 
 * */
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i = left; i <= right; i++){
            int tmp = i;
            bool flag = true;
            while(tmp > 0){
                int num = tmp % 10;
                if(num == 0 || i % num != 0)
                {
                    flag = false;
                    break;
                }
                tmp /= 10;
            }
            if(flag)
                result.push_back(i);
        }
        return result;
    }
};

void show(vector<int> vec){
    for(int num : vec)
        cout<<num<<",";
    cout<<endl;
}

int main(){
    Solution s;
    
    show(s.selfDividingNumbers(1,22));
}