#include<iostream>

using namespace std;

void selectionSort(int* arr1, int n)
{
    for(int i=0; i<(n-1); i++)
    {
        int min = i;
        for(int j=i+1; j<(n-1); j++)
        {
            if(arr1[j] < arr1[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = arr1[min];
            arr1[min] = arr1[i];
            arr1[i] = temp;
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int arr1[n];
    for(int i = 0; i<n; i++)
    {
        cout << "Enter element : ";
        cin >> arr1[i];
    }

    selectionSort(arr1, n);

    cout << endl << "SORTED ARRAY : " << endl;
    for(int i = 0; i<n; i++)
    {
        cout << arr1[i] << " ";
    }

    return 0;
}