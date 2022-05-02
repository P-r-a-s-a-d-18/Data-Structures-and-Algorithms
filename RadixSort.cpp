# include <iostream>
using namespace std;

int GetMax(int array[], int size)
{
    int max = array[0];
    for(int i=1; i<size; i++)
    {
	if(array[i] > max)
	{
	    max = array[i];
	}
    }
    return max;
}

void CountingSort(int array[], int size, int div)
{
    int output[size];
    int count[10] = {0};

    for(int i=0; i<size; i++)
    {
	count[(array[i]/div)%10]++;
    }

    for(int i=1; i<10; i++)
    {
	count[i] += count[i-1];
    }
    
    for(int i=size-1; i>=0; i--)
    {
	output[count[(array[i]/div)%10]-1] = array[i];
	count[(array[i]/div)%10]--;
    }

    for(int i=0; i<size; i++)
    {
	array[i] = output[i];
    }
}

void RadixSort(int array[], int size)
{
    int m = GetMax(array, size);
    for(int div=1; m/div>0; div*=10)
    {
	CountingSort(array, size, div);
    }
}

int main()
{
    int size;
    cout << "Enter size of array : ";
    cin >> size;
    
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

    RadixSort(arr, size);

    cout << "\nAfter Sort : ";
    for(int i=0; i<size; i++)
    {
	cout << arr[i] << " ";
    }
    
    return 0;
}