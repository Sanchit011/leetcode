class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* ans = new ListNode();
        ListNode* curr = ans;
        while(p1 != NULL || p2 != NULL){
            int x = carry;
            if(p1 != NULL){
                x += p1->val;
                p1 = p1->next;
            }
            if(p2 != NULL){
                x += p2->val;
                p2 = p2->next;
            }
            curr->next = new ListNode(x%10);
            curr = curr->next;
            carry = x/10;
        }
        if(carry != 0){
            curr->next = new ListNode(carry);
        }
        ans = ans->next;
        return ans;
    }
};