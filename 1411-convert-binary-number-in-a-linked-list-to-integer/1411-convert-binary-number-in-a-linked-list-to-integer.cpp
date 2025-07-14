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
    int getLen(ListNode* head){

        if(!head)
            return 0 ;

        return 1 + getLen(head->next);
    }

    int getDecimalValue(ListNode* head) {
        
        int l = getLen(head);

        int p = 1 ;
        for(int i=0; i<l-1; i++)
            p *= 2 ;

        int ans = 0 ;
        ListNode* temp = head ;
        while(temp){

            ans += p * temp->val ;
            p /= 2 ;
            temp = temp->next ;
        }

        return ans ;
    }
};