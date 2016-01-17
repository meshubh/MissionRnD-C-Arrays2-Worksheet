/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	if (A == NULL || B == NULL)
		return NULL;
	else
	{
		struct transaction *output = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
		int iterator1, iterator2, iterator3 = 0, arr1_year, arr1_month, arr1_day, arr2_day, arr2_month, arr2_year;
		for (iterator1 = 0; iterator1 < ALen; iterator1++)
		{
			arr1_year = A[iterator1].date[6] * 1000 + A[iterator1].date[7] * 100 + A[iterator1].date[8] * 10 + A[iterator1].date[9];
			arr1_month = A[iterator1].date[3] * 10 + A[iterator1].date[4];
			arr1_day = A[iterator1].date[0] * 10 + A[iterator1].date[1];
			for (iterator2 = 0; iterator2 < BLen; iterator2++)
			{
				arr2_year = B[iterator2].date[6] * 1000 + B[iterator2].date[7] * 100 + B[iterator2].date[8] * 10 + B[iterator2].date[9];
				if (arr1_year == arr2_year)
				{
					arr2_month = B[iterator2].date[3] * 10 + B[iterator2].date[4];
					if (arr1_month == arr2_month)
					{
						arr2_day = B[iterator2].date[0] * 10 + B[iterator2].date[1];
						if (arr1_day == arr2_day)
						{
							output[iterator3] = A[iterator1];
							iterator3++;
						}
						else if (arr1_day < arr2_day)
						{
							break;
						}
					}
					else if (arr1_month < arr2_month)
					{
						break;
					}
				}
				else if (arr1_year<arr2_year)
				{
					break;
				}
			}
		}
		if (iterator3 == 0)
			return NULL;
		else
			return output;
	}
}