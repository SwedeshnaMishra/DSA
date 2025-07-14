//143. Reorder List

//You are given the head of a singly linked-list. The list can be represented as:
// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// Example 1:
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

// Example 2:
// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]
 
// Constraints:
// The number of nodes in the list is in the range [1, 5 * 104].
// 1 <= Node.val <= 1000

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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* second = slow -> next;
        ListNode* prev = slow->next = nullptr;
        while(second != nullptr) {
        ListNode* tmp = second->next;
        second -> next = prev;
        prev = second;
        second = tmp;   
        }
        ListNode* first = head;
        second = prev;
        while (second != nullptr){
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;
        first -> next = second;
        second -> next = tmp1;
        first = tmp1;
        second = tmp2;
        }
    }
};
