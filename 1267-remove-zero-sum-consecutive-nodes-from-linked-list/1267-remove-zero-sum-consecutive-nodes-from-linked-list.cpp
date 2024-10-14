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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> prefixSumMap;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        int prefixSum = 0;
        ListNode* cur = dummy;

        while (cur) {
            prefixSum += cur->val;
            prefixSumMap[prefixSum] = cur;
            cur = cur->next;
        }

        cur = dummy;
        prefixSum = 0;
        while (cur) {
            prefixSum += cur->val;
            cur->next = prefixSumMap[prefixSum]->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};
