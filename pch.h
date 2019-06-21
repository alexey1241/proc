// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#ifndef PCH_H
#define PCH_H

enum type { COMPLEX, SIMPLE };
struct complex {
	type key;
	float real;
	float imaginary;
};
struct simple {

	type key;
	int numerator;
	int denominator;
};
struct numbers {
	type key;
};

struct Node {
	Node() {
		this->Next = nullptr;
		this->Prev = nullptr;
		this->data = nullptr;
	};
	Node* Next;
	Node* Prev;
	numbers* data;
};
struct container {
	Node* Top;
	int count;
};

// TODO: add headers that you want to pre-compile here

#endif //PCH_H