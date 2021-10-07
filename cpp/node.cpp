#include<stdio.h>
#include<stdlib.h>

struct lisnode {
    int val;
    struct lisnode *next;
};

struct lisnode* re(struct lisnode* head)
{
    printf("4");
    struct lisnode* left = nullptr;
    struct lisnode* curr = head;
    while (curr)
    {
        struct lisnode* next = curr -> next;
        curr -> next  = left;
        left = curr;
        curr = next;
    }
    return left;
}
struct lisnode* init(int data,struct lisnode* head)
{
    printf("5");
    struct lisnode* p = head;
    while(p->next){
        p = p ->next;
    }
    struct lisnode* temp = (struct lisnode*)malloc(sizeof(lisnode));
    temp ->val = data;
    temp -> next = nullptr;
    p->next = temp;
    return head;

}
struct lisnode* InitList(struct lisnode* head)
{
    printf("6");
	head=(struct lisnode*)malloc(sizeof(lisnode));
    head->next = NULL;
    return head;
}
void split(struct lisnode* &head1,struct lisnode* &head2)
{
    printf("7");
    struct lisnode* head3 = nullptr;
    
    while (head1 && head2)
    {
        if (head1->val < head2->val){
            head3 = head1 ->next;
            head1->next = head2;
            head1 = head3;
        }
        else if (head1->val > head2->val)
        {
            head3 = head2 ->next;
            head2->next = head1;
            head2 = head3;
        }
        
    }
}
int main()
{
    int data,len1,len2;
    struct lisnode* A =nullptr;
    struct lisnode* B = nullptr;
    struct lisnode* C = nullptr;
    printf("1");
    A = InitList(A);
    B = InitList(B);
    printf("请输入len1");
    scanf("%d",&len1);
    printf("请输入len2");
    scanf("%d",&len2);
    for(int i =0;i<len1;i++){
        printf("数据");
        scanf("%d",&data);
        A = init(data,A);
    }
    for(int i =0;i<len2;i++){
        printf("数据0");
        scanf("%d",&data);
        B = init(data,B);
    }
    split(A,B);
    C = A;
    printf("10");
    C = re(C);

    return 0;
}