#include <stdio.h>
#include "ETestStatus.h"
#include "testMain.h"
#include "testExample.h"
#include "csem_initTest.h"
#include "sourceExample.h"

ETestStatus runAllTests()
{
	// All tests variable
	ETestStatus overallTestStatus = TestSuccess;
	// Current test variable
	ETestStatus currentTestStatus = TestSuccess;

	// csem_init test
	// Currently running test 
	printf("testExampleSuccess:\t");
	// Run the test
	currentTestStatus = csem_init_test();
	// Check if test runned successfully
	if (currentTestStatus != TestSuccess)
	{
		overallTestStatus -= TestError;
		printf("FAILED\n");
	}
	else
	{
		printf("SUCCESS\n");
	}

	// If any test failed
	if (overallTestStatus != 0)
	{
		printf("Number of failed tests: %d\n", overallTestStatus);
	}

	return overallTestStatus;
}