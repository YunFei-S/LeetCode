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
#if 0
class Solution {
public:

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> rowmin; // 行的最小值
        vector<int> rankmax; // 列的最大值
        for(int i = 0;i < matrix.size();i++){
            int minnum = INT_MAX;
            for(int j = 0;j < matrix[i].size();j++)
                minnum = min(matrix[i][j],minnum);
            rowmin.push_back(minnum);
        }
        // show(rowmin);
        for(int i = 0;i< matrix[0].size();i++){
            int maxnum = INT_MIN;
        for(int j = 0; j< matrix.size();j++){
            maxnum = max(matrix[j][i],maxnum);
        }       
            rankmax.push_back(maxnum);
        }
        // show(rankmax);
        vector<int> res = cmp(rowmin,rankmax);
        // show(res);
        return res;
    }    
    vector<int> cmp(vector<int> vec1,vector<int>vec2){
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        int i = 0,j = 0;
        vector<int> res;
        while(i < vec1.size() && j<vec2.size()){
            if(vec1[i] == vec2[j])
            {
                res.push_back(vec1[i]);
                i++;j++;
            }
            else if(vec1[i] < vec2[j]){
                i++;
            }
            else if(vec1[i] > vec2[j]){
                j++;
            }
        }
        return res;
    }
    void show(vector<int> vec1){
        for(int i = 0; i < vec1.size();i++)
            cout<<vec1[i]<<" ";
        cout<<endl;
    }
};
#endif

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix){
        int row = matrix.size(); // 行
        int col = matrix[0].size(); // 列
        vector<int> rownum(row,0);
        vector<int> colnum(col,0);
        vector<int> res;
        for(int i = 0; i < row; i++)
            for(int j = 0;j < col;j++){
                if(matrix[i][j] < matrix[i][rownum[i]])
                    rownum[i] = j;
                if(matrix[i][j] > matrix[colnum[j]][j])
                    colnum[j] = i;
            }
        for(int i = 0;i < row;i++)
        {
            if(i == colnum[rownum[i]])
                res.push_back(matrix[i][rownum[i]]);
        }
        return res;
    }
};

/*
[[3,7,8],[9,11,13],[15,16,17]]
[[1,10,4,2],[9,3,8,7],[15,16,17,12]]
*/
int main(){
    Solution s;
    // vector<vector<int>> vec={{3,7,8},{9,11,13},{15,16,17}};
    vector<vector<int>> vec={{1,10,4,2},{9,3,8,7},{15,16,17,12}};
    s.luckyNumbers(vec);
}