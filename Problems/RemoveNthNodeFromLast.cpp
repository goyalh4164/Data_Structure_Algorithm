class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode * d=head;
        int count=0;
        while (d!=NULL)
        {
            count++;
            d=d->next;
        }
        if(n==1){
            int temp=count-1;
            d=head;
            int i=1;
            while(i!=temp){
                d=d->next;
                i++;
            }
            d->next=NULL;
            return head;
        }
        else if(n==count){
            head=head->next;
            return head;
        }
        d=head;
        int temp=count-n-1;
        while(temp){
            d=d->next;
            temp--;
        }
        d->next=d->next->next;
        return head;


        
    }
};