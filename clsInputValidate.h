#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
using namespace std;

class clsInputValidate
{
public:
	template<typename T>
	static bool IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From && Number <= To);
	}

	/*static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}
*/

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		return (( ( (clsDate::IsDate1AfterDate2(Date, From)) || (clsDate::IsDate1EqualToDate2(Date, From)) ) 
				&& 
				((clsDate::IsDate1BeforeDate2(Date, To)) || (clsDate::IsDate1EqualToDate2(Date, To))) )
			||
				( ((clsDate::IsDate1AfterDate2(Date, To)) || (clsDate::IsDate1EqualToDate2(Date, To)))
				&& 
				((clsDate::IsDate1BeforeDate2(Date, From)) || (clsDate::IsDate1EqualToDate2(Date, From))) ));
	}
	
	template <typename T> static 
		T ReadNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		T Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	//old
	/*static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter agian\n")
	{
		int Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter agian\n")
	{
		short Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter agian\n")
	{
		double Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter agian\n")
	{
		float Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}
*/

	template<typename T>
	static int ReadNumberBetween(T From, T To, string ErrorMessage)
	{
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	//old
	/*
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage)
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage << endl;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage)
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage << endl;
			Number = ReadShortNumber();
		}

		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage)
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage << endl;
			Number = ReadDblNumber();
		}

		return Number;
	}
*/

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}
};

