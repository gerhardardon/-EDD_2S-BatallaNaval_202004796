#include <iostream>
using namespace std;

class nodoavl {
public:
    int id;
    string name;
    int cant;

    nodoavl* left;
    nodoavl* right;
    int altura;
};

int altura(nodoavl* nodo) { //para obtener la altura del nodo
    if (nodo == NULL)
        return 0;
    return nodo->altura;
}

int max(int a, int b) //regresa el maximo de dos valores
{
    return (a > b) ? a : b;
}

nodoavl* newNode(int id, string name, int cant) //vuelve null las ramas left y right
{
    nodoavl* node = new nodoavl();
    node->id = id;
    node->name = name;
    node->cant = cant;
    node->left = NULL;
    node->right = NULL;

    node->altura = 1; // new node is initially
    // added at leaf
    return(node);
}

nodoavl* rightRotate(nodoavl* y) //rotar derecha
{
    nodoavl* x = y->left;
    nodoavl* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->altura = max(altura(y->left), altura(y->right)) + 1;
    x->altura = max(altura(x->left), altura(x->right)) + 1;

    // Return new root
    return x;
}

nodoavl* leftRotate(nodoavl* x)
{
    nodoavl* y = x->right;
    nodoavl* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->altura = max(altura(x->left), altura(x->right)) + 1;
    y->altura = max(altura(y->left), altura(y->right)) + 1;

    // Return new root
    return y;
}

int getBalance(nodoavl* nodo) //obtiene el balance
{
    if (nodo == NULL)
        return 0;
    return altura(nodo->left) - altura(nodo->right);
}

nodoavl* insert(nodoavl* node, int id, string name, int cant)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL) {//si está vacio
        return(newNode(id, name, cant));
    }
    if (id < node->id) {
        node->left = insert(node->left, id, name, cant);
    }
    else if (id > node->id) {
        node->right = insert(node->right, id, name, cant);
    }
    else { // Equal keys are not allowed in BST
        return node;
    }

    /* 2. Update height of this ancestor node */
    node->altura = 1 + max(altura(node->left), altura(node->right));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && id < node->left->id) {
        return rightRotate(node);
    }
    // Right Right Case
    if (balance < -1 && id > node->right->id) {
        return leftRotate(node);
    }
    // Left Right Case
    if (balance > 1 && id > node->left->id) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (balance < -1 && id < node->right->id) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

void preOrder(nodoavl* root)
{
    if (root != NULL)
    {
        cout << root->id << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

/*int main()
{
    nodoavl *root = NULL;


    root = insert(root, 10,"s",1);
    root = insert(root, 20,"s",1);
    root = insert(root, 30,"s",1);
    root = insert(root, 40,"s",1);
    root = insert(root, 50,"s",1);
    root = insert(root, 25,"s",1);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    return 0;
}
*/