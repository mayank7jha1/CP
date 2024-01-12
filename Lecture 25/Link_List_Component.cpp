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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int>s;

        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        int components = 0;
        while (head != NULL) {

            if (s.count(head->val) == 1 and (head->next == NULL or s.count(head->next->val) == 0)) {
                components++;
            }
            head = head->next;
        }

        return components;
    }
};


// .count(x) == = 0 if element is not present and 1 if element is present.
// .find(x)=== Iterator to the element if element is present and if element is not present
// .end() return