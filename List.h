/*
����
*/
#pragma once
#pragma comment(lib,"ws2_32.lib")
struct Node_double;
struct Node_char;
template<typename T, typename B>
class List
{
	T* first;  //��һ��Nodeָ��Ԫ��
	T* end;   //β��������Nodeָ��Ԫ��
	unsigned int sum;
public:
	List();
	~List();
	List(List&);
	void Push_first(B);
	B Seek(unsigned int);
	void Insert(unsigned int, B);
	void Delete(unsigned int);
};
extern List<Node_double, double> p;