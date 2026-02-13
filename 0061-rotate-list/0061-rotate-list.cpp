class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;

        // Step 1: find length
        int len = 1;
        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }

        // Step 2: reduce k
        k = k % len;
        if(k == 0) return head;

        // Step 3: make circular
        tail->next = head;

        // Step 4: find new tail
        int steps = len - k;
        ListNode* newTail = head;
        for(int i = 1; i < steps; i++){
            newTail = newTail->next;
        }

        // Step 5: break circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};
