#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<limits.h>
using namespace std;


/** Function
 * 找出星型图的中心节点
 * 
 * */
class Solution {
public:
    int findCenter(vector<vector<int>>& edges){
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        if(edges[0][1] == edges[1][0] || edges[0][1] == edges[1][1])
            return edges[0][1];
    }
    // int findCenter(vector<vector<int>>& edges) {
    //     vector<int> vec(edges.size()+2,0);
    //     for(int i = 0; i < edges.size();i++){
    //         vec[edges[i][0]]++;
    //         vec[edges[i][1]]++;
    //     }
    //     for(int i = 0; i < vec.size();i++)
    //         if(vec[i] == edges.size())
    //             return i;
    //     return 0;
    // }
};


int main(){
    Solution s;
    vector<vector<int>> edges{{1,2},{2,3},{4,2}};
    cout<<s.findCenter(edges)<<endl; 
}