#include<iostream> 
#include <Queue.h>

void menu()
{
    List *begin, *end;
    int c;
    int d;
    do
    {
        printf("Choose one option: \n\t0: exit\n\t1: Add element\n\t2: print all elements\n\t3: clear queue\n\t4: queue is empty?\n\t5: reverse queue");
        printf("\n");
        // cin >> c;
        scanf("%i", &c);
        switch (c)
        { 
        case 1:
            cin >> d;
            push(*begin, d);
            break;
        case 2:
            print(*begin);
            break;
        case 3:
            clear(*begin);
            break;
        case 4:
            isempty(*begin);
            break;
        case 5:
            reverse(*begin);
            break;
        case 0:
            return;
        default:
            printf("Something went wrong! Please try again!");
            break;
        }
    } while (c != 0);
}

int main()
{
    menu();
    return 0;
}