#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
using namespace std;


/** 强密码检测器
 * 如果一个密码满足下述所有条件，则认为这个密码是强密码：
 * 由至少 6 个，至多 20 个字符组成。
 * 至少包含 一个小写 字母，一个大写 字母，和 一个数字 。
 * 同一字符 不能 连续出现三次 (比如 "...aaa..." 是不允许的, 但是 "...aa...a..." 如果满足其他条件也可以算是强密码)。
 * 
 * a 5
 * aA1 3
 * 1337C0d3 0
 * */
class Solution{
public:
    int strongPasswordChecker(string password) {
        bool hasnum = false;   // 数字  
        bool haslower = false; // 小写字母
        bool hasupper = false; // 大写字母
        int res = 0;           // 操作数
        char last = '.';// 给一个不符合的初值
        int i = 0;
        for(char c : password){
            if(isdigit(c))
                hasnum = true;
            else if(islower(c))
                haslower = true;
            else if(isupper(c))
                hasupper = true;
        }
        while(i < password.length()) {
            if(password[i] != last)
            {
                last = password[i];
            }
            else {   
                int num = 0;
                int modCount = 0; // 此时运行相同的数量
                while(password[i+1] == last & i < password.size()){
                    i++;
                    modCount++;
                }
                if(modCount > 0){
                    res += modCount;
                }     
            }  
            i++;
        }
        int boolnum = 0;
        if(!hasnum)
            boolnum++;
        if(!haslower)
            boolnum++;
        if(!hasupper)
            boolnum++;
        
        if(password.size() < 6){
            if(password.size() == 5)
                if(res == 1)
                    return res;
            res = 6-password.size();
        }
        else if(password.size() > 20)
            res += password.size() -20;
        // cout<<"res = "<<res<<",boolnum = "<<boolnum<<endl;
        res = max(res,boolnum);
        
        return res > 0 ? res : 0;
    }

};


// class Solution {
// public:
//     int strongPasswordChecker(string password) {
//         bool hasnum = false;   // 数字  
//         bool haslower = false; // 小写字母
//         bool hasupper = false; // 大写字母
//         int res = 0;           // 操作数
//         char last = '.';       // 给一个不符合的初值
//         int i = 0;
//         while(i < password.length()) {
//             if(password[i] != last)
//             {
//                 if(isdigit(password[i]))
//                     hasnum = true;
//                 else if(isupper(password[i]))
//                     hasupper = true;
//                 else if(islower(password[i]))
//                     haslower = true;
//                 last = password[i];
//             }
//             else {   
//                 int num = 0;
//                 int modCount = 0; // 此时运行相同的数量
//                 while(password[i+1] == last & i < password.size()){
//                     i++;
//                     modCount++;
//                 }
//                 if(modCount > 0){
//                     res += modCount;
//                 }     
//             }
                
//             i++;
//         }
//         int boolnum = 0;
//         if(!hasnum){
//             boolnum++;
//             // cout<<"!hasnum"<<endl;
//             }
            
//         if(!haslower)
//         {
//             boolnum++;
//             // cout<<"!haslower"<<endl;
//         }
//         if(!hasupper)
//         {
//             boolnum++;
//             // cout<<"!hasupper"<<endl;
//         }
        
//         if(password.size() < 6){
//             res += 6 - password.size();
//         }
//         else if(password.size() > 20)
//             res += password.size() -20;
//         cout<<"res = "<<res<<",boolnum = "<<boolnum<<endl;
//         res = max(res,boolnum);
        
//         return res > 0 ? res : 0;
//     }
// };


int main(){
    string str1 = "a"; //5
    string str2 = "aA1"; //3
    string str3 = "1337C0d3"; // 0
    string str4 = "aaa111"; // 2
    string str5 = "aa123"; // 1
    string str6 = "aaaB1"; // 1
    string str7 = "aA1"; // 3
    Solution s;
    cout<<s.strongPasswordChecker(str1)<<endl;
    cout<<s.strongPasswordChecker(str2)<<endl;
    cout<<s.strongPasswordChecker(str3)<<endl;
    cout<<s.strongPasswordChecker(str4)<<endl;
    cout<<s.strongPasswordChecker(str5)<<endl;
    cout<<s.strongPasswordChecker(str6)<<endl;
    cout<<s.strongPasswordChecker(str7)<<endl;
}