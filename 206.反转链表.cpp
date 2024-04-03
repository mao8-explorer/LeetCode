/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        // ListNode* pre = nullptr;
        // ListNode* cur = head;
        // while(cur != nullptr) {
        //     ListNode* temp = cur->next; // 标志要改动的cur->next
        //     // 翻转链表核心
        //     cur->next = pre;
        //     // 翻转完成后 状态转移
        //     pre = cur;
        //     cur = temp;
        // }
        // // return cur; 不对。 cur现在已经指向了null
        // return pre;
        return reverse(nullptr, head);
    }

    ListNode* reverse(ListNode* pre , ListNode* cur){
        if(cur == nullptr) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);
    }
};
// @lc code=end

