#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
#include<map>
#include<unordered_map>
using namespace std;


/** Function
 * 
 * 
 * */
class AllOne {
public:
    AllOne() {

    }



    // 添加
    void inc(string key) {
        if(mp.count(key) == 0){
            mp[key] = 1;
        }
        else mp[key]++;
    }
    // 删除
    void dec(string key) {
        if(mp[key] == 1)
            mp.erase(key);
        else mp[key]--;
    }
    // 获取最大值
    string getMaxKey() {

    }
    // 获取最小值
    string getMinKey() {

    }
    
    
    
};


int main(){
    AllOne all;
}