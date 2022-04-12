#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<map>
#include<unordered_map>
#include<limits.h>
using namespace std;


/** Function
 * 
 * 
 * */
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<double, double> m;
        // 读取每个值保存
        for (auto& num : A) {
            m[num]++;
        }
        for (auto& [c, d] : m) {
            if (d < 0) return false;
            if (d == 0) continue;
            if (c > 0) {
                // 判断值是否存在
                if (!m.count(c * 2)) return false;
                // 存在减去值的数量
                m[c * 2] -= d;
            } else {
                if (!m.count(c / 2.0)) return false;
                m[c / 2.0] -= d;
            }
        }
        return true;
    }
};


int main(){
    vector<int> vec1 ={3,1,3,6};
    vector<int> vec2 ={2,1,2,6};
    vector<int> vec3 ={4,-2,2,-4};
    vector<int> vec4 = {2,4,0,0,8,1};
    Solution s;
    cout<<s.canReorderDoubled(vec1)<<endl;
    cout<<s.canReorderDoubled(vec2)<<endl;
    cout<<s.canReorderDoubled(vec3)<<endl;
    cout<<s.canReorderDoubled(vec4)<<endl;
}