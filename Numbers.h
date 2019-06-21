#include <fstream>

enum type { COMPLEX, SIMPLE, POLCOOR };
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
struct polcoor {
	type key;
	float corner;
	int distance;
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