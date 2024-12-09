#include <stdio.h>
#include <string.h>
#include "library.h"

// Sorting by title
void sortBooksByTitle(Book books[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(books[i].title, books[j].title) > 0) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Books sorted by title.\n");
}

// Sorting by author
void sortBooksByAuthor(Book books[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(books[i].author, books[j].author) > 0) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Books sorted by author.\n");
}

// Filtering by author
void filterBooksByAuthor(Book books[], int count, const char *author) {
    printf("Books by author '%s':\n", author);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].author, author) == 0) {
            printf("Title: %s, ISBN: %s\n", books[i].title, books[i].isbn);
            found++;
        }
    }
    if (found == 0) {
        printf("No books found by author '%s'.\n", author);
    }
}

// Filtering by genre
void filterBooksByGenre (Book books[], int count, const char *genre) {
    printf("Books in genre '%s':\n", genre);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].genre, genre) == 0) {
            printf("Title: %s, Author: %s, ISBN: %s\n", books[i].title, books[i].author, books[i].isbn);
            found++;
        }
    }
    if (found == 0) {
        printf("No books found in genre '%s'.\n", genre);
    }
}