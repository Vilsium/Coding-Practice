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
    int getLength(ListNode* head) {
        int result = 0;
        while(head) {
            result++;
            head = head->next;
        }
        return result;
    }
    ListNode* pad(ListNode* head, int qty) {
        while(qty--) {
            ListNode* temp = new ListNode(0, head);
            head = temp;
        }
        return head;
    }
    void addLists(ListNode* head1, ListNode* head2, int& carry, ListNode*& result) {
        if(!head1 && !head2 && carry == 0) return ;
        ListNode* newNode = nullptr;
        addLists(head1 ? head1->next : nullptr, head2 ? head2->next : nullptr, carry, newNode);
        int total = (head1 != nullptr ? head1->val : 0) + (head2 != nullptr ? head2->val : 0) + carry;
        carry = total/10;
        result = new ListNode(total%10);
        result->next = newNode;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverseList(l1);
        // l2 = reverseList(l2);
        int n1 = getLength(l1);
        int n2 = getLength(l2);
        if(n1 < n2) l1 = pad(l1, n2-n1);
        else if(n2 < n1) l2 = pad(l2, n1-n2);
        int carry = 0;
        ListNode* answer = nullptr;
        addLists(l1, l2, carry, answer);
        if(carry) {
            ListNode* temp = new ListNode(carry, answer);
            answer = temp;
        }
        return answer;
    }
};