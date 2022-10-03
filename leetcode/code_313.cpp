/*
 * @Author: xinao_seven_
 * @Date: 2022-10-02 10:26:45
 * @LastEditTime: 2022-10-02 15:37:37
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\leetcode\\code_313.cpp
 * 
 */

#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int left = 0,top =0 ,xia = 2,right = 2;
        int res = 0;
        for(;xia<grid.size();xia++,top++){
            for(int right = 2,left = 0;right < grid[0].size();right++,left++){
                int sum = 0;
                for(int i=left;i<=right;i++){
                    for(int j=top;j<=xia;j++){
                        sum += grid[j][i];
                    }
                }
                sum -= grid[top+1][left];
                sum -= grid[top+1][right];
                res = max(res,sum);
            }
            
        }
        return res;
    }
};

class Solution1 {
public:
    pair<vector<int>,int> getbit(int num)
    {
        int num1 = num;
        vector<int> temp;
        while(num){
            temp.push_back(num%2);
            num /= 2;
        }
        num = num1;
        int sum = 0;
        while(num){
            sum += num%2==1;
            num/=2;
        }
        return {temp,sum};
    }
    int minimizeXor(int num1, int num2) {
        auto res1 = getbit(num1);
        auto res2 = getbit(num2);
        
        if(res1.first.size() < res2.first.size()){
            for(int i=0;i<res2.first.size() - res1.first.size();i++){
                res1.first.push_back(0);
            }
        }
        int diff = res2.second - res1.second;
        if(diff == 0){
            return num1;
        }
        if(diff < 0){
            diff = -diff;
            for(int i=0;i<res1.first.size()&&diff>0;i++){
                if(res1.first[i] == 0){
                    res1.first[i] = 1;
                    diff--;
                }
            }

        }else{
            
            for(int i=0;i<res1.first.size()&&diff>0;i++){
                if(res1.first[i] == 1){
                    res1.first[i] = 0;
                    diff--;
                }
            }
        }
        int res = 0;
        int index = 0;
        for(int i=0;i<res1.first.size();i++){
            res += res1.first[i]*pow(2,index++);
        }
        return res;



    }
};

static const int MAXP = 30;
void bits_fun()
{
    int num1 = 1;
    //求num1的二级制表示
    int A[MAXP + 1] = {0};
    for (int i = MAXP; i >= 0; i--) A[i] = num1 >> i & 1;
    for(int i=0;i<MAXP;i++){
        cout<<A[i];
    }
    //从左往右是低位->高位

}


int main()
{
    Solution1 test;
    bits_fun();

    return 0;
}