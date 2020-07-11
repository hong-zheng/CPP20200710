#define _CRT_SECURE_NO_WARNGINS 1
#include <iostream>
#include <string>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
using namespace std;



// AVL����ƽ������,���������-��������� (-1,0,1)




template<class T>
struct AVLNode{
	T _value;
	int _bf; //ƽ������
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	AVLNode<T>* _parent;

	AVLNode(const T& val=T())
	:_value(val)
	, _vf(0)
	, _left(nullptr)
	, _right(nullptr)
	, _parent(nullptr)
	{	}
};

template<class T>
class AVLTree{
public:
	typedef AVLNode<T> Node;

	AVLTree():_root(nullptr){}

	bool insert(const T& val){
		if (_root == nullptr){
			_root = new Node(val);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur){
			parent = cur;
			if (cur->_value == val) return false;
			if (cur->_value < val){
				cur = cur->_right;
			}
			else{
				cur = cur->_left;
			}
		}
		// ����
		cur = new Node(val);
		if (parent->_value < val)
			parent->_right = cur;
		else
			parent->_left = cur;
		// ���¸��ڵ�
		cur->_parent = parent;

		// ����_bf���������ṹ
		// �����µĽڵ�֮��������ƽ������
		//  ������Ҫ����ƽ�����ӵĽڵ������е����Ƚڵ�
		//		����ڵ����������߶ȷ����仯������Ҫ����
		while (parent){

			if (parent->_left == cur){
				--parent->_bf;
			}
			else{
				++parent->_bf;
			}

			// �ж��Ƿ���Ҫ��������
			if (parent->_bf == 0){
				break;
			}
			// ��ʾ���ڵ�ƽ�ⷢ���仯�������Ҫ��������
			else if (parent->_bf==1||parent->_bf==-1) {
				cur = parent;
				parent = cur->_parent;
			}
			// �����ʱ�Ѿ���ƽ�⣬��Ҫ����
			else if (parent->_bf == 2 || parent->_bf == -2){

				// ����


				if (parent->_bf == -2 && cur->_bf == -1)
				{
					// ��ߵ���߸ߣ�����
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1){
					// �ұ߸ߣ�����
					RotaRotateRteL(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1){
					// �ұߵ���߸ߣ�����˫��
					Node* subR = parent->_right;
					Node* subRL = subR->_left;
					int bf = subRL->_bf;

					RotateR(cur);
					RotateR(parent);

					//����ƽ������
					if (bf == 1){
						//subRL��������
						subR->_bf = 0;
						parent->_bf = -1;
					}
					else if (bf == -1){
						// subRL��������
						subR->_bf = 1;
						parent->_bf = 0;
					}
				}
				else if (parent->_bf == -2 && cur->_bf == 1){
					RotateL(cur);
					RotateR(parent);
				}

				// �������Ҳ�Ͳ��������ϸ���
				// ������֮��϶�����AVL�����������ֱ���˳�
				break;
			}
		}


		return true;
	}

	void RotateL(Node* parent){
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;

		if (subRL){
			subRL->_parent = parent;
		}
		
		if (parent == _root){
			_root = subR;
			subR->_parent = nullptr;
		}
		else{
			Node* g = parent->_parent;
			subR->_parent = g;
			if (g->_left == parent){
				g->_left = subR;
			}
			else{
				g->_right = subR;
			}
		}

		parent->_parent = subR;

		parent->_bf = subR->_bf = 0;
	}
	void RotateR(Node* parent){
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;

		// �������
		if (subLR){
			subLR->_parent = parent;
		}

		if (parent == _root){
			_root = subL;
			subLR->_parent = nullptr;
		}
		else{
			Node* g = parent->_parent;
			subL->_parent = g;

			if (g->_left == parent){
				g->_left = subL;
			}
			else{
				g->_right = subL;
			}
		}

		parent->_parent = subL;
		parent->_bf = subL->_bf = 0;
	}
private:
	Node* _root;
};
void test(){

}
int main(){

	test();

	system("pause");
	return 0;
}
//
//
//void test(){
//	// �ײ���Ȼ�������������Դ���ظ�Ԫ��
//	multiset<int> mset;
//	multimap<int,string> mmap;
//
//	mset.insert(1);
//	mset.insert(2);
//	mset.insert(4);
//	mset.insert(-1);
//	mset.insert(-10);
//	mset.insert(-1);
//
//	for (const auto& e : mset){
//		cout << e << " ";
//	}
//	cout << endl;
//}
//void testMap(){
//
//	// multimapû��[]�ӿ�
//	multimap<int, string> mmap;
//	mmap.insert(make_pair(1, string("11111")));
//	mmap.insert(make_pair(2, string("wsfds")));
//
//	for (const auto& e : mmap){
//		cout << e.first << "-->" << e.second.c_str() << endl;
//	}
//	cout << endl;
//
//	
//}
//
//
//template<class T>
//struct AVLNode{
//	T _value;
//	int _bf;
//	AVLNode<T>* _left;
//	AVLNode<T>* _right;
//	AVLNode<T>* _parent;
//
//	AVLNode(const T& val = T())
//		:_value(val)
//		, _bf(0)
//		, _left(nullptr)
//		, _right(nullptr)
//	{}
//};
//
//template<class T>
//class AVLTree{
//public:
//	typedef AVLNode<T> Node;
//
//	bool insert(const T& val){
//		if (nullptr == _root) _root = new Node(val) , return true;
//		// ����������
//		Node* cur = _root;
//		Node* prev = nullptr;
//		while (cur){
//			prev = cur;
//			if (cur->_value == val) return fasle;
//			if (val > cur->_value){
//				cur = cur->_right;
//			}
//			else{
//				cur = cur->_left;
//			}
//		}
//		cur = new Node(val);
//		if (prev->_value < val)
//			prev->_right = cur;
//		else
//			prev->_left=cur;
//
//		cur->_parent = prev;
//		// ����+����
//		Node* parent = prev;
//		while (parent){
//			//1������parentƽ������
//			if (parent->_left == cur){
//				--parent->_bf;
//			}
//			else{
//				++parent->_left;
//			}
//			// �ж��Ƿ���Ҫ��������
//			if (parent->_bf == 0)
//				break;
//			else if(parent->_bf==1||parent->_bf==-1){
//				//�������ϸ���
//				cur = parent;
//				parent = parent->_parent;
//			}
//			// ��ʱ�Ѿ���ƽ�⣬��Ҫ����
//			else if (parent->_bf == -2 || parent->_bf == 2){
//				// ����֮����Ҫ���ϸ��£�ֱ��break������
//
//
//				break ;
//			}
//		}
//		return true;
//	}
//private:
//	Node* _root;
//};
//
//
//int len(string& str){
//	int sz = str.size();
//	if (sz <= 4) return 5;
//	if (sz <= 7) return 10;
//	return 25;
//}
//
//int Zcnt = 0;
//int ZCNT = 0;
//int zimu(string& str){
//	for (int i = 0; i<str.size(); ++i){
//		if (str[i] >= 'a' && str[i] <= 'z')
//			Zcnt++;
//		if (str[i] >= 'A' && str[i] <= 'Z')
//			ZCNT++;
//	}
//
//	if (Zcnt == 0 && ZCNT == 0) return 0;
//	if (((Zcnt == 0) && (ZCNT != 0)) || ((Zcnt != 0) && (ZCNT == 0))) return 10;
//	return 20;
//}
//
//int num(string& str){
//	int cnt = 0;
//	for (int i = 0; i<str.size(); ++i){
//		if (str[i] >= '0' && str[i] <= '9')
//			++cnt;
//	}
//	if (!cnt) return 0;
//	if (cnt == 1) return 10;
//	return 20;
//}
//int fuhao(string& str){
//	int cnt = 0;
//	for (int i = 0; i<str.size(); ++i){
//		char c = str[i];
//		if (((c >= 0x21) && (c <= 0x2F))
//			|| ((c >= 0x3A) && (c <= 0x40))
//			|| ((c >= 0x5B) && (c <= 0x60))
//			|| ((c >= 0x7B) && (c <= 0x7E))){
//			cnt++;
//		}
//	}
//	if (!cnt) return 0;
//	if (cnt == 1) return 10;
//	return 25;
//}
//int jiangli(int num1, int fuhao1){
//	if (ZCNT && Zcnt && num1 && fuhao1) return 5;
//	if ((Zcnt + ZCNT) && num1 && fuhao1) return 3;
//	if ((ZCNT + Zcnt) && num1) return 2;
//	return 0;
//}
//
//int ret(string& str){
//	int num1 = num(str);
//	int fuhao1 = fuhao(str);
//	int retfen = len(str) + zimu(str) + fuhao1 + num1 + jiangli(num1, fuhao1);
//	return retfen;
//}
//int main1(){
//	string str;
//	while (getline(cin, str)){
//		int fen = ret(str);
//		if (fen >= 90)
//			cout << "VERY_SECURE";
//		else if (fen >= 80)
//			cout << "SECURE";
//		else if (fen >= 70)
//			cout << "VERY_STRONG";
//		else if (fen >= 60)
//			cout << "STRONG";
//		else if (fen >= 50)
//			cout << "AVERAGE";
//		else if (fen >= 25)
//			cout << "WEAK";
//		else
//			cout << "VERY_WEAK";
//		str.clear();
//	}
//	return 0;
//}
//int main(){
//	//int i = 0;
//	//for (; i < 10;++i)
//	//	printf("%c\n", 0x21+i);
//	main1();
//	//testMap();
//	//test();
//
//	system("pause");
//	return 0;
//}