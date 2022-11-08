#include <iostream>
#include <map>

using namespace std;

map <int, int> mp;

struct Node
{
    int data;                   
    Node *left;                 
    Node *right;                
    Node (int data){
        this -> data = data;    
        left = nullptr;         
        right = nullptr;
    }
};

struct BinSearchTree
{   
    Node *root = nullptr;

    void insert(Node *node, int data)
    {
        if (root == nullptr){
            root = new Node(data);
            return;
        }

        if (data > node -> data)
        {
            if (node -> right == nullptr)           
                node -> right = new Node(data);
            else
                insert(node -> right, data);        
        }
        else{
            if (node -> left == nullptr)            
                node -> left = new Node(data);
            else
                insert(node -> left, data);         
        }

    }

    int getLeaf(Node *node, char x)
    {
        int cnt = 0;
        while (node)
        {
            if (x == 'l') node = node -> left;
            else          node = node -> right;

            cnt++;
        }
        return cnt;
        
    }

    void kTriang(Node *node)
    {
        if (node == nullptr)
            return;

     
        int l = getLeaf(node, 'l');
        int r = getLeaf(node, 'r');
        
        int MIN = min(l, r) + 1;
        while (MIN--)
            mp[MIN]++;
        
        kTriang(node -> left);
        kTriang(node -> right);
    }

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    BinSearchTree bst;

    int x;
    for (size_t i = 0; i < n; i++)
    {
        cin >> x;
        bst.insert(bst.root, x);
    }

    bst.kTriang(bst.root);

    for (int k = 2; k <= n; k++)
        cout << mp[k] << " ";
}
