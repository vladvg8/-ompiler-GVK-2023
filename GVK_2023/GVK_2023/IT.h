#pragma once
#define ID_MAXSIZE 25 // ������������ ����� ��������������
#define TI_MAXSIZE 4096 // ������������ ���������� ����� � ������� ���������������
#define TI_BYTE_DEFAULT 0 // �������� �� ��������� ��� byte - ������������� ��� ������ � 1 ����
#define TI_TEXT_DEFAULT "" // �������� �� ��������� ��� text - ������ string
#define TI_SYMBOL_DEFAULT '\0' // �������� �� ��������� ��� symbol - ������ char
#define TI_BOOLEAN_DEFAULT false // �������� �� ��������� ��� boolean - true/false
#define TI_NULLIDX 0xffffffff // ��� �������� � ������� ���������������
#define TI_TEXT_MAXSIZE 255 // ������������ ���������� �������� � text
#define TI_SYMBOL_MAXSIZE 1 // ������������ ���������� �������� � symbol

#include <vector>
#include "Error.h"

namespace IT {
	enum IDDATATYPE { // ���� ������ ���������������
		BYTE = 1, 
		TEXT = 2,
		SYMBOL = 3,
		BOOLEAN = 4,
		HALLOW = 5
	};
	enum IDTYPE { // ��� ���������������
		VARIABLE = 1, 
		FUNCTION = 2, 
		PARAMETER = 3, 
		LITERAL = 4 
	};

	struct Entry {
		int idxfirstLE; // ������ ������ ������ � ������� ������
		char id[ID_MAXSIZE]{}; // ��� ��������������
		IDDATATYPE iddatatype; // ��� ������
		IDTYPE idtype; // ��� ��
		union {
			unsigned short vbyte; // �������� byte
			bool vboolean; // �������� boolean
			char vsymbol; // �������� symbol
			struct {
				int len; // ���������� ��������
				char str[TI_TEXT_MAXSIZE - 1]; // �������
			} vtext[TI_TEXT_MAXSIZE]; // �������� text
		} value;
		Entry(
			int ifLE,
			char* name,
			IDDATATYPE iddatatype,
			IDTYPE idtype
		) {
			this->idxfirstLE = ifLE;
			int nameSize = strlen(name);
			if (nameSize > ID_MAXSIZE) {
				throw ERROR_THROW(125);
			}
			strncpy_s(id, name, ID_MAXSIZE);
			id[ID_MAXSIZE] = '\0';
			this->iddatatype = iddatatype;
			this->idtype = idtype;
		}
		Entry() {};
	};

	struct IdTable {
		int size;
		std::vector<Entry>table;
	};
	IdTable Create();
	void Add(
		IdTable& idtable,
		Entry entry
	);
	Entry GetEntry(
		IdTable& idtable,
		int n
	);
	int IsId(
		IdTable& idtable,
		char id[ID_MAXSIZE]
	);
	void Delete(IdTable& idtable);
}