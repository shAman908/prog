#include "Proc.h"
#include <string>

bool Skobina::Procedural_Input(Procedural& Obj, ifstream& FileInput)
{
	string TempString;

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

	int State = stoi(TempString);

	getline(FileInput, TempString, '\n'); // ������� ���������� ������

	if (State > 0)
	{
		Obj.AbstractType = true;
	}
	else
	{
		Obj.AbstractType = false;
	}
	return true;
}


void Skobina::Procedural_Output(Procedural& Obj, ofstream& FileOutput)
{
	FileOutput << "It is Procedural programming language: Abstract data types is ";
	if (Obj.AbstractType)
	{
		FileOutput << "present, ";
	}
	else
	{
		FileOutput << "missing, ";
	}
}