#include<iostream>
#include<list>

using namespace std;

class IntList{
private:
    struct ListItem{
        int item;
        ListItem *next;

        ListItem(int i, ListItem *n = NULL){
            item = i;
            next = n;
        }                                                                                                
    };

    int itemsCount;
    ListItem *first;
    ListItem *last;
public:
    IntList(){
        itemsCount = 0;
        first = last = NULL;
    }
    IntList(const IntList & src);
    
};

int main(){
    return 0;
}