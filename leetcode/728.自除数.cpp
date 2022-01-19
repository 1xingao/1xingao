/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> re;
        for(int i = left;i<=right;i++){
            int tempn = i;
            int pec = 0;
            
            while(i!=0){
                int d = i%10;
                if(d==0){
                    pec = 1;
                    break;
                }
                if(tempn%d!=1){
                    pec=1;
                }
                i/=10;
            }
            
            if(pec == 0){
                re.push_back(tempn);
            }
        }
        return re;
    }
};
// @lc code=end

