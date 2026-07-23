/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        insertInBetween(head);
        connectRandomNodes(head);
        Node * newHead = getDeepCopyOfList(head);
        return newHead;
    }
    void insertInBetween(Node * head)
    {
        Node * temp = head;

        while(temp)
        {
            Node * copyNode = new Node(temp->val);
            Node * nextElement = temp->next;
            copyNode->next = nextElement;
            temp->next = copyNode;
            
            temp = nextElement;
        }
    }
    void connectRandomNodes(Node * head)
    {
        Node * temp = head;

        while(temp)
        {
             Node * copyNode = temp->next;
            if(temp->random)
                copyNode->random = temp->random->next;
            else
                copyNode->random = nullptr;
            
            temp = temp->next->next;
        }
    }
    Node * getDeepCopyOfList(Node * head)
    {
        Node * temp = head;
        Node * dummy = new Node(-1);
        Node * res = dummy;

        while(temp)
        {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};
https://www.youtube.com/watch?v=q570bKdrnlw&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=28
