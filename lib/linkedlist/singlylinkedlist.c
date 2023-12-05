#include <stdio.h>
#include <stdlib.h>
#include "singlylinkedlist.h"

void singlylinkedlist()
{
    struct node *start = NULL;
    int choice, data, x, k;

    start = createList(start);

    while (1)
    {
        printf("\n");
        printf("1.Display list\n");
        printf("2.Count the number of nodes\n");
        printf("3.Search for an element\n");
        printf("4.Insert in empty list / Insert in beginning of the list\n");
        printf("5.Insert a node at the end of the list\n");
        printf("6.Insert a node after a specified node\n");
        printf("7.Insert a node before a specified node\n");
        printf("8.Insert a node at a given position\n");
        printf("9.Delete a node\n");
        printf("10.Reverse the list\n");
        printf("11.Quit\n\n");

        printf("Enter your choice : ");
        scanf_s("%d", &choice);

        if (choice == 11)
            break;

        switch (choice)
        {
        case 1:
            displayList(start);
            break;
        case 2:
            countNodes(start);
            break;
        case 3:
            printf("Enter the element to be searched : ");
            scanf_s("%d", &data);
            search(start, data);
            break;
        case 4:
            printf("Enter the element to be inserted : ");
            scanf_s("%d", &data);
            start = insertInBeginning(start, data);
            break;
        case 5:
            printf("Enter the element to be inserted : ");
            scanf_s("%d", &data);
            insertAtEnd(start, data);
            break;
        case 6:
            printf("Enter the element to be inserted : ");
            scanf_s("%d", &data);
            printf("Enter the element after which to insert : ");
            scanf_s("%d", &x);
            insertAfter(start, data, x);
            break;
        case 7:
            printf("Enter the element to be inserted : ");
            scanf_s("%d", &data);
            printf("Enter the element before which to insert : ");
            scanf_s("%d", &x);
            start = insertBefore(start, data, x);
            break;
        case 8:
            printf("Enter the element to be inserted : ");
            scanf_s("%d", &data);
            printf("Enter the position at which to insert : ");
            scanf_s("%d", &k);
            start = insertAtPosition(start, data, k);
            break;
        case 9:
            printf("Enter the element to be deleted : ");
            scanf_s("%d", &data);
            start = deleteNode(start, data);
            break;
        case 10:
            start = reverseList(start);
            break;
        default:
            printf("Wrong choice\n");
        }
    }
}

struct node *createList(struct node *start)
{
    int i, n, data;

    printf("Enter the number of nodes : ");
    scanf_s("%d", &n);

    if (n == 0)
        return start;

    printf("Enter the first element to be inserted : ");
    scanf_s("%d", &data);
    start = insertInBeginning(start, data);

    for (i = 2; i <= n; i++)
    {
        printf("Enter the next element to be inserted : ");
        scanf_s("%d", &data);
        insertAtEnd(start, data);
    }
    return start;
}

void displayList(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List: \n");
    p = start;
    while (p != NULL)
    {
        printf("%d  ", p->info);
        p = p->link;
    }
    printf("\n");
}

void countNodes(struct node *start)
{
    int n = 0;
    struct node *p = start;
    while (p != NULL)
    {
        n++;
        p = p->link;
    }
    printf("Number of nodes in list = %d\n", n);
}

void search(struct node *start, int x)
{
    struct node *p = start;
    int position = 1;
    while (p != NULL)
    {
        if (p->info == x)
        {
            break;
        }
        position++;
        p = p->link;
    }
    if (p == NULL)
    {
        printf("%d not found in this list\n", x);
    }
    else
    {
        printf("%d found at position %d.\n", x, position);
    }
}

struct node *insertInBeginning(struct node *start, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;

    temp->link = start;
    start = temp;

    return start;
}
void insertAtEnd(struct node *start, int data)
{
    struct node *p, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;

    p = start;
    while (p->link != NULL)
        p = p->link;

    p->link = temp;
    temp->link = NULL;
}
void insertAfter(struct node *start, int data, int x) {}
struct node *insertBefore(struct node *start, int data, int x)
{
    struct node *n = NULL;
    return n;
}
struct node *insertAtPosition(struct node *start, int data, int k)
{
    struct node *n = NULL;
    return n;
}
struct node *deleteNode(struct node *start, int data)
{
    struct node *n = NULL;
    return n;
}
struct node *reverseList(struct node *start)
{
    struct node *n = NULL;
    return n;
}