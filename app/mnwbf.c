/**
 * mnwbf - функция для перемещения курсора в начало следующего слова
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
 * для перемещения курсора в начало следующего слова
 */
void mnwbf(text txt)
{
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    }
    
    if (txt -> cursor -> line == NULL) return;

    if (txt -> cursor -> line == txt -> begin) return;
    
    node *line = txt -> cursor -> line; 
    
    char *str = line -> contents;
    size_t str_len = strlen(str);
    
    unsigned int i;

    for (i = txt -> cursor -> position + 1; i + 1 < str_len; ++i) {
        if (str[i] == ' ' && str[i + 1] != ' ') {
            txt -> cursor -> position = i + 1;
            return;
        }
    }
    
    return;
}
