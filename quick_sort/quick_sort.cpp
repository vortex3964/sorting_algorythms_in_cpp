#include <iostream>
#include <chrono>

const int SIZE = 300;

void quick_sort(int array[], int start, int end);
void print_array(int array[],int size);

//quick sort
int main() {
	int array[SIZE];//the array
	
	srand(0);
	for (int i = 0; i < SIZE;i++) array[i] = rand() % 100; //initialize the numbers in the array with random ones

	print_array(array,SIZE);
	std::cout << "\n_______________________________________________________________________\n\n\n";

	auto start = std::chrono::high_resolution_clock::now();//start counting time
	quick_sort(array,0,SIZE-1); //the quick sort function
	auto finish= std::chrono::high_resolution_clock::now();
	std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);//calculate duration of quick sort

	print_array(array, SIZE);

	std::cout << "\n_______________________________________________________________________\n\n\n";
	std::cout << "quick sort sorted the array in " << duration.count() << " microseconds";

	return 0;
}

void quick_sort(int array[], int start,int end) {
	if (end<=start) return;

	int j =start, pivot =start-1;
	int temp;

	while (j<end) {
		if (array[end] >= array[j]) {
			pivot++;
			temp = array[pivot];
			array[pivot] = array[j];
			array[j] = temp;
			j++;
		}
		else  j++;
	}
	pivot++;
	temp = array[end];
	array[end] = array[pivot];
	array[pivot] = temp;
	
	quick_sort(array,start,pivot-1);
	quick_sort(array,pivot+1,end);
}

void print_array(int array[], int size) {
	for (int i = 1; i <= size; i++) {
		std::cout << array[i-1] << "\t";
		if (i % 15 == 0) std::cout << "\n";
	}
}