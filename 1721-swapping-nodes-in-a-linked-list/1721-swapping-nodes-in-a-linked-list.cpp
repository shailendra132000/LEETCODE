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
    ListNode* swapNodes(ListNode* head, int k) {
        int len=0;
        int i=0;
        ListNode* temp=head;
        int val1=-1;
        while(temp!=NULL)
        {
            i++;
            len++;
            if(i==k)val1=temp->val;
            temp=temp->next;
        } 
        int val2=-1;
        temp=head;
        i=0;
        len=len-k;
        while(i<len)
        {
            i++;
            temp=temp->next;
        }
        val2=temp->val;
        temp->val=val1;
        i=0;
        temp=head;
        while(temp!=NULL)
        {
            i++;
            if(i==k)break;
            temp=temp->next;
        }
        temp->val=val2;
        return head;
    }
};