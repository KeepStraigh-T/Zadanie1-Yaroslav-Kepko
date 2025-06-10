#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* To start the program use command-line arguments:
*
*	./main.c <array_size> <shifts_number>
*
*/

// Function to print the array
void print_array(int *array, int array_size)
{
	for(int i = 0; i < array_size; i++)
		printf("%d ", array[i]);

	printf("\n");
}

// Function to fill the array
void fill_array(int *array, int array_size)
{
	for(int i = 0; i < array_size; i++)
		array[i] = rand() % 10;
}

// Fuction that shifts elements in the array
void cyklicky_posun_rychlo(int *p, int array_size, int shift_size)
{
	int temp = 0; 					// Temporary variable to store the next value
	int current_value = 0;	// Variable to store the current value being move
	int counter = 0;				// Counter to track the number of elements moved
	int current_index = 0;	// Index of the current element beiing processed

	//Reduce the shift size
	shift_size %= array_size; 

	// If the shift size is 0, no shifting is needed
	if(shift_size == 0) 
	{
		printf("\nNumber of shifts equals the array size so no moves are needed\n\n");
		return;
	}

	// Loop through each cycle in the array
	for(int start = 0; counter < array_size; start++)
	{
		current_index = start; // Start a new cycle
		current_value = p[current_index]; // Store the value at the starting index

		// Perform the cyclic shift for the current cycle
		do
		{
			current_index = (current_index + shift_size) % array_size; // Calculate the next index
			temp = p[current_index];					// Store the value at the next index
			p[current_index] = current_value; // Move the current value to the next position
			current_value = temp;							// Update the current value with the stored value
			counter++; 												// Increment the counter for moved elements

		} while(current_index != start);    // Continue untill the cycle is complete
	}
}

int main(int argc, char **argv)
{
	// Seed the random number generator with the current time
	srand(time(NULL));

	// Check if the required number of command-line arguments is provided
	if(argc < 3)
	{
		printf("Usage: %s <array_size> <shifts_number>\n", argv[0]);
		return 1;
	}
	
	// Pointer to first non-numeric character (required in strtol function)
	char *endptr;

	// Convert the first command-line argument to an integer (array size)
	int array_size = strtol(argv[1], &endptr, 10);

	// Validate the array size (must be a positive integer)
	if(*endptr != '\0' || array_size <= 0)
	{
		printf("Error: array_size must be a positive number\n");
		return 1;
	}
	
	// Convert the second command-line argument to an integer (shift size)
	int shifts_number = strtol(argv[2], &endptr, 10);

	// Validate the shift size (must be a non-negative integer)
	if(*endptr != '\0' || shifts_number < 0)
	{
		printf("Error: shifts_number must be a non-negative number\n");
		return 1;
	}

	// Allocate memory for the array dynamically
	int *array = calloc(array_size, sizeof(int));

	// Check if memory allocation was successful
	if(array == NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}

	// Fill the array with random values
	fill_array(array, array_size);

	// Print the original array
	printf("Original array: ");
	print_array(array, array_size);

	// Perform the cyclic shift on the array
	cyklicky_posun_rychlo(array, array_size, shifts_number);

	// Print the shifted array
	printf("Shifted array:  ");
	print_array(array, array_size);

	// Free the allocated memory
	free(array);
	
	return 0;
}




