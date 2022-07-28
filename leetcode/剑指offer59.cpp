#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> res;
        for(int i=0;i<k;i++){
            while(!que.empty()&&que.back() < nums[i]){
                que.pop_back();
            }
            que.push_back(nums[i]);
        }
        res.push_back(que.front());
        while(i<nums.size()){
            if(que.front() == nums[i-k]){
                que.pop_front();
            }
            while(!que.empty()&&que.back() < nums[i]){
                que.pop_back();
            }
            que.push_back(nums[i++]);
            res.push_back(que.front());
        }
        return res;
    }
};