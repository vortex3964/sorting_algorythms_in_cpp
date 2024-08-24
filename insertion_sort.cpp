#include <iostream>
#include <chrono>

const int SIZE = 300;

void print_array(int array[],int size);
std::chrono::microseconds insertion_sort(int array[],int size);

//insertion sort
int main() {
	int array[SIZE];

	srand(0);
	for (int i = 0; i < SIZE; i++) array[i] = rand()%100; //fill with random numbers

	print_array(array,SIZE);
	std::cout << "\n______________________________________________________________________________\n\n\n\n";
	std::chrono::microseconds execusion = insertion_sort(array, SIZE);
	std::cout << "\n______________________________________________________________________________\n\n\n\n";
	print_array(array, SIZE);
	std::cout << "the execusion  time of insertion sort was "<< execusion.count() <<" microseconds";
	return 0;
}

void print_array(int array[],int size){
	for (int i=1;i<=size;i++) {
		std::cout << array[i-1] << "\t";
		if (i % 15 == 0) std::cout << "\n";
	}
}

std::chrono::microseconds insertion_sort(int array[],int size) {
	auto start = std::chrono::high_resolution_clock::now();//start counting
	int temp;
	int offset;
	//bool shifts = false;

	for (int i = 1; i < size; i++) {
		temp = array[i];
		offset = i-1;

		while (temp < array[offset] && offset>-1) {
			//shift element
			array[offset+1] = array[offset];
			offset--;
		}
		
		array[++offset] = temp;
	}

	auto finish = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);//time it took for the array to get sorted
	return  duration;
}
