#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
using namespace std;

//TODO

class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        int distance = (numRows - 1)*2;
        int i = 0;
        while(i < s.size())
        {
            res += s[i];
            i = i + distance;
        }
        int j = 1;
        i = 0;
        while(j < numRows& i < s.size()){
            res += s[j];
        }
    }
};


int main(){
    Solution s;
    cout<<s.convert("PAYPALISHIRING",3)<<endl;
}