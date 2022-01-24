// C++ implementation of Radix Sort
#include <iostream>
using namespace std;

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
	int output[n]; // output array
	int i; 
	int count[10] = { 0 };

	i = 0;
	// Store count of occurrences in count[]
	while (i < n)
	{
		count[(arr[i] / exp) % 10]++;
		i++;
	}
	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}
	// Build the output array
	i = n - 1;
	while (i >= 0)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
		i--;
	}	
	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
	// Find the maximum number to know number of digits
	// cout << m << "\n";

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	int	exp = 1;
	int m = getMax(arr, n);
	while (m / exp > 0)
	{
		countSort(arr, n, exp);
		exp *= 10;
	}
}

// A utility function to print an array
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int n = sizeof(arr) / sizeof(arr[0]);
	// cout << n << \n""
	
	// Function Call
	radixsort(arr, n);
	print(arr, n);
	return 0;
}

	exp = 1;
	while (ps->arrsize / exp > 0)
	{
		countSort(ps->arrsize, exp, ps);
		exp *= 10;
	}
	

void countSort(int n, int exp, t_ps *ps)
{
	int output[n];
	int i; 
	int count[10] = { 0 };

	i = 0;
	while (i < n)
	{
		printf("%i\n", (ps->stack_a[i] / exp) % 10);
		count[(ps->stack_a[i] / exp) % 10]++;
		// printf("%i\n", count[i]);
		i++;
	}
	printf("\n\n");

	printf("%i\n", count[0]);
	printf("\n");

	i = 1;
	while (i < 10)
	{
		count[i] = count[i] + count[i - 1];
		printf("%i\n", count[i]);
		i++;
	}
	i = n - 1;
	while (i >= 0)
	{
		output[count[(ps->stack_a[i] / exp) % 10] - 1] = ps->stack_a[i];
		count[(ps->stack_a[i] / exp) % 10]--;
		i--;
	}
	for (i = 0; i < n; i++)
		ps->stack_a[i] = output[i];
}