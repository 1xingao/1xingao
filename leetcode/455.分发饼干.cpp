// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem455.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int began = 0;
        for(int i= 0;i<s.size();++i){
            //if(began=s.size()) {return sat;}
            if(g[began]<=s[i]&&began<g.size()){
                began++;
            }
        }
        return began;
    }
};
// @lc code=end

