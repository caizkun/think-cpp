// summary for linked list, 01/31/2017
#include<list>

//>>> Always first check the corner cases!!

    if (head == NULL) { balabala }
    if (head == NULL || head->next == NULL) { balabala}


//>>> Add a new dummy head if the head node may be changed!

    ListNode *new_head = new ListNode(0);
    new_head->next = head;
    head = new_head; // maybe


//>>> Almost every problem of linked list can be solved with RECURSION!!

//1. Consider what you need to do for the current step;
//2. The subproblem can be taken care of by recusion;
//3. Make sure the two steps are correctly connected.



//>>> TWO POINTERS approach!!

//1. Race between a slow and a fast pointer (overwrite node val, find periodicity, etc)

//2. Find the middle node in the list to partition the list (merge sort a list)

    ListNode *slow = new ListNode(0);
    slow->next = head;
    ListNode *fast = head;
    while (fast != NULL  && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *new_head = slow->next;


//3. Let one pinter run first and then keep the gap between two pinters fixed (find the k-th node from end of list)

    ListNode *new_head = new ListNode(0);
    new_head->next = head;
    ListNode *fast = new_head;
    ListNode *slow = new_head;
    for (int i = 0; i < k && fast != NULL; ++i) {
        fast = fast->next;
    }
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    // slow->next is the k-th node from end of list
