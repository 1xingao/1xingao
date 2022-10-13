/*
 * @Author: xinao_seven_
 * @Date: 2022-10-07 20:52:13
 * @LastEditTime: 2022-10-09 11:47:32
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\leetcode\\code_1311.cpp
 * 
 */

#include<bits/stdc++.h>
using namespace  std;
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> que;
        unordered_set<int> hash;
        
        que.push(id);
        int index = 0;
        while(!que.empty()){
            int n = que.size();
            for(int i=0;i<n;i++){
                int idx= que.front();
                hash.insert(idx);
                que.pop();
                for(int j:friends[idx]){
                    if(!hash.count(j)){
                        que.push(j);
                        hash.insert(j);
                    }
                }
            }
            index++;
            if(index == level){
                break;
            }
        }
        vector<int> fri;
        while(!que.empty()){
            fri.push_back(que.front());
            que.pop();
        }
        unordered_map<string,int> counthash;
        for(int i:fri){
            vector<string> res = watchedVideos[i];
            for(string s:res){
                counthash[s]++;
            }
        }
        vector<pair<string,int>> vt(counthash.begin(),counthash.end());
        sort(vt.begin(),vt.end(),[&](auto &a,auto &b){
            if(a.second == b.second){
                return a.first<b.first;
            }
            return a.second < b.second;
        });
        vector<string> ans;
        for(auto &[first,second]:vt){
            ans.push_back(first);
        }
        return ans;
        
    }
};

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int>temp(nums1.begin(),nums1.end());
        vector<int> res;
        for(int num2 : nums2){
            
            //超时拉
            // for(int i=0;i<nums1.size();i++)
            // {
                
            //     if(nums1[i] > num2){
            //         resnum = nums1[i];
            //         nums1.erase(nums1.begin()+i);
            //         res.push_back(resnum);
            //         break;
            //     }
                
            // }
            
            auto iter = temp.upper_bound(num2);
            if(iter == temp.end()){
                res.push_back(*temp.begin());
                temp.erase(temp.begin());
            }else{
                res.push_back(*iter);
                temp.erase(iter);
            }

            
        }
        return res;
    }
};

//谁先到达谁后到达模拟

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int,int>> arrival;
        vector<pair<int,int>> leaveing;
        //未被使用的椅子
        priority_queue<int,vector<int>,greater<int>> chire;
        
        int n = times.size();
        for(int i=0;i<n;i++){
            arrival.push_back({times[i][0],i});
            leaveing.push_back({times[i][1],i});
        }
        sort(arrival.begin(),arrival.end());
        sort(leaveing.begin(),leaveing.end());
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++){
            chire.push(i);
        }
        int j=0;
        for(auto &[time,persion]:arrival){
            while(j < n&&leaveing[j].first <= time){
                chire.push(hash[leaveing[j++].second]);
            }

            hash[persion] = chire.top();
            if(persion == targetFriend){
                return chire.top();
            }
            chire.pop();
        }
        return -1;

    }
};

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int last = 0;
        sort(logs.begin(),logs.end(),[&](auto &p1,auto&p2){
            return p1[1] < p2[1];
        });
        unordered_map<int,vector<int>> hash;
        int maxres = INT_MIN;
        for(auto &temp:logs){
            hash[temp[1]-last].push_back(temp[0]);
            maxres = max(temp[1]-last,maxres);
            last = temp[1];
            
        }
        if(hash[maxres].size()>1){
            int minres = INT_MAX;
            for(int id:hash[maxres]){
                minres = min(minres,id);
            }
            return minres;
        }
        return hash[maxres][0];

    }
};

class Solution {
public:
    
    int temp  =0;
    
    int dfs(vector<vector<int>>& grid, int k,int row,int col,vector<vector<int>>& us){
        if(row<0||row>=grid.size()||col<0||col>=grid[0].size()){
            return 0;
        }
        if(us[row][col]!=0){
            return us[row][col];
        }
        temp+=grid[row][col];
        if(row == grid.size()-1&&col==grid[0].size()-1){
            if(temp%k==0){
                temp-=grid[row][col];
                return 1;
            }
            temp-=grid[row][col];
            return 0;
        }
        
        int res1 = dfs(grid,k,row+1,col,us);
        int res2 = dfs(grid,k,row,col+1,us);
        temp-=grid[row][col];
        us[row][col] = max(res1+res2,us[row][col]);
        return res1+res2;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vector<vector<int>> us(grid.size(),vector<int>(grid[0].size(),0));
        int res = dfs(grid,k,0,0,us);
        return res;
    }
};
int main(){

    return 0;
}