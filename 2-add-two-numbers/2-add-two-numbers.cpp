class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr) return l1 == nullptr ? l2: l1;        
        int c = 0;
        ListNode* tmp1 = l1; ListNode* tmp2 = l2;
        ListNode* ans = new ListNode(0); ListNode* tmp = ans;
        ListNode* ptmp = ans;
        while(tmp1 != nullptr || tmp2 != nullptr) {
            int sum = c;
            if(tmp1 != nullptr) {
                sum+=tmp1->val;
                tmp1 = tmp1->next;
            }
            if(tmp2 != nullptr) {
                sum+=tmp2->val;
                tmp2 = tmp2->next;
            }
            tmp->val = sum%10;
            c = sum/10;
            ptmp = tmp;
            tmp->next = new ListNode(0);
            tmp = tmp->next;
        }
        if(c != 0) {
            ptmp->next = new ListNode(c);
        } else {
            ptmp->next = nullptr;
            delete(tmp);
        }
        return ans;
    }
};