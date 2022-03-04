#include<iostream>
using namespace std;

class Node
{
    public:
        int key;
        int data;
        Node* next;

        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
        }
        Node(int k, int d)
        {
            key = k;
            data = d;
        }
};

class SinglyLinkedList
{
    public:
        Node* head;

        SinglyLinkedList()
        {
            head = NULL;
        }
        SinglyLinkedList(Node *n)
        {
            head = n;
        }

        Node* nodeExists(int k)
        {
            Node* temp = NULL;
            Node* ptr = head;

            while(ptr != NULL)
            {
                if(ptr -> key == k)
                {
                    temp = ptr;
                }
                ptr = ptr -> next;
            }
            return temp;
        }

        void appendNode(Node *n)
        {
            if(nodeExists(n -> key) != NULL)
            {
                cout << "Node already exists with key value : " << n -> key << ". Append another node with different key value." << endl;
            }
            else
            {
                if(head == NULL)
                {
                    head = n;
                    cout << "Node appended." << endl;
                }
                else
                {
                    Node* ptr = head;
                    while(ptr -> next != NULL)
                    {
                        ptr = ptr -> next;
                    }
                    ptr -> next = n;
                    cout << "Node appended." << endl;
                }
            }
        }

        void prependNode(Node *n)
        {
            if(nodeExists(n -> key) != NULL)
            {
                cout << "Node already exists with key value : " << n -> key << ". Prepend another node with different key value." << endl;
            }
            else
            {
                 n -> next = head;
                 head = n;
                 cout << "Node prepended." << endl;
            }
        }

        void insertNodeAfter(int k, Node *n)
        {
            Node* ptr = nodeExists(k);
            if(ptr == NULL)
            {
                cout << "No node exist with key value : " << k << endl;
            }
            else
            {
                if(nodeExists(n -> key) != NULL)
                {
                    cout << "Node already exists with key value : " << n -> key << ". Insert another node with different key value." << endl;
                }
                else
                {
                    n -> next = ptr -> next;
                    ptr -> next = n;
                    cout << "Node Inserted." << endl;
                }
            }
        }

        void deleteNodeByKey(int k)
        {
            if(head == NULL)
            {
                cout << "Singly Linked List already empty. Can't delete." << endl;
            }
            else if(head != NULL)
            {
                if(head -> key == k)
                {
                    head = head -> next;
                    cout << "Node UNLINKED with key : " << k << endl;
                }
                else
                {
                    Node* temp = NULL;
                    Node* prev_ptr = head;
                    Node* current_ptr = head -> next;

                    while(current_ptr != NULL)
                    {
                        if(current_ptr -> key == k)
                        {
                            temp = current_ptr;
                            current_ptr = NULL;
                        }
                        else
                        {
                            prev_ptr = prev_ptr -> next;
                            current_ptr = current_ptr -> next;
                        }
                    }
                    if(temp != NULL)
                    {
                        prev_ptr -> next = temp -> next;
                        cout << "Node UNLINKED with key : " << k << endl;
                    }
                    else
                    {
                        cout << "Node doesn't exist with key value : " << k << endl;
                    }
                }
            }
        }

        void updateNodeByKey(int k, int d)
        {
            Node* ptr = nodeExists(k);
            if(ptr != NULL)
            {
                ptr -> data = d;
                cout << "Node data updated successfully." << endl;
            }
            else
            {
                cout << "Node doesn't exist with key value : " << k << endl;
            }
        }

        void printList()
        {
            if(head == NULL)
            {
                cout << "No nodes in the linked-list." << endl;
            }
            else
            {
                cout << endl << "Linked List Values : ";
                Node* temp = head;

                while(temp != NULL)
                {
                    cout << "(" << temp -> key << "," << temp -> data << ") --> ";
                    temp = temp -> next;
                }
            }
        }
};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1, k1, data1;

    do
    {
        cout << endl << "\nWhat operation do you want to perform ? Select Option no. Enter 0 to exit." << endl;
        cout << "1. Append Node" << endl;
        cout << "2. Prepend Node" << endl;
        cout << "3. Insert Node after a key" << endl;
        cout << "4. Delete Node by key" << endl;
        cout << "5. Update Node by key" << endl;
        cout << "6. Display" << endl;
        cout << "7. Clear Screen" << endl << endl;

        cin >> option;

        Node* n1 = new Node();

        switch(option)
        {
            case 0:
                break;

            case 1:
                cout << "\nEnter key and data for Node to be appended - " << endl;
                cin >> key1;
                cin >> data1;
                n1 -> key = key1;
                n1 -> data = data1;
                s.appendNode(n1);
                break;

            case 2:
                cout << "\nEnter key and data for Node to be prepended - " << endl;
                cin >> key1;
                cin >> data1;
                n1 -> key = key1;
                n1 -> data = data1;
                s.prependNode(n1);
                break;

            case 3:
                cout << "Enter key of existing node after which you want to Insert the new Node : " << endl;
                cin >> k1;
                cout << "Enter key and data of new Node - " << endl;
                cin >> key1;
                cin >> data1;
                n1 -> key = key1;
                n1 -> data = data1;
                s.insertNodeAfter(k1, n1);
                break;

            case 4:
                cout << "Enter key of Node to be deleted : " << endl;
                cin >> k1;
                s.deleteNodeByKey(k1);
                break;

            case 5:
                cout << "Enter key and NEW DATA to be updated : " << endl;
                cin >> key1;
                cin >> data1;
                s.updateNodeByKey(key1, data1);
                break;

            case 6:
                s.printList();
                break;

            case 7:
                system("cls");
                break;

            default:
                cout << "Enter proper option number." << endl;
        }
    }while(option != 0);

    return 0;
}