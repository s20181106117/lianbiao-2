//
//  main.c
//  lianbiao
//
//  Created by s20181106117 on 2019/9/17.
//  Copyright © 2019 yxy. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* build();
struct node* _delete(struct node* head);
void print(struct node* head);
int main()
{
    struct node *head;
    head=build();
    head=_delete(head);
    print(head);
    return 0;
}
struct node* build()
{
    int n;
    struct node *head,*tail,*t;
    head=tail=NULL;
    scanf("%d",&n);
    while(n!=-1)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=n;
        t->next=NULL;
        if(head==NULL)
        {
            head=t;
        }
        else
        {
            tail->next=t;
        }
        tail=t;
        scanf("%d",&n);
    }
    return head;
}
struct node* _delete(struct node* head)
{
    struct node *t1,*t2;
    while(head!=NULL&&head->data%2==0)
    {
        t2=head;
        head=head->next;
        free(t2);
    }
    if(head==NULL)
    {
        return NULL;
    }
    t1=head;
    t2=head->next;
    while(t2!=NULL)
    {
        if(t2->data%2==0)
        {
            t1->next=t2->next;
            free(t2);
        }
        else
        {
            t1=t2;
        }
        t2=t1->next;
    }
    return head;
}
void print(struct node* head)
{
    struct node *p;
    p=head;
    if(p == NULL)
        printf("NULL");
    else
    {
        while(p->next)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("%d",p->data);
    }
}

