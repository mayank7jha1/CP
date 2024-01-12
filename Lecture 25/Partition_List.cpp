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
    ListNode* partition(ListNode* head, int x) {
        ListNode* n = NULL, *b = NULL, *c = NULL;
        ListNode* bh = NULL, *ch = NULL;

        while (head != NULL) {
            n = head->next;

            if (head->val < x) {
                /*
                    THis is the very first node of the smaller LL.
                    or THis is not the first node.
                */

                if (c == NULL) {
                    //This the very first node and you have to make it as ch.
                    ch = c = head;
                    head->next = NULL;
                    head = n;
                } else {
                    //This means the current element is not the first element.

                    c->next = head;
                    head->next = NULL;
                    c = head;
                    head = n;
                }


            } else {
                if (b == NULL) {
                    //This is the very first node of my bigger element LL.

                    b = bh = head;
                    head->next = NULL;
                    head = n;
                } else {
                    //This means the current element is not the first element.
                    b->next = head;
                    head->next = NULL;
                    b = head;
                    head = n;
                }
            }
        }


        //If you are standing here that means you have divided your LL into
        //two halves.

        if (c != NULL) {
            c->next = bh;
            return ch;
        } else {

            return bh;
        }

    }
}






// 1->4->3->2->5->2


//ch----->1->NULL;
//c--->1

//head----->n(4);

// 1->NULL;
// 4->3->2->5->2->NULL;

//ch=c---->1
//head------>4;



//head------>NULL
//ch-->1
//c--->2
//bh--->4
//b---->5


//1->2->2-->NULL;
//4->3->5-->NULL;

//NULL