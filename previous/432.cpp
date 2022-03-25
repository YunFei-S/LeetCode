#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
using namespace std;


/** Function
 * 
 * 使用set加map
 * */
class AllOne {
public:

    AllOne() {}
    
    void inc(string key) {
        int count=m[key]++;
        if(count)
            s.erase({count, key});
        s.insert({m[key], key});
    }
    
    void dec(string key) {
        if(m[key]<=0) return;
        int count=m[key]--;
        s.erase({count, key});
        if(m[key])
            s.insert({m[key], key});
    }
    
    string getMaxKey() {
        if(s.empty()) return "";
        return s.rbegin()->second;
    }
    
    string getMinKey() {
        if(s.empty()) return "";
        return s.begin()->second;
    }
    set<pair<int, string>> s;
    unordered_map<string, int> m;
};


int main(){
    AllOne all;
    all.inc("hello");
    all.inc("hello");
    cout<<all.getMaxKey()<<endl;
    cout<<all.getMinKey()<<endl;
    all.inc("leet");
    cout<<all.getMaxKey()<<endl;
    cout<<all.getMinKey()<<endl;
}