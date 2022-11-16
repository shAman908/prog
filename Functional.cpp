#include "Functional.h"
#include <string>

bool Skobina::Functional_Input(Functional& Obj, ifstream& FileInput)
{
	string TempString;

	FileInput >> TempString;
	if (TempString == "\0") // �������� �� ����� ������
	{
		return false;
	}
	if (TempString.length() > 1) // �������� �� ����� ������
	{
		getline(FileInput, TempString, '\n'); // ������� ���������� ������
		return false;
	}
	if (!isdigit(int(unsigned char(TempString.front())))) // �������� �� ���� �����
	{
		getline(FileInput, TempString, '\n'); // ������� ���������� ������
		return false;
	}

	int State = stoi(TempString);
	if (State > 0)
	{
		Obj.LazyCalculations = true;
	}
	else
	{
		Obj.LazyCalculations = false;
	}

	FileInput >> TempString;
	if (TempString == "\0") // �������� �� ����� ������
	{
		return false;
	}
	if (TempString.length() > 1) // �������� �� ����� ������
	{
		return false;
	}
	if (!isdigit(int(unsigned char(TempString.front())))) // �������� �� ���� �����
	{
		return false;
	}
	State = stoi(TempString);

	getline(FileInput, TempString, '\n'); // ������� ���������� ������

	switch (State)
	{
	case 1:
		Obj.Type = Functional::Typification::STRICT;
		return true;
	case 2:
		Obj.Type = Functional::Typification::DYNAMIC;
		return true;
	default:
		return false;
	}
}


void Skobina::Functional_Output(Functional& Obj, ofstream& FileOutput)
{
	FileOutput << "It is Functional programming language: Support \"lazy\" calculations is ";
	if (Obj.LazyCalculations)
	{
		FileOutput << "present, ";
	}
	else
	{
		FileOutput << "missing, ";
	}
	FileOutput << "Typification is ";

	switch (Obj.Type)
	{
	case Functional::Typification::STRICT:
		FileOutput << "strict, ";
		break;
	case Functional::Typification::DYNAMIC:
		FileOutput << "dynamic, ";
		break;
	default:
		break;
	}
}