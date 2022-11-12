#include "Main_Header.h"

/*
 * class Node constructor 
 *
 * @param data data of list.
 */
template<typename T>
Node<T>::Node(T data)
{
	this->data = data;
	previous_elem = next_elem = nullptr;
}


/*
 * class DoubleLinkedList constructor
 *
 */
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
		head = tail = nullptr;
		length = 0;
}


/*
 * class DoubleLinkedList destructor
 *
 */
template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	while (head != nullptr)
		pop_front();
}


/*
 * pushing list node in front
 *
 * @param data data of list.
 * @return flag of completing.
 */
template<typename T>
bool DoubleLinkedList<T>::push_front(T data)
{
	try
	{
		Node<T>* pointer = new Node<T>(data);
		pointer->next_elem = head;
		if (head != nullptr)
			head->previous_elem = pointer;
		if (tail == nullptr)
			tail = pointer;
		head = pointer;
		++length;
		return 0;
	}
	catch (const std::exception&)
	{
			return 1;
	}
}


/*
 * pushing list node in back
 *
 * @param data data of list.
 * @return flag of completing.
 */
template<typename T>
bool DoubleLinkedList<T>::push_back(T data)
{
	try
	{
		Node<T>* pointer = new Node<T>(data);
		pointer->previous_elem = tail;
		if (tail != nullptr)
			tail->next_elem = pointer;
		if (head == nullptr)
			head = pointer;
		tail = pointer;
		++length;
		return 0;
	}
	catch (const std::exception&)
	{
		return 1;
	}
}


/*
 * deleting list node from front
 *
 */
template <typename T>
void DoubleLinkedList<T>::pop_front()
{
	if (head == nullptr)
		return;

	Node<T>* pointer = head->next_elem;

	if (pointer != nullptr)
		pointer->previous_elem = nullptr;
	else
		tail = nullptr;

	delete head;
	head = pointer;
	--length;
}


/*
 * deleting list node from back
 *
 */
template<typename T>
void DoubleLinkedList<T>::pop_back()
{
	if (tail == nullptr)
		return;

	Node<T>* pointer = tail->previous_elem;

	if (pointer != nullptr)
		pointer->next_elem = nullptr;
	else
		head = nullptr;

	delete tail;
	tail = pointer;
	--length;
}


/*
 * getting list node from front
 *
 * @return head node data.
 */
template<typename T>
T DoubleLinkedList<T>::getFrontElem()
{
	return head->data;
}


/*
 * getting list node from back
 *
 * @return tail node data.
 */
template<typename T>
T DoubleLinkedList<T>::getBackElem()
{
	return tail->data;
}


/*
 * getting list length
 *
 * @return list length.
 */
template<typename T>
int DoubleLinkedList<T>::getLength()
{
	return length;
}


/*
 * checking empty list or no
 *
 * @return flag of completing.
 */
template<typename T>
bool DoubleLinkedList<T>::checkEmptyListOrNo()
{
	if (head != nullptr || tail != nullptr)
		return 1; // not empty
	else
		return 0; // empty
}


/*
 * main function - checking all functions 
 *
 * @return flag of completing.
 */
int main(void)
{
	DoubleLinkedList<int> list, list_;
	list.push_back(1);
	list.push_back(2.3);
	list.push_back(3.3);
	list.push_back(9);
	list.push_front(45);
	list.pop_front();
	list.pop_back();

	std::cout << list.checkEmptyListOrNo() << " " << list_.checkEmptyListOrNo() << std::endl;
	std::cout << list.getLength() << std::endl;
	for (auto itter : list)
		std::cout << itter << " ";
		
	return 0;
}