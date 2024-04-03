/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
// struct ListNode 
// {
//     int val;
//     ListNode *next;
//     ListNode(): val(0), next(nullptr){}
//     ListNode(int x): val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next): val(x), next(next) {}
// };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    // 创建一个虚拟的首结点， 部署一致的逻辑
    ListNode * dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *current = dummyHead; 

    while(current->next != nullptr){
        if(current->next->val == val){
            ListNode *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else{
        current = current->next; //移动节点 cuurent本体开头
        }
    }
    head = dummyHead->next;
    delete dummyHead;
    return head;
    }
};
// @lc code=end