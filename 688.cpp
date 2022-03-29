#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
using namespace std;


/** Function
 * n = 3, k = 2, row = 0, column = 0
 * 0.0625
 * 开始位置[row,column]
 * [row-2,column-1],[row-1,column-2],[row+1,column-2],[row+2,column-1]
 * [row-2,column+1],[row-1,column+2],[row+1,column+2],[row+2,column+1]
 * {{-2,1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}}
 * */
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        double all = pow(8,k);
        printf("%f\r\n",all);
        double res = 4/all;
        printf("%f\r\n",res);
        return res;
    }
};


int main(){
    Solution s;
    s.knightProbability(3,2,0,0);
}