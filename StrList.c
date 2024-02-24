#include <stdio.h>
#include <string.h>
#include "StrList.h"

Node *Node_alloc(char *data, Node *next)
{
    Node *curr = (Node *)malloc(sizeof(Node));
    if (curr == NULL)
    {
        exit(1);
    }
    curr->data = data;
    curr->next = next;
}

StrList *StrList_alloc(Node *root)
{
    StrList *lstRoot = (StrList *)malloc(sizeof(StrList));
    if (lstRoot == NULL)
    {
        exit(1);
    }
    lstRoot->root = root;
}

StrList *create_list(int size)
{
    StrList *strList = StrList_alloc(NULL);
    Node *curr = Node_alloc(NULL, NULL);
    strList->root = curr;

    for (int i = 0; i < size; i++)
    {
        char word[WORD_SIZE];
        printf("Enter word: ");
        scanf("%s", word);

        char *newWord = (char *)malloc(strlen(word) + 1);
        strcpy(newWord, word);

        if (i == 0)
        {
            curr->data = newWord;
        }
        else
        {
            Node *newNode = Node_alloc(newWord, NULL);
            curr->next = newNode;
            curr = newNode;
        }
    }

    return strList;
}

size_t StrList_size(const StrList *StrList)
{
    if (!StrList || !StrList->root)
        return 0;

    int counter = 0;

    Node *temp = StrList->root;

    while (temp)
    {
        counter++;
        temp = temp->next;
    }

    return counter;
}

void StrList_insertAt(StrList *StrList, const char *data, int index)
{
    if (index < 0)
    {
        return;
    }

    Node *toAdd = Node_alloc(data, NULL);
    Node *curr = StrList->root;

    if (index == 0)
    {
        toAdd->next = curr;
        StrList->root = toAdd;
        return;
    }

    int counter = 0;

    while (counter < index - 1)
    {
        curr = curr->next;
        counter++;
    }

    toAdd->next = curr->next;
    curr->next = toAdd;
}

void StrList_free(StrList *StrList)
{
    if (!StrList)
        return;
    Node *root = StrList->root;
    Node *next = root->next;
    free(StrList);
    while (next)
    {
        free(root->data);
        free(root);
        root = next;
        next = next->next;
    }
    free(root);
}

void StrList_print(const StrList *StrList)
{
    Node *temp = StrList->root;
    while (temp)
    {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}