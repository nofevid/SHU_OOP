#ifndef _H_MYVECTOR
#define _H_MYVECTOR

#include<iostream>
#include<iomanip>
#include<cmath>
#include<stdio.h>
using namespace std;

template<typename T>
class myvector
{
public:
	myvector();
	myvector(int len, T element=0);
	virtual ~myvector();
	myvector(const myvector<T>& c);
	myvector<T>& operator=(const myvector<T>& c);
	T& operator[](int index);
	template<typename T2> friend ostream& operator<<(ostream& out,const myvector<T2>& c);
	void print()const;
	void print(int a)const;
	int size()const;
	int capacity()const;
	void resize(int newsize, T element=0);
	void reverse(int newcapacity);
	void push_back(T element);
	T& pop_back();
	T& back()const;
	T& begin()const;

private:
	int _size;
	int _capacity;
	T *head;

	void capacity_up();
};
template<typename T> myvector<T>::myvector() :_capacity(16), _size(0)
{
	head = new T[_capacity];
};
template<typename T> myvector<T>::myvector(int len, T element) :_capacity(16)
{
	_size = len;
	_capacity += len;
	head = new T[_capacity];
	for (int i = 0; i < _size; i++)
	{
		*(head+i) = element;
	}
};
template<typename T> myvector<T>::~myvector()
{
	delete[] head;
};
template<typename T> myvector<T>::myvector(const myvector<T>& c)
{
	_capacity = c._capacity;
	_size = c._size;
	head = new T[_capacity];
	for (int i = 0; i <_size; i++)
	{
		*(head + i) = *(c.head + i);
	}
};
template<typename T> myvector<T>& myvector<T>::operator=(const myvector<T>& c)
{
	if (this == &c) return *this;
	if (nullptr!=head)
	{
		delete[] head;
		head = nullptr;
	}
	_size = c._size;
	_capacity = c._capacity;
	head = new T[_capacity];
	for (int i = 0; i < _size; i++)
	{
		*(head + i) = *(c.head + i);
	}
	return *this;
}
template<typename T> T& myvector<T>::operator[](int index)
{
    return head[index];
}
template<typename T2> ostream& operator<<(ostream& out, const myvector<T2>& c)
{
	for (int i = 0; i < c._size; i++)
	{
		out << c.head[i];
	}
	return out;
}

template<typename T> void myvector<T>::print()const
{
	for (int i = 0; i < _size; i++)
	{
		cout << *(head + i);
	}
}
template<typename T> void myvector<T>::print(int i)const
{
	cout << *(head + i);
}

template<typename T> void myvector<T>::capacity_up()
{
	int newcapacity = 2 * _capacity+1;
	T* newhead = new T[newcapacity];
	for (int i = 0; i < _size; i++)
	{
		*(newhead + i) = *(head + i);
	}
	delete[] head;
	head = newhead;
	_capacity = newcapacity;
}

template<typename T> int myvector<T>::size()const
{
	return _size;
}
template<typename T> int myvector<T>::capacity()const
{
	return _capacity;
}
template<typename T> void myvector<T>::resize(int newsize, T element)
{
	if (newsize<=0)
	{
		cout << "ERROR!" << endl;
	}
	else if (newsize<_size)
	{
		for (int i = newsize; i <_size; i++)
		{
			*(head + i) = '\0';
		}
		_size = newsize;
	}
	else if(newsize>=_size)
	{
		while (newsize > _capacity)
		{
			this->capacity_up();
		}
		for (int i = _size; i < newsize; i++)
		{
			*(head + i) = element;
		}
		_size = newsize;
	}
}
template<typename T> void myvector<T>::reverse(int newcapacity)
{
//	int foo_capacity = _size;
	if (newcapacity < _size)
	{
		cout << "THE NEWCAPACITY IS TOO SMALL!" << endl;
	}
	else
	{
		T* newhead = new T[newcapacity];
		for (int i = 0; i < _size; i++)
		{
			*(newhead + i) = *(head + i);
		}
		delete[] head;
		head = newhead;
		_capacity = newcapacity;
	}
}
template<typename T> void myvector<T>::push_back(T element)
{
	if (head==nullptr)
	{
		_capacity = 16;
		_size = 0;
		head = new T[_capacity];
	}
	if (_size==_capacity)
	{
		this->capacity_up();
	}
	head[_size++] = element;
}
template<typename T> T& myvector<T>::pop_back()
{
	if (head == nullptr)
	{
		_capacity = 16;
		_size = 0;
		head = new T[_capacity];
	}

		T temp = head[_size - 1];
		head[_size - 1] = '\0';
		_size--;
		return temp;
}
template<typename T> T& myvector<T>::back()const
{
	return head[_size - 1];
}
template<typename T> T& myvector<T>::begin()const
{
	return head[0];
}
#endif // !_H_VECTOR
