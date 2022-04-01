/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int lastflag = 0;//用于保存上一次相加的进位

        ListNode* dis = new ListNode(-1);//虚拟头节点
        ListNode* res = dis;
        while(l1!=nullptr||l2!=nullptr){
            int flag = 0;//临时进位，因为上一次的进位需要重置
            if(l1==nullptr&&l2){
                if(l2->val+lastflag>=10){//进位
                    dis->next = new ListNode(l2->val+lastflag-10);
                    flag = 1;//传递下一次进位
                }else{
                    dis->next = new ListNode(l2->val+lastflag);
                }
                dis = dis->next;
                l2 = l2->next;
                lastflag = 0;
            }
            if(l2==nullptr&&l1){
                if(l1->val+lastflag>=10){
                    dis->next = new ListNode(l1->val+lastflag-10);
                    flag = 1;
                }else{
                    dis->next = new ListNode(l1->val+lastflag);
                }
                dis = dis->next;
                l1 = l1->next;
                lastflag = 0;
            }
            if(l1&&l2){
                int thi = l1->val+l2->val+lastflag;
                if(thi>=10){
                    thi = thi-10;
                    flag = 1;
                }
                dis->next = new ListNode(thi);
                dis = dis->next;
                lastflag = 0;
                l1 = l1->next;
                l2 = l2->next;
            }
            lastflag = flag;
        }
        if(lastflag==1){
            dis->next = new ListNode(1);//如果过最后两个数字相加需要进位
        }
        return res->next;
    }
};
// @lc code=end

