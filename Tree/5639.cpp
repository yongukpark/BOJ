//구조체로 구현하니깐 생각보다 쉬운문제였던 것 같음
//하지만 초반에 시간복잡도를 고려한다고 코드 삽질한것이 너무 손해였음


#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* left = NULL;
    Node* right = NULL;
};

void postOrder(Node* n)
{
    if(n->left != NULL)
    {
        postOrder(n->left);
    }
    if(n->right != NULL)
    {
        postOrder(n->right);
    }
    cout << n->value << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> a;
    Node* root = new Node;
    root->value = a;
    while(cin >> a)
    {
        Node* newNode = new Node;
        newNode->value = a;
        Node* curNode = root;
        while(1)
        {
            if(a < curNode->value)
            {
                if(curNode->left == NULL)
                {
                    curNode->left = newNode;
                    break;
                }
                else
                {
                    curNode = curNode->left;
                }
            }
            else if(a > curNode->value)
            {
                if(curNode->right == NULL)
                {
                    curNode->right = newNode;
                    break;
                }
                else
                {
                    curNode = curNode->right;
                }
            }
        }
    }
    postOrder(root); 
}
