#include <iostream>


void Merge(int *arr, const int low, const int high, int mid)
{
	
	int i, j, k, temp[6];
	i = low;
	k = 0;
	j = mid + 1;

	
	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}

	
	while (i <= mid)
	{
		temp[k] = arr[i];
		k++;
		i++;
	}

	
	while (j <= high)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}


	
	for (i = low; i <= high; ++i)
	{
		arr[i] = temp[i - low];
	}
}


void MergeSort(int *arr, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		
		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, high);

		
		Merge(arr, low, high, mid);
	}
}

void PrintArr(int *arr, int n)
{

	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	int arr[] = { 18, 11, 13, 57, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);


	MergeSort(arr, 0, n - 1);
	PrintArr(arr, n);

}
