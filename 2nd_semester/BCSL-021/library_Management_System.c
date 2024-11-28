#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define ISBN_LEN 13

typedef struct {
	char title[MAX_TITLE_LEN];
	char author[MAX_AUTHOR_LEN];
	char isbn[ISBN_LEN + 1];  // 13 digits + null terminator
} Book;

// Function prototypes
void boilerPlate();
void tree();
void addBook(Book books[], int *count);
void displayBooks(const Book books[], int count);
void fauthor();
void ftitle();
void deleteBook(Book books[], int *count, const char *isbn);
int isValidISBN(const char *isbn);
int isDuplicateISBN(const Book books[], int count, const char *isbn);
void trimNewline(char *str);

// Global variables
int option;
int count = 0;
Book books[MAX_BOOKS];  // Array to store up to 10 books







// Main function


int main() {
	while (1) {          	// Loop to keep showing options until user exits
    		boilerPlate();
    		printf("Enter your choice: ");
    		scanf("%d", &option);
    		getchar();       	// Consume newline left by scanf

    		if (option == 10) {  // Exit condition
        			printf("Exiting...\n");
        			break;
    		}
    		tree();
	}
	return 0;
}

// Display options
void boilerPlate() {
	printf("\nChoose Your Operation:\n");
	printf("1. Add a New Book\n");
	printf("2. Display All Books\n");
	printf("3. Fetch a Book by ISBN\n");
	printf("4. Search a Book by Author\n");
	printf("5. Fetch a Book by Title\n");
	printf("6. Update Book Record\n");
	printf("7. Remove Book from Record\n");
	printf("8. Save Book Record to a File\n");
	printf("9. Fetch Book Record from a File\n");
	printf("10. Exit\n");
}

// Helper function to validate ISBN (must be exactly 13 digits)
int isValidISBN(const char *isbn) {
	if (strlen(isbn) != ISBN_LEN) return 0;  // ISBN must be 13 characters
	for (int i = 0; i < ISBN_LEN; i++) {
    		if (!isdigit(isbn[i])) return 0;  // All characters must be digits
	}
	return 1;  // ISBN is valid
}

// Helper function to check for duplicate ISBN
int isDuplicateISBN(const Book books[], int count, const char *isbn) {
	for (int i = 0; i < count; i++) {
    		if (strcmp(books[i].isbn, isbn) == 0) {
        			return 1;  // Duplicate ISBN found
    		}
	}
	return 0;  // No duplicate found
}

// Helper function to trim newline character from fgets input
void trimNewline(char *str) {
	str[strcspn(str, "\n")] = '\0';  // Find the newline character and replace it with a null terminator
}



// #1 Add a New Book
void addBook(Book books[], int *count) {
	if (*count >= MAX_BOOKS) {
    		printf("Book storage is full.\n");
    		return;
	}

	Book newBook;

	// Input Book Title
	printf("Enter Book Title: ");
	fgets(newBook.title, sizeof(newBook.title), stdin);
	trimNewline(newBook.title);
	if (strlen(newBook.title) == 0) {
    		printf("Error: Title cannot be empty.\n");
    		return;
	}

	// Input Author's Name
	printf("Enter Author's Name: ");
	fgets(newBook.author, sizeof(newBook.author), stdin);
	trimNewline(newBook.author);
		if (strlen(newBook.author) == 0) {
    		printf("Error: Author's name cannot be empty.\n");
    		return;
	}



	// Input ISBN
	printf("Enter ISBN (13 digits): ");
	fgets(newBook.isbn, sizeof(newBook.isbn), stdin);
	trimNewline(newBook.isbn);

	// Validate ISBN
	if (!isValidISBN(newBook.isbn)) {
    		printf("Error: ISBN must be exactly 13 digits long and contain only numbers.\n");
    		return;
	}

	// Check for duplicate ISBN
	if (isDuplicateISBN(books, *count, newBook.isbn)) {
    		printf("Error: A book with this ISBN already exists in the record.\n");
    		return;
	}

	// Add the new book to the array
	books[*count] = newBook;
	(*count)++;
	printf("Book added successfully!\n");
}

// #2 Display All Books
void displayBooks(const Book books[], int count) {
	printf("\nStored Books:\n");
	if (count == 0) {
    	printf("No books available.\n");
	} else {
    	for (int i = 0; i < count; i++) {
        	printf("Book %d:\n", i + 1);
        	printf("  Title: %s\n", books[i].title);
        	printf("  Author: %s\n", books[i].author);
        	printf("  ISBN: %s\n", books[i].isbn);
    	}
	}
}








// #3 Search Book by ISBN
int searchBookByISBN(const Book books[], int count, const char *isbn) {
	for (int i = 0; i < count; i++) {
    	if (strcmp(books[i].isbn, isbn) == 0) {
        	printf("Book found:\n");
        	printf("  Title: %s\n", books[i].title);
        	printf("  Author: %s\n", books[i].author);
        	printf("  ISBN: %s\n", books[i].isbn);
        	return 1;  // Book found, return 1
    	}
	}
	printf("No book found with ISBN %s.\n", isbn);
	return 0;  // Book not found, return 0
}




// #4 Search Book by Author
void fauthor() {
	char author[MAX_AUTHOR_LEN];
	printf("Enter author name to search: ");
	fgets(author, sizeof(author), stdin);
	trimNewline(author);

	int found = 0;
	for (int i = 0; i < count; i++) {
    		if (strstr(books[i].author, author) != NULL) {
        	printf("Book found:\n");
        	printf("  Title: %s\n", books[i].title);
        	printf("  Author: %s\n", books[i].author);
        	printf("  ISBN: %s\n", books[i].isbn);
        	found = 1;
    		}
	}
	if (!found) {
    		printf("No books found by author %s.\n", author);
	}
}


// #5 Fetch Book by Title
void ftitle() {
	char title[MAX_TITLE_LEN];
	printf("Enter title to search: ");
	fgets(title, sizeof(title), stdin);
	trimNewline(title);

	int found = 0;
	for (int i = 0; i < count; i++) {
    		if (strstr(books[i].title, title) != NULL) {
        	printf("Book found:\n");
        	printf("  Title: %s\n", books[i].title);
        	printf("  Author: %s\n", books[i].author);
        	printf("  ISBN: %s\n", books[i].isbn);
        	found = 1;
    		}
	}
	if (!found) {
    		printf("No books found with title %s.\n", title);
	}
}

// #6 Update Book Record
void fupdateRecord() {
	char isbn[ISBN_LEN + 1];
	printf("Enter ISBN of the book to update: ");
	fgets(isbn, sizeof(isbn), stdin);
	trimNewline(isbn);  // Remove any newline character left by fgets

	// Search for the book by ISBN
	for (int i = 0; i < count; i++) {
    	if (strcmp(books[i].isbn, isbn) == 0) {
        	// Book found, display current details
        	printf("Current book details:\n");
        	printf("Title: %s\n", books[i].title);
        	printf("Author: %s\n", books[i].author);
        	printf("ISBN: %s\n", books[i].isbn);

        	// Ask the user if they want to update the title
        	char updateChoice;
        	while (1) {
            	printf("\nDo you want to update the title of the book? (y/n): ");
            	scanf(" %c", &updateChoice);
            	getchar();  // To clear the newline left in the input buffer
            	if (updateChoice == 'y' || updateChoice == 'Y') {
                	printf("Enter new title (or press Enter to keep the current one): ");
                	char newTitle[MAX_TITLE_LEN];
                	fgets(newTitle, sizeof(newTitle), stdin);
                	trimNewline(newTitle);  // Remove the newline if user presses Enter without entering new text
                	if (strlen(newTitle) > 0) {
                    	strcpy(books[i].title, newTitle);  // Update the title
                	}
                	break;  // Exit the loop and move on
            	} else if (updateChoice == 'n' || updateChoice == 'N') {
                	break;  // Exit the loop and move on
            	} else {
                	printf("Invalid choice, please enter 'y' or 'n'.\n");
            	}
        	}

        	// Ask the user if they want to update the author
        	while (1) {
            	printf("\nDo you want to update the author of the book? (y/n): ");
            	scanf(" %c", &updateChoice);
            	getchar();  // To clear the newline left in the input buffer
            	if (updateChoice == 'y' || updateChoice == 'Y') {
                	printf("Enter new author (or press Enter to keep the current one): ");
                	char newAuthor[MAX_AUTHOR_LEN];
                	fgets(newAuthor, sizeof(newAuthor), stdin);
                	trimNewline(newAuthor);  // Remove any newline character from author input
                	if (strlen(newAuthor) > 0) {
                    	strcpy(books[i].author, newAuthor);  // Update the author
                	}
                	break;  // Exit the loop and move on
            	} else if (updateChoice == 'n' || updateChoice == 'N') {
                	break;  // Exit the loop and move on
            	} else {
                	printf("Invalid choice, please enter 'y' or 'n'.\n");
            	}
        	}

        	// Ask the user if they want to update the ISBN
        	while (1) {
            	printf("\nDo you want to update the ISBN of the book? (y/n): ");
            	scanf(" %c", &updateChoice);
            	getchar();  // To clear the newline left in the input buffer
            	if (updateChoice == 'y' || updateChoice == 'Y') {
                	printf("Enter new ISBN (or press Enter to keep the current one): ");
                	char newIsbn[ISBN_LEN + 1];
                	fgets(newIsbn, sizeof(newIsbn), stdin);
                	trimNewline(newIsbn);  // Remove any newline character from ISBN input
                	if (strlen(newIsbn) > 0) {
                    	// Validate and update the ISBN if it's provided
                    	if (isValidISBN(newIsbn) && !isDuplicateISBN(books, count, newIsbn)) {
                        	strcpy(books[i].isbn, newIsbn);  // Update the ISBN
                        	printf("ISBN updated successfully.\n");
                    	} else {
                        	printf("Error: Invalid ISBN or duplicate ISBN found. Keeping the old ISBN.\n");
                    	}
                	}
                	break;  // Exit the loop and move on
            	} else if (updateChoice == 'n' || updateChoice == 'N') {
                	break;  // Exit the loop and move on
            	} else {
                	printf("Invalid choice, please enter 'y' or 'n'.\n");
            	}
        	}

        	printf("Book details updated successfully.\n");
        	return;
    	}
	}
	printf("No book found with ISBN %s.\n", isbn);
}

// #7 Delete Book Record
void deleteBook(Book books[], int *count, const char *isbn) {
	int index = -1;
    
	// Search for the book with the given ISBN
	for (int i = 0; i < *count; i++) {
    	if (strcmp(books[i].isbn, isbn) == 0) {
        	index = i;
        	break;
    	}
	}

	// If book is found
	if (index != -1) {
    	// Shift remaining books to fill the gap
    	for (int i = index; i < *count - 1; i++) {
        	books[i] = books[i + 1];
    	}

    	// Decrease the count of books
    	(*count)--;

    	printf("Book with ISBN %s has been deleted.\n", isbn);
	} else {
    	printf("No book found with ISBN %s.\n", isbn);
	}
}



// #8 Save Book Record to a File (Updated)
void saveToFile(const Book books[], int count, const char *filename) {
	FILE *file = fopen(filename, "w");
	if (!file) {
    	printf("Error opening file for writing.\n");
    	return;
	}

	for (int i = 0; i < count; i++) {
    	fprintf(file, "%s\n%s\n%s\n", books[i].title, books[i].author, books[i].isbn);
	}

	fclose(file);
	printf("Book records saved to file: %s\n", filename);
}






// #9 Fetch Book Record from a File (Updated)
void loadFromFile(Book books[], int *count, const char *filename) {
	FILE *file = fopen(filename, "r");
	if (!file) {
    	printf("Error opening file for reading.\n");
    	return;
	}

	// Read the book records from the file
	while (fscanf(file, "%99[^\n]\n%49[^\n]\n%13s\n", books[*count].title, books[*count].author, books[*count].isbn) == 3) {
    	if (++(*count) >= MAX_BOOKS) {
        	break;  // Stop if the book count exceeds the maximum limit
    	}
	}

	fclose(file);
	printf("Book records loaded from file: %s\n", filename);
}




// Process user option
// Tree function to call different actions based on user input
void tree() {
	switch (option) {
    	case 1: addBook(books, &count); break;
    	case 2: displayBooks(books, count); break;
    	case 3:
        	char isbn[ISBN_LEN + 1];
        	printf("Enter ISBN to search: ");
        	fgets(isbn, sizeof(isbn), stdin);
        	trimNewline(isbn);
       	 
        	// Call the updated search function
        	int found = searchBookByISBN(books, count, isbn);  // Store the result
        	if (!found) {
            	printf("No book found with ISBN %s.\n", isbn);
        	}
break;
    	case 4: fauthor(); break;
    	case 5: ftitle(); break;
    	case 6: fupdateRecord(); break;
    	case 7: {
        	// Case to delete a book
        	char isbn[ISBN_LEN + 1];
        	printf("Enter ISBN of the book to delete: ");
        	fgets(isbn, sizeof(isbn), stdin);
        	trimNewline(isbn);  // Remove the newline character

        	// Function call to delete the book
        	deleteBook(books, &count, isbn);  // Pass books, count, and ISBN
        	break;
    	}
break;
    	case 8: {
        	// Case to save book records to a file
        	const char *filename = "books.txt";  // Define the file name
        	saveToFile(books, count, filename);  // Pass books, count, and filename
        	break;
    	}
    	case 9: 
	{
        		const char *filename = "books.txt";  // Define the file name
        		loadFromFile(books, &count, filename);  // Pass books, count, and filename to loadFromFile
        	break;
    	}
    	default:
        			printf("Invalid option. Please choose a valid operation.\n");
        		break;
	}
}


