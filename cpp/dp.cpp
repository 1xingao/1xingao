/*
 * @Author: xinao_seven_
 * @Date: 2022-10-17 19:16:41
 * @LastEditTime: 2022-11-06 12:57:12
 * @LastEditors: xinao_seven_
 * @Description: 动态规划
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\dp.cpp
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Soluation_For_Stock
{
public:
    // stock2

    int maxProfit2(vector<int> &prices)
    {
        int sell = 0;
        int buy = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            buy = max(buy, sell - prices[i]);
            sell = max(sell, buy + prices[i]);
        }
        return sell;
    }
    //test
    // stock3
    int maxProfit3(vector<int> &prices)
    {
        vector<int> dp1(prices.size()); //在第i天一次买入最大收益
        vector<int> dp2(prices.size()); //在第i天一次卖出最大收益
        vector<int> dp3(prices.size()); //在第i天二次买入最大收益
        vector<int> dp4(prices.size()); //在第i天二次卖出最大收益
        dp1[0] = dp3[0] = -prices[0];
        dp2[0] = dp4[0] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp1[i] = max(dp1[i - 1], -prices[i]);
            dp2[i] = max(dp1[i - 1] + prices[i], dp2[i - 1]);
            dp3[i] = max(dp2[i - 1] - prices[i], dp3[i - 1]);
            dp4[i] = max(dp3[i - 1] + prices[i], dp4[i - 1]);
        }
        return dp4[prices.size() - 1];
    }
    //滚动数组优化版本，当一个数改成一维数组就是股票四的问题
    int maxProfit_1(vector<int> &prices)
    {
        int dp1, dp2, dp3, dp4;
        dp1 = dp3 = -prices[0];
        dp2 = dp4 = 0;
        for (int price : prices)
        {
            dp1 = max(dp1, -price);
            dp2 = max(dp2, dp1 + price);
            dp3 = max(dp2 - price, dp3);
            dp4 = max(dp4, dp3 + price);
        }
        return dp4;
    }

    //将III里面多个数组压缩成两个一维数组（滚动数组）
    //参考股票三优化版本，下边
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.size() == 0 || k == 0)
        {
            return 0;
        }
        vector<int> buy(k);  //第j次持有股票
        vector<int> sell(k); //不持有股票
        for (int i = 0; i < k; i++)
        {
            buy[i] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++)
        {
            //第一次买卖的时间
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max(sell[0], buy[0] + prices[i]);
            for (int j = 1; j < k; j++)
            {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]); // pricrs中参数为i是因为不确定第一次有没有持有该股票
                //第一次是取最大收益，所以后续每次都要尝试持有当前股票
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k - 1];
    }

    //数位dp
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        auto s = to_string(n);
        int m = s.length(), dp[m];
        memset(dp, -1, sizeof(dp)); // dp[i] = -1 表示 i 这个状态还没被计算出来
        // i 表示当前填数字的位数， islimit表示是否受到前一个数字的限制（前一个数字等于s[i-1]）
        //  isnum 表示是否可以不填，前面都是前导零的情况
        function<int(int, bool, bool)> f = [&](int i, bool is_limit, bool is_num) -> int
        {
            if (i == m)
                return is_num; // 如果填了数字，则为 1 种合法方案
            if (!is_limit && is_num && dp[i] >= 0)
                return dp[i]; // 在不受到任何约束的情况下，返回记录的结果，避免重复运算
            int res = 0;
            if (!is_num) // 前面不填数字，那么可以跳过当前数位，也不填数字
                // is_limit 改为 false，因为没有填数字，位数都比 n 要短，自然不会受到 n 的约束
                // is_num 仍然为 false，因为没有填任何数字
                res = f(i + 1, false, false);
            char up = is_limit ? s[i] : '9'; // 根据是否受到约束，决定可以填的数字的上限
            // 注意：对于一般的题目而言，如果这里 is_num 为 false，则必须从 1 开始枚举，由于本题 digits 没有 0，所以无需处理这种情况
            for (auto &d : digits)
            { // 枚举要填入的数字 d
                if (d[0] > up)
                    break; // d 超过上限，由于 digits 是有序的，后面的 d 都会超过上限，故退出循环
                // is_limit：如果当前受到 n 的约束，且填的数字等于上限，那么后面仍然会受到 n 的约束
                // is_num 为 true，因为填了数字
                res += f(i + 1, is_limit && d[0] == up, true);
            }
            if (!is_limit && is_num)
                dp[i] = res; // 在不受到任何约束的情况下，记录结果
            return res;
        };
        return f(0, true, false);
    }

    int countSpecialNumbers(int n)
    {
        auto s = to_string(n);
        int m = s.length(), dp[m][1 << 10];
        memset(dp, -1, sizeof(dp));
        // dp[i] = -1 表示 i 这个状态还没被计算出来
        // i 表示当前填数字的位数， islimit表示是否受到前一个数字的限制（前一个数字等于s[i-1]）
        // isnum 表示是否可以不填，前面都是前导零的情况,mask表示前面的数字序列
        function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit, bool is_num) -> int
        {
            if (i == m)
                return is_num;
            if (!is_limit && is_num && dp[i][mask] >= 0)
                return dp[i][mask];
            int res = 0;
            if (!is_num)
                res = f(i + 1, mask, false, false);                                // 可以跳过当前数位
            for (int d = 1 - is_num, up = is_limit ? s[i] - '0' : 9; d <= up; ++d) // 枚举要填入的数字 d
                if ((mask >> d & 1) == 0)                                          // d 不在 mask 中
                    res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
            if (!is_limit && is_num)
                dp[i][mask] = res;
            return res;
        };
        return f(0, 0, true, false);
    }
};
