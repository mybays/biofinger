#include<stdio.h>

#include "bsapi.h"
//#include "bstypes.h"
//#include "bserror.h"

int main()
{
	printf("hello world.\n");
	
	ABS_STATUS res;
	res = ABSInitialize();
	if(res != ABS_STATUS_OK)
	{
		printf("ABSInitilize() failed\n");
		return -1;
	}
	
	ABSTerminate();
	return 0;
}