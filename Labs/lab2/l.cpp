#include <iostream>
using namespace std;

/* Node data structure for linked list */
struct Tree {
    int val;
    Tree *next;
    
    Tree (int val){
        this -> val = val;
        this -> next = nullptr;
    }
};

/* To append elements into the linked list */
Tree* push(Tree **head, int data, Tree **last)
{
    /* Allocate and store data */
    Tree *new_node = new Tree(data);

    /* Make new node to be head if the linked list is empty */
    if (*head == NULL)
    {
        *head = new_node;
        return *head;
    }

    /* Make last node point to new one, making the new node to be last */
    (*last) -> next = new_node;
    return new_node;
}

/* To find maximum subarray sum */
int findMaxSum(Tree *head)
{
    int tmp_max = 0;
    long long int MAX = INTMAX_MIN;

    Tree *iter = head;
    while (iter != NULL)
    {
        /* Sum the value of the node */
        tmp_max += (iter -> val);

        /* Update the value of max value if needed */
        if (tmp_max > MAX) MAX = tmp_max;
            
        /* If current subarray sum if negative, start sum of new subarray */
        if (tmp_max < 0) tmp_max = 0;

        /* swing to next node */
        iter = iter -> next;
    }

    /* Return the sum of maximum subarray */
    return MAX;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* Take input to linked list */
    int n;
    cin >> n;

    int x;
    Tree *head = nullptr;
    Tree *tail = nullptr;
    for (size_t i = 0; i < n; i++)
    {
        cin >> x;
        tail = push(&head, x, &tail);
    }

    /* Print the answer */
    cout << findMaxSum(head);
}