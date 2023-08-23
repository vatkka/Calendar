/*COMP-111 Programming Principles I Assignment 3
Dmitrii Frolov U214N1483*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

#define BLACK 0
#define RED 4
#define WHITE 15

HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

void TextColor(int fontcolor, int backgroundcolor)
{
	int color_attribute;
	color_attribute = backgroundcolor;
	color_attribute = _rotl(color_attribute, 4) | fontcolor;
	SetConsoleTextAttribute(screen, color_attribute);
}

bool leapYear(int y0)  //this function outputs true if the year is a leap year and false if not
{
	if ((y0 % 4 == 0 && y0 % 100 != 0) || y0 % 400 == 0)
		return true;
	else
		return false;
}

int  dayCount(int x, int y1)
{
	int dayC;
	switch (x)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: dayC = 31; break;
	case 4:
	case 6:
	case 9:
	case 11: dayC = 30; break;
	case 2:
	{ if (leapYear(y1) == true)
		dayC = 29;
	else
		dayC = 28;

	}

	}

	return dayC;
	

}

void monthName(int monthNumber)
{

	switch (monthNumber)
	{
	case 1: cout << setw(20) << "January\n"; break;
	case 2:cout << setw(20) << "February\n"; break;
	case 3:cout << setw(19) << "March\n"; break;
	case 4:cout << setw(19) << "April\n"; break;
	case 5:cout << setw(18) << "May\n"; break;
	case 6:cout << setw(19) << "June\n"; break;
	case 7:cout << setw(19) << "July\n"; break;
	case 8:cout << setw(20) << "August\n"; break;
	case 9:cout << setw(21) << "September\n"; break;
	case 10:cout << setw(20) << "October\n"; break;
	case 11:cout << setw(20) << "November\n"; break;
	case 12:cout << setw(20) << "December\n"; break;
	};
	cout << "   S   M   T   W   T   F   S  \n";
	cout << " ----------------------------\n";
}

int weekDay (int cYear)
{
	int c = (cYear - 1) / 100;
	int y = (cYear - 1) % 100;
	int w = ((29 - (2 * c) + y + (y / 4) + (c / 4)) % 7 + 7) % 7;

	return w;


}

void display (int m1,int wDay)
{

	int wDay1 = (wDay + 1) * 4;
	cout << setw(wDay1);
	
	for (int d = 1; d <= m1; d++)
	{
		if (wDay % 7 == 0)
			TextColor(4, 15);
		else
			TextColor(0, 15);
		cout  << d << setw(4);
		
		wDay++;
		if (wDay % 7 == 0)
		{

			cout  << endl;
		}
	
	}
	TextColor(0, 15);
	cout << endl << endl;
}


int main()
{
	bool b = true;
	cout << b << endl ;
	system("color f0");
	int year;
	cout << "Enter year: ";
	cin >> year;
	cout << endl << endl<< setw(17)<< year << endl;
	int day = weekDay(year);

	for (int month = 1; month <= 12; month++)
	{
		monthName(month);
		display(dayCount(month, year),day);
		day = (dayCount(month, year)+day)%7;
	}

}

