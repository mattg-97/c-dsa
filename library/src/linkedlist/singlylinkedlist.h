#pragma once

#include "defines.h"

typedef struct node
{
    int info;
    struct node *link;
} node;

API void singlylinkedlist();
struct node *createList(struct node *start);
void displayList(struct node *start);
void countNodes(struct node *start);
void search(struct node *start, int x);
struct node *insertInBeginning(struct node *start, int data);
void insertAtEnd(struct node *start, int data);
void insertAfter(struct node *start, int data, int x);
struct node *insertBefore(struct node *start, int data, int x);
struct node *insertAtPosition(struct node *start, int data, int k);
struct node *deleteNode(struct node *start, int data);
struct node *reverseList(struct node *start);