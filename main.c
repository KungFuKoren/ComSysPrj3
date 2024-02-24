#include <stdlib.h>
#include <stdio.h>
#include "StrList.h"

int main()
{
    StrList *StrList = NULL;

    while (TRUE)
    {
        int choice;
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case (1):
            int numOfWords;
            printf("Number of words: ");
            scanf("%d", &numOfWords);
            StrList = create_list(numOfWords);
            break;
        case (2):
            if (!StrList)
                break;

            int insertIndex = NULL;
            char word[WORD_SIZE];

            printf("Insert at index: ");
            scanf("%d", &insertIndex);

            printf("Enter word: ");
            scanf("%s", word);

            char *newWord = (char *)malloc(strlen(word) + 1);
            strcpy(newWord, word);

            StrList_insertAt(StrList, newWord, insertIndex);

            free(newWord);

            break;
        case (3):
            StrList_print(StrList);
            break;
        case (4):
            printf("%ld\n", StrList_size(StrList));
            break;
        case (5):
            int printIndex = NULL;

            printf("Print at index: ");
            scanf("%d", &printIndex);

            StrList_printAt(StrList, printIndex);

            break;
        case (6):
            printf("%d\n", StrList_printLen(StrList));
            break;
        case (7):
            char wordInsert[WORD_SIZE];

            printf("Word to count: ");
            scanf("%s", wordInsert);

            char *newWordInsert = (char *)malloc(strlen(wordInsert) + 1);
            strcpy(newWordInsert, wordInsert);

            printf("%d\n", StrList_count(StrList, newWordInsert));

            free(newWordInsert);
            break;

        case (8):
            char wordInsert2[WORD_SIZE];

            printf("Word to remove: ");
            scanf("%s", wordInsert2);

            char *newWordInsert2 = (char *)malloc(strlen(wordInsert2) + 1);
            strcpy(newWordInsert2, wordInsert2);

            StrList_remove(StrList, newWordInsert2);

            free(newWordInsert2);
            break;
        case (9):
            int removeAt = NULL;
            printf("Remove at index: ");
            scanf("%d", &removeAt);
            StrList_removeAt(StrList, removeAt);
            break;

        case (11):
            StrList_free(StrList);
            StrList = NULL;
            break;
        case (0):
            StrList_free(StrList);
            return 0;
        }
    }

    return 0;
}