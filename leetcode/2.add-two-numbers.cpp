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
    void listAdd(ListNode*& tmp, ListNode*& l1, ListNode*& l2, int& carry) {
        int sum = carry;
        if(l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        if(sum > 9) {
            sum -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        tmp->next = new ListNode(sum);
        tmp = tmp->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0); //void node
        ListNode* tmp = result;
        int carry = 0;
        
        while(l1 || l2) {
            listAdd(tmp, l1, l2, carry);
        }
        if(carry) {
            tmp->next = new ListNode(carry);
        }
        
        return result->next;
    }
};