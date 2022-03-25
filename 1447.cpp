#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>  
#include<cmath> 
using namespace std;


/** Function
 *  最简分数
 * ["1/2","1/3","1/4","2/3","3/4"]
 * 
 * */
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> vec;
        for(int i = 2;i <= n;i++)
            for(int j = 1; j < i;j++){
                if(__gcd(i,j) == 1)
                    vec.push_back(to_string(j)+"/"+to_string(i));
            }
        return vec;
    }
};

void show(vector<string> vec){
    for(auto str : vec)
        cout<<str<<" "; 
    cout<<endl;
}

int main(){
    Solution s;
    vector<string> vec = s.simplifiedFractions(4);
    show(vec);
}