#include <stdlib.h>
#include "cdata.h"
#include "utils.h"
#include "TBool.h"

// Searches queue for the thread with the TID == content
// At the end, the it of the queue will be positioned on the found element, else it will be null
EOperationStatus SearchThreadFila2(PFILA2 queue, int content)
{
	// Operation status
	EOperationStatus retStatus = OpUknownError;

	// If allocation was successfull
	if (queue != NULL)
	{
		// Initializing iterator
		if (FirstFila2(queue) == 0)
		{
			// Found flag
			TBool found = false;
			// Iterates through the queue
			while ((queue->it != queue->last->next) && (found != true))
			{
				// If the TID of the thread is equal to the content
				if ((((TCB_t*)queue->it->node)->tid == content))
				{
					found = true;
				}
				// If not found
				if (!found)
				{
					NextFila2(queue);
				}
			}
			// If the element was not found, then we set to null it
			if (!found)
			{
				queue->it = NULL;
			}
			// Operation success if it could search and try to find
			retStatus = OpSuccess;
		}
	}
	else
	{
		// Null struct received
		retStatus = OpNullStructError;
	}

	return retStatus;
}

// Searches queue for the pair where p1 == content
// At the end, the it of the queue will be positioned on the found element, else it will be null
// Optype == 1 when searching for p1 and == 2 when searching p2 
EOperationStatus SearchFila2(PFILA2 queue, int content, int opType)
{
	// Operation status
	EOperationStatus retStatus = OpUknownError;

	// If allocation was successfull
	if (queue != NULL)
	{
		// Initializing iterator
		if (FirstFila2(queue) == 0)
		{
			// Found flag
			TBool found = false;
			// Iterates through the queue
			while ((queue->it != queue->last->next) && (found != true))
			{
				switch (opType)
				{
				case 1:
					// If the p1 of the pair is equal to the content
					if ((((pair*)queue->it->node)->p1 == content))
					{
						found = true;
					}
					// If not found
					if (!found)
					{
						NextFila2(queue);
					}
					break;
				case 2:
					// If the p2 of the pair is equal to the content
					if ((((pair*)queue->it->node)->p2 == content))
					{
						found = true;
					}
					// If not found
					if (!found)
					{
						NextFila2(queue);
					}
					break;
				default:
					break;
				}
			}
			// If the element was not found, then we set to null it
			if (!found)
			{
				queue->it = NULL;
			}
			// Operation success if it could search and try to find
			retStatus = OpSuccess;
		}
	}
	else
	{
		// Null struct received
		retStatus = OpNullStructError;
	}

	return retStatus;
}

// Gets the size of a queue, returns 0 for NULL
int GetSizeFila2(PFILA2 queue)
{
	// Size of the queue
	int size = 0;

	// If allocation was successfull
	if (queue != NULL)
	{
		// Initializing iterator
		if (FirstFila2(queue) == 0)
		{
			// Iterates through the queue
			for (; queue->it != queue->last->next; NextFila2(queue))
			{
				// Adds to the size
				size++;
			}
		}
	}

	return size;
}

// Free queue and its contents
void freeQueue(PFILA2* queue)
{
	while ((*queue)->it != (*queue)->last->next)
	{
		FirstFila2((*queue));
		// Free content
		free((*queue)->it->node);
		// Free node
		DeleteAtIteratorFila2((*queue));
	}

	free(queue);
}