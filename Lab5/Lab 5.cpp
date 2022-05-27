#include "tree.h"

int main()
{
    tree* root = NULL;
    int size;
    char element;
    cout << "Enter the number of elements in tree: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the character:";
        cin >> element;
        addElement(root, element);
    }
    cout << "Your tree:" << endl;
    printTree(root,0);
    int maxD = getMaxDepth(root);
    cout << endl <<"Max depth/height of the tree: " << maxD;
}