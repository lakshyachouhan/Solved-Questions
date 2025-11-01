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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode* ansHead = new ListNode(-1);
        ListNode* ansTail = ansHead ;

        ListNode* temp = head ;
        while(temp){
            if(st.find(temp->val) == st.end()){
                ansTail -> next = temp ;
                ansTail = ansTail->next ;
            }

            temp = temp->next ;
        }

        ansTail->next = NULL ;
        return ansHead->next ;
    }
};