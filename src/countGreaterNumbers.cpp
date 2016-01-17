/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
struct transaction
{
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int given_day, given_month, given_year, arr_day, arr_month, arr_year;
	given_day = date[0] * 10 + date[1];
	given_month = date[3] * 10 + date[4];
	given_year = date[6] * 1000 + date[7] * 100 + date[8] * 10 + date[9];
	int iterator = 0, count = 0;
	while (iterator < len)
	{
		arr_year = Arr[iterator].date[6] * 1000 + Arr[iterator].date[7] * 100 + Arr[iterator].date[8] * 10 + Arr[iterator].date[9];
		if (arr_year > given_year)
		{
			count++;
			iterator++;
		}
		else if (arr_year == given_year)
		{
			arr_month = Arr[iterator].date[3] * 10 + Arr[iterator].date[4];
			if (arr_month > given_month)
			{
				count++;
				iterator++;
			}
			else if (arr_month == given_month)
			{
				arr_day = Arr[iterator].date[0] * 10 + Arr[iterator].date[1];
				if (arr_day > given_day)
				{
					count++;
					iterator++;
				}
				else
					iterator++;
			}
			else
				iterator++;
		}
		else
			iterator++;
	}
	return count;
}