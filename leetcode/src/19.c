int traverse(struct ListNode* head, int n, bool * flag)
    {
        int count = 0;
        if(NULL != head)
        {
            count = traverse(head->next, n, flag);
        }
        else
        {
            *flag = true;
            return 1;
        }
        
        if(n < count && *flag)
        {
            *flag = false;
            struct ListNode* p = head->next;
            head->next = p->next;
            free(p);
        }
        else
        {
            ++count;
        }
        return count;
    }

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    bool flag = false;
    int count = traverse(head , n , &flag);
    if(n < count && flag)
    {
        struct ListNode* p = head;
        head = head->next;
        free(p);
    }
    return head;
}
