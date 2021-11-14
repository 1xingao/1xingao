// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem202.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int faman(int n)
    {
        int s=0;
        while(n>0){
            int temp = n%10;
            n/=10;
            s+=temp*temp;
        }
        return s;
    }
    bool isHappy(int n) {
        //快慢指针类似龟兔赛跑，最终乌龟总是回追上兔子
        int fast =n ,slow =n;
        do{
            slow = faman(slow);
            fast = faman(fast);
            fast = faman(fast);
        }while(fast!=slow);
        return slow==1;
    }
};
// @lc code=end

