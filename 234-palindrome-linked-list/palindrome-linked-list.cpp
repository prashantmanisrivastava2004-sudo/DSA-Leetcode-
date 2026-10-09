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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return true;
        }
    //middle node find karo
      ListNode* slow = head;
      ListNode* fast = head;
      while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
      }
      //second half ko reverse karo
      ListNode* prev = NULL;
      while( slow != NULL){
        ListNode* next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
      }
    // second half ko first half ke value se compare karo, agar same aata hai to palindrome hai otherwise nahi hai.
      ListNode* temp1 = head;
      ListNode* temp2 = prev;
      while(temp2 != NULL){
        if(temp1->val != temp2->val) return false;
        temp1  = temp1->next;
        temp2  = temp2->next;
      }
      return true;
    }
};