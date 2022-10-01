#include<Queue.h>

void push(List &l, int n){
    Element *t = (Element*)malloc(sizeof(Element));
    t->n = n;
    t->next = NULL;
    if(l.begin == NULL){
        l.end = t;
        l.begin = t;
    }else{
        l.end->next = t;
        l.end = t;
    }
};
void reverse(List &begin);
void print(List &begin);
void clear(List &begin);
void isempty(List &begin);