#include <iostream>


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
	/*
	* returning begin iterator
	*
	* @return begin iterator.
	*/
	Iterator begin()
	{
		return Iterator(head);
	}
	/*
	* returning end iterator
	*
	* @return end iterator.
	*/
	Iterator end()
	{
		return Iterator(tail->next_elem);
	}
	/*
	* getting elem data via index
	*
	* @param index elem index.
	* @return elem data.
	*/
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
	/*
	* getting elem data via pointer
	*
	* @param pointer node pointer.
	* @return elem data.
	*/
	static T& getElemDataViaPointer(Node<T>* pointer)
	{
		return pointer->data;
	}
	/*
	* overloading [] operator
	*
	* @param index elem index.
	* @return elem data link.
	*/
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
		/*
		* overloading ++ operator
		*
		* @return iterator link.
		*/
		Iterator& operator++()
		{
			pointer = pointer->next_elem;
			return *this;
		}
		/*
		* overloading * operator
		*
		* @return data link.
		*/
		T& operator*()
		{
			return  getElemDataViaPointer(pointer);
		}
		/*
		* overloading != operator
		*
		* @param it iterator link. 
		* @return flag of completing.
		*/
		bool operator!=(Iterator& it)
		{
			return it.pointer != pointer;
		}
	};

};
