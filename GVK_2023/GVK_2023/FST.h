#pragma once
#include <iostream>
#include "In.h"
#include "LT.h"
#include "IT.h"

namespace FST {
	struct RELATION { // �����
		char symbol;
		unsigned short nnode; // ������� �������
		RELATION(
			char c = 0x00,
			unsigned short ns = NULL
		);
	};

	struct NODE { // ������� (���������)
		unsigned short n_relation; // ���������� ����������� �����
		RELATION* relations; // �����
		NODE();
		NODE(
			unsigned short n,
			RELATION rel, ...
		);
	};

	struct FST {
		std::vector<char>string; // �������
		unsigned short position; // ������� ������� � �������
		unsigned short nstates; // ���������� ���������
		std::vector<NODE> nodes; // ���� ���������
		unsigned short* rstates; // ��������� ���������
		FST(
			std::vector<char> s,
			unsigned short ns,
			NODE n, ...
		);
		void FSTreturn() {
			this->position = -1;
			this->rstates[0] = 0;
		}
	};

	struct FSTAssigned {
		FST* fst; // �������� ��������
		IT::IDDATATYPE iddatatype; // ���
		char lex; // �������
		FSTAssigned(FST* f, IT::IDDATATYPE i, char l) {
			fst = f;
			iddatatype = i;
			lex = l;
		}
	};

	bool execute(
		FST& fst
	);

	void Analyze(In::IN in, LT::LexTable& lextable, IT::IdTable& idtable);
}