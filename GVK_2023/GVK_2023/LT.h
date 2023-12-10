#pragma once
#define LEXEMA_FIXSIZE 1 // ������ �������
#define LT_MAXSIZE 4096 // ������������ ���������� ����� � ������� ������
#define LT_TI_NULLIDX 0xffffffff // ��� �������� � ������� ���������������
#define LEX_HALLOW 't'    // void
#define LEX_BYTE 't'      // byte
#define LEX_TEXT 't'	  // text (string)
#define LEX_SYMBOL 't'    // symbol (char)
#define LEX_BOOLEAN 't'   // boolean
#define LEX_ID 'i'        // �������������
#define LEX_LITERAL 'l'   // �������
#define LEX_FUNCTION 'f'  // function
#define LEX_IF 'y'		  // if
#define LEX_ELSE 'u'      // else
#define LEX_DECLARE 'd'   // declare
#define LEX_RETURN 'r'    // return
#define LEX_DISPLAY 'p'   // display (print)
#define LEX_MAIN 'm'      // main - ����� ����� � ���������
#define LEX_ASSIGNMENT ':'// ������������
#define LEX_SEMICOLON ';'  
#define LEX_COMMA ','
#define LEX_LEFTBRACE '{'
#define	LEX_BRACELET '}'
#define LEX_LEFTTHESIS '('
#define LEX_RIGHTTHESIS ')'
#define LEX_MORE 'k'		// ������
#define LEX_LESS 'k'        // ������
#define LEX_EQUAL 'k'       // ���������
#define LEX_EXCLAMATION 'k' // �����������
#define LEX_MOREEQUAL 'k'   // ������ �����
#define LEX_LESSEQUAL 'k'   // ������ �����

#include "In.h"
#include <vector>

namespace LT {
	struct Entry {
		char lexema; // �������
		int sn; // ����� ������ � �������� ����
		int cn;
		int idxTI; // ������ � ������� ���������������
		char data;

		Entry( // ����������� ��� ������ ������� ������
			char lexema,
			int sn,
			int col,
			int idxTI
		) {
			this->lexema = lexema;
			this->sn = sn;
			this->cn = col;
			this->idxTI = idxTI;
		};

		Entry() = default;
	};

	struct LexTable {
		int size;			 // ������� ������
		std::vector<Entry>table; // ������ ������� ������
	};
	LexTable Create();
	void AddEntry(
		LexTable& lextable,
		Entry entry
	);
	Entry GetEntry(
		LexTable& lextable,
		int n // ����� ���������� ������
	);
	void Delete(LexTable& lextable);
}