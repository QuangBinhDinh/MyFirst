#include<iostream>
using namespace std;
class Stack{
	private: 
		int A[100];
		int top;//top dinh nghia la phan tu cuoi cung trong Stack
	public:
		Stack(){//ham khoi tao mac dinh
			top = -1;//gia tri index ban dau cua top la -1(tuong tuong)
		}
		void Push(int data){//ham chen vao cuoi danh sach
			if(top == 100) cout<<"Overflow!!!"<<endl;
			else {
				++top;//top duoc day len 1 gia tri
				A[top] = data;//chen du lieu vao phan tu top
			}
		}
		void Pop(){//ham xoa phan tu cuoi stack
			if(top == -1) cout<<"Stack empty"<<endl;//truong hop stack rong
			else{
				top--;//lui gia tri cua top xuong 1 don vi
			}
		}
		void Print(){
			int i;
			for(i = 0; i<= top; i++){//in ra stack co index tu 0 den top
				cout<<A[i]<<" ";
			}
			cout<<endl;
		}
		int Top(){//tra ve gia tri cuoi stack(top)
			return A[top];
		}
		
};
int main(){
	Stack A;
	A.Push(2);
	A.Print();
	A.Push(5);
	A.Print();
	A.Push(7);
	A.Print();
	
	return 0;
}
