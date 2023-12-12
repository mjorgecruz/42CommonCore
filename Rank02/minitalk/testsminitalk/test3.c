#include <stdio.h>

int main()
{
	static __CHAR16_TYPE__ rec = 0;

		rec |= 1;
		rec |= 0;
	rec<<=1;
	printf("%x", rec);	
}