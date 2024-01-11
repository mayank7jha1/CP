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


    ListNode* mid(ListNode* head) {
        if (head == NULL or head->next == NULL) {
            return head;
        }

        //Logic for the first mid point in case of even length LL.
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL and fast->next != NULL) {
            // fast = fast->next;
            // fast = fast->next;
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    void ReverseLL(ListNode* &head) {
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* n;

        while (current != NULL) {
            n = current->next;
            current->next = prev;
            prev = current;
            current = n;
        }
        head = prev;
    }

    bool isPalindrome(ListNode* head) {

        ListNode* m = mid(head);
        ListNode* h = head;
        ListNode* h1 = m->next;
        m->next = NULL;
        ReverseLL(h1);


        while (h != NULL and h1 != NULL) {
            if (h->val != h1->val) {
                return false;
            }

            h = h->next;
            h1 = h1->next;
        }

        return true;
    }
};