#include <iostream>
template <class T>
struct Node
{
    T data;
    struct Node<T> *left;
    struct Node<T> *right;
};
template <class T>
class Binary_Tree
{
private:
    Node<T> *root;
    int size;

public:
    Binary_Tree()
    {
        size = 0;
    }
    void insert(const T &val)
    {

        Node<T> *newnode;
        newnode = new Node<T>();
        newnode->data = val;
        newnode->left = newnode->right = NULL;
        if (root == NULL)
        {
            root = newnode;
        }
        else
        {
            Node<T> *temp;
            temp = root;
            while (true)
            {
                if (val < temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = newnode;
                        return;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else if (val > temp->data)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = newnode;
                        return;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
                else
                {
                    throw("duplicate");
                }
            }
        }
    }
    void displayInOrder(Node<T> *node)
    {
        if (node != NULL)
        {
            displayInOrder(node->left);
            std::cout << node->data << " ";
            displayInOrder(node->right);
        }
    }
    void display()
    {
        if (root == NULL)
        {
            std::cout << "The tree is empty." << std::endl;
        }
        else
        {
            std::cout << "In-order traversal: ";
            displayInOrder(root->left);
            std::cout << std::endl;
        }
    }
};
int main()
{
    try
    {
        Binary_Tree<int> obj_1;
        obj_1.insert(15);
        obj_1.insert(7);
        obj_1.insert(25);
        obj_1.insert(5);
        obj_1.insert(9);
        obj_1.insert(8);
        obj_1.insert(11);
        obj_1.insert(23);
        obj_1.insert(27);
        obj_1.display();
    }
    catch (const char *msg)
    {
        std::cout << msg << '\n';
    }
    return 0;
}