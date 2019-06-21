// pch.cpp: исходный файл, соответствующий предкомпилированному заголовку; нужен для компиляции

#include "pch.h"
#include <iostream>
#include <fstream>
// В целом этот файл можно пропустить, но не удаляйте его, если вы используете предкомпилированные заголовки.


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
			ofst << "It is Complex number: действительная часть = " << p->real
				<< ", мнимая часть = " << p->imaginary << endl << p->real << p->imaginary << "i";
		}
		else
		{
			ofst << "It is Complex number: действительная часть = " << p->real
				<< ", мнимая часть = " << p->imaginary << endl << p->real << "+" << p->imaginary << "i";
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
		ofst << "It is Simple number: числитель = " << t->numerator 
			 << ", знаменатель = " << t->denominator << endl << t->numerator << "/" << t->denominator;
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
			/*ifst >> s->real >> s->imaginary;*/
			return s;
		}
		else if (key == 2)
		{
			simple* t = new simple;
			s = (numbers*)InSimple(*t, ifst);
			s->key = SIMPLE;
			/*ifst >> s->numerator >> s->denominator;*/
			return s;
		}
		else
			return 0;
	}
}
