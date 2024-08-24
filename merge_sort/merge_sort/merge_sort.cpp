#include <iostream>        
#include <chrono>

const int SIZE = 300;

void print_array(int array[],int size);
void merge_sort(int array[], int size);
void merge(int left_arr[], int right_arr[], int left, int right,int  array[]);

//merge sort
int main() {
	int array[SIZE];
	int size = SIZE;

	srand(0);
	for (int i = 0; i < size; i++) array[i] = rand() % 100; //fill the array with random numbers

	print_array(array,SIZE);
	std::cout << "\n____________________________________________________________________________________\n\n";
	std::cout << "\n____________________________________________________________________________________\n\n";

	auto start = std::chrono::high_resolution_clock::now();//start counting the time
	
	merge_sort(array, SIZE);

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	print_array(array,SIZE);
	std::cout << "\nmerge sort took " << duration.count() << " microseconds to sort the array of "<< SIZE << " elements";

	return 0;
}

void print_array(int array[],int size) {
	std::cout << "\n";
	for (int i = 1; i <= size; i++) {
		std::cout << array[i-1] << "\t";
		if (i % 10 == 0) std::cout <<"\n";
	}
}

void merge_sort(int array[], int size) {
	if (size == 1) return; //when the array has a size of 1 recursion ends
	
	int right = size / 2; //size of the right array
	int left = size - right; //size of the left array

	int *left_arr = new int[left];
	int* right_arr = new int[right];

	//copy data from originall array to the new  arrays
	int i,r=0;
	for (i = 0; i < left; i++) left_arr[i] = array[i];
	for (i = 0; i < right; i++) right_arr[r++] = array[left + i];

	merge_sort(left_arr, left);
	merge_sort(right_arr, right);

	merge(left_arr, right_arr, left, right,array);

	//free the memmory
	delete[] left_arr;
	delete[] right_arr;
}

void merge(int larr[], int rarr[], int left, int right, int array[]) {
	int size = right + left;
	int r=0, l=0, i=0;

	while (r < right && l < left) {
		if (larr[l] < rarr[r]) array[i++] = larr[l++];

		else array[i++] = rarr[r++];
	}

	while(r < right) array[i++] = rarr[r++];
	while (l < left) array[i++] = larr[l++];

}


