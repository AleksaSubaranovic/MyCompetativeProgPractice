#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int data){
		this->data = data;
		left = right = nullptr;
	}
};

Node* root;

/* DFS */
void PrintInorder(Node* node){
	if (node == nullptr) return;
	PrintInorder(node->left);
	cout << node->data;
	PrintInorder(node->right);
}

void PrintPreorder(Node* node){
	if (node == nullptr) return;
	cout << node->data;
	PrintPreorder(node->left);
	PrintPreorder(node->right);
}

void PrintPostorder(Node* node){
	if (node == nullptr) return;
	PrintPostorder(node->left);
	PrintPostorder(node->right);
	cout << node->data;
}
/* DFS */

/* BFS */
int height(Node* node){
	if (node == nullptr) return 0;
	int lheight = height(node->left);
	int rheight = height(node->right);
	return lheight > rheight ? lheight + 1 : rheight + 1 ;
}

void PrintLevel(Node* root, int level){
	if (root == nullptr) return;
	if (level == 1) cout << root->data;
	else if (level > 1){
		PrintLevel(root->left,level-1);
		PrintLevel(root->right,level-1);	
	}
}

void PrintOrder(Node* node){
	int h = height(node);
	for (int i = 1; i<=h; i++) PrintLevel(node,i);
}
/* BFS */

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	root = new Node(1);
	root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);
    PrintInorder(root); cout << endl;
    PrintPreorder(root); cout << endl;
    PrintPostorder(root); cout << endl;
    PrintOrder(root);
	
}
