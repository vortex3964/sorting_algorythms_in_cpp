#include <iostream>
#include <chrono>

const int SIZE = 300;
int offset = 1;

std::chrono::microseconds bubble_sort(int array[]);
void print_array(int array[]);

//bubble sort
int main() {
	//the array
	int array[SIZE];

	//fill the array with random numbers
	srand(0);
	for (int i = 0; i < SIZE; i++) array[i] = rand() % 100;

	print_array(array);

	//sort the array using bubble_sort
	std::chrono::microseconds execution_time=bubble_sort(array);

	std::cout << "\n___________________________________________________________________\n___________________________________________________________________\n\n\n";

	//finall result
	print_array(array);

	std::cout << "\nprogram  ended in "  << execution_time.count() <<" microseconds"<<"\n";

	return 0;
}

std::chrono::microseconds bubble_sort(int array[]) {
	auto start = std::chrono::high_resolution_clock::now();//start counting the time to sort

	bool sorted = false;
	int temp;

	while (!sorted) {
		sorted = true;

		for (int i = 0; i < SIZE - offset; i++) {
			if (array[i] > array[i + 1]) {
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				sorted = false;
			}
		}
		offset++;
	}

	
	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);//time for bubble sort to sort the array calculation
	return  duration;
}

void print_array(int array[]) {
	for (int i = 1; i <= SIZE; i++) {
		std::cout << array[i - 1] << "\t";
		if (i % 15 == 0) {
			std::cout <<"\n";
		}
	}
}
