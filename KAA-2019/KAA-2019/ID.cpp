#include "stdafx.h"

namespace ID
{
	IdTable Create(int size)
	{
		if (size >= TI_MAXSIZE)
			throw ERROR_THROW(114, ERROR_ZERO_LINE, ERROR_ZERO_COL);
		IdTable itable = { size, 0, new Entry[size] };
		return itable;
	}

	void Add(IdTable& itable, Entry istr)
	{
		itable.table[itable.size] = istr;
		itable.size++;
		if (itable.size >= itable.maxsize)
			throw ERROR_THROW(114, ERROR_ZERO_LINE, ERROR_ZERO_COL);
	}

	void Delete(IdTable& itable)
	{
		if (!&itable)
			throw ERROR_THROW(118, ERROR_ZERO_LINE, ERROR_ZERO_COL);
		delete itable.table;
		itable.table = nullptr;
	}

	Entry GetEntry(IdTable& itable, int nstr)
	{
		if (itable.size > nstr)
			throw ERROR_THROW(119, ERROR_ZERO_LINE, ERROR_ZERO_COL);
		return itable.table[nstr];
	}

	Id getid(wchar_t idfile[])
	{
		Id id;
		wcscpy_s(id.idfile, idfile);
		ofstream *FILE = new ofstream;
		(*FILE).open(idfile);
		if (!(*FILE).is_open())
			throw ERROR_THROW(108, ERROR_ZERO_LINE, ERROR_ZERO_COL);
		id.stream = FILE;
		return id;
	}
	void Close(Id id)
	{
		(*id.stream).close();
	}
	void WriteId(Id id, ID::IdTable& itable)
	{
		*id.stream << "\t������� ���������������:\n\n";
		*id.stream << "   ������\t��� Id\t ��� ����������\t���\t  ��������\n\n";
		for (unsigned int i = 0; i < (unsigned int)itable.size; i++)
		{
			*id.stream << "\t" << itable.table[i].idxfirstLE << "\t\t" << itable.table[i].idtype << " \t\t" << itable.table[i].iddatatype << "\t\t " << itable.table[i].id << "\t";
			if (itable.table[i].iddatatype == ID::INT)
				*id.stream << "\t" << itable.table[i].value.vint;
			else if (itable.table[i].iddatatype == ID::STR)
				*id.stream << "\t" << itable.table[i].value.vstr->str;
			else if (itable.table[i].iddatatype == ID::BOOL)
				*id.stream << "\t" << itable.table[i].value.vbool;
			*id.stream << endl;
		}
		*id.stream << "\n��� ID:\n   1- ����������\n   2 - �������\n   3 - ������� \n";
		*id.stream << "\n��� ����������:\n   1 - byte\n   2 - string\n   3 - bool";
		*id.stream << "\n\n";
	}
	void WriteData(Id id)
	{
		char Date[50];
		struct tm *date;
		const time_t nowtime = time(NULL);
		date = localtime(&nowtime);
		strftime(Date, 50, "%d.%m.%Y %H:%M:%S, %A", date);
		*id.stream << "----�������� id----" << endl;
		*id.stream << "����� �������� ���������: " << Date << endl;
	}
}