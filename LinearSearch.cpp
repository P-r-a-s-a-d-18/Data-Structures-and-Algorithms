#include<iostream>

using namespace std;

void linearSearch(int *a, int num)
{
    int temp = -1;
    for(int i=0; i<sizeof(a); i++)
    {
        if(a[i] == num)
        {
            cout << "Element found at position : " << i+1 << endl;
            temp = 0;
        }
    }
    if(temp == -1)
    {
        cout << "No element found." << endl;
    }
}

int main()
{
    int n, num;
    cout << "Enter size of array : " << endl;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cout << "Enter element : ";
        cin >> arr[i];
    }
    cout << "Enter an element to be searched : ";
    cin >> num;

    linearSearch(arr, num);

    return 0;
}