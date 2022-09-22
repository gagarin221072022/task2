/**
 * rp.c - функция для удаления строки перед текущей
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
 * для удаления строки перед той, на которую указывает курсор 
 */
void rp(text txt)
{
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    }
    if (txt == NULL || txt -> length <= 1) {
        fprintf(stderr, "There are not enough lines for delete\n");
        return;
    }

    
    if (txt -> cursor -> line == NULL) return;
    
    if (txt -> cursor -> line == txt -> begin) return;
    
    node *cur = txt -> begin;
    
    // если курсор находится на второй строке
    if (txt -> cursor -> line == cur -> next) {
        txt -> begin = cur -> next;
        return;
    }
    
    while (cur -> next != NULL) {
        if (cur -> next == txt -> cursor -> line) {
            cur -> previous -> next = cur -> next;
            cur -> next -> previous = cur -> previous;
            
            return;
        }

        cur = cur -> next;
    }

    return;
}
