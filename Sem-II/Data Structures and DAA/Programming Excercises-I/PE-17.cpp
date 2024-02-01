#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int info;
    node * left;
    node * right;
    bool lthread;
    bool rthread;
};
node *insert(node *root, int ikey){
    node *ptr = root;
    node *par = NULL; // Parent of key to be inserted
    while (ptr != NULL){
        // If key already exists, return
        if (ikey == (ptr->info)){
            cout<<"Duplicate Key"<<endl;
            return root;
        }
        par = ptr; // Update parent pointer
        // Moving on left subtree.
        if (ikey < ptr->info){
            if (ptr -> lthread == false){
                ptr = ptr -> left;
            }
            else
                break;
        }
        // Moving on right subtree.
        else{
            if (ptr->rthread == false){
                ptr = ptr -> right;
            }
            else
                break;
        }
    }
 
    // Create a new node
    node *tmp = new node();
    tmp -> info = ikey;
    tmp -> lthread = true;
    tmp -> rthread = true;
    if (par == NULL){
        root = tmp;
        tmp -> left = NULL;
        tmp -> right = NULL;
    }
    else if (ikey < (par -> info)){
        tmp -> left = par -> left;
        tmp -> right = par;
        par -> lthread = false;
        par -> left = tmp;
    }
    else{
        tmp -> left = par;
        tmp -> right = par -> right;
        par -> rthread = false;
        par -> right = tmp;
    }
 
    return root;
}
node *inorderSuccessor(node *ptr){
    // If rthread is set, we can quickly find
    if (ptr -> rthread == true){
        return ptr->right;
    }
    // Else return leftmost child of right subtree
    ptr = ptr -> right;
    while (ptr -> lthread == false)
        ptr = ptr -> left;
    return ptr;
}
void inorder(node *root){
    if (root == NULL)
        cout<<"Empty Tree"<<endl;
    // Reach leftmost node
    node *ptr = root;
    while (ptr -> lthread == false){
        ptr = ptr -> left;
    }
    // One by one print successors
    while (ptr != NULL){
        cout<<ptr->info<<" ";
        ptr = inorderSuccessor(ptr);
    }
    cout<<endl;
}
node* inPred(node* ptr){
    if (ptr->lthread == true)
        return ptr->left;
    ptr = ptr->left;
    while (ptr->rthread == false)
        ptr = ptr->right;
    return ptr;
}
node* inSucc(node* ptr){
    if (ptr->rthread == true)
        return ptr->right;
    ptr = ptr->right;
    while (ptr->lthread == false)
        ptr = ptr->left;
 
    return ptr;
}
 
node* caseA(node* root,node* par,node* ptr){
    // If Node to be deleted is root
    if (par == NULL){
        root = NULL;
    }
    // If Node to be deleted is left
    // of its parent
    else if (ptr == par->left) {
        par->lthread = true;
        par->left = ptr->left;
    }
    else {
        par->rthread = true;
        par->right = ptr->right;
    }
    // Free memory and return new root
    free(ptr);
    return root;
}
node* caseB(node* root,node* par,node* ptr){
    node* child;
    // Initialize child Node to be deleted has
    // left child.
    if (ptr->lthread == false)
        child = ptr->left;
    // Node to be deleted has right child.
    else
        child = ptr->right;
    // Node to be deleted is root Node.
    if (par == NULL)
        root = child;
    // Node is left child of its parent.
    else if (ptr == par->left)
        par->left = child;
    else
        par->right = child;

    // Find successor and predecessor
    node* s = inSucc(ptr);
    node* p = inPred(ptr);
    // If ptr has left subtree.
    if (ptr->lthread == false)
        p->right = s;
    // If ptr has right subtree.
    else {
        if (ptr->rthread == false)
            s->left = p;
    }
    free(ptr);
    return root;
}
node* caseC(node* root,node* par,node* ptr){
    // Find inorder successor and its parent.
    node* parsucc = ptr;
    node* succ = ptr->right;
    // Find leftmost child of successor
    while (succ->left != NULL) {
        parsucc = succ;
        succ = succ->left;
    }
    ptr->info = succ->info;
    if (succ->lthread == true && succ->rthread == true)
        root = caseA(root, parsucc, succ);
    else
        root = caseB(root, parsucc, succ);
    return root;
}
node* delThreadedBST(node* root, int dkey){
    // Initialize parent as NULL and ptrent
    // Node as root.
    node *par = NULL, *ptr = root;
    // Set true if key is found
    int found = 0;
    // Search key in BST : find Node and its
    // parent.
    while (ptr != NULL) {
        if (dkey == ptr->info) {
            found = 1;
            break;
        }
        par = ptr;
        if (dkey < ptr->info) {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    if (found == 0)
        cout<<"Key not present in tree"<<endl;
    // Two Children
    else if (ptr->lthread == false && ptr->rthread == false)
        root = caseC(root, par, ptr);
    // Only Left Child
    else if (ptr->lthread == false)
        root = caseB(root, par, ptr);
    // Only Right Child
    else if (ptr->rthread == false)
        root = caseB(root, par, ptr);
    // No child
    else
        root = caseA(root, par, ptr);
    return root;
}
int main(){
    node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 13);
    inorder(root);
    root=delThreadedBST(root,20);
    inorder(root);
    return 0;
}
