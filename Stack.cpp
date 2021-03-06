#include <iostream>
#include <string>

using namespace std;

class Stack
{
    private:
        int top;
        int n;
        int arr[];
    public:
        Stack()
        {
            top = -1;
            cout << "Enter the size of Stack : ";
            cin >> n;
            for(int i = 0; i<n; i++)
            {
                arr[i] = 0;
            }
        }
        bool isEmpty()
        {
            if (top == -1)
                return true;
            else
                return false;
        }
        bool isFull()
        {
            if(top == (n-1))
                return true;
            else
                return false;
        }
        void push(int val)
        {
            if (isFull())
            {
                cout << "Stack Overflow" << endl;
            }
            else
            {
                top++;
                arr[top] = val;
            }
        }
        int pop()
        {
            if(isEmpty())
            {
                cout << "Stack Underflow" << endl;
                return 0;
            }
            else
            {
                int popValue = arr[top];
                arr[top] = 0;
                top--;
                return popValue;
            }
        }
        int count()
        {
            return(top+1);
        }
        int peek(int pos)
        {
            if(isEmpty())
            {
                cout << "Stack Underflow" << endl;
                return 0;
            }
            else
            {
                return arr[pos];
            }
        }
        void change(int pos, int val)
        {
            arr[pos] = val;
            cout << "Value changed at the location " << pos << endl;
        }
        void display()
        {
            cout << "Values in the stack are : " << endl;
            for(int i = (n-1); i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
};

int main()
{
    Stack s1;
    int option, position, value;

    do
    {
        cout << endl << "What operation do you want to perform ? Select Option no. Enter 0 to exit." << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl << endl;

        cin >> option;
        switch(option)
        {
            case 0:
                break;
            case 1:
                cout << "Enter an item to push in the stack" << endl;
                cin >> value;
                s1.push(value);
                break;
            case 2:
                cout << "Pop function called. Popped value : " << s1.pop() << endl;
                break;
            case 3:
                if (s1.isEmpty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                    break;
            case 4:
                if (s1.isFull())
                    cout << "Stack is full." << endl;
                else
                    cout << "Stack is not full." << endl;
                    break;
            case 5:
                cout << "Enter position of item you want to peek : " << endl;
                cin >> position;
                cout << "Peek function called - " << endl <<s1.peek(position) << endl;
                break;
            case 6:
                cout << "Number of items in stack are : " << s1.count() << endl;
                break;
            case 7:
                cout << "Enter position of value to be changed : " << endl;
                cin >> position;
                cout << endl;
                cout << "Enter new value : " << endl;
                cin >> value;
                s1.change(position, value);
                break;
            case 8:
                cout << "Display function called : " << endl;
                s1.display();
                break;
            case 9:
                system("cls");
                break;
            deafult:
                cout << "Enter proper option number." << endl;
        }

    }while(option != 0);

    return 0;
}