#include <iostream>
using namespace std;

// Class Topic: Data Structures: Binary Search Trees
// What are BSTs?
// BSTs are a data structure that stores data in a tree-like structure
// Each node has a value and a pointer to the left and right nodes
// The left node is always less than the current node
// The right node is always greater than the current node
// This means that the tree is sorted

// Example:
//       5      |
//     /   \    |
//    3     7   |
//   / \   / \  |
//  2   4 6   8 |

// How do we implement a BST?
// We can use a class to represent a node

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    int getData()
    {
        return this->data;
    }
    void setData(int data)
    {
        this->data = data;
    }
    void setLeft(Node *left)
    {
        this->left = left;
    }
    void setRight(Node *right)
    {
        this->right = right;
    }


    Node *getLeft()
    {
        return this->left;
    }
    Node *getRight()
    {
        return this->right;
    }

}; // end of class Node

class BST
{
private:
public:
    Node *root;
    BST()
    {
        this->root = NULL;
    }
    void insertNode(Node *node)
    {
        if (this->root == NULL)
        {
            this->root = node;
        }
        else
        {
            Node *current = this->root;
            while (current != NULL)
            {
                if (node->getData() < current->getData())
                {
                    if (current->getLeft() == NULL)
                    {
                        current->setLeft(node);
                        break;
                    }
                    else
                    {
                        current = current->getLeft();
                    }
                }
                else
                {
                    if (current->getRight() == NULL)
                    {
                        current->setRight(node);
                        break;
                    }
                    else
                    {
                        current = current->getRight();
                    }
                }
            }
        }
    }

    void printInOrder(Node *node)
    {
        if (node == NULL)
            return;
        printInOrder(node->getLeft());
        cout << node->getData() << " ";
        printInOrder(node->getRight());
    }

    void prettyPrint(Node *node, int level)
    {
        if (node != NULL)
        {
            prettyPrint(node->getRight(), level + 1);
            for (int i = 0; i < level; i++)
            {
                cout << "    ";
            }
            cout << node->getData() << endl;
            prettyPrint(node->getLeft(), level + 1);
        }
    }
    // explaination of prettyPrint
    // pretty print is a recursive function
    // it takes in a node and a level
    // the level is used to determine how many spaces to print
    // the first time prettyPrint is called, the level is 0
    // the first thing prettyPrint does is call itself on the right node
    // the level is incremented by 1
    // this means that the right node will be printed 1 level deeper
    // the next thing prettyPrint does is print the current node
    // the current node is printed with the appropriate number of spaces
    // the last thing prettyPrint does is call itself on the left node
    // the level is incremented by 1
    // this means that the left node will be printed 1 level deeper
    // the level is incremented by 1 each time prettyPrint is called
    // this means that the left node will be printed 2 levels deeper
    // the right node will be printed 2 levels deeper
    // and so on

    void printPreOrder(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->getData() << " ";
        printPreOrder(node->getLeft());
        printPreOrder(node->getRight());
    }

    void printPostOrder(Node *node)
    {
        if (node == NULL)
            return;
        printPostOrder(node->getLeft());
        printPostOrder(node->getRight());
        cout << node->getData() << " ";
    }

    void deleteNode(Node *node)
    {
        if(this->root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        Node *current = this->root;
        Node *parent = NULL;
        while(current != NULL)
        {
            if(current->getData() == node->getData())
            {
                break;
            }
            else if(node->getData() < current->getData())
            {
                parent = current;
                current = current->getLeft();
            }
            else
            {
                parent = current;
                current = current->getRight();
            }
        }

        if(current == NULL)
        {
            cout << "Node not found" << endl;
            return;
        }

        if(current->getLeft() == NULL && current->getRight() == NULL)
        {
            if(parent == NULL)
            {
                this->root = NULL;
            }
            else if(parent->getLeft() == current)
            {
                parent->setLeft(NULL);
            }
            else
            {
                parent->setRight(NULL);
            }
            delete current;
        }
        else if(current->getLeft() == NULL || current->getRight() == NULL)
        {
            Node *child;
            if(current->getLeft() == NULL)
            {
                child = current->getRight();
            }
            else
            {
                child = current->getLeft();
            }

            if(parent == NULL)
            {
                this->root = child;
            }
            else if(parent->getLeft() == current)
            {
                parent->setLeft(child);
            }
            else
            {
                parent->setRight(child);
            }
            delete current;
        }
        else
        {
            Node *successor = current->getRight();
            Node *successorParent = current;
            while(successor->getLeft() != NULL)
            {
                successorParent = successor;
                successor = successor->getLeft();
            }

            current->setData(successor->getData());

            if(successorParent->getLeft() == successor)
            {
                successorParent->setLeft(successor->getRight());
            }
            else
            {
                successorParent->setRight(successor->getRight());
            }
            delete successor;
        }

    }


};

int main()
{
    BST *bst = new BST();
    bst->insertNode(new Node(5));
    bst->insertNode(new Node(3));
    bst->insertNode(new Node(7));
    bst->insertNode(new Node(2));
    bst->insertNode(new Node(4));
    bst->insertNode(new Node(6));
    bst->insertNode(new Node(8));

    cout << "Delete Node 5" << endl << endl;
    bst->deleteNode(new Node(5));

    cout << "In Order: ";
    bst->printInOrder(bst->root);
    cout << endl << endl;

    cout << "Pre Order: ";
    bst->printPreOrder(bst->root);
    cout << endl << endl;
    
    cout << "Post Order: ";
    bst->printPostOrder(bst->root);
    cout << endl << endl;

    cout << "Pretty Print: " << endl << endl;
    bst->prettyPrint(bst->root, 0);
    cout << endl << endl;

    return 0;
}