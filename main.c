#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	void cyklicky_posun_rychlo(int *p, int l, int s);
	int gcd(int array_size, int shift_size);
	void fill_array(int *array, int array_size);
	
	
	int main(int argc, char **argv)
		{
			srand(time(NULL));

			if(argc < 3)
				{
					printf("Usage: %s <array_size> <shifts_number>\n", argv[0]);
					return 1;
				}

			int array_size = atoi(argv[1]);
			int shifts_number = atoi(argv[2]);
			
			if(array_size <= 0)
				{
					printf("Error: array_size must be a positive number\n");
					return 1;
				}
			
			if(shifts_number < 0)
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

			for(int i = 0; i < array_size; i++)
				printf("%d ", array[i]);

			printf("\n");
				
			cyklicky_posun_rychlo(array, array_size, shifts_number);
				
			for(int i = 0; i < array_size; i++)
				printf("%d ", array[i]);

			printf("\n");

			free(array);
			return 0;
		}
 
	void fill_array(int *array, int array_size)
		{
			for(int i = 0; i < array_size; i++)
				{
					array[i] = rand() % 100;
				}
		}

	int gcd(int array_size, int shift_size)
		{
			if(array_size == 0)
				return shift_size;

			if(shift_size == 0)
				return array_size;

			if (array_size == shift_size)
				return array_size;

			if(array_size > shift_size)
				return gcd(array_size - shift_size, shift_size);

			if(shift_size > array_size)
				return gcd(array_size, shift_size - array_size);
		}

	void cyklicky_posun_rychlo(int *p, int array_size, int shift_size)
		{
			int temp = 0;
			int current_value = 0;
			int gcd1 = 0;
			int counter = 0;
			int current_index = 0;

			shift_size %= array_size; //Reduce shift size

			if(shift_size == 0) 
				{
					printf("Number of shifts equals the array size so no moves are needed\n");
					return;
				}

			gcd1 = gcd(array_size, shift_size);

			
			if(gcd1 == 1)
				{
					current_value = *p;

					do
						{
							current_index += shift_size;
							current_index %= array_size;
							temp = p[current_index]; 
							p[current_index] = current_value;
							current_value = temp;
							counter++;

						} while(counter != array_size);
					}
			
			else if(gcd1 > 1)
				{

					for(int i = 0; i < gcd1; i++)
						{
							current_value = *(p + i);
							current_index = i;
							counter = 0;

							do
								{
									current_index += shift_size;
									current_index %= array_size;
									temp = p[current_index]; 
									p[current_index] = current_value;
									current_value = temp;
									counter++;
		
								} while(counter != array_size / gcd1);
						}
				}
			
		}

