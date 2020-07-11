#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
typedef int HPDataType;
void swap(HPDataType& a, HPDataType& b){
	HPDataType tmp = a;
	a = b;
	b = tmp;
}
 
//��С��
// parent:��ʾ��ʼ������λ��
// size:��ʾ����ĳ���
// ץס�ڵ�parent���µ������γ�С��
void shiftDown(HPDataType* array, int size, int parent){
	// ����λ��
	int child = 2 * parent + 1;
	// �����Һ�����ѡһ����С
	while (child < size){
		if (child + 1 < size && array[child] > array[child + 1]){
			child++;
		}
		// �͸��ڵ�Ƚ�
		if (array[child] < array[parent]){
			swap(array[child], array[parent]);
			// ����
			parent = child;
			child = 2 * parent + 1;
		}
		else{
			break;
		}
	}
}
// ��С��
void shiftDown001(int* arr,int size ,int parent){
	int child = 2 * parent + 1;
	while (child < size){
		if (child + 1 < size && arr[child] > arr[child + 1]){
			child++;
		}
		if (arr[child + 1] < arr[parent]){
			swap(arr[child + 1], arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else{
			break;
		}
	}
}

typedef struct Heap{
	HPDataType* _arr;
	int _size;
	int _capacity;
};
void heapCreat(Heap* hp , HPDataType* arr, int size){
	hp->_arr = (HPDataType*)malloc(sizeof(HPDataType)*size);
	memcpy(hp->_arr, arr, sizeof(HPDataType)*size);
	hp->_size = size;
	hp->_capacity = size;
	// ���ѣ������һ����Ҷ�ӽڵ㿪ʼ����
	//(size-2)/2���ǵ�һ����Ҷ�ӽڵ�
	for (int parent = (size - 2) / 2; parent >= 0; parent--){
		shiftDown(hp->_arr, size, parent);
	}
}

void print(int arr[], int len){
	for (int i = 0; i < len;++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}

// �����ʱ��С�����ϵ���
void shiftUp(HPDataType* arr, int child){
	int parent = (child - 1) / 2;
	while (parent >= 0){
		if (arr[parent] > arr[child]){
			swap(arr[child], arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else{
			// ���Ӵ��ڵ��ڸ��ף���������
			break;
		}
	}
}
void test(){
	Heap hp;
	int arr[] = { 20, 30, 7, 9, 50, 15, 28 };
	int len = sizeof(arr) / sizeof(arr[0]);
	print(arr, len);
	heapCreat(&hp,arr, len);
	print(hp._arr, len);
}
int main(){
	test();
	system("pause");
	return 0;
}
// ������
// �յ�/�и��ڵ�/ֻ������/ֻ���Һ���/�����Һ��ӵ�

// ��������������Ҷ�ӣ������ڵ�Ķȶ��Ƕ���ÿһ�㶼������
// ��ȫ���������������һ�����������������������һ����������м��޼��
// ���������϶�����ȫ����������ȫ��������һ������������

//��i��Ľڵ������ 2^(i-1)��

// �����
//void shiftDown(int arr[], int len,int parent){
//	// ���һ����Ҷ�ӽڵ�
//	int child = 2 * parent + 1;
//	if (child + 1 < len && arr[child + 1] > arr[child]){
//		child = child + 1;
//	}
//	// һ���к��Ӳ�ҪԽ��
//	while (child < len){
//		if (arr[parent] < arr[child]){
//			swap(arr[parent], arr[child]);
//			parent = child;
//			child = 2 * parent + 1;
//			if (child + 1 < len && arr[child] < arr[child + 1]){
//				child = child + 1;
//			}
//		}
//		else{
//			break;
//		}
//	}
//}
//void buildBigHeap(int arr[], int len){
//	for (int parent = (len - 2) / 2; parent >= 0; parent--){
//		shiftDown(arr, len , parent );
//	}
//}
//
//void print(int arr[], int len){
//	for (int i = 0; i < len;++i){
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//// ������
//// ����ѣ������������
//void Heapsort(int arr[], int len){
//	buildBigHeap(arr, len);
//	for (int tmplen=len; tmplen > 0 ; tmplen--){
//		swap(arr[0], arr[tmplen - 1]);
//		shiftDown(arr, tmplen-1, 0);
//	}
//}
//int main(){
//	int arr[] = { 20, 30, 7, 9, 50, 15, 28 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	print(arr, len);
//	buildBigHeap(arr, len);
//	print(arr, len);
//	Heapsort(arr, len);
//	print(arr, len);
//	cout << "end of process" << endl;
//	system("pause");
//	return 0;
//}

//typedef int BTDataType;
//
//// ������
//struct BinaryTreeNode{
//	struct BinaryTreeNode* _pleft;
//	struct BinaryTreeNode* _pright;
//	BTDataType _data;
//};
//
//struct ThreeTreeNode{
//	struct BinaryTreeNode* _pParent;
//	struct BinaryTreeNode* _pleft;
//	struct BinaryTreeNode* _pright;
//	BTDataType _data;
//};