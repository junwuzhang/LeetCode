/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (45.78%)
 * Total Accepted:    516.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // two pointers pointing at start of each linked list
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* head = NULL;
        // process the start of the linked list (add head, and also effectively keep l1 and l2 where )
        if (l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        // process remainder of linked list, first connect pointer p to head
        ListNode* p = head;
        while(l1!=NULL && l2!=NULL){
            // compare two lists
            if (l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            // move forward
            p = p->next;
        }
        // if any linked list has unprocessed tails
        if (l1 != NULL){
            p->next = l1;
        } else {
            p->next = l2;
        }
        return head;
    }
};  

