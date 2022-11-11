#include <iostream>
#include <ostream>


template <typename T>
class Node
{
public:
	T data;
	Node<T>* previous_elem;
	Node<T>* next_elem;
	Node(T data);
};


template <typename T>
class DoubleLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int length;
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	bool push_front(T data);
	bool push_back(T data);
	void pop_front();
	void pop_back();
	T getFrontElem();
	T getBackElem();
	int getLength();
	bool checkEmptyListOrNo();
	class Iterator;
	Iterator begin()
	{
		return Iterator(head);
	}

	Iterator end()
	{
		return Iterator(tail->next_elem);
	}

	T getElemData(int index)
	{
		Node<T>* pointer = head;
		int n = 0;
		while (n != index)
		{
			if (pointer == nullptr)
				return NULL;
			pointer = pointer->next_elem;
			++n;
		}
		return pointer->data;
	}

	static T& getElemDataViaPointer(Node<T>* pointer)
	{
		return pointer->data;
	}

	T& operator[](int index)
	{
		return getElemData(index);
	}

	class Iterator
	{
	private:
		Node<T>* pointer;
	
	public:
		Iterator(Node<T>* pointer) : pointer(pointer) {}
		Iterator& operator++()
		{
			pointer = pointer->next_elem;
			return *this;
		}

		T& operator*()
		{
			return  getElemDataViaPointer(pointer);
		}

		bool operator!=(Iterator& it)
		{
			return it.pointer != pointer;
		}
	};

};
