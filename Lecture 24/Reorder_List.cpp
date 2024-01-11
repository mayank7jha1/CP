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

        //Logic for the second mid point in case of even length LL.
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL and fast->next != NULL) {
            // fast = fast->next;
            // fast = fast->next;
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // ListNode* ReverseLLRecursively(ListNode* head) {
    //     //Base Condition:
    //     if (head == NULL or head->next == NULL) {
    //         return head;
    //     }

    //     //Recursive Task: Smaller Problem
    //     ListNode* Ultimate_Head = ReverseLLRecursively(head->next);


    //     //EK Bar ka Kaam/ Task that you have to do:

    //     ListNode* Current_head = head;
    //     Current_head->next->next = Current_head;
    //     Current_head->next = NULL;


    //     //Return the Final Answer:
    //     return Ultimate_Head;
    // }

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

    void reorderList(ListNode* head) {
        if (head == NULL or head->next == NULL) {
            return;
        }

        //Break the Current Given LL into 2 Halves:
        //Step 1: Find the Mid
        //Step 2: Break the LL.

        ListNode* m = mid(head);
        ListNode* h = head;

        //h1 is the pointer that will point to the second (half) LL head.
        ListNode* h1 = m->next;

        //Breaking
        m->next = NULL;

        //Reverse the second half LL.

        ReverseLL(h1);
        ListNode* x, *y;


        while (h1 != NULL) {
            x = h->next;
            y = h1->next;

            h->next = h1;
            h = x;
            h1->next = h;
            h1 = y;
        }

    }
};