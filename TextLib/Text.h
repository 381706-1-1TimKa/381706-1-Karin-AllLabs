#pragma once
#include "Node.h"
#include "NodeIter.h"
class TText
{
protected:
	TNode *root;
public:
	TText();
	char* Copy(int start, int n);
	void Del(int start, int n);
	void Ins(TNode* start, TNode* d); // �������
	void Ins(TNode* start, TMyString S);
	void Ins(TNode* start, char c);
	TNode* Find(char* a); // ����� � �������� ����
	int FindIndex(char* a); // ����� � ��������� ������ �����

};