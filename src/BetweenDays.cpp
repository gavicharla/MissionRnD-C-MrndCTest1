/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int return_day(int date, int month, int year)
{
	return 365 * year + year / 4 - year / 100 + year / 400 + date + (153 * month + 8) / 5;
}
int between_days(struct node *date1head, struct node *date2head){
	if (date1head ==NULL || date2head == NULL)
		return -1;
	int i = 8;
	int day1 = 0, day2 = 0, mon1 = 0, mon2 = 0, y1 = 0, y2 = 0;
	while (i--)
	{
		if (i >= 6)
		{
			day1 = day1 * 10 + date1head->data;
			day2 = day2 * 10 + date2head->data;
		}
		else if (i > 3)
		{
			mon1 = mon1 * 10 + date1head->data;
			mon2 = mon2 * 10 + date2head->data;
		}
		else
		{
			y1 = y1 * 10 + date1head->data;
			y2 = y2 * 10 + date2head->data;
		}
		date1head = date1head->next;

		date2head = date2head->next;
	}
	return return_day(day2, mon2, y2) - return_day(day1, mon1, y1) - 1;
}