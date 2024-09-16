//the binary search algorithm
#include <iostream>

int binary_search(int array[],int target);

int size;
int target;

int main() {
	std::cout << "how big do you want your array to be:";
	std::cin >> size;
	int* array = new int[size];

	std::cout << "filling your array....\n";//assume array will be sorted
	for (int i = 0; i < size; i++) array[i] = i;
	//for (int i = 0; i < size; i++) std::cout << array[i] << "\n";
	std::cout << "enter the numebr your looking for:";
	std::cin >> target;
	int index=binary_search(array, target);
	std::cout << index;
	return 0;
}

int binary_search(int array[], int target) {
	int start = 0;
	int end = size-1;

	while (start<=end) {

		int midle = start + (end - start) / 2;

		if (target == array[midle]) return midle;

		else if (target<array[midle]) end =midle-1;

		else start = midle + 1;
	}

	return -1;
}