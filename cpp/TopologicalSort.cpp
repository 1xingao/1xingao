/*
 * @Author: xinao_seven_
 * @Date: 2023-02-01 19:19:38
 * @LastEditTime: 2023-02-02 23:27:34
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\TopologicalSort.cpp
 * 
 */


#include <bits/stdc++.h>
using namespace std;
#define ll long long 

//拓扑排序判断有向无环图
class SolForTopo {
public:
    vector<vector<int>> edges;
    vector<int> indu ;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indu.resize(numCourses);

        for(auto &pre:prerequisites){
            edges[pre[1]].push_back(pre[0]);
            ++indu[pre[0]];
        }

        queue<int> que;
        for(int i=0;i<indu.size();i++){
            if(indu[i] == 0){
                que.push(i);
            }
        }
        int vis = 0;
        while(!que.empty()){
            int pre = que.front();
            que.pop();
            ++vis;
            for(auto &v:edges[pre]){
                indu[v]--;
                if(indu[v] == 0){
                    que.push(v);
                }
            }
            
        }
        return vis == numCourses;
    }
};


class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        // 红蓝分别建图
        vector<vector<int>> redE(n),blueE(n);
        for(auto &red:redEdges){
            redE[red[0]].push_back(red[1]);
        }
        for(auto &blue:blueEdges){
            blueE[blue[0]].push_back(blue[1]);
        }

        queue<pair<int,int>> que; //pair结构为{节点号，下一个要走的颜色(蓝色为1，红色为0)}
        int deep = 0;

        vector<int> r(n,INT_MAX);
        vector<int> b(n,INT_MAX); // 以对应颜色结尾到达该点的deep
        r[0] = 0,b[0] = 0;

        que.push(pair<int,int>{0,0});
        que.push(pair<int,int>{0,1});

        while(!que.empty()){
            int m = que.size();
            deep++;
            for(int i=0;i<m;i++){
                auto node = que.front();
                que.pop();
                int cur = node.first;

                if(node.second == 0) {// 红色
                    for(auto red:redE[cur]){
                        if(deep < r[red]){
                            r[red] = deep;
                            que.push({red,1});
                        }
                    }
                }else{
                    for(auto blue:blueE[cur]){
                        if(b[blue] > deep){
                            b[blue] = deep;
                            que.push({blue,0});
                        }
                    }
                }

            }
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if (b[i] == r[i]&&r[i] == INT_MAX){
                res[i] = -1;
            }else{
                res[i] = min(b[i],r[i]);
            }
        }

        return res;


    }
};

int main()
{
    Solution test;
    vector<vector<int>> temp1{{0,1},{1,2}},temp2;
    auto c = test.shortestAlternatingPaths(3,temp1,temp2);
    cout <<c.size();
    return 0;
}