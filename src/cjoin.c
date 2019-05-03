#include <stdlib.h>
#include "cthread.h"
#include "EOperationStatus.h"

/******************************************************************************
Par�metros:
	tid:	identificador da thread cujo t�rmino est� sendo aguardado.
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contr�rio, retorna um valor negativo.
******************************************************************************/
int cjoin(int tid)
{
	// Operation return code
	EOperationStatus returnCode = OpUknownError;

	// Search for the tid to see if thread exists

	// if it exists, we should block this one and the next thread with the highest priority

	// else we return error

	return returnCode;
}