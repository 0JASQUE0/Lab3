#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Heap bh;
	bh.insert(1);
	bh.insert(0);
	bh.insert(2);
	bh.insert(4);
	bh.insert(3);
	bh.out();
	cout << endl;

	Iterator* Iter = bh.create_dft_iterator();
	for (size_t i = 0; i < 5; i++) {
		cout << Iter->next() << " ";
	}


	return 0;
}