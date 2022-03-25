#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
#include<cmath> 
using namespace std;


/** Function
 *  正方形的个数
 * 
 * 
 * */

class DetectSquares {
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        vec.push_back(point);
    }
    
    static bool cmp(vector<int> a, vector<int> b) {
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] < b[1];
    }

    int distance(vector<int> point1, vector<int> point2){
        return sqrt(pow(point1[0] - point2[0], 2) + pow(point1[1] - point2[1], 2));
    }

    bool IsRightAngle(vector<int> a, vector<int> b, vector<int> c){
        double x;
        x = (a[0] - b[0])*(a[0]-c[0])+(a[1]-b[1])*(a[1]-c[1]);
        if(fabs(x) < eps){
            return true;
        }
        return false;
    }

    bool equal(vector<int> point1,vector<int> point2,vector<int> point3,vector<int> point4){
        if(IsRightAngle(point1,point2,point3))
            return false;
        int s1 = distance(point1,point2);
        int s2 = distance(point2,point3);
        int s3 = distance(point1,point4);
        int s4 = distance(point3,point4);

        return (s1 == s2 & s3 == s4 & s1 == s3 ) ;

    }

    int count(vector<int> point) {
        int res = 0;
        if(vec.size()<3)
            return res;
        sort(vec.begin(),vec.end(), cmp);
        if(vec.size()==3)
            return equal(vec[0],vec[1],vec[2],point) == true ? 1 : 0;
        for(int i = 0;i < vec.size()-2;i++)
            for(int j = 1;j< vec.size()-1;j++)
                for(int k = 2;k< vec.size();k++)
                {
                    if(equal(vec[i],vec[j],vec[k],point))
                        res+=1;
                }
        vec.push_back(point);
        return res;
    }
    double eps = 1e-6;
    vector<vector<int>> vec;
};


int main()
{
    
    return 0;
}