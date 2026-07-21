// nned to understamd completely -- not fully understood!!!!
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = head;
        ListNode* prevNode = NULL;
        ListNode* kthNode = new ListNode(-1);

        if(head == NULL || head->next == NULL)
        return head;

        while(temp != NULL)
        {
            kthNode = findKthNode(temp, k);

            if(kthNode == NULL)
            {
                if(prevNode) prevNode->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;

            //now reverse the list of size k
            reverseList(temp);
            if(head == temp)
            {
                head = kthNode;
            }
            else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;

        }
        return head;
    }
    ListNode* findKthNode(ListNode* temp, int k)
    {
        k--;
        while(temp && k>0)
        {
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* temp = head;
        ListNode* front = nullptr;

        while (temp != NULL) {
        front = temp->next;   // Save next node
        temp->next = prev;    // Reverse the link
        prev = temp;          // Move prev forward
        temp = front;         // Move current forward
    }
        return prev;
    }
};
