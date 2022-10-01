#include<iostream>

using namespace std;

struct Element{
    int n;
    Element *next;
};

struct List{
    Element *begin = NULL, *end = NULL;
};

void push(List &l, int n);
void reverse(List &l);
void print(List &l);
void clear(List &l);
void isempty(List &l);