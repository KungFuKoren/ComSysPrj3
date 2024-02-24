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

            size_t StriListSize = StrList_size(StrList);

            if (insertIndex > StriListSize || insertIndex < 0)
                break;

            StrList_insertAt(StrList, newWord, insertIndex);

            break;
        case (3):
            StrList_print(StrList);
            break;
        case (4):
            printf("%ld\n", StrList_size(StrList));
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