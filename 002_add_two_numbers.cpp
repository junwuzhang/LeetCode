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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // brute force method is to construct two numbers, add them up and then convert back to linked list
        // but we can also add digits of the two linked lists directly
        
        // input1: num1.1->num1.2->num1.3
        // input2: num2.1->num2.2->num2.3
        ListNode *start = NULL, *prev = NULL;
        int carryOver = 0;
        // while both linked lists have contents
        while(l1 || l2){
            // if l1 is not none, assign l1->val to num1; same with l2 and num2
            int num1 = l1? l1->val : 0;
            int num2 = l2? l2->val : 0;
            int tempSum = num1 + num2 + carryOver;
            // if tempSum is larger than 10, then there is some carry over and a remainder to be put into the list
            carryOver = tempSum / 10;
            int remainder = tempSum % 10;
            ListNode* currNode = new ListNode(remainder);
            if (!start) start = currNode;
            else if (prev) prev->next = currNode;
            prev = currNode;
            l1 = l1? l1->next : NULL;
            l2 = l2? l2->next : NULL;      
        }
        // if the last calculation results in a carryOver
        if (carryOver > 0){
            ListNode* lastNode = new ListNode(carryOver);
            prev->next = lastNode;
        }
        return start;       
    }
};