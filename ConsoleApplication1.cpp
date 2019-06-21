// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;
namespace simple_shapes {
	void Init(container &c);
	void Clear(container &c);
	complex* InComplex(complex &p, ifstream &ifst);
	simple* InSimple(simple &t, ifstream &ifst);
	Node* In(ifstream &ifst);
	void In(container &c, ifstream &ifst);
	void OutComplex(complex *p, ofstream &ofst);
	void Out(container &c, ofstream &ofst);
	void Out(Node *s, ofstream &ofst);
	int addlist(container &c, ifstream &ifst);
	void OutSimple(simple *t, ofstream &ofst);
}
using namespace simple_shapes;
int main(int argc, char* argv[])
{
	int a;
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		system("pause");
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);	cout << "Start" << endl;
	setlocale(LC_ALL, "Russian");
	container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled container. " << endl;

	Out(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	system("pause");
	cin >> a;
	return 0;	
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
