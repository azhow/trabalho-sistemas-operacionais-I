#include <stdio.h>
#include "ETestStatus.h"
#include "testMain.h"
#include "testExample.h"
#include "testCSem_Init.h"
#include "testCSignal.h"
#include "testCIdentify.h"
#include "testCWait.h"
#include "testCYield.h"
#include "testCJoin.h"
#include "testCCreate.h"
#include "sourceExample.h"

ETestStatus runAllTests()
{
	// All tests variable
	ETestStatus overallTestStatus = TestSuccess;
	// Current test variable
	ETestStatus currentTestStatus = TestSuccess;

	// csem_init test
	// Currently running test 
	printf("csem_init_test:\t");
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

	// csignal test
	// Currently running test 
	printf("csignal_test:\t");
	// Run the test
	currentTestStatus = csignal_test();
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

	// cidentify test
	// Currently running test
	printf("cidentify_test:\t");
	// Run the test
	currentTestStatus = cidentify_test();
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

	// cwait test
	// Currently running test
	printf("cwait_test:\t");
	// Run the test
	currentTestStatus = cwait_test();
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

	// cyield test
	// Currently running test
	printf("cyield_test:\t");
	// Run the test
	currentTestStatus = cyield_test();
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

	// cyield test
	// Currently running test
	printf("cjoin_test:\t");
	// Run the test
	currentTestStatus = cjoin_test();
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

	// ccreate test
	// Currently running test
	printf("ccreate_test:\t");
	// Run the test
	currentTestStatus = ccreate_test();
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