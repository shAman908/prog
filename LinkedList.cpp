#include "LinkedList.h"

void Skobina::Init(Linked_List& Obj) // �����������
{
	Obj.Head = NULL;
	Obj.Tail = NULL;
	Obj.SizeLinkedList = 0;
}


void Skobina::Clear(Linked_List& Obj) // ����������
{
	Node* TempNode = NULL;

	while (Obj.Tail != NULL)
	{
		TempNode = Obj.Tail->Previous;
		delete Obj.Tail;
		Obj.Tail = TempNode;
		--Obj.SizeLinkedList;
	}
	Obj.Head = TempNode;
}


void Skobina::Linked_List_Input(Linked_List& Obj, ifstream& FileInput)
{
	Node* TempNode;

	while (!FileInput.eof())
	{
		TempNode = new Node;

		TempNode->Langu = Language_Input(FileInput); // ���������� ����� ������
		TempNode->Next = NULL;
		++Obj.SizeLinkedList;

		if (Obj.Head == NULL)
		{
			TempNode->Previous = NULL;
			Obj.Head = Obj.Tail = TempNode;
		}
		else
		{
			TempNode->Previous = Obj.Tail;
			Obj.Tail->Next = TempNode;
			Obj.Tail = TempNode;
		}
	}
}


void Skobina::Linked_List_Output(Linked_List& Obj, ofstream& FileOutput)
{
	Node* TempNode = Obj.Head; // �������� ��������� �� ������ �������
	FileOutput << "Container contains " << Obj.SizeLinkedList << " elements." << endl;

	for (size_t i = 0; i < Obj.SizeLinkedList; i++)
	{
		FileOutput << i + 1 << ": ";
		if (TempNode->Langu == NULL)
		{
			FileOutput << "Error reading data! Expected other values in the string." << endl;
		}
		else
		{
			Language_Output(*TempNode->Langu, FileOutput);
			FileOutput << "The number of years that have passed since the year the language was created = "
				<< Past_Years(*TempNode->Langu) << endl;
		}
		TempNode = TempNode->Next;
	}
}


void Skobina::Sort_List(Linked_List& Obj) // ������� ���������� ������
{
	if (Obj.SizeLinkedList < 2) // ������ � ����� ��������� �� �����������
	{
		return;
	}

	Node* TempNode = Obj.Head;
	bool Flag = false;

	do
	{
		TempNode = Obj.Head;
		Flag = false;

		for (size_t i = 0; i < (Obj.SizeLinkedList - 1); ++i)
		{
			if (Compare(TempNode->Langu, TempNode->Next->Langu))
			{
				Swap(Obj, TempNode, TempNode->Next);
				Flag = true;
			}
			else
			{
				TempNode = TempNode->Next;
			}
		}
	} while (Flag);
}


void Skobina::Swap(Linked_List& Obj, Node* First, Node* Second)
{
	if ((First->Previous == NULL) && (Second->Next == NULL)) // ���� ����� 2 �������� � ������
	{
		Obj.Head = Second;
		Obj.Tail = First;
		First->Previous = Second;
		Second->Next = First;
		First->Next = NULL;
		Second->Previous = NULL;
		return;
	}
	if ((First->Previous == NULL) && (Second->Next != NULL))
	{
		First->Next = Second->Next;
		First->Previous = Second;
		Second->Next->Previous = First;
		Second->Next = First;
		Second->Previous = NULL;
		Obj.Head = Second;
		return;
	}
	if ((First->Previous != NULL) && (Second->Next == NULL))
	{
		Second->Previous = First->Previous;
		First->Previous = Second;
		First->Next = NULL;
		Second->Next = First;
		Second->Previous->Next = Second;
		Obj.Tail = First;
		return;
	}
	if ((First->Previous != NULL) && (Second->Next != NULL))
	{
		First->Next = Second->Next;
		Second->Previous = First->Previous;
		Second->Next = First;
		First->Previous = Second;
		Second->Previous->Next = Second;
		First->Next->Previous = First;
		return;
	}
}


void Skobina::Linked_List_Output_Only_Procedural(Linked_List& Obj, ofstream& FileOutput)
{
	Node* TempNode = Obj.Head;
	FileOutput << endl << "Only Procedural languages." << endl;

	for (size_t i = 0; i < Obj.SizeLinkedList; i++)
	{
		FileOutput << i + 1 << ": ";
		if (TempNode->Langu == NULL)
		{
			FileOutput << endl;
			continue;
		}
		if (TempNode->Langu->Key == Language::Lang::PROCEDURAL)
		{
			Language_Output(*TempNode->Langu, FileOutput);
		}
		else
		{
			FileOutput << endl;
		}
		TempNode = TempNode->Next;
	}
	FileOutput << endl;
}