#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *Insert_Begin(int val, Node *begin)
{
    Node *newNode = new Node(val);
    newNode->next = begin;
    begin->prev = newNode;
    begin = newNode;
    return begin;
}

Node *Remove_Begin(Node *begin, Node *end)
{
    Node *rmv = begin;
    begin = begin->next;
    begin = begin->next;
    begin->prev = NULL;
    delete rmv;
    return begin;
}

Node *Remove_End(Node *begin, Node *end)
{
}

Node *Insert_End(int val, Node *end)
{
    Node *newNode = new Node(val);
    newNode->prev = end;
    end->next = newNode;
    end = newNode;
    return end;
}

int Get_Size(Node *begin)
{
    Node *gs = begin;
    int count = 0;
    while (gs)
    {
        gs = gs->next;
        count++;
    }
    return count;
}

Node *Insert(int val, int pos, Node *begin, Node *end)
{
    Node *in = begin;
    Node *newNode = new Node(val);
    if (pos == 0)
    {
        return Insert_Begin(val, begin);
    }
    else if (pos == Get_Size(begin))
    {
        return Insert_End(val, end);
    }
    for (int i(0); i < pos - 1; i++)
    {
        in = in->next;
    }
    newNode->next = in->next;
    in->next->prev = newNode;
    in->next = newNode;
    newNode->prev = in;
    return begin;
}

Node *Remove_Pos(int pos, Node *begin, Node *end)
{
    if (pos == 0)
        return Remove_Begin(begin, end);
    if (pos == Get_Size(begin) - 1)
        return Remove_End(begin, end);
    Node *cur = begin;
    for (int i(0); i < pos - 1; i++)
    {
        cur = cur->next;
    }
    Node *tmp = cur->next;
    cur->next->next->prev = cur;
    cur->next = cur->next->next;
    delete tmp;
    return begin;
}

int main()
{
    Node *a = new Node(5);
    Node *b = new Node(15);
    a->next = b;
    Node *begin = a;
}