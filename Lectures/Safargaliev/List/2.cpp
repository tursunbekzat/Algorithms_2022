#include <iostream>

using namespace std;

struct Tree
{
    int val;
    Tree *next;
    Tree *prev;
    Tree(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

Tree *Insert_Begin(int val, Tree *begin)
{
    Tree *newNode = new Tree(val);
    newNode->next = begin;
    begin->prev = newNode;
    begin = newNode;
    return begin;
}

Tree *Remove_Begin(Tree *begin, Tree *end)
{
    Tree *rmv = begin;
    begin = begin->next;
    begin = begin->next;
    begin->prev = NULL;
    delete rmv;
    return begin;
}

Tree *Remove_End(Tree *begin, Tree *end)
{
}

Tree *Insert_End(int val, Tree *end)
{
    Tree *newNode = new Tree(val);
    newNode->prev = end;
    end->next = newNode;
    end = newNode;
    return end;
}

int Get_Size(Tree *begin)
{
    Tree *gs = begin;
    int count = 0;
    while (gs)
    {
        gs = gs->next;
        count++;
    }
    return count;
}

Tree *Insert(int val, int pos, Tree *begin, Tree *end)
{
    Tree *in = begin;
    Tree *newNode = new Tree(val);
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

Tree *Remove_Pos(int pos, Tree *begin, Tree *end)
{
    if (pos == 0)
        return Remove_Begin(begin, end);
    if (pos == Get_Size(begin) - 1)
        return Remove_End(begin, end);
    Tree *cur = begin;
    for (int i(0); i < pos - 1; i++)
    {
        cur = cur->next;
    }
    Tree *tmp = cur->next;
    cur->next->next->prev = cur;
    cur->next = cur->next->next;
    delete tmp;
    return begin;
}

int main()
{
    Tree *a = new Tree(5);
    Tree *b = new Tree(15);
    a->next = b;
    Tree *begin = a;
}