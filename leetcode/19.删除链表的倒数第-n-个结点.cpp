/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    int calc(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = calc(head);
        if(count ==1){
            head = nullptr;
            return head;
        }
        int tem = count - n;
        if(tem ==0){
            return head->next;
        }
        int te=0;
        ListNode* head_re = head->next;
        ListNode* last = head;
        while(head_re){
            
            if(te == tem-1){
                last->next = head_re->next;
                return head;
            }else{
                head_re = head_re->next;
                last = last->next;
                ++te;
            }
        }
        return head;
    }

};
// @lc code=end

