/* TO test the setjmp */
#include "../../include/setjmp.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>



void test_return_value()
{
	JmpBuf buf; /* Allocates the process contex */
	
	int flag = setjmp(&buf);

	if (flag == 0) { /* try something */
		puts("getting an error");
		longjmp(&buf, 10);
	} else {
		assert(flag == 10); /* It should be in 10 */
		puts("handling the error ");
	}
}

void test_process_contex()
{
	JmpBuf buf; /* Allocates the process contex */
	int val = 10;
	char somedata[] = "somedata";
	
	int flag = setjmp(&buf);


	if (flag == 0) { /* try something */
		puts("getting an error");
		longjmp(&buf, 0);
	} else {
		assert(flag == 1); /* It should be in 1 */
		puts("handling the error ");
	}


	assert(val == 10);
	assert(strcmp(somedata, "somedata") == 0);
}


int main(void)
{
	test_process_contex();
	test_return_value();
	
	return 0;
}