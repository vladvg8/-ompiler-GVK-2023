#pragma once
#define LEXEMA_FIXSIZE 1 // ������ �������
#define LT_MAXSIZE 4096 // ������������ ���������� ����� � ������� ������
#define LT_TI_NULLIDX 0xffffffff // ��� �������� � ������� ���������������
#define LEX_HALLOW 'h'    // void
#define LEX_BYTE 'b'      // byte
#define LEX_TEXT 't'	  // text (string)
#define LEX_SYMBOL 'c'    // symbol (char)
#define LEX_BOOLEAN 'o'   // boolean
#define LEX_ID 'i'        // �������������
#define LEX_LITERAL 'l'   // �������
#define LEX_FUNCTION 'f'  // function
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
#define LEX_MORE 'v'		// ������
#define LEX_LESS 'v'        // ������
#define LEX_EQUAL 'v'       // ���������
#define LEX_EXCLAMATION 'v' // �����������
#define LEX_MOREEQUAL 'v'   // ������ �����
#define LEX_LESSEQUAL 'v'   // ������ �����
#define LEX_PLUS 'v'        // +
#define LEX_MINUS 'v'       // -
#define LEX_START 'v'       // *
#define LEXT_DIRSLASH 'v'   // /

#include "In.h"
#include <vector>

namespace LT {
	struct Entry {
		char lexema; // �������
		int sn; // ����� ������ � �������� ����
		int idxTI; // ������ � ������� ���������������

		Entry( // ����������� ��� ������ ������� ������
			char lexema,
			int sn,
			int idxTI
		) {
			this->lexema = lexema;
			this->sn = sn;
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