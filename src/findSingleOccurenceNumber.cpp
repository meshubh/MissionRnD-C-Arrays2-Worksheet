/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

int findSingleOccurenceNumber(int *A, int len) 
{
	if (A== nullptr || len<=0)
		return -1;
	else
	{
		int iterator, iterator1, count = 0;
		for (iterator = 0; iterator < len; iterator++)
		{
			for (iterator1 = iterator; iterator1 < len; iterator1++)
			{
				if (A[iterator]>A[iterator1])
				{
					A[iterator] = A[iterator] + A[iterator1];
					A[iterator1] = A[iterator] - A[iterator1];
					A[iterator] = A[iterator] - A[iterator1];
				}
			}
		}
		for (iterator = 0; iterator < len; iterator++)
		{
			if (iterator > 0 && iterator < len-1)
			{
				if (A[iterator - 1] != A[iterator] && A[iterator] != A[iterator + 1])
				{
					return A[iterator];
				}
			}
			else if (iterator == 0)
			{
				if (A[iterator] != A[iterator + 1])
				{
					return A[iterator];
				}
			}
			else
			{
				if (A[iterator - 1] != A[iterator])
				{
					return A[iterator];
				}
			}
		}

	}

}