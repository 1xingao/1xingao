/*
 * @Author: xinao_seven_
 * @Date: 2022-10-17 19:16:41
 * @LastEditTime: 2022-10-17 19:20:20
 * @LastEditors: xinao_seven_
 * @Description: 动态规划
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\dp.cpp
 * 
 */

#include<bits/stdc++.h>

using namespace std;

class Soluation_For_Stock{
    public:

    //stock2

    
    int maxProfit2(vector<int>& prices) {
        int sell =0 ;
        int buy = -prices[0];
        for(int i=1;i<prices.size();i++){
            buy = max(buy,sell-prices[i]);
            sell = max(sell,buy+prices[i]);
        }
        return sell;
    }

    //stock3
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
};