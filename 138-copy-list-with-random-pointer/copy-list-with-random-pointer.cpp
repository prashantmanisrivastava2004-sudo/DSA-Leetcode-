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
        if(head == NULL) return NULL;
        Node* temp = head;
        unordered_map<Node*,Node*>mp;
        while(temp != NULL){
            mp[temp]= new Node(temp->val);
            temp = temp->next;
        }
        Node* temp1 = head;
        while(temp1 != NULL){
            if(temp1->next != NULL){
                mp[temp1]->next=mp[temp1->next];
            }
            if(temp1->random != NULL){
                mp[temp1]->random=mp[temp1->random];
            }
            temp1 = temp1->next;
        }
        return mp[head];
    }
};