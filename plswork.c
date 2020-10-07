






#include <stdbool.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

int main(void)
{
	int DoW_index = 0;
	int illness_input = 0;
	int exempt_input = 0;
	int DoW = 0;
	int classesDoW[7] = { 1, 2, 1, 2, 0, 0, 0 }; // CHANGE THIS TO YOUR OWN TIMETABLE- THE NUMBERS INDICATE HOW//
	                                           // MANY CLASSES YOU HAVE ON EACH DAY, STARTING ON MONDAY//
	long today = 0;
	long startClasses = 20200914;
	long endClasses = 20201211;
	long startStudyWeek = 20201016;
	long endStudyWeek = 20201020;
	long startExamWeek = 20201214;
	long endExamWeek = 20201218;
	long thanksgivingDay = 20201012;

	bool term;
	bool isHoliday;
	bool StudyWeek;
	bool hasClass;
	bool ill;
	bool hasExam;
	bool exemption;


	//=============================================//
	//Retrieving user input//
	{
		printf("====Boolean Bash====");

		printf("\nPlease enter today's calendar date (YYYYMMDD): ");
		scanf("%ld", &today);

		printf("\nPlease enter the day of week corresponding to ISO 8601 standards: ");
		scanf(" %d", &DoW);

		printf("\nIf you are sick, enter 1. If not, enter 0: ");
		scanf(" %d", &illness_input);

		printf("\nIf you have an exemption, enter 1. If you don't have one (or don't require such) enter 0: ");
		scanf(" %d", &exempt_input);

	}

	//=============================================//
	//Defining the boolean variables//

	if (today >= startClasses && today <= endClasses)
	{
		term = true;
	}
	else
	{
		term = false;
	}


	DoW_index = DoW - 1;

	if (classesDoW[DoW_index] == 0)
	{
		hasClass = false;
	}
	else
	{
		hasClass = true;
	}

	if (illness_input ==1)
	{
		ill = true;
	}
	else
		ill = false;

	if (exempt_input ==1)
		exemption = true;
	else
		exemption = false;

	if (today >= startClasses && today <= endClasses)
	{
		term = true;
	}
	else
	{
		term = false;
	}

	if (today != thanksgivingDay)
	{
		isHoliday = false;
	}
	else
	{
		isHoliday = true;
	}

	if (today >= startStudyWeek && today <= endStudyWeek)
	{
		StudyWeek = true;
	}
	else
	{
		StudyWeek = false;
	}

	if (today >= startExamWeek && today <= endExamWeek)
	{
		hasExam = true;
	}
	else
	{
		hasExam = false;
	}

	//=============================================//
	//Evalulating the user input//

	if (term)
	{
		if (ill||isHoliday||StudyWeek||!hasClass)
		{
			printf("\nYou do not have to attend college today. Although, I'm sure there's some homework you could be working on...");
		}

		if (hasClass && !isHoliday && !ill)
		{
			printf("\nYou have class today!");
		}
		

	}
	else
	{
		if (hasExam && ill && exemption)
		{
			printf("\nYou have an exam, but you took the appropriate steps given the circumtances. Get some rest!");
		}
		else
		{
			printf("\nYou HAVE to attend and write an exam. I hope you studied...");
		}
	}




 
	return 0; 

}

	
	


	

