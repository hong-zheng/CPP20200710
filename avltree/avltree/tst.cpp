
#define _CRT_SECURE_NO_WARNGINS 1
#include <iostream>
#include <string>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

class solution{
public:
	int pr1 = 0;
	int pr2 = 0;
	bool is = true;
	int dst = 0;
	bool isprimer(){
		for (int i = 2; i<pr1 / 2; ++i){
			if (pr1%i == 0){
				is = false; break;
			}

		}
		if (is){
			for (int i = 2; i<pr2 / 2; ++i){
				if (pr2%i == 0){
					is = false; break;
				}

			}
		}
		return this->is;
	}
};
int mainasad(){
	int even;
	cin >> even;
	int len = even / 2;
  	vector<solution> ret;
	for (int i = 1; i < len; ++i){
		solution tmp;
		tmp.pr1 = i;
		tmp.pr2 = even - i;
		if (tmp.isprimer()){
			tmp.dst = tmp.pr2 - tmp.pr1;;
			ret.reserve(1);
			ret.push_back(tmp);
		}
	}
	int min = ret[0].dst;
	int minindx = 0;
	len = ret.size();
	for (int i = 1; i<len; i++){
		if (ret[i].dst < min){
			min = ret[i].dst;
			minindx = i;
		}
	}
	cout << ret[minindx].pr1 << endl;
	cout << ret[minindx].pr2 << endl;
	system("pause");
	return 0;
}
