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
    //TODO: insert the code here for sorting the books by author
}

// Filtering by author
void filterBooksByAuthor(Book books[], int count, const char *author) {
    //TODO: insert the code here for filtering the books by author
}

// Filtering by genere
void filterBooksByGenre () {
    //TODO: insert the code here for filtering the books by genre
}
