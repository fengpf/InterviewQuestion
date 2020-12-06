#include<stdio.h>
#include<stdlib.h> 
#include <assert.h>
//  Reverse a singly linked-list, you need to implement functions as these followings

struct Node{
  int val;
  struct Node* next; 
};

struct Node* CreateLinkedList(int* array, int length);
struct Node* ReverseLinkedList(struct Node* node);
void DestoryLinkedList(struct Node** node);

//add Unit tests
struct Node* testCreateLinkedList(int len);
void testReverseLinkedList(int len);
void testDestoryLinkedList(struct Node* node);
void testByNum(int len);
void testFull(int len);

int main() {
    testByNum(1);
    testByNum(10);
    testByNum(50);
    testByNum(100);
    return 0;
}

void testByNum(int len) {
    printf("testCreateLinkedList\n");
    struct Node* head;
    head = testCreateLinkedList(len);

    printf("testReverseLinkedList\n");
    testReverseLinkedList(len);

    printf("testDestoryLinkedList\n");
    testDestoryLinkedList(head);

    printf("testFull\n");
    testFull(len);
}

struct Node* testCreateLinkedList(int len) {
    int *p,i;
    int a[len] ;
    for(i=0; i<len; i++)
    {
        a[i]=i;
    }
    p = a;
  
    struct Node* head, *q;
    head = CreateLinkedList(p, len);

    int j;
    int res;

    for(q=head; q!=NULL; q=q->next) {
        printf("a[%d]:%d, q->val:%d\n", j, a[j], q->val);
        assert(a[j] == q->val);//add Corner cases check
        j++;
    }

    return head;
}

void testReverseLinkedList(int len) {
    int *p, i;
    int a[len] ;
    for(i=0; i<len; i++)
    {
        a[i]=i;
    }
    p = a;
  
    struct Node* head, *reverseNode, *q;
    head = CreateLinkedList(p, len);
    reverseNode = ReverseLinkedList(head);

    int j=len-1;
    int res;
    for(q=reverseNode; q!=NULL; q=q->next) {
        printf("a[%d]:%d, q->val:%d\n", j, a[j], q->val);
        assert(a[j] == q->val);//add Corner cases check
        j--;
    }
}

void testDestoryLinkedList(struct Node* node) {
    DestoryLinkedList(&node);
    assert(node==NULL);
}

void testFull(int len) {
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

    DestoryLinkedList(&head);//销毁链表
    
    printf("head(%p)\n", head);
}
 
 struct Node* CreateLinkedList(int* array, int length) {
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

    // while (pre!=NULL) {
    //     printf("after reverse node(%d)\n", pre->val);
    //     pre = pre->next;
    // }

    return pre;
}

void DestoryLinkedList(struct Node** node) {
   if(!*node) return;

    struct Node* temp;
    while (*node)
    {
        temp = *node;
        *node = temp->next;
        free(temp);
    }
}