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
    return curr;
}

StrList *StrList_alloc(Node *root)
{
    StrList *lstRoot = (StrList *)malloc(sizeof(StrList));
    if (lstRoot == NULL)
    {
        exit(1);
    }
    lstRoot->root = root;
    return lstRoot;
}

StrList *create_list(int size)
{
    StrList *strList = StrList_alloc(NULL);
    Node *curr = Node_alloc(NULL, NULL);
    strList->root = curr;

    for (int i = 0; i < size; i++)
    {
        char word[WORD_SIZE];
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
    if (!StrList || !StrList->root)
        return;

    Node *temp = StrList->root;
    while (temp)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void StrList_printAt(const StrList *Strlist, int index)
{
    size_t strListSize = StrList_size(Strlist);
    if (strListSize == 0 || index >= strListSize || index < 0)
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
    if (!StrList || !StrList->root)
        return "";
    Node *root = StrList->root;

    return root->data;
}

int StrList_printLen(const StrList *Strlist)
{
    if (!Strlist || !Strlist->root)
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
        return 0;
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
    Node *prev = NULL;

    while (curr && strcmp(curr->data, data) == 0)
    {
        StrList->root = curr->next;
        free(curr->data);
        free(curr);
        curr = StrList->root;
    }

    while (curr)
    {
        if (strcmp(curr->data, data) == 0)
        {
            if (prev)
                prev->next = curr->next;
            free(curr->data);
            free(curr);
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
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

int StrList_isEqual(const StrList *StrList1, const StrList *StrList2)
{
    size_t strListSize1 = StrList_size(StrList1);
    size_t strListSize2 = StrList_size(StrList2);
    if (strListSize1 != strListSize2)
    {
        return 0;
    }
    int counter = 0;
    Node *root1 = StrList1->root;
    Node *root2 = StrList2->root;
    while (counter < strListSize1)
    {
        if (root1->data != root2->data)
        {
            return 0;
        }
        counter++;
        root1 = root1->next;
        root2 = root2->next;
    }
    return 1;
}

void StrList_reverse(StrList *StrList)
{
    if (!StrList || !StrList->root)
        return;

    size_t strListSize = StrList_size(StrList);

    if (strListSize == 1)
        return;

    Node *nodesArr[strListSize];

    Node *curr = StrList->root;
    for (int i = 0; i < strListSize; i++)
    {
        nodesArr[i] = curr;
        curr = curr->next;
    }

    curr = nodesArr[strListSize - 1];
    StrList->root = curr;

    for (int i = strListSize - 1; i > 0; i--)
        nodesArr[i]->next = nodesArr[i - 1];

    nodesArr[0]->next = NULL;
}

StrList *StrList_clone(const StrList *_StrList)
{
    if (!_StrList || !_StrList->root)
        return NULL;

    size_t strListSize = StrList_size(_StrList);
    Node *origRoot = _StrList->root;

    if (strListSize == 0 || origRoot == NULL)
    {
        return NULL;
    }

    char *origData = origRoot->data;
    Node *copyRoot = Node_alloc(origData, NULL);
    StrList *clonedList = StrList_alloc(copyRoot);
    int counter = 1;

    while (counter < strListSize)
    {
        origRoot = origRoot->next;
        origData = origRoot->data;
        Node *temp = Node_alloc(origData, NULL);
        copyRoot->next = temp;
        copyRoot = copyRoot->next;
        counter++;
    }
    return clonedList;
}

void StrList_sort(StrList *StrList)
{
    if (!StrList || !StrList->root)
        return;

    size_t strListSize = StrList_size(StrList);

    if (strListSize == 1)
        return;

    Node *nodesArr[strListSize];

    Node *curr = StrList->root;
    for (int i = 0; i < strListSize; i++)
    {
        nodesArr[i] = curr;
        curr = curr->next;
    }

    for (int i = 0; i < strListSize; i++)
    {
        for (int j = i + 1; j < strListSize; j++)
        {
            if (strcmp(nodesArr[i]->data, nodesArr[j]->data) > 0)
            {
                Node *temp = nodesArr[i];
                nodesArr[i] = nodesArr[j];
                nodesArr[j] = temp;
            }
        }
    }

    StrList->root = nodesArr[0];
    curr = nodesArr[0];

    for (int i = 0; i < strListSize - 1; i++)
    {
        curr->next = nodesArr[i + 1];
        curr = curr->next;
    }

    curr->next = NULL;
}

int StrList_isSorted(StrList *StrList)
{
    if (!StrList || !StrList->root)
        return 1;

    Node *curr = StrList->root;
    Node *next = curr->next;

    while (next)
    {
        if (strcmp(curr->data, next->data) > 0)
            return 0;

        curr = next;
        next = curr->next;
    }

    return 1;
}