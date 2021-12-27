/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next){return false;}
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast!=slow){
            if(!fast || !fast->next){return false;}
            fast=fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};
// @lc code=end

