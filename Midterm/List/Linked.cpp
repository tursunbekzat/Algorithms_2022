// // CPP program to show the implementation of List
// #include <iostream>
// #include <iterator>
// #include <list>
// using namespace std;

// // function for printing the elements in a list
// void showlist(list<int> g)
// {
// 	list<int>::iterator it;
// 	for (it = g.begin(); it != g.end(); ++it)
// 		cout << *it << " --> ";
// 	cout << "NULL" << '\n';
// }

// // Driver Code
// int main()
// {

// 	list<int> gqlist1, gqlist2;

// 	for (int i = 0; i < 10; ++i) {
// 		gqlist1.push_back(i * 2);
// 		gqlist2.push_front(i * 3);
// 	}
// 	cout << "\nList 1 (gqlist1) is : ";
// 	showlist(gqlist1);

// 	cout << "\nList 2 (gqlist2) is : ";
// 	showlist(gqlist2);

// 	cout << "\ngqlist1.front() : " << gqlist1.front();
// 	cout << "\ngqlist1.back() : " << gqlist1.back();

// 	cout << "\ngqlist1.pop_front() : ";
// 	gqlist1.pop_front();
// 	showlist(gqlist1);

// 	cout << "\ngqlist2.pop_back() : ";
// 	gqlist2.pop_back();
// 	showlist(gqlist2);

// 	cout << "\ngqlist1.reverse() : ";
// 	gqlist1.reverse();
// 	showlist(gqlist1);

// 	cout << "\ngqlist2.sort(): ";
// 	gqlist2.sort();
// 	showlist(gqlist2);

// 	return 0;
// }

#include <iostream>
using namespace std;

struct List
{
    int val;
    List *next;
    List(int val)
    {
        this->val = val;
        // next = NULL;
    }
};

void Init(List **begin, List **end, int n)
{
    cout << "Print values: ";
    int x;
    cin >> x;

    (*begin) = new List(x);
    (*begin)->next = NULL;
    (*end) = (*begin);

    for (int i(1); i < n; i++)
    {
        cin >> x;
        (*end)->next = new List(x);
        (*end) = (*end)->next;
        (*end)->next = NULL;
    }
}

void Print(List *begin)
{
    List *tmp = begin;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int getSize(List *begin)
{
    if (begin == NULL)
    {
        return 0;
    }
    List *tmp = begin;
    int cnt = 0;
    while (tmp)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

void AddFront(List **begin, int x)
{
    List *newNode = new List(x);
    newNode->next = (*begin);
    (*begin) = newNode;
}

void AddBack(List **end, int x)
{
    List *newNode = new List(x);
    (*end)->next = newNode;
    (*end) = (*end)->next;
    (*end)->next = NULL;
}

void Insert(List **begin, List **end, int pos, int val)
{
    if (pos == 0)
    {
        AddFront(&(*begin), val);
        return;
    }
    if (getSize((*begin)) - 1 == pos)
    {
        AddBack(&(*end), val);
        return;
    }
    List *newNode = new List(val);
    List *tmp = (*begin);
    // List* cur = (*begin)->next;
    List *cor;
    while (pos)
    {
        cor = tmp;
        pos--;
        tmp = tmp->next;
        // cur = tmp->next;
    }
    cor->next = newNode;
    newNode->next = tmp;
}

void Delete(List **begin, int val)
{
    if(begin == NULL){
        cout << "Sorry, current list is empty!" << endl;
        return;
    }
    List *tmp = (*begin);
    if ((*begin)->val == val)
    {
        (*begin) = (*begin)->next;
        delete[] tmp;
        return;
    }
    List *cur = tmp;
    int cnt = 0;
    while (tmp->val != val)
    {
        cnt++;
        if (getSize((*begin)) == cnt)
        {
            return;
        }
        cur = tmp;
        tmp = tmp->next;
    }
    cur->next = tmp->next;
    delete[] tmp;
}

void Free(List *begin)
{
    List *tmp = begin;
    while (begin)
    {
        begin = begin->next;
        delete tmp;
        tmp = begin;
    }
}

void menu()
{
    cout << "-----------------Working with Linked List------------------\n"
         << endl
         << "\t\tSelect one option: \t\n\n"
         << "**            Create Linked List(create)                 **\n"
         << "**       AddFront value from Linked List(addfront)       **\n"
         << "**       AddBack value from Linked List(addback)         **\n"
         << "** Insert value any position to the Linked List(insert)  **\n"
         << "**       Delete element from Linked List(delete)         **\n"
         << "**            Get size current Linked List(getsize)      **\n"
         << "**                   Exit(exit)                          **\n"
         << endl;
}

int main()
{

    List *begin = NULL, *end;
    string command = "";
    while (1)
    {
        menu();
        cin >> command;

        if (command == "create")
        {

            cout << "Print count of list: ";
            int n;
            cin >> n;
            Init(&begin, &end, n);
            cout << "Current list: ";
            Print(begin);
        }
        else if (command == "addfront")
        {
            cout << "Print value to add front: ";
            int f;
            cin >> f;
            AddFront(&begin, f);
            cout << "Current list: ";
            Print(begin);
        }
        else if (command == "addback")
        {
            int b;
            cout << "Print value to add back: ";
            cin >> b;
            AddBack(&end, b);
            cout << "Current list: ";
            Print(begin);
        }
        else if (command == "insert")
        {
            cout << "Print value to insert any position(pos, value): ";
            int pos, val;
            cin >> pos >> val;
            Insert(&begin, &end, pos, val);
            cout << "Current list: ";
            Print(begin);
        }
        else if (command == "exit")
        {
            break;
        }
        else if (command == "delete")
        {
            cout << "Print value which you want to remove: ";
            int val;
            cin >> val;
            Delete(&begin, val);
            cout << "Current list: ";
            Print(begin);
        }
        else if(command == "getsize"){
            cout << getSize(begin) << endl;
        }
        else
        {
            cout << "Something went wrong! Please try to select correct command!" << endl;
        }
    }

    Free(begin);
    cout << "End of the program, see you soon!\n";
    return 0;
}