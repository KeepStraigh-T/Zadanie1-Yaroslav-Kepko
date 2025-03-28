#include <stdio.h>

	void cyklicky_posun_rychlo(int *p, int l, int s);
	int gcd(int array_size, int shift_size);

	int main(void)
		{
			int array[6] = {5, 4, 2, 7, 8, 9};
			int array_size = sizeof(array) / sizeof(array[0]); 
			
			printf("%d\n",gcd(11,4));
			// cyklicky_posun_rychlo(array, array_size, 5);
			return 0;
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
			int *temp;

			shift_size %= array_size; //Reduce shift size

			if(shift_size == 0) 
				return;
		}

