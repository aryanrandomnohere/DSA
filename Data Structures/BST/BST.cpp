#include <iostream>
#include <queue>
using namespace std;
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode;
       newNode->data = data;
        return newNode;
}

bool Search(BstNode* root,int data){
    if(root == NULL) return false;
    if(data == root->data) return true;
    if(data < root->data) return Search(root->left,data);
    else return Search(root->right,data);
}

BstNode* Insert(BstNode* root,int x){
    BstNode* newNode = GetNewNode(x);
    if(root == NULL) root = newNode;
    else if(root->data >= x){
       root->left = Insert(root->left,x);
    }else {
        root->right = Insert(root->right,x);
    }
    return root;
} 

BstNode* FindMin(BstNode* root){
    BstNode*current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}
BstNode* FindMax(BstNode* root){
    BstNode* current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return current;
}

int FindHeight(BstNode* root){
    if(root == NULL){
        return -1;
    }
    return max(FindHeight(root->right),FindHeight(root->left))+1;
}

void levelOrderTraversal(BstNode* root){
if(root == NULL) return;
queue<BstNode*> q; 
    q.push(root);
while(!q.empty()){
   BstNode* current =q.front();
        cout<<current->data<<"\n";
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
        q.pop();
    }
}

void PreorderTraversal(BstNode* root){
    if(root ==NULL) return;
    cout<<root->data<<"\n";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
void InorderTraversal(BstNode*root){
if(root == NULL) return;
InorderTraversal(root->left);
cout<<root->data;
InorderTraversal(root->right);
}

void PostOrderTraversal(BstNode*root){
if(root==NULL) return;
PostOrderTraversal(root->left);
PostOrderTraversal(root->right);
cout<<root->data;
}
bool isSubtreelesser(BstNode* root, int value){
if(root == NULL) return true;
if(root->data <= value) return true;
    return false;
}

bool isSubtreeGreater(BstNode* root,int value){
if(root == NULL) return true;
    if(root->data > value) return true;
    return false;
}


bool IsBinarySearchTree(BstNode* root){
if(root== NULL) return true;
    if(isSubtreelesser(root->left,root->data)&& isSubtreeGreater(root->right,root->data) && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right)) return true;
    return false;
}

BstNode* Delete(BstNode*root, int data){
    if(root == NULL) return root;
    if(root->data > data ){ root->left = Delete(root->left, data);
    } else if(root->data < data){ root->right = Delete(root->right, data);}
    else if(root->left == NULL && root->right == NULL) {
        delete root;
        root = NULL;
    }else if(root->right == NULL){
         BstNode* temp = root;
         root = root->left;
         delete temp;
    }else if(root->left == NULL){
         BstNode* temp = root;    
         root = root->right;
         delete temp;
     }else{
        BstNode* temp = FindMin(root->right);
        cout<<"Min element is: "<<temp->data<<endl;
        root->data = temp->data;
        root->right = Delete(root->right,temp->data);
    }


    return root;
}


BstNode* getSuccessor(BstNode* root, int data){
    BstNode* current = root;
    while(current->data != data){
        if(data > current->data) current = current->right;
        else if(data< current->data) current = current->left;
    }
    if(current->right != NULL) {
    current =current->right;
    if(current->left  == NULL) return current;
    while (current->left != NULL) current = current->left;
    return current;
}else{
    BstNode*successor = NULL;
    BstNode* ancestor = root;
    while (ancestor != current){
    if(current->data < ancestor->data){
    successor = ancestor;
                ancestor = ancestor->left;
            }else{
                ancestor = ancestor->right;
            }
    }
        return successor;

      
}
    
}

int main(){
    BstNode* root = NULL;
    cout<<"Binary Search Tree"<<"\n";
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,1);
    root = Insert(root,16);
    root = Insert(root,21);
    root = Insert(root,70);
    root = Insert(root,69);
    root = Insert(root,71);
    root = Insert(root,68);
    root = Insert(root,67);
    cout<<FindMin(root)<<endl;
    cout<<FindMax(root)<<endl;
    cout<<FindHeight(root)<<endl;
    levelOrderTraversal(root);
    bool isValid =   IsBinarySearchTree(root);
    if(isValid) cout<<"The binary tree is valid";
    else cout<<"Binary tree is not valid";
    root = Delete(root,70);
    levelOrderTraversal(root);
     BstNode*successor =  getSuccessor(root,69);
    cout<<"The successor of "<< 69<<"is"<<successor->data;
    InorderTraversal(root);
}       
