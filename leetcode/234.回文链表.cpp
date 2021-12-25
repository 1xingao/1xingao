/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> cal;
        
        while (head!= nullptr)
        {
            cal.push_back(head->val);
            head = head->next;
        }
        int end = cal.size()-1;
        for(int i = 0; i<end-i;++i){
            if(cal[i] != cal[end-i])
                return false;
        }
        return true;
    }
};
// @lc code=end

