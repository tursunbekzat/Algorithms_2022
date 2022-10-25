#include <iostream>
 
using namespace std;

struct Tree{
    int val;
    Tree* next;
    Tree(): val(0), next(nullptr) {}
    Tree(int x): val(x), next(nullptr) {}
    Tree(Tree* next): val(0), next(next) {}
    Tree(int x, Tree* next): val(x), next(next) {}
};

/* To count number of nodes in the linked list, that is, get its size */
int GetSize(Tree *node)
{
    int cnt = 0;
    while (node != NULL)
    {
        cnt++;
        node = node -> next;   
    }

    return cnt;    
}
/* To get the Nth node */
Tree* getNode(Tree* head, int n)
{
    /* Just for some case */
    if (head == NULL)
        return (new Tree());

    /* If n = -1 or bigger than length of the list, return 0 element that points to the head */
    if (n == -1 || n > GetSize(head)){
        Tree *null = new Tree();
        null -> next = head;
        return null;
    }

    /* Else return required node */
    int cnt = 0;
    Tree *iter = head;
    while (iter != NULL)
    {
        if (cnt == n)
            return iter;
        
        iter = iter -> next;
        cnt++;
    }
    return (new Tree());
}

/* To insert a node at a given position */
Tree* insert(Tree* head, Tree* node, int p){

    /* If head is null, make our node the head */    
    if (head == nullptr)
        return node;

    /* If we want to insert at the beginning */
    if (p == 0)
    {
        node -> next = head;
        head = node;
        return head;
    }

    /* Iterate till the needed position */
    Tree *cur = head;
    while ((p--) - 1)
        cur = cur -> next;
    
    /* Make new node point to the next of the node at the given position */
    node -> next = cur -> next;

    /* Make current node point to the new node */
    cur -> next = node;

    return head;
}

/* To remove the node at a given position p */ 
Tree* remove(Tree* head, int p){

    /* If p = 0 than delete current head and make head be the next node */
    if (p == 0)
    {
        Tree *new_head = head -> next;
        delete head;
        return new_head;
    }

    /* Else remove the desired node */
    Tree *cur = head;
    for (int i = 0; i < p - 1; i++)
        cur = cur -> next;
    
    Tree *tmp = cur -> next;
    cur -> next = (cur -> next) -> next;
    delete tmp;

    return head;
}

Tree* replace(Tree* head, int p1, int p2){

    /* Same positions do not change anything */
    if (p1 == p2)
        return head;

    /* If head is moved */
    if (p1 == 0)
    {
        /* Change head */
        Tree *p1_node = head;
        head = head -> next;

        /* insert node at position p2 */
        return insert(head, p1_node, p2);
    }

    /* Else take out p1 from its position and insert it on p2*/
    Tree *prev_p1 = getNode(head, p1 - 1);
    Tree *p1_node = prev_p1 -> next;
    prev_p1 -> next  = p1_node -> next;

    return insert(head, p1_node, p2);   
}

/* To traverse the list backwards */ 
Tree* reverse(Tree* head){
    
    Tree *prev = NULL;
    Tree *iter = head;
    Tree *after;

    while (iter != NULL)
    {
        after = iter -> next;
        iter -> next = prev;
        prev = iter;
        iter = after;
    }
    return prev;
}   
 
/* Iterate over and print data of every node */
void print(Tree* head){
    /* If list is empty, print -1 */
    if (head == nullptr)
    {
        cout << -1 << '\n';
        return;
    }

    while (head != nullptr)
    {
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << '\n';
}

/* To shift the list to the left by given x */ 
Tree* cyclic_left(Tree* head, int x){

    /* Nothing changes after shift by 0 */
    if (x == 0) return head;

    /* Node to iterate through the list */
    Tree *cur = head;

    /* Making new head */
    for(int i = 0; i < x; i++)
        cur = cur -> next;
    
    Tree *NewHead  = cur;

    /* Make last node point to old head */
    Tree *node = NewHead;
    while (node -> next != NULL)
        node = node -> next;

    node -> next = head;

    /* Make node before the new head point to NULL */
    Tree *last = head;
    while (last -> next != NewHead)
        last = last -> next;

    last -> next = NULL;

    /* Return the new head */
    return NewHead;   
}

/* To shift the list to the right by given x */ 
Tree* cyclic_right(Tree* head, int x){

    /* Return original head, since 0 shift changes nothing */
    if (x == 0) return head;

    /* Re-connect */
    int SIZE = GetSize(head);                           // Get the size of the linked list
    Tree *old_tail = getNode(head, SIZE - 1),           // Store the last node  
         *new_tail = getNode(head, SIZE - x - 1),       // New tail is always node before new head
         *new_head = new_tail -> next;                  // Store node after tail as a new head

    new_tail -> next = NULL;                            // Point new tail to null
    old_tail -> next = head;                            // Make old tail simple node pointing to old head
    
    return new_head;                                    // Return new beginning of the linked list
}
 
int main(){
    Tree* head = nullptr;

    /* Take commands and call requested functions */
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Tree(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}