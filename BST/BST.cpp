#include <iostream>
#include <Queue>
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

int FindMin(BstNode* root){
    BstNode*current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current->data;
}
int FindMax(BstNode* root){
    BstNode* current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return current->data;
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
        cout<<"current->data"<<"\n";
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

bool isSubreeGreater(BstNode* root,int Value){
    if(root == NULL) return true;
    if(root->data< Value) return true;
        return false;
    
}

bool isLeftSubtreeBalanced(BstNode*root, int Value){
if(root == NULL) return true;
    if(root->data <= value && isLeftSubtreeBalanced(root->left, root->data) &&isSubreeGreater(root->right,value)){
        
    }
}

bool checkBalanceofNode(BstNode*root){
    if(root == NULL) return true;
    BstNode* left = root->left;
    BstNode* right = root->right;
    if(root->data >= left->data){
    return checkBalanceofNode(root->left);
    }


}

int main(){
    BstNode* root = NULL;
    cout<<"Binary Search Tree"<<"\n";
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,1);
    root =Insert(root,16);
    root = Insert(root,21);
    root= Insert(root,70);
    root = Insert(root,69);
    root = Insert(root,68);
    root = Insert(root,67);
    cout<<FindMin(root)<<endl;
    cout<<FindMax(root)<<endl;
    cout<<FindHeight(root)<<endl;
}
