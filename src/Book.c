//
// Created by Nathan Mikhail on 12/6/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 50
#define ISBN_LENGTH 20

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    char isbn[ISBN_LENGTH];
} Book;
