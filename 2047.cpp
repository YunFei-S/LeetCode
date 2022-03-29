#include<iostream>
#include<string>
#include<vector>
using namespace std;

/**
 * @brief 单词中的有效个数
 * 仅由小写字母、连字符和/或标点（不含数字）。
 * 至多一个 连字符 '-' 。如果存在，连字符两侧应当都存在小写字母（"a-b" 是一个有效单词，但 "-ab" 和 "ab-" 不是有效单词）。
 * 至多一个 标点符号。如果存在，标点符号应当位于 token 的 末尾 。
 * 几个有效单词的例子："a-b."、"afad"、"ba-c"、"a!" 和 "!" 。
 */
// cat and  dog
// !this  1-s b8d!
// alice and  bob are playing stone-game10

class Solution {
public:
    bool func(string str){
        // cout<<str<<endl;
        // return true;
        bool hash = false;
        for(int i = 0; i < str.length(); i++){
            if(isdigit(str[i]))
                return false;
            else if(str[i] == '-')
            {
                if(hash || i == 0 || i == str.length()-1)
                    return false;
                if(!islower(str[i-1]) || !islower(str[i+1]))
                    return false;
                hash = true;
            }
            else if(str[i] == '!' || str[i] == '.' || str[i] ==',')
            {
                if(i != str.length()-1)

                
                    return false;
            }
        }
        return true;
    }

    int countValidWords(string sentence) {
        int n = sentence.length();
        int res = 0;
        for(int i = 0; i < n;){
            while(isspace(sentence[i]))
                i++;
            if(i >= n)
                break;
            int j = i;
            while(sentence[j] != ' ')
                j++;
            if(func(sentence.substr(i,j-i+1)))
                res++;
            i = j;
        }
        return res;
    }
};

int main() {
    Solution so;

    cout<<so.countValidWords("alice and  bob are playing stone-game10")<<endl;
    
    return 0;
}