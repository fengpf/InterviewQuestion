#include<stdio.h>
#include<stdlib.h> 

//  Reverse a singly linked-list, you need to implement functions as these followings

struct Node{
  int val;
  struct Node* next; 
};

struct Node* CreateLinkedList(int* array, int length);

struct Node* ReverseLinkedList(struct Node* node);

void DestoryLinkedList(struct Node* node);

int test(int len);

int main() {
    printf("zero node reverse\n");
    test(0);

    printf("one node reverse\n");
    test(1);

    printf("five nodes reverse\n");
    test(5);

    printf("ten nodes reverse\n");
    test(10);

    return 0;
}

int test(int len) {
    int *p,i;
    int a[len] ;
    for(i=0; i<len; i++)
    {
        a[i]=i;
    }
    p = a;
  
    struct Node* head, *reverseNode;
    head = CreateLinkedList(p, len);//构造链表

    reverseNode = ReverseLinkedList(head);//翻转链表

    //销毁链表
    DestoryLinkedList(head);
    DestoryLinkedList(reverseNode);
    
    head = NULL;
    printf("head(%p)\n", head);
    printf("reverseNode(%p)\n", reverseNode);

    return 0;
}
 
 struct Node* CreateLinkedList(int* array, int length){
     struct Node* head, *temp;
     head = (struct Node*) malloc(sizeof(struct Node*));
     if(head == NULL)
     {
        printf("error - unable to allocate required memory for head node\n");
        return NULL;
     }

     head->val = *array;
     temp = (struct Node*) malloc(sizeof(struct Node*));
     temp = head;

     int i;
     for (i=1; i<length; i++) {

        struct Node* next;
        next = (struct Node*) malloc(sizeof(struct Node*));
        if(next == NULL)
        {
            printf("error - unable to allocate required memory for node(%d)\n", i);
            return NULL;
        }
        next->val = *(array + i) ;

        // printf("*(array + %d)=%d, next addr(%p)\n",  i, *(array + i), next);

        temp->next = next;
		temp = temp->next;
     }

    // while (head!=NULL) {
    //     printf("node(%d)\n", head->val);
    //     head = head->next;
    // }

     return head;
 }

struct Node* ReverseLinkedList(struct Node* node) {
    if (node == NULL) {
        printf("error - no node to reverse\n");
        return NULL;
    }

    struct Node *cur, *pre;
    cur=node;
    pre = NULL;
    while (cur != NULL)
    {
        struct Node* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    while (pre!=NULL) {
        printf("after reverse node(%d)\n", pre->val);
        pre = pre->next;
    }

    return pre;
}

void DestoryLinkedList(struct Node* node) {
    struct Node* p, *q;
    p = node;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    node = NULL;
}