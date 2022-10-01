#include <iostream>

using namespace std;

/* Constructor for node in double linked list */
struct Node{
    char val;
    Node *prev;
    Node *next;
    Node(char x): val(x), next(nullptr), prev(nullptr) {}
    Node(char x, Node *last): val(x), next(nullptr), prev(last) {}
};

/* Constructor for double linked list with member functions */
struct DLL{

    /* Set head and tail to null */
    Node *head = nullptr;
    Node *tail = nullptr;

    /* Function that creates a node with value x and inserts it at the end */
    Node* push_back(char x)
    {
        /* Make new node head and tail if list is empty */
        if (head == nullptr)
        {
            Node *new_node = new Node(x);
            head = new_node;
            tail = new_node;

            return new_node;
        }

        /* Else make it the tail */
        Node *new_node = new Node(x, tail);
        tail -> next = new_node;
        tail = new_node;

        return new_node;
    }
    
    /* To remove a node with given pointer */
    void remove(Node *node)
    {
        if (head == nullptr)                        // Can't delete anything from empty list
            return;

        if (head == node)                           // If head to be removed, change head
            head = head -> next;

        if (tail == node)                           // If tail to be removed, change tail
            tail = tail -> prev;

        if (node -> next != nullptr)                // If element is not last, make next node of it point to previous
            node -> next -> prev = node -> prev;

        if (node -> prev != nullptr)                // If element is not first, make next node of it point to previous
            node -> prev -> next = node -> next;

        delete node;                                // Free unused memory
    }

    /* To print the front of the list or -1 if list is empty */
    void PrintHead(){
        if (head)
            cout << head -> val << " ";
        else
            cout << "-1 ";
    }

    /* To delete all the nodes and make head and tail null */
    void clear(){
        
        if (head == nullptr) return;

        Node *prev = nullptr;
        while (head != nullptr)
        {
            prev = head;
            head = head -> next;
            delete(prev);
        }

        tail = nullptr;
    }

};

int main()
{
    /* Take input */
    int N, n;
    cin >> N;

    /* loop for intaking characters */
    char x;
    for (int i = 0; i < N; i++)
    {
        Node* inDLL[256] = {nullptr};           // To store pointers to the dll nodes
        bool repeated[256] = {0};               // To know if char x is repeated or not
        DLL dll;                                // Create double linked list object

        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> x;

            /* If 'x' is repeated, ignore it and print first non repeated character */
            if (repeated[x])
            {
                dll.PrintHead();
                continue;
            }
            
            /* If we see 'x' for the first time, store it in dll and pointer to it in inDLL*/
            if (!repeated[x] && !inDLL[x])
                inDLL[x] = dll.push_back(x);

            /* If we see 'x' for the 2nd time, remove it from dll and inDLL and mark it as repeated */
            else
            if (!repeated[x] && inDLL[x])
            {
                dll.remove(inDLL[x]);
                inDLL[x] = nullptr;
                repeated[x] = 1;
            }
            
            /* Print first non repeated character anyway */
            dll.PrintHead();
        }
        cout << '\n';

        /* Clear out dll to start the procces for new stream of chars */
        dll.clear();
    }

}