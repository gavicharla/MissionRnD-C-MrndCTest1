/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *a, int len){
	if (a == NULL )
		return NULL;
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	int start1 = -1, end1 = -1;
	int* diff = (int *)malloc(sizeof(int)* (len - 1));
	int k = 0;
	for (int i = 0, j = 1; i < len - 1; i++, j++)
	{
		diff[k++] = a[j] - a[i];
	}
	int recur_diff = 0, flag = 0;
	int * final = (int*)malloc(sizeof(int) * 6);
	for (int i = 0; i < 6; i++)
		final[i] = -1;
	for (int i = 0, j = 1; i < k - 1; i++, j++)
	{
		if (diff[i] == diff[j])
		{
			recur_diff++;
			end1 = j;
			if (recur_diff == 1)
				start1 = i;
			printf("%d %d\n", diff[i], diff[j]);
		}
		else
		{

			if (start1 != -1)
			{
				if (final[0] == -1)
				{
					final[0] = end1 - recur_diff;
					final[1] = final[0] + recur_diff + 1;
				}
				else if (final[2] == -1)
				{
					final[2] = end1 - recur_diff;
					final[3] = final[2] + recur_diff + 1;
				}
				start1 = -1;
				end1 = -1;
				recur_diff = 0;
			}
		}

	}
	if (start1 != -1 && final[2] == -1)
	{
		final[2] = end1 - recur_diff;
		final[3] = final[2] + recur_diff + 1;
	}
	recur_diff = 0;
	start1 = -1;
	end1 = -1;
	for (int i = 0, j = 1; i<len - 2; i++, j++)
	{
		if ((float)a[j] / a[i] == (float)a[j + 1] / a[j])
		{
			if (start1 == -1)
				start1 = i;
			end1 = j + 1;
			recur_diff++;
		}
	}
	final[4] = start1;
	final[5] = end1;
	return final;
}