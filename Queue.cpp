#include <iostream>
#include <string>

using namespace std;

class Queue
{
    private:
        int n;
        int rear;
        int front;
        int arr[];
    public:
        Queue()
        {
            cout << "Enter size of Queue : ";
            cin >> n;
            front = -1;
            rear = -1;
            for(int i = 0; i < n; i++)
            {
                arr[i] = 0;
            }
        }
        bool isEmpty()
        {
            if(front == -1 && rear == -1)
                return true;
            else
                return false;
        }
        bool isFull()
        {
            if(rear == (n-1))
                return true;
            else
                return false;
        }
        void enqueue(int val)
        {
            if(isFull())
                {
                    cout << "Queue is full." << endl;
                }
            else if(isEmpty())
            {
                rear = 0;
                front = 0;
                arr[rear] = val;
            }
            else
            {
                rear++;
                arr[rear] = val;
            }
        }
        int dequeue()
        {
            int x = 0;
            if(isEmpty())
            {
                cout << "Queue is empty." << endl;
                return 0;
            }
            else if(front == rear)
            {
                x = arr[front];
                arr[front] = 0;
                front = -1;
                rear = -1;
                return x;
            }
            else
            {
                x = arr[front];
                arr[front] = 0;
                front++;
                return x;
            }
        }
        int count()
        {
            return (rear - front + 1);
        }

       void display()
       {
            cout << "All values in Queue are : ";
            for(int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
       }
};

int main()
{
    Queue q1;
    int option, value;

    do
    {
        cout << endl << "\nWhat operation do you want to perform ? Select Option no. Enter 0 to exit." << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl << endl;

        cin >> option;
        switch(option)
        {
            case 0:
                break;
            case 1:
                cout << "Enter an item to enqueue in the Queue" << endl;
                cin >> value;
                q1.enqueue(value);
                break;
            case 2:
                cout << "Dequeue function called. Dequeued value : " << q1.dequeue() << endl;
                break;
            case 3:
                if (q1.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Queue is not empty." << endl;
                    break;
            case 4:
                if (q1.isFull())
                    cout << "Queue is full." << endl;
                else
                    cout << "Queue is not full." << endl;
                    break;
            case 5:
                cout << "Number of items in queue are : " << q1.count() << endl;
                break;
            case 6:
                cout << "Display function called." << endl;
                q1.display();
                break;
            case 7:
                system("cls");
                break;
            deafult:
                cout << "Enter proper option number." << endl;
                break;
        }

    }while(option != 0);

    return 0;
}