// Leetcode question no 86

/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* greater = new ListNode(0);
        ListNode* lessTemp = less;
        ListNode* greaterTemp = greater;
        while(head) {
            if(head->val < x) {
                lessTemp->next = head;
                lessTemp = head;
            } else {
                greaterTemp->next = head;
                greaterTemp = head;
            }
            head = head->next;
        }
        greaterTemp->next = nullptr;
        lessTemp->next = greater->next;
        return less->next;
    }
};