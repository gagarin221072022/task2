/**
 * showlengths.c - функция для вывода длин строк в прямом порядке следования
 * 
 * Copyright (c) 2022, Valeriy Gagarin
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include "common.h"
#include "text.h"
#include "_text.h"

/**
 * для вывода каждого последнего непробельного символа строки 
 * в прямом порядке следования строк
 */
void showlengths(text txt)
{
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    }
    

    
    node *cur = txt -> begin;

    while (cur != NULL) {
        char* cur_line = cur -> contents;
        printf("%d\n", (int)strlen(cur_line));
        
        cur = cur -> next;
    }

    return;
}
