#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_BOOKS 100

// Function Prototypes
void borrow_book(const char *book_id, const char *user);
void return_book(const char *book_id, const char *user);
void log_transaction(const char *action, const char *book_id, const char *user);

// Global book data storage
char book_ids[MAX_BOOKS][20];
char book_authors[MAX_BOOKS][100];
char book_titles[MAX_BOOKS][100];
int book_count = 0;

// Load books from the file
void load_books() {
    FILE *file = fopen("books.txt", "r");
    if (!file) {
        perror("Failed to open books.txt");
        exit(EXIT_FAILURE);
    }

    book_count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;

        if (sscanf(line, "%19[^,],%99[^,],%99[^,]", 
                   book_ids[book_count], 
                   book_authors[book_count], 
                   book_titles[book_count]) == 3) {
            book_count++;
            if (book_count >= MAX_BOOKS) {
                printf("Reached maximum book capacity\n");
                break;
            }
        }
    }

    fclose(file);
}

// Check if a book exists
int find_book_index(const char *book_id) {
    for (int i = 0; i < book_count; i++) {
        if (strcmp(book_ids[i], book_id) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

// Borrow a book
void borrow_book(const char *book_id, const char *user) {
    int index = find_book_index(book_id);
    if (index == -1) {
        printf("Book with ID %s not found.\n", book_id);
        return;
    }

    // Log the borrow transaction
    log_transaction("BORROWED", book_id, user);
    printf("Book '%s' borrowed by %s.\n", book_titles[index], user);
}

// Return a book
void return_book(const char *book_id, const char *user) {
    int index = find_book_index(book_id);
    if (index == -1) {
        printf("Book with ID %s not found.\n", book_id);
        return;
    }

    // Log the return transaction
    log_transaction("RETURNED", book_id, user);
    printf("Book '%s' returned by %s.\n", book_titles[index], user);
}

// Log transaction to logs.txt
void log_transaction(const char *action, const char *book_id, const char *user) {
    FILE *log_file = fopen("logs.txt", "a");
    if (!log_file) {
        perror("Failed to open logs.txt");
        exit(EXIT_FAILURE);
    }

    fprintf(log_file, "%s,%s,%s\n", action, book_id, user);
    fclose(log_file);
}

int main() {
    // Load books from the file
    load_books();

    // Borrow and return book examples
    borrow_book("B101", "John Doe");
    return_book("B101", "John Doe");

    return 0;
}
