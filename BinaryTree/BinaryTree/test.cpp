#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
typedef int HPDataType;
void swap(HPDataType& a, HPDataType& b){
	HPDataType tmp = a;
	a = b;
	b = tmp;
}
 
//建小堆
// parent:表示起始调整的位置
// size:表示数组的长度
// 抓住节点parent向下调整，形成小堆
void shiftDown(HPDataType* array, int size, int parent){
	// 左孩子位置
	int child = 2 * parent + 1;
	// 从左右孩子中选一个最小
	while (child < size){
		if (child + 1 < size && array[child] > array[child + 1]){
			child++;
		}
		// 和父节点比较
		if (array[child] < array[parent]){
			swap(array[child], array[parent]);
			// 更新
			parent = child;
			child = 2 * parent + 1;
		}
		else{
			break;
		}
	}
}
// 建小堆
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
	// 建堆，从最后一个非叶子节点开始建堆
	//(size-2)/2就是第一个非叶子节点
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

// 插入的时候，小堆向上调整
void shiftUp(HPDataType* arr, int child){
	int parent = (child - 1) / 2;
	while (parent >= 0){
		if (arr[parent] > arr[child]){
			swap(arr[child], arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else{
			// 孩子大于等于父亲，结束调整
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
// 二叉树
// 空的/有根节点/只有左孩子/只有右孩子/有左右孩子的

// 满二叉树：除过叶子，其他节点的度都是二，每一层都是满的
// 完全二叉树：除过最后一层其余层组成满二叉树，最后一层从左向右中间无间隔
// 满二叉树肯定是完全二叉树，完全二叉树不一定是满二叉树

//第i层的节点最多有 2^(i-1)个

// 建大堆
//void shiftDown(int arr[], int len,int parent){
//	// 最后一个非叶子节点
//	int child = 2 * parent + 1;
//	if (child + 1 < len && arr[child + 1] > arr[child]){
//		child = child + 1;
//	}
//	// 一轮中孩子不要越界
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
//// 堆排序
//// 建大堆：排序就是增序
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
//// 二叉树
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