#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
    int mark;
    struct nd *next;
}node;

node *create()
{
    int i,n;
    node *p, *head;
    printf("Enter total number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            head = (node*)malloc(sizeof(node));
            p=head;
        }
        else
        {
            p->next = (node*)malloc(sizeof(node));
            p=p->next;
        }
        printf("Enter mark %d: ",i+1);
        scanf("%d",&p->mark);
    }
    p->next=NULL;
    return head;
}

void insert(node **head)
{
    int mark;
    node *p, *q, *ne;
    ne = (node*)malloc(sizeof(node));
    printf("Enter mark: ");
    scanf("%d",&ne->mark);
    printf("Insert before mark (negative value to insert at end): ");
    scanf("%d",&mark);
    
    p=*head;
    if(p->mark==mark)
    {
        ne->next = p;
        *head=ne;
    }
    else
    {
        while((p!=NULL) && (p->mark!=mark))
        {
            q=p;
            p=p->next;
        }
        if(p==NULL)
        {
            q->next = ne;
            ne->next = NULL;
        }
        else if(p->mark==mark)
        {
            q->next = ne;
            ne->next = p;
        }
    }
}

void delete(node **head)
{
    int mark;
    node *p, *q;
    printf("Enter mark to be deleted: ");
    scanf("%d",&mark);
    
    p=*head;
    if(p->mark==mark)
    {
        *head=p->next;
        free(p);
    }
    else
    {
        while((p!=NULL) && (p->mark!=mark))
        {
            q=p;
            p=p->next;
        }
        if(p==NULL)
        {
            printf("No match found.");
        }
        else if(p->mark==mark)
        {
            q->next=p->next;
            free(p);
        }
    }
}

void display(node *head)
{
    int count=1;
    node *p;
    p=head;
    while(p!=NULL)
    {
        printf("NODE %d: %d\n",count,p->mark);
        count++;
        p=p->next;
    }
}

int main()
{
    node *l = create();
    insert(&l);
    delete(&l);
    display(l);
    return 0;
}
