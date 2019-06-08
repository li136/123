/*
具体实现
*/
#include<iostream>
#include"List.h"
using namespace std;
/*************************************
方便起见，Node不做模板实现
**************************************/
struct Node_double
{
	double Data;
	Node_double* head;
	Node_double* next;
};
struct Node_char
{
	char Data;
	Node_char* head;
	Node_char* next;
};
/*-----------------------
以下为模板List实现
------------------------*/
List<Node_double, double> p;
template<typename T, typename B>
List<typename T, typename B>::List()
{
	first = NULL;
	sum = 0;
	end = NULL;
}
template<typename T, typename B>
List<typename T, typename B>::~List()
{
	if (first != NULL)
	{
		auto p = first;
		if (p->next == NULL)
			delete p;
		else
		{
			while (p->next!=NULL)
			{
				p = p->next;
				delete p->head;
			}
			delete p;
		}
	}
}
template<typename T, typename B>
List<typename T, typename B>::List(List& a)
{
	first = NULL;
	end = NULL;
	//接下来依次add，建立新的链
	auto x=a.Seek(sum);
	for (auto p = a.sum; p != 0; --p)
	{
		this->Push_first(x->Data);
		x = x->head;
	}
}
template<typename T, typename B>
void List<typename T, typename B>::Push_first(B b)
{
	T* p = new T;
	p->Data = b; p->head = NULL; p->next = first;
	first->head = p; first = p;
	++sum;
}
template<typename T, typename B>
void List<typename T, typename B>::Insert(unsigned int a,B b)
{
	if (a == 0)
	{
		throw("error input");//抛出异常
	}
	else if (a == 1)
		this->Push_first(b);
	else
	{
		auto x = first;
		for (; a != 2; --a)
		{
			x = x->next;
		}
		T* p=new T;
		x->next = p; p->Data = b; p->head = x; p->next = x->next;
		x->next->head = p;
	}
	++sum;
}
template<typename T, typename B>
B List<typename T, typename B>::Seek(unsigned int a)
{
	if (a == 0)
	{
		throw("error input");//抛出异常
	}
	auto p = first;
	if (a == 1 && p == NULL)
		throw("Meaningless value");
	else
		for (; a != 1; --a)
		{
			p = p->next;
			if (p == NULL)
				throw("Meaningless value");
		}
	return p->Data;
}
template<typename T, typename B>
void List<typename T, typename B>::Delete(unsigned int a)
{
	auto p = first;
	for (; a != 1; --a)
	{
		p = p->next;
	}
	p->head->next = p->next;
	p->next->head = p->head;
	delete p;
	--sum;
}