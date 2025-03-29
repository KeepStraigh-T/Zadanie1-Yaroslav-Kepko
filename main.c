#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	void cyklicky_posun_rychlo(int *p, int l, int s);
	void fill_array(int *array, int array_size);
	void print_array(int *array, int array_size);
	
	
	int main(int argc, char **argv)
		{
			srand(time(NULL));

			if(argc < 3)
				{
					printf("Usage: %s <array_size> <shifts_number>\n", argv[0]);
					return 1;
				}

			char *endptr;
			int array_size = strtol(argv[1], &endptr, 10);
			
			if(*endptr != '\0' || array_size <= 0)
				{
					printf("Error: array_size must be a positive number\n");
					return 1;
				}
			
			int shifts_number = strtol(argv[2], &endptr, 10);

			if(*endptr != '\0' || shifts_number < 0)
				{
					printf("Error: shifts_number must be a non-negative number\n");
					return 1;
				}

			int *array = calloc(array_size, sizeof(int));

			if(array == NULL)
				{
					printf("Memory allocation failed\n");
					return 1;
				}

			fill_array(array, array_size);
			print_array(array, array_size);
			cyklicky_posun_rychlo(array, array_size, shifts_number);
			print_array(array, array_size);
			
			free(array);
			
			return 0;
		}
 
	void print_array(int *array, int array_size)
		{
			for(int i = 0; i < array_size; i++)
				printf("%d ", array[i]);

			printf("\n");
		}
	
	void fill_array(int *array, int array_size)
		{
			for(int i = 0; i < array_size; i++)
				{
					array[i] = rand() % 10;
				}
		}


	void cyklicky_posun_rychlo(int *p, int array_size, int shift_size)
		{
			int temp = 0;
			int current_value = 0;;
			int counter = 0;
			int current_index = 0;

			shift_size %= array_size; //Reduce shift size

			if(shift_size == 0) 
				{
					printf("\nNumber of shifts equals the array size so no moves are needed\n\n");
					return;
				}

					for(int start = 0; counter < array_size; start++)
						{
							current_index = start;
							current_value = *(p + current_index);

							do
								{
									current_index = (current_index + shift_size) % array_size;
									temp = p[current_index]; 
									p[current_index] = current_value;
									current_value = temp;
									counter++;
		
								} while(current_index != start);
						}
			
		}

