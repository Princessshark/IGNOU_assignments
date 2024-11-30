#include<stdio.h>
#define MAX_LEN 1000  // Maximum length for the concatenated result string


void tree(), boilerPlate();
void length(), concatenate_strings(), copy(), compare();

int option;

int main() {
	boilerPlate();
	tree();
return 0;
}


void boilerPlate() {
	printf("Choose operation on String\n");
	printf("[Length: 1, Concatenation: 2, Copy: 3, Compare: 4]\n");
	scanf("%d", &option);
}

void tree() {
 	switch(option) {
    	case 1:
          	length();
    	break;
    	case 2:
           	concatenate_strings();
    	break;
    	case 3:
        	copy();
    	break;
    	case 4:
           	compare();
    	break;
    	default:
        	printf("Error: Invalid parameter, read the prompt before an input.\n");
	break;
	}
}



//#1 Find String Length
// Function to read input using scanf and calculate its length
void length() {
	char userinput[100];  // Buffer to store the user input (maximum length of 99 characters)
	int length = 0;  // Initialize length to 0

	// Clear any previous newline characters in the buffer before taking input
	while (getchar() != '\n');  // This will consume any residual newline characters in the buffer
    
	// Asking the user for input using scanf to read until newline
	printf("Enter a string: ");
	scanf("%[^\n]", userinput);  // Read input until newline (including spaces)
    
	// Counting the length of the string manually
	while (userinput[length] != '\0') {
    	length++;  // Increment length for each character
	}
    
	// Output the result
	printf("The length of the string is: %d\n", length);
}

//#2 String Concatenation
void concatenate_strings() {
	int n;
	printf("Enter the number of strings: ");
	scanf("%d", &n);
	getchar();  // Consume the newline left by scanf
    
	char result[MAX_LEN];  // To hold the concatenated string
	result[0] = '\0';  	// Initialize result as an empty string

	for (int i = 0; i < n; i++) {
    	char temp[MAX_LEN];  // Temporary array to store each input string
    	printf("Enter string %d: ", i + 1);

    	// Use fgets to read input, which allows spaces and special characters
    	fgets(temp, MAX_LEN, stdin);

    	// Remove the trailing newline character if present
    	int j = 0;
    	while (temp[j] != '\0') {
        	if (temp[j] == '\n') {
            	temp[j] = '\0';
            	break;
        	}
        	j++;
    	}

    	// Concatenate the input string to the result string
    	int k = 0;
    	while (result[k] != '\0') {
        	k++;  // Find the end of the result string
    	}
   	 
    	int l = 0;
    	while (temp[l] != '\0') {
        	result[k] = temp[l];  // Copy characters from temp to result
        	k++;
        	l++;
    	}
    	result[k] = '\0';  // Null-terminate the result string
	}

	printf("Concatenated string: %s\n", result);
}

//#3 Copy String
void copy() {
	char input[100]; // Array to store user input
	int n, i = 0;
	char c;

	// Ask the user how many times to copy the string
	printf("How many times would you like to copy the string? ");
	scanf("%d", &n);
	getchar(); // Consume the newline character left by scanf

	// Wait for user input
	printf("Enter a string: ");
    
	// Read user input one character at a time
	while ((c = getchar()) != '\n' && c != EOF) {
    	input[i] = c;   // Store each character in the input array
    	i++;
	}
	input[i] = '\0';  // Null-terminate the string

	// Copy the input string n times
	for (int j = 0; j < n; j++) {
    	printf("Copy %d: ", j + 1);

    	// Print the string character by character (without using string functions)
    	for (int k = 0; input[k] != '\0'; k++) {
        	putchar(input[k]);
    	}
    	printf("\n");
	}
}




//#4 Compare String 1 to String 2
void compare() {
	int n;
    
	// Ask how many strings the user will input
	printf("How many strings would you like to compare? ");
	scanf("%d", &n);
	getchar(); // To consume the newline character left by scanf

	char input[100];  // Array to store user input
	char prevInput[100];  // Array to store the previous input for comparison
	int i = 0, j;

	printf("Enter string 1: ");
    
	// Get the first input string
	while ((input[i] = getchar()) != '\n' && input[i] != EOF) {
    	i++;
	}
	input[i] = '\0';  // Null-terminate the first string

	// Copy the first string to prevInput to start the comparison
	for (j = 0; input[j] != '\0'; j++) {
    	prevInput[j] = input[j];
	}
	prevInput[j] = '\0';

	// Now, read and compare the rest of the strings
	for (int k = 2; k <= n; k++) {
    	i = 0;
    	printf("Enter string %d: ", k);
   	 
    	// Get the next input string
    	while ((input[i] = getchar()) != '\n' && input[i] != EOF) {
        	i++;
    	}
    	input[i] = '\0';  // Null-terminate the current string

    	// Compare the current string with the previous one
    	j = 0;
    	while (prevInput[j] != '\0' && input[j] != '\0') {
        	if (prevInput[j] != input[j]) {
            	printf("The strings are not equal.\n");
            	return;  // Exit the function if strings are not equal
        	}
        	j++;
    	}

    	// If one string is longer than the other
    	if (prevInput[j] != '\0' || input[j] != '\0') {
        	printf("The strings are not equal.\n");
        	return;
    	}

    	// Copy the current string into prevInput for the next comparison
    	for (j = 0; input[j] != '\0'; j++) {
        	prevInput[j] = input[j];
    	}
    	prevInput[j] = '\0';

    	// Optionally, clear the input buffer to prevent any leftover data affecting next iteration
    	for (int x = 0; x < 100; x++) {
        	input[x] = '\0';  // Resetting the array
    	}
	}

	// If all strings are equal
	printf("All strings are equal.\n");
}
