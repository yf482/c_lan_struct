// vector.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void test();
void printVec(vector<int> vec);
void test2();
typedef struct rect
{
	int id;
	int length;
	int width;

	//对于向量元素是结构体的，可在结构体内部定义比较函数，下面按照id,length,width升序排序。
	bool operator< (const rect &a)  const
	{
		if (id != a.id)
			return id<a.id;
		else
		{
			if (length != a.length)
				return length<a.length;
			else
				return width<a.width;
		}
	}
}Rect;
/*	  
c.assign(beg, end)：将[beg; end)区间中的数据赋值给c。
c.assign(n, elem)：将n个elem的拷贝赋值给c。
c.at(idx)：传回索引idx所指的数据，如果idx越界，抛出out_of_range。
c.back()：传回最后一个数据，不检查这个数据是否存在。
c.front()：传回地一个数据。
get_allocator：使用构造函数返回一个拷贝。
c.rbegin()：传回一个逆向队列的第一个数据。
c.rend()：传回一个逆向队列的最后一个数据的下一个位置。
c.~vector <Elem>()：销毁所有数据，释放内存。
*/
int main()
{
	test();
	test2();
	cout << "\n 按任意键继续……";
	cin.clear();
	cin.sync();
	cin.get();
    return 0;
}

void test() {
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(14);
	cout << vec[1] << endl;
	printVec(vec);
	vec.insert(vec.begin() + 1, 10);
	printVec(vec);
	vec.erase(vec.begin() + 2);
	printVec(vec);
	vec.erase(vec.begin(), vec.begin() + 2);
	printVec(vec);
	int size = vec.size();
	cout << "size:" << size << endl;
	int capacity = vec.capacity();
	cout << "capacity:" << capacity << endl;
	reverse(vec.begin(), vec.end());
	printVec(vec);
	//默认是按升序排列, 即从小到大).
	sort(vec.begin(), vec.end()); 
	printVec(vec);
	vec.clear();

}

void printVec(vector<int> vec) {
	cout << "vector : " << endl;
	vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++) {
		cout << *it << "\t";
	}
	cout << endl;
}


void test2()
{
	vector<Rect> vec;
	Rect rect;
	rect.id = 1;
	rect.length = 2;
	rect.width = 3;
	vec.push_back(rect);
	vector<Rect>::iterator it = vec.begin();
	cout << (*it).id << ' ' << (*it).length << ' ' << (*it).width << endl;
}

