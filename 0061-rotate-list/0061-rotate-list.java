class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) return head;

        // Step 1: Calculate the length of the list
        ListNode curr = head;
        int length = 1; // at least 1 node
        while (curr.next != null) {
            curr = curr.next;
            length++;
        }

        // Step 2: Connect the tail to the head to make it circular
        curr.next = head;

        // Step 3: Normalize k
        k = k % length;
        if (k == 0) {
            curr.next = null; // break the circle
            return head;
        }

        // Step 4: Find the new tail = length - k - 1 steps from head
        ListNode newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail.next;
        }

        // Step 5: Set the new head and break the circle
        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}
