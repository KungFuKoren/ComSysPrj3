#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "StrList.h"

int main()
{
    StrList *_StrList = NULL;

    while (TRUE)
    {
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case (1):
            int numOfWords;
            scanf("%d", &numOfWords);
            _StrList = create_list(numOfWords);
            break;
        case (2):
            if (!_StrList)
                break;

            int insertIndex;
            char word[WORD_SIZE];

            scanf("%d", &insertIndex);

            scanf("%s", word);

            char *newWord = (char *)malloc(strlen(word) + 1);
            if (newWord == NULL)
                exit(1);

            strcpy(newWord, word);

            StrList_insertAt(_StrList, newWord, insertIndex);

            free(newWord);

            break;
        case (3):
            StrList_print(_StrList);
            break;
        case (4):
            printf("%ld\n", StrList_size(_StrList));
            break;
        case (5):
            int printIndex;

            scanf("%d", &printIndex);

            StrList_printAt(_StrList, printIndex);

            break;
        case (6):
            printf("%d\n", StrList_printLen(_StrList));
            break;
        case (7):
            char wordInsert[WORD_SIZE];

            scanf("%s", wordInsert);

            char *newWordInsert = (char *)malloc(strlen(wordInsert) + 1);
            if (newWordInsert == NULL)
                exit(1);

            strcpy(newWordInsert, wordInsert);

            printf("%d\n", StrList_count(_StrList, newWordInsert));

            free(newWordInsert);
            break;

        case (8):
            char wordInsert2[WORD_SIZE];

            scanf("%s", wordInsert2);

            char *newWordInsert2 = (char *)malloc(strlen(wordInsert2) + 1);
            if (newWordInsert2 == NULL)
                exit(1);

            strcpy(newWordInsert2, wordInsert2);

            StrList_remove(_StrList, newWordInsert2);

            free(newWordInsert2);
            break;
        case (9):
            int removeAt;

            scanf("%d", &removeAt);
            StrList_removeAt(_StrList, removeAt);
            break;
        case (10):
            StrList_reverse(_StrList);
            break;
        case (11):
            StrList_free(_StrList);
            _StrList = NULL;
            break;
        case (12):
            StrList_sort(_StrList);
            break;
        case (13):
            int isSorted = StrList_isSorted(_StrList);
            printf("%s\n", isSorted ? "true" : "false");
            break;
        case (0):
            StrList_free(_StrList);
            return 0;
        }
    }

    return 0;
}