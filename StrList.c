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
    size_t StriListSize = StrList_size(StrList);

    if (index < 0 || index > StriListSize)
    {
        return;
    }

    char *newWord = (char *)malloc(strlen(data) + 1);
    strcpy(newWord, data);

    Node *toAdd = Node_alloc(newWord, NULL);
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

void StrList_printAt(const StrList *Strlist, int index)
{
    size_t strListSize = StrList_size(Strlist);
    if (index >= strListSize || index < 0)
        return;

    Node *curr = Strlist->root;
    int counter = 0;

    while (counter < index)
    {
        curr = curr->next;
        counter++;
    }
    printf("%s\n", curr->data);
}

char *StrList_firstData(const StrList *StrList)
{
    Node *node = StrList->root;
    if (node && node->data)
    {
        return node->data;
    }
}

int StrList_printLen(const StrList *Strlist)
{
    if (!Strlist)
    {
        return 0;
    }
    int counter = 0;
    Node *node = Strlist->root;
    char *word = Strlist->root->data;
    while (node->next)
    {
        counter += strlen(word);
        node = node->next;
        word = node->data;
    }
    counter += strlen(node->data);

    return counter;
}

int StrList_count(StrList *StrList, const char *data)
{
    if (!StrList)
        return;
    Node *curr = StrList->root;
    int counter = 0;

    while (curr)
    {
        if (strcmp(data, curr->data) == 0)
            counter++;
        curr = curr->next;
    }

    return counter;
}

void StrList_remove(StrList *StrList, const char *data)
{
    if (!data || !StrList)
        return;

    Node *curr = StrList->root;

    while (strcmp(curr->data, data) == 0)
    {
        StrList->root = curr->next;
        free(curr);
        curr = StrList->root;
    }

    Node *next = curr->next;

    while (next)
    {
        if (strcmp(next->data, data) == 0)
        {
            curr->next = next->next;
            free(next->data);
            free(next);
        }
        curr = curr->next;
        next = curr->next;
    }
    // if (strcmp(curr->data, data) == 0)
    // {

    //     free(curr->data);
    //     free(curr);
    // }
}

void StrList_removeAt(StrList *StrList, int index)
{
    size_t strListSize = StrList_size(StrList);
    if (index >= strListSize || index < 0)
        return;
    if (index == 0)
    {
        Node *root = StrList->root;
        StrList->root = root->next;
        free(root->data);
        free(root);
    }
    else
    {
        Node *curr = StrList->root;
        int counter = 0;

        while (counter < index - 1)
        {
            curr = curr->next;
            counter++;
        }
        Node *next = curr->next;
        curr->next = next->next;
        free(next->data);
        free(next);
    }
}
