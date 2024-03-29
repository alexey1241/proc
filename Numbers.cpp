#include "Numbers.h"
#include <iostream>
#include <fstream>

using namespace std;
namespace simple_shapes {
	void Init(container &c);
	void Clear(container &c);
	complex* InComplex(complex &p, ifstream &ifst);
	simple* InSimple(simple &t, ifstream &ifst);
	numbers* In(ifstream &ifst);
	void In(container &c, ifstream &ifst);
	void OutComplex(complex *p, ofstream &ofst);
	void Out(container &c, ofstream &ofst);
	void Out(numbers *s, ofstream &ofst);
	int addnode(container &c, ifstream &ifst);
	void OutSimple(simple *t, ofstream &ofst);

	float numbers_s(simple *t);
	float numbers_s(complex *p);
	float numbers_s(simple *t)
	{
		float numbers1 = (t->numerator / t->denominator);
		return numbers1;
	}

	float numbers_s(complex *p)
	{
		float numbers2 = sqrt(pow((p->real),2) + pow((p->imaginary),2));
		return numbers2;
	}
	float numbers_s(numbers *s)
	{
		switch (s->key)
		{
		case SIMPLE:
		{
			return numbers_s((simple*)s);
		}break;
		case COMPLEX:
		{
			return numbers_s((complex*)s);
		}break;
		default:
		{
			return -1;
		}
		break;
		}
	}

	complex * InComplex(complex & p, ifstream & ifst)
	{
		ifst >> p.real >> p.imaginary;
		return &p;
	}

	simple * InSimple(simple & t, ifstream &ifst)
	{
		ifst >> t.numerator >> t.denominator;
		return &t;
	}

	void Init(container & c)
	{
		c.Top = nullptr;
		c.count = 0;

	}

	void Clear(container & c)
	{
		Node* current = c.Top;
		int i = 1;
		while (i < c.count)
		{
			current = current->Next;
			delete current->Prev;
			i++;
		}
		delete current;
		c.count = 0;
	}

	void OutComplex(complex *p, ofstream &ofst)
	{
		if (p->imaginary < 0)
		{
			ofst << "It is Complex number: �������������� ����� = " << p->real
				<< ", ������ ����� = " << p->imaginary << endl << p->real << p->imaginary << "i";
		}
		else
		{
			ofst << "It is Complex number: �������������� ����� = " << p->real
				<< ", ������ ����� = " << p->imaginary << endl << p->real << "+" << p->imaginary << "i";
		}
	}
	void Out(container & c, ofstream &ofst)
	{
		Node* current = c.Top;
		ofst << " Container contains " << c.count
			<< " elements." << endl;
		for (int j = 0; j < c.count; j++) {
			ofst << j << ": ";
			Out(current->data, ofst);
			ofst << "�������� = " << numbers_s(current->data) << endl;
			current = current->Next;
		}
	}
	void Out(numbers *s, ofstream &ofst)
	{
		switch (s->key) {
		case COMPLEX:
			OutComplex((complex*)s, ofst);
			ofst << endl;
			break;
		case SIMPLE:
			OutSimple((simple*)s, ofst);
			ofst << endl;
			break;
		default:
			cout << "Incorrect figure!" << endl;
		}
	}
	int addnode(container &c, ifstream &ifst)
	{
		if (c.count == 0)
		{
			c.Top = new Node;
			c.Top->Next = c.Top;
			c.Top->Prev = c.Top;
			if ((c.Top->data = In(ifst)) != 0)
				return 1;
			else
				return 0;

		}
		else
		{
			Node *current = c.Top;
			for (int j = 1; j < c.count; j++)
			{
				current = current->Next;
			}
			current->Next = new Node;
			if ((current->Next->data = In(ifst)) != 0)
			{
				c.Top->Prev = current->Next;
				current->Next->Prev = current;
				current->Next->Next = c.Top;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	void OutSimple(simple * t, ofstream &ofst)
	{
		ofst << "It is Simple number: ��������� = " << t->numerator
			<< ", ����������� = " << t->denominator << endl << t->numerator << "/" << t->denominator;
	}
	void In(container &c, ifstream &ifst)

	{
		while (!ifst.eof()) {
			if (addnode(c, ifst) != 0)
				c.count++;
		}
	}
	numbers * In(ifstream &ifst)
	{
		numbers *s = new numbers;
		int key;
		ifst >> key;
		if (key == 1) {
			complex* p = new complex;
			s = (numbers*)InComplex(*p, ifst);
			s->key = COMPLEX;
			return s;
		}
		else if (key == 2)
		{
			simple* t = new simple;
			s = (numbers*)InSimple(*t, ifst);
			s->key = SIMPLE;
			return s;
		}
		else
			return 0;
	}
}
