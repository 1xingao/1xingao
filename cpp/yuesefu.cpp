#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void delet(struct node* head,int count)
{
    struct node* p = head->next;
    struct node* left = head;
    while(p){
        if (count = 0){
            struct node* temp = p;
            p = p->next;
            free(temp);
            continue;
        }
        count--;
        p = p->next;
        left = left ->next;
    }
}