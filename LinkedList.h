#pragma once
#include <iostream>
#include <cassert>

template <typename T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void display();
	void addItem(T item);
	void deleteItem(T item);
	inline int getNumberOfItems();
	const T operator[](int index);


	//... and other methods
private:
	//nested class definition of LLNode
	template<typename S>
	class LLNode
	{
	public:
		LLNode(const S data, LLNode* next);
		~LLNode();
		S getData() const;
		LLNode* getNext() const;
		void setNext(LLNode<S>* next);
		inline int getLength();

	private:
		S data;
		LLNode<S>* next;
	};

	//LLNode needs to be another template class
	LLNode<T>* head;  // root node
};

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr)
{

}

template<typename T>
LinkedList<T>::~LinkedList()
{
	delete head;
		
}


template<typename T>
void LinkedList<T>::display()
{
	LLNode<T>* current = head;
	while (current)
	{
		std::cout << current->getData() << "=>";
		current = current->getNext();
	}
}
// add item to the tail
template<typename T>
void LinkedList<T>::addItem(T item)
{
	LLNode<T>* newLLNode = new LLNode<T>(item, nullptr);
	if (head==nullptr)
	{
		head = newLLNode;
	}
	else
	{
		LLNode<T>* current = head;
		while (current->getNext())
			current = current->getNext();

		current->setNext(newLLNode);
	}

}

// delete specific item from the list
template<typename T>
void LinkedList<T>::deleteItem(T item)
{
	assert(head != nullptr);

	LLNode<T>* current = head;


	if (head->getData() == item)
	{
		head = head->getNext();
		current->setNext(nullptr);
		delete current;
	}
	else 
	{
		LLNode<T>* previous = current;

		while (current->getNext() && current->getData() != item)
		{
			previous = current;
			current = current->getNext();
		}

		if (current)
		{
			previous->setNext(current->getNext());
			current->setNext(nullptr);
			delete current;
		}
	}
	
	
}

template<typename T>
int LinkedList<T>::getNumberOfItems()
{
	return (head ? head->getLength() : 0);

}


template<typename T>
const T LinkedList<T>::operator[](int index)
{
	assert(index >= 0 && head != nullptr);

	LLNode<T>* current = head;

	while (current != nullptr)
	{
		if (index == 0)
			return current->getData();
		else
			--index;
	}
}


template<typename T>
template<typename S>
LinkedList<T>::LLNode<S>::LLNode(const S data, LinkedList<T>::LLNode<S>* next) : data(data), next(next)
{
}


template<typename T>
template<typename S>
LinkedList<T>::LLNode<S>::~LLNode()
{
	delete next;
}

template<typename T>
template<typename S>
S LinkedList<T>::LLNode<S>::getData() const
{
	return data;
}

template<typename T>
template<typename S>
LinkedList<T>::LLNode<S>* LinkedList<T>::LLNode<S>::getNext() const
{
	return next;
}


template<typename T>
template<typename S>
void LinkedList<T>::LLNode<S>::setNext(LLNode<S>* next) 
{
	this->next=next;
}

template<typename T>
template<typename S>
inline int LinkedList<T>::LLNode<S>::getLength()
{
	return (next ? 1 + next->getLength() : 1);
}






