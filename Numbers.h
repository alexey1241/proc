enum type { COMPLEX, SIMPLE };
struct complex {
	type key;
	float real;
	float imaginary;
};
struct simple {

	type key;
	float numerator;
	float denominator;
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
