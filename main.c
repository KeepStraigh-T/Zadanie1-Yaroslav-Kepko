#include <stdio.h>

	void cyklicky_posun_rychlo (int *p, int l, int s);

	int main (void)
		{
			int array[6] = {5, 4, 2, 7, 8, 9};
			int array_size = sizeof(array) / sizeof(array[0]);
			
			cyklicky_posun_rychlo(array, array_size, 5);
			return 0;
		}

	void cyklicky_posun_rychlo (int *p, int array_size, int shift_size)
		{

		}