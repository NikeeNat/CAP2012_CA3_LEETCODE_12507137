
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<int, vector<int>, greater<int>> pq;

        // Put all node values into the priority queue
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];

            while (temp != NULL) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        // Create the merged linked list
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (!pq.empty()) {
            current->next = new ListNode(pq.top());
            pq.pop();

            current = current->next;
        }

        return dummy.next;
    }
};