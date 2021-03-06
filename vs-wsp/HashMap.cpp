// HashMap.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
//#include <hash_map>  
#include <hash_map>  
#include <map>
#include <string>

using namespace std;
using namespace stdext;
//首先写一个仿函数CharLess，继承自仿函数基类binary_function
struct CharLess : public binary_function<const char*, const char*, bool>
{
public:
	result_type operator()(const first_argument_type& _Left, const second_argument_type& _Right) const
	{
		return(strcmp(_Left, _Right) < 0 ? true : false);
	}
};

struct str_hash {
	size_t operator()(const string& str) const
	{
		unsigned long __h = 0;
		for (size_t i = 0; i < str.size(); i++)
			__h = 5 * __h + str[i];
		return size_t(__h);
	}
};
struct compare_str {
	bool operator()(const char* p1, const char*p2) const {
		return strcmp(p1, p2) == 0;
	}
};
struct mystruct {
	int iID;
	int  len;
	bool operator==(const mystruct & my) const {
		return (iID == my.iID) && (len == my.len);
	}
};
//如果你希望利用系统定义的字符串hash函数，你可以这样写：
/*
struct str_hash2 {
size_t operator()(const string& str) const
{
return __stl_hash_string(str.c_str());
}
};	
*/

void test();
void test2();
void test3();
void test4();
int main()
{
	//test();
	//test2();
	test4();
	cout << "\n 按任意键继续……";
	cin.clear();
	cin.sync();
	cin.get();
    return 0;
}

void test() {
	hash_map<int, int> IntHash;
	IntHash[1] = 123;
	IntHash[2] = 456;
	int val1 = IntHash[1];
	cout << val1 << endl;
	int val2 = IntHash[2];
	cout << val2 << endl;
}

void test2() {
	hash_map<const char*, int> CharHash;
	CharHash["a"] = 123;
	CharHash["b"] = 456;
	char szInput[64] = "a";
	int val = CharHash[szInput];
	cout << val << endl;
}

void test3() {
	hash_map<const char*, int, hash_compare<const char*, CharLess> > CharHash;
	CharHash["a"] = 123;
	CharHash["b"] = 456;
	char szInput[64] = "a";
	int val = CharHash[szInput];
	cout << val << endl;
}

void test4() {
	map<string, string> namemap;
	//增加。。。
	namemap["岳不群"] = "华山派掌门人，人称君子剑";
	namemap["张三丰"] = "武当掌门人，太极拳创始人";
	namemap["东方不败"] = "第一高手，葵花宝典";
	//查找。。
	if (namemap.find("岳不群") != namemap.end()) {
		cout << "find element from map!" << endl;
	}
}

void test5() {
	hash_map<int, string> mymap;
	mymap[9527] = "唐伯虎点秋香";
	mymap[1000000] = "百万富翁的生活";
	mymap[10000] = "白领的工资底线";
	//查找。。
	if (mymap.find(10000) != mymap.end()) {
		cout << "find element from map!" << endl;
	}
}

void test6() {
	typedef hash_map<const char*, string, hash<const char*>, compare_str> StrIntMap;
	StrIntMap namemap;
	namemap["岳不群"] = "华山派掌门人，人称君子剑";
	namemap["张三丰"] = "武当掌门人，太极拳创始人";
	namemap["东方不败"] = "第一高手，葵花宝典";
}