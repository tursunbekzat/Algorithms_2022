#include <iostream>
using namespace std;

struct DoubleNode{

    /* Make variables */
    public:
        string name;
        DoubleNode *prev;
        DoubleNode *next;

    /* Constructor for empty node */
    DoubleNode ()
    {
        name = "";
        prev = nullptr;
        next = nullptr;
    }

    /* Constructor for node that stores data */
    DoubleNode (string name)
    {
        this -> name = name;
        prev = nullptr;
        next = nullptr;
    }

    /* Constructor to add new node between two nodes */
    DoubleNode (string name, DoubleNode *prev, DoubleNode *next)
    {
        this -> name = name;
        this -> prev = prev;
        this -> next = next;
    }
};

/* To add node at the begining */
void add_front(DoubleNode **head, string name)
{
    /* Make new head */
    DoubleNode *new_node = new DoubleNode(name, nullptr, *head);

    /* Point previous part of the head to the new head */
    if (*head != NULL)
        (*head) -> prev = new_node;

    *head = new_node;
    cout << "ok\n";
}

/* To add node at the end*/
void add_back(DoubleNode **head, string name)
{
    /* Create new head if list is empty */
    if (*head == NULL)
    {
        DoubleNode *new_node = new DoubleNode(name);
        *head = new_node;
        cout << "ok\n";
        
        return;
    }

    /* Else iterate till the end */
    DoubleNode *iter = *head;
    while (iter -> next != NULL)
        iter = iter -> next;

    /* Point last node to the new node */
    DoubleNode *new_node = new DoubleNode(name, iter, nullptr);
    iter -> next = new_node;

    cout << "ok\n";
}

/* To delete the node at the front, that is, delete head */
void erase_front(DoubleNode **head)
{
    /* We cannot erase anything in empty list */
    if (*head == NULL)
    {
        cout << "error\n";
        return;
    }
    /* Make head null if it is alone */
    if ((*head) -> next == NULL)
    {
        cout << (*head) -> name << '\n';
        *head = NULL;
        return;
    }

    /* Else just make new head, deleting the old one */
    DoubleNode *after_head = (*head) -> next;
    after_head -> prev = nullptr;
    
    cout << (*head) -> name << '\n';
    *head = after_head;
    return;
}

/* To delete the node at the end */
void erase_back(DoubleNode **head)
{
    /* We cannot erase anything in empty list */
    if (*head == NULL)
    {
        cout << "error\n";
        return;
    }
    /* Make head null if it is alone */
    if ((*head) -> next == NULL)
    {
        cout << (*head) -> name << '\n';
        *head = NULL;
        return;
    }

    /* Else make node before the last node point to null and delete the last one */
    DoubleNode *last = *head;
    while (last -> next != nullptr)
        last = last -> next;

    
    DoubleNode *pre_last = last -> prev;
    pre_last -> next = nullptr;
    cout << last -> name << '\n';
    delete last;

    return;
}

/* To print the node at the begin, i.e. head */
void front(DoubleNode *head){
    /* Print error if list is empty */
    if (head == NULL)
    {
        cout << "error\n";
        return;
    }

    cout << head -> name << '\n';
}

/* To print the node at the end */
void back(DoubleNode *head){
    /* Print error if list is empty */
    if (head == NULL)
    {
        cout << "error\n";
        return;
    }
    
    /* Else iterate till the end and print the last node data */
    while (head -> next != NULL)
        head = head -> next;

    cout << head -> name << '\n';
}

/* To delete all the nodes in a list by deleting link to them */
void clear(DoubleNode **head)
{
    /* Print ok, since list is already empty */
    if (*head == nullptr)
    {
        cout << "ok\n";
        return;
    }

    /* Else just make head null, so it loses links to the next nodes */
    (*head) = nullptr;
    cout << "ok\n";
    return;
}

int main()
{
    DoubleNode *head = NULL;

    /* Take command and call requested function */
    string command, name;
    while (true)
    {
        cin >> command;
        if (command == "add_front"){
            cin >> name;
            add_front(&head, name);
        }
        else if (command == "add_back"){
            cin >> name;
            add_back(&head, name);
        }
        else if (command == "erase_front")  erase_front(&head);
        else if (command == "erase_back")   erase_back(&head);
        else if (command == "front")        front(head);
        else if (command == "back")         back(head);
        else if (command == "clear")        clear(&head);
        else if (command == "exit")
        {
            cout << "goodbye\n";
            break;
        }
    }
    
    return 0;
}