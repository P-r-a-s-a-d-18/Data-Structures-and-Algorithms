# include <iostream>
using namespace std;

void CountingSort(int array[], int s, int r)
{
    int output_arr[s];
    int count_arr[r];

    for(int i=0; i<r; i++)
    {
	count_arr[i] = 0;
    }

    for(int i=0; i<s; i++)
    {
	++count_arr[array[i]];
    }

    for(int i=1; i<r; i++)
    {
	count_arr[i] = count_arr[i] + count_arr[i-1];
    }

    for(int i=0; i<s; i++)
    {
	output_arr[--count_arr[array[i]]] = array[i];
    }

    for(int i=0; i<s; i++)
    {
	array[i] = output_arr[i];
    }
}

int main()
{
    int size;
    int range;
    cout << "Enter size of array : ";
    cin >> size;
    cout << "Enter the range : ";
    cin >> range;
    
    int arr[size];

    for(int i=0; i<size; i++)
    {
	cout << "Enter element : ";
	cin >> arr[i];
    }

    cout << "Before Sort : ";
    for(int i=0; i<size; i++)
    {
	cout << arr[i] << " ";
    }

    CountingSort(arr, size, range);

    cout << "\nAfter Sort : ";
    for(int i=0; i<size; i++)
    {
	cout << arr[i] << " ";
    }
    
    return 0;
}