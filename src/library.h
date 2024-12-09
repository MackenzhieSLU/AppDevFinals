#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 50
#define ISBN_LENGTH 20
#define GENRE_LENGTH 30

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    char isbn[ISBN_LENGTH];
    char genre[GENRE_LENGTH];
} Book;

void addBook();
void displayBooks();

#endif