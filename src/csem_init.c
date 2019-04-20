/*
	csem_init from cthread.h implementation.
*/

#include <stdlib.h>
#include <errno.h>
#include "cthread.h"
#include "EOperationStatus.h"
#include "support.h"

/******************************************************************************
Par�metros:
	sem:	ponteiro para uma vari�vel do tipo csem_t. Aponta para uma estrutura de dados que representa a vari�vel sem�foro.
	count: valor a ser usado na inicializa��o do sem�foro. Representa a quantidade de recursos controlados pelo sem�foro.
Retorno:
	Quando executada corretamente: retorna 0 (zero)
	Caso contr�rio, retorna um valor negativo.
******************************************************************************/
int
csem_init(csem_t *sem, int count)
{
	// Operation status to be returned
	EOperationStatus returnCode = OpUknownError;

	// If allocation was successfull
	if (sem != NULL)
	{
		// sets semaphore counter
		sem->count = count;
		// Allocates queue
		sem->fila = (PFILA2)malloc(sizeof(FILA2));
		// sets semaphore queue
		if ((errno != ENOMEM) && (CreateFila2(sem->fila) == 0))
		{
			// operation was successfull
			returnCode = OpSuccess;
		}
		else
		{
			// Could not allocate queue
			returnCode = OpAllocError;

			// If the operation failed and we allocated memory, we need to free it
			free(sem);
		}
	}
	else
	{
		// Null struct
		returnCode = OpNullStructError;
	}

	return returnCode;
}