#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
#include<set>
#include<map>
#include<limits.h>
using namespace std;


/** 找到处理最多请求的服务器
 * 
 * 需要一个 flag保存当前的任务数
 * */


class Solution {
public:

    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second < b.second;
    }

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> tasknum(k,1); // 保存任务数量
        vector<int> endtime(k,0); // 保存任务完成时间
        int resnum = 0;
        if(arrival.size() <= k){
            vector<int> res;
            for(int i = 0;i<k;i++)
                res.push_back(i);
            return res;
        }
        // for(int i = 0;i < k;i++){
        //     int time = arrival[i];
        //     endtime[i] = time + load[i];
        // }

        for(int i = k=0; i<arrival.size();i++){
            int time = arrival[i]; // 代表任务到来时间
            int servernum = time%k; // 当前任务服务器
            // 如果当期服务器空闲
            if(endtime[servernum] <= time){
                tasknum[servernum]++;
                resnum = max(tasknum[servernum],resnum);
                endtime[servernum] = time+load[i];
            }
            else{
                // 当遇到最后一个
                int tmpnum = (servernum + 1)%k;
                //循环查找下一个服务器,如果找到空闲的那么就处理,如果未找到没有处理相当于放弃
                while(servernum != tmpnum%k){
                    if(endtime[tmpnum] <= time){
                        tasknum[tmpnum]++;
                        resnum = max(tasknum[tmpnum],resnum);
                        endtime[tmpnum] = time+load[i];
                        break;
                    }
                    tmpnum = (tmpnum+1)%k;
                }
            }
        }
        vector<int> res;
        for(int i = 0;i < tasknum.size();i++)
        {
            if(resnum == tasknum[i])
                res.push_back(i);
        }
            
        return res;
    }
};


int main(){
    Solution s;
    int k = 3;
    vector<int> arrival = {1,2,3,4,5};
    vector<int> load = {5,2,3,3,3};
    vector<int> res = s.busiestServers(k,arrival,load);
    cout<<res.size()<<endl;
}