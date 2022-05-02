#include<iostream>

using namespace std;

class Node
{
    public:
        int key;
        int data;
        Node* next;
        Node* previous;

        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
            previous = NULL;
        }

        Node(int k, int d)
        {
            key = k;
            data = d;
        }
};

class DoublyLinkedList
{
    public:
        Node* head;

        DoublyLinkedList()
        {
            head = NULL;
        }

        DoublyLinkedList(Node *n)
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
                    cout << "Node Appended as Head Node." << endl;
                }
                else
                {
                    Node* ptr = head;
                    while(ptr -> next != NULL)
                    {
                        ptr = ptr -> next;
                    }
                    ptr -> next = n;
                    n -> previous = ptr;
                    cout << "Node Appended." << endl;
                }
            }
        }

        void prependNode(Node *n)
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
                    cout << "Node Prepended." << endl;
                }
                else
                {
                    head -> previous = n;
                    n -> next = head;
                    head = n;
                    cout << "Node Prepended." << endl;
                }
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
                    cout << "Node already exists with key value : " << n -> key << ". Append another node with different key value." << endl;
                }
                else
                {
                    Node* nextNode = ptr -> next;

                    if(nextNode == NULL)
                    {
                        ptr -> next = n;
                        n -> previous = ptr;
                        cout << "Node Inserted at the end." << endl;
                    }
                    else
                    {
                        n -> next = nextNode;
                        nextNode -> previous = n;
                        n -> previous = ptr;
                        ptr -> next = n;
                        cout << "Node Inserted in between." << endl;
                    }
                }
            }
        }

        void deleteNodeByKey(int k)
        {
            Node* ptr = nodeExists(k);
            if(ptr == NULL)
            {
                cout << "No Node exist with key value : " << k << endl;
            }
            else
            {
                if(head == NULL)
                {
                    cout << "Doubly Linked List already empty. Can't delete." << endl;
                }
                else if(head != NULL)
                {
                    if(head -> key == k)
                    {
                        head = head -> next;
                        cout << "Node UNLINKED with key value : " << k << endl;
                    }
                    else
                    {
                        Node* nextNode = ptr -> next;
                        Node* prevNode = ptr -> previous;

                        if(nextNode == NULL)
                        {
                            prevNode -> next = NULL;
                            cout << "Node deleted at the end position." << endl;
                        }
                        else
                        {
                            prevNode -> next = nextNode;
                            nextNode -> previous = prevNode;
                            cout << "Node deleted in between." << endl;
                        }
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
                cout << "No nodes in Doubly Linked List." << endl;
            }
            else
            {
                cout << endl << "Doubly Linked List Values : ";
                Node* temp = head;

                while(temp != NULL)
                {
                    cout << "(" << temp -> key << "," << temp -> data << ") <--> ";
                    temp = temp -> next;
                }
            }
        }

};


int main()
{
    DoublyLinkedList obj;
    int option;
    int key1, k1, data1;

    do
    {
        cout << endl << "\nWhat operation do you want to perform ? Select Option no. Enter 0 to exit." << endl;
        cout << "1. Append Node" << endl;
        cout << "2. Prepend Node" << endl;
        cout << "3. Insert Node after a key" << endl;
        cout << "4. Delete Node ny key" << endl;
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
                obj.appendNode(n1);
                break;

            case 2:
                cout << "\nEnter key and data for Node to be prepended - " << endl;
                cin >> key1;
                cin >> data1;
                n1 -> key = key1;
                n1 -> data = data1;
                obj.prependNode(n1);
                break;

            case 3:
                cout << "Enter key of existing node after which you want to Insert the new Node : " << endl;
                cin >> k1;
                cout << "Enter key and data of new Node - " << endl;
                cin >> key1;
                cin >> data1;
                n1 -> key = key1;
                n1 -> data = data1;
                obj.insertNodeAfter(k1, n1);
                break;

            case 4:
                cout << "Enter key of Node to be deleted : " << endl;
                cin >> k1;
                obj.deleteNodeByKey(k1);
                break;

            case 5:
                cout << "Enter key and NEW DATA to be updated : " << endl;
                cin >> key1;
                cin >> data1;
                obj.updateNodeByKey(key1, data1);
                break;

            case 6:
                obj.printList();
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