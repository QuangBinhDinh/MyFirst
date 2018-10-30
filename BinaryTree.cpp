#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};
Node* GetNode(int data){
	//ham khoi tao 1 node moi
	Node *p = new Node();
	p->data = data;//gan gia tri node
	p->left = NULL;
	p->right = NULL;
	return p;
};
Node* insertNode(Node* root,int data){
	//ham insert Node (tra ve root)
	if(root == NULL) {
		root = GetNode(data);//neu root Null thi them node moi
	}
	else if(root->data >= data) {
		root->left = insertNode(root->left,data);//neu data co gia tri nho hon root->left thi coi child cua root la root moi
		//de quy ham(kiem tra root == NULL 1 lan nua)
	}
	else {
		root->right = insertNode(root->right,data);//de quy tuong tu nhu tren
	}
	return root;
};

bool searchNode(Node *root, int data){
	if(root == NULL) return false;//neu root NULL tra ve false
	else if(root->data == data) return true;//neu dung voi du lieu tra ve true
	else if(root->data > data) return searchNode(root->left,data);//neu gia tri root lon hon data thi de quy ham (root moi la left child cua root truoc)
	else  return searchNode(root->right,data);//de quy tiep tra ve 1 trong 2 gia tri true hay false. Neu root co child thi tiep tuc thuc hien de quy
};
void preOrder(Node *root){//in theo thu tu preOrder
    //thu tu preOrder: root -> left child -> right child
	if(root == NULL) return;//neu root Null thi ket thuc ham, neu khong thi tiep tuc thuc hien cac lenh duoi
	cout<<root->data<<" ";//in ra du lieu cua root
	preOrder(root->left);//de quy ham (lan nay left child cua root la root moi). Kiem tra root moi Null hay khong, neu khong thi in ra du lieu
	preOrder(root->right);//luu y: neu nhu root->left con nhieu child thi phai doi cho tat ca cac child cua left duoc in ra, khi do de quy right moi dc thuc hien
};
void inOrder(Node *root){//in theo thu tu inOrder
    //thu tu: left child -> root -> right child
	if(root == NULL) return;//neu root Null ket thuc ham ngay lap tuc, neu khong tiep tuc thuc hien ham
	inOrder(root->left);//de quy ham(left child se la root moi), roi kiem tra root moi co Null hay khong
	//luu y: ham de quy moi se chay tiep 2 ham de quy root->left va root->right, khi nao khong con child thi moi dung lai
	cout<<root->data<<" ";//in ra du lieu cua root hien tai
	inOrder(root->right);//tiep tuc thuc hien de quy nhu tren
};
void postOrder(Node *root){//in ra the thu tu postOrder
	//thu tu: left child -> right child -> root
	if(root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
};
int findMin(Node *root){//in ra phan tu min trong tree
    if(root == NULL) return -1;//neu tree rong
    while(root->left != NULL){
    	root = root->left;//kiem tra neu root co left child thi root se tro den chinh left child do
	}
	return root->data;//khi root cua left child khong con thi tra ve gia tri
	//luu y: tham so *root la local variable nen thay doi root khong lam anh huong den root trong tree
}
Node* findNodeMin(Node *root){//ham tra ve node co gia tri nho nhat trong tree(sub tree)
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}
Node* deleteNode(Node* root, int data){//ham delete 1 node co gia tri data
	if(root == NULL) return root;//tra ve root luon neu root NULL, neu khong thi tiep tuc thuc hien cac lenh duoi
	else if(data < root->data) root->left = deleteNode(root->left, data);//tim kiem Node thong qua de quy
	else if(data > root->data) root->right = deleteNode(root->right,data);
	else{//truong hop tim thay duoc node
		if(root->left == NULL && root->right == NULL){//truong hop Node khong co left child hay right child
			delete root;//delete Node trong heap
			root = NULL;//set root la NULL, khi ham return se la NULL
		}else if(root->left == NULL){//neu chi co 1 child
			Node* temp = root;//tao ra 1 node tam thoi de luu tru du lieu cua root
			root = root->right;//cho root cho den child con lai(cach lam nay la de lien ket den right child
			//khi ham return Node se la right child
			delete temp;
		}else if(root->right == NULL){
			Node* temp = root;
			root = root->left;
			delete temp;
		}else{
			Node* temp = findNodeMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	return root;
}
int main(){
	Node *root = NULL;
	root = insertNode(root,2);
	root = insertNode(root,1);
	root = insertNode(root,10);
	root = insertNode(root,6);
	root = insertNode(root,3);
	root = insertNode(root,8);
	root = insertNode(root,7);
	root = insertNode(root,13);
	root = insertNode(root,20);
	root = insertNode(root,14);
	root = insertNode(root,0);
	root = insertNode(root,35);
    cout<<endl;
    cout<<"Preorder list"<<endl;
    preOrder(root);
    cout<<endl;
    root = deleteNode(root,6);
    root = deleteNode(root,13);
    root = deleteNode(root,35);
    cout<<"Preorder"<<endl;
    preOrder(root);
	return 0;
}
