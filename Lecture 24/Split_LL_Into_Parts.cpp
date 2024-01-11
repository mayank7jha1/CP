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

    int Length(ListNode* head) {
        int ans = 0;
        while (head != NULL) {
            ans++;
            head = head->next;
        }
        return ans;
    }


    vector<ListNode*> splitListToParts(ListNode* root, int k) {

        int n = Length(root);
        ListNode* head = root;
        int Min_Element_In_Each_Part = n / k;
        int ExtraElements = n % k;

        //Count Tell us we the part we are currently filling.
        int count = 1;
        //This is the ultimate vector that will contain the head of all the parts
        vector<ListNode*>ans;


        if (Min_Element_In_Each_Part == 0) {
            // k > n; That Means every part can atmax have 1 element only.

            for (int i = 0; i < k; i++) {
                if (head != NULL) {

                    ListNode* n = head->next;
                    head->next = NULL;
                    ans.push_back(head);
                    head = n;

                } else {
                    ans.push_back(NULL);
                }
            }
        } else {
            //k<=n
            while (head != NULL) {

                ans.push_back(head);
                int x;

                if (ExtraElements > 0) {
                    x = 1;
                    ExtraElements--;
                } else {
                    x = 0;
                }

                //You have to break the current ll for the current part.

                for (int i = 1; i < Min_Element_In_Each_Part + x; i++) {
                    head = head->next;
                }

                //You are currently standing at the point from where you want to end the
                //current part.
                ListNode* n = head->next;
                head->next = NULL;
                head = n;


                count++;

                //Below Process just Speeds up your code.
                if (count == k) {
                    //This means you are trying to fill the last part.
                    ans.push_back(head);
                    break;
                }
            }
        }

        return ans;
    }
};