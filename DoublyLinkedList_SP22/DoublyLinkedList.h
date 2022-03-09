#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template<class T>
struct Node
{
	Node* prev;
	T info;
	Node* next;
};

template<class T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void Insert(T info_);
	void Delete(T info_);
	bool Find(T info_);
	T GetNextItem();
	T GetPrevItem();
	void EmptyList();
	bool IsEmpty();
	bool IsFull();

private:
	Node* head;
	Node* loc;
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = nullptr;
	loc = nullptr;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	EmptyList();
}

template<class T>
inline void DoublyLinkedList<T>::Insert(T info_)
{
	if (!IsFull())
	{
		Node* temp = new Node<T>;

		temp->info = info_;
		temp->prev = nullptr;

		if (IsEmpty())
		{
			temp->next = nullptr;
			loc = head;
		}
		else
		{
			temp->next = head;
			head->prev = temp;
		}

		head = temp;
	}
}

template<class T>
inline void DoublyLinkedList<T>::Delete(T info_)
{
	if (!IsEmpty())
	{
		while (loc->info != nullptr)
		{
			if (loc->info == info_)
			{
				loc->prev->next = loc->next;
				loc->next->prev = loc->prev;

				delete loc;

				loc = head;
				break;
			}

			loc = loc->next;
		}
	}
}

template<class T>
inline bool DoublyLinkedList<T>::Find(T info_)
{
	return false;
}

template<class T>
inline T DoublyLinkedList<T>::GetNextItem()
{
	if (loc == nullptr)
	{
		loc = head;
	}
	else if (loc->next != nullptr)
	{
		loc = loc->next;
	}

	return loc->info;
}

template<class T>
inline T DoublyLinkedList<T>::GetPrevItem()
{
	return T();
}

template<class T>
inline void DoublyLinkedList<T>::EmptyList()
{
}

template<class T>
inline bool DoublyLinkedList<T>::IsEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

template<class T>
inline bool DoublyLinkedList<T>::IsFull()
{
	try
	{
		Node* temp = new Node;
	}
	catch
	{
		return true;
	}

	delete temp;

	return false;
}

#endif
