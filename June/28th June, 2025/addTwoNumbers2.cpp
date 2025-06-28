// Leetcode question 445

/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addLists(ListNode* head1, ListNode* head2, int carry) {
        if(!head1 && !head2 && carry == 0) return nullptr;
        int total = (head1 != nullptr ? head1->val : 0) + (head2 != nullptr ? head2->val : 0) + carry;
        carry = total/10;
        ListNode* newNode = new ListNode(total%10);
        newNode->next = addLists(head1 ? head1->next : nullptr, head2 ? head2->next : nullptr, carry);
        return newNode;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* answer = reverseList(addLists(l1, l2, 0));
        return answer;
    }
};