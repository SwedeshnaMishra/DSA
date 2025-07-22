// 23. Merge k Sorted Lists

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6

// Example 2:
// Input: lists = []
// Output: []

// Example 3:
// Input: lists = [[]]
// Output: []
 
// Constraints:
// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.

class Solution {    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;

        while (true) {
            int minNode = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (!lists[i]) continue;
                if (minNode == -1 || lists[minNode]->val > lists[i]->val) {
                    minNode = i;
                }
            }

            if (minNode == -1) break;
            cur->next = lists[minNode];
            lists[minNode] = lists[minNode]->next;
            cur = cur->next;
        }
        return res->next;
    }
};
