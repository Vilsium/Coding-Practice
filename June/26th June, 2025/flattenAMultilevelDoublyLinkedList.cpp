// Leetcode question 430

/*
You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    Node* solve(Node* head) {
        Node* curr = head;
        Node* last = head;
        while(curr) {
            Node* next = curr->next;
            if(curr->child) {
                Node* childHead = curr->child;
                Node* childTail = solve(curr->child);
                curr->next = childHead;
                childHead->prev = curr;
                if(next) {
                    childTail->next = next;
                    next->prev = childTail;
                }
                curr->child = nullptr;
                last = childTail;
            } else last = curr;
            curr = next;
        }
        return last;
    }
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        solve(head);
        return head;
    }
};