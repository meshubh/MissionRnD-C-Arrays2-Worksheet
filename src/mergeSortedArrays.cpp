/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
#include<malloc.h>
#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	if (A == NULL || B == NULL)
		return NULL;
	else
	{
		struct transaction *output = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
		int iterator1 = 0, iterator2 = 0, iterator3 = 0, fin_len, arr1_year, arr1_month, arr1_day, arr2_day, arr2_month, arr2_year;
		fin_len = BLen + ALen;
		while (iterator1 + iterator2 < fin_len)
		{
			arr1_year = A[iterator1].date[6] * 1000 + A[iterator1].date[7] * 100 + A[iterator1].date[8] * 10 + A[iterator1].date[9];
			arr2_year = B[iterator2].date[6] * 1000 + B[iterator2].date[7] * 100 + B[iterator2].date[8] * 10 + B[iterator2].date[9];
			if (arr1_year > arr2_year)
			{
				if (iterator2 < BLen)
				{
					output[iterator3] = B[iterator2];
					iterator3++;
					iterator2++;
				}
				else
				{
					while (iterator1 < ALen)
					{
						output[iterator3] = A[iterator1];
						iterator3++;
						iterator1++;
					}
					break;
				}
			}
			else if (arr1_year<arr2_year)
			{
				if (iterator1 < ALen)
				{
					output[iterator3] = A[iterator1];
					iterator3++;
					iterator1++;
				}
				else
				{
					while (iterator2 < BLen)
					{
						output[iterator3] = B[iterator2];
						iterator2++;
						iterator3++;
					}
					break;
				}

			}
			else
			{
				arr1_month = A[iterator1].date[3] * 10 + A[iterator1].date[4];
				arr2_month = B[iterator2].date[3] * 10 + B[iterator2].date[4];
				if (arr1_month > arr2_month)
				{
					if (iterator2 < BLen)
					{
						output[iterator3] = B[iterator2];
						iterator3++;
						iterator2++;
					}
					else
					{
						while (iterator1 < ALen)
						{
							output[iterator3] = A[iterator1];
							iterator3++;
							iterator1++;
						}
						break;
					}
				}
				else if (arr1_month<arr2_month)
				{
					if (iterator1 < ALen)
					{
						output[iterator3] = A[iterator1];
						iterator3++;
						iterator1++;
					}
					else
					{
						while (iterator2 < BLen)
						{
							output[iterator3] = B[iterator2];
							iterator2++;
							iterator3++;
						}
						break;
					}
				}
				else
				{
					arr1_day = A[iterator1].date[0] * 10 + A[iterator1].date[1];
					arr2_day = B[iterator2].date[0] * 10 + B[iterator2].date[1];
					if (arr1_day > arr2_day)
					{
						if (iterator2 < BLen)
						{
							output[iterator3] = B[iterator2];
							iterator3++;
							iterator2++;
						}
						else
						{
							while (iterator1 < ALen)
							{
								output[iterator3] = A[iterator1];
								iterator3++;
								iterator1++;
							}
							break;
						}
					}
					else if (arr1_day<arr2_day)
					{
						if (iterator1 < ALen)
						{
							output[iterator3] = A[iterator1];
							iterator3++;
							iterator1++;
						}
						else
						{
							while (iterator2 < BLen)
							{
								output[iterator3] = B[iterator2];
								iterator2++;
								iterator3++;
							}
							break;
						}
					}
					else
					{
						output[iterator3] = A[iterator1];
						iterator3++;
						iterator1++;
						output[iterator3] = B[iterator2];
						iterator3++;
						iterator2++;
					}
				}
			}
		}
		return output;
	}
}