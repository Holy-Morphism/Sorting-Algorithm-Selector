#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void bubblesort(vector<int>& arr, int size);
void selectionsort(vector<int>&, int);
void insertionsort(vector<int>&, int);
void merge(vector<int>&, int, int, int);
void mergeSort(vector<int>&, int, int);
int partition(vector<int>&, int, int);
void quickSort(vector<int>&, int, int);
bool isAlmostSorted(vector<int>&);
bool containsWideRange(const vector<int>&, double);
int main()
{
	int size = 0, input = 0;
	vector<int> arr;
	cout << "Please enter the size of array" << endl;
	cin >> size;
	cout << "Enter values " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> input;
		arr.push_back(input);
	}
	/*Bubble Sort: Best for small arrays with up to about 100 elements.
	 *Selection Sort: Best for small arrays with up to about 100 elements.
	 *Insertion Sort: Best for small arrays with up to about 1000 elements.
	 *Merge Sort: Efficient for large arrays with tens of thousands or millions of elements.
	 *Quick Sort: Efficient for large arrays with tens of thousands or millions of elements,
	  but may have performance issues with highly repetitive data.
	*/
	if (size < 50)
	{
		cout << endl;
		bubblesort(arr, size);
		cout << "array after sorted :" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl << endl;
		cout << "Bubble sort" << endl;
		cout << "Bubble Sort: Best for small arrays with up to about 50 elements." << endl;
		cout << "Time complexity" << endl;
		cout << "Best Case : n" << endl;
		cout << "Average Case : n^2" << endl;
		cout << "Worst Case :  n^2" << endl;
	}
	else if (size < 100)
	{
		if (isAlmostSorted(arr))
		{
			cout << endl << endl;
			selectionsort(arr, size);
			cout << "array after sorted : " << endl;
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "Selection Sort" << endl;
			cout << "Selection Sort: Best for small arrays with up to about 100 elements" << endl;
			cout << "No. Elements Slightly greater Bubble sort" << endl;
			cout << "Best for small and almost sorted arrays" << endl;
			cout << "Time complexity" << endl;
			cout << "Best Case : n^2" << endl;
			cout << "Average Case : n^2" << endl;
			cout << "Worst Case :  n^2" << endl;
		}
		else
		{
			cout << endl << endl;
			insertionsort(arr, size);
			cout << "array after sorted : " << endl;
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "Insertion Sort" << endl;
			cout << "Selection Sort: Best for small to medium sized arrays with up to about 100 elements" << endl;
			cout << "No. Elements are mostly unsorted , not suitable Selection sort" << endl;
			cout << "Best for small to medium, unsorted arrays,used if selection sort not suitable" << endl;
			cout << "Time complexity" << endl;
			cout << "Best Case : n" << endl;
			cout << "Average Case : n^2" << endl;
			cout << "Worst Case :  n^2" << endl;
		}
	}
	else if (size < 1000)
	{
		cout << endl << endl;
		insertionsort(arr, size);
		cout << "array after sorted : " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "Insertion Sort" << endl;
		cout << "Insertion Sort: Best for small to medium sized arrays with up to about 1000 elements" << endl;
		cout << "No. Elements greater than 100 upto 1000" << endl;
		cout << "Best for  small to medium, unsorted arrays,used if selection sort is not suitable" << endl;
		cout << "Time complexity" << endl;
		cout << "Best Case : n" << endl;
		cout << "Average Case : n^2" << endl;
		cout << "Worst Case :  n^2" << endl;
	}
	else
	{
		if (containsWideRange(arr, 1))
		{
			cout << endl << endl;
			quickSort(arr, 0, size - 1);
			cout << "array after sorted : " << endl;
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "Quick Sort" << endl;
			cout << "Quick Sort: Best for large sized arrays with up to about n>1000 elements" << endl;
			cout << "Best for large, wide ranged arrays" << endl;
			cout << "If array is not almost sorted ,Quick sort will go in it's Worst Time Complexity" << endl;
			cout << "Time complexity" << endl;
			cout << "Best Case : nlogn" << endl;
			cout << "Average Case : nlogn" << endl;
			cout << "Worst Case :  n^2" << endl;
		}
		else
		{
			cout << endl << endl;
			mergeSort(arr, 0, size - 1);
			cout << "array after sorted : " << endl;
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "Merge Sort" << endl;
			cout << "Merge Sort: Best for large sized arrays with up to about n>1000 elements" << endl;
			cout << "Best for large, unsorted arrays" << endl;
			cout << "Time complexity" << endl;
			cout << "Best Case : nlogn" << endl;
			cout << "Average Case : nlogn" << endl;
			cout << "Worst Case :  nlogn" << endl;
		}
		return 0;
	}
}
void bubblesort(vector<int>& arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}
void selectionsort(vector<int>& arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}
void insertionsort(vector<int>& arr, int size)
{
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

//this is used to merge it and will be call recursively in merge sort
void merge(vector<int>& arr, int left, int middle, int right) {
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int* leftArr = new int[n1], * rightArr = new int[n2];
	for (int i = 0; i < n1; i++) {
		leftArr[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++) {
		rightArr[j] = arr[middle + 1 + j];
	}
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k] = leftArr[i];
			i++;
		}
		else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = rightArr[j];
		j++;
		k++;
	}
	delete[]leftArr;
	delete[]rightArr;
}
//merge sort algo
void mergeSort(vector<int>& arr, int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}
//used to depart the array
int partition(vector<int>& arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}
void quickSort(vector<int>& arr, int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


bool isAlmostSorted(vector<int>& arr)
{
	int n = arr.size();
	int count = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			count++;
			if (count > 1) {
				return false;
			}
			if (i > 1 && arr[i] < arr[i - 2])
			{
				arr[i] = arr[i - 1];
			}
		}
	}
	return true;
}
bool containsWideRange(const vector<int>& arr, double threshold)//Checks if arr contain a wide range of number,ideal for quick sort
{
	int size = arr.size();
	if (size == 0) {
		return false;
	}
	int min = *min_element(arr.begin(), arr.end());
	int max = *max_element(arr.begin(), arr.end());
	double range = static_cast<double>(max - min);
	double ratio = range / size;
	return ratio >= threshold;
}