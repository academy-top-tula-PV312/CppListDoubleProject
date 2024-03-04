#include <iostream>

template <typename T>
struct Node
{
    T value;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};

template <typename T>
struct List
{
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;
};

template <typename T>
void ListAddHead(List<T>& list, T value);

template <typename T>
void ListAddTail(List<T>& list, T value);

template <typename T>
void ListInsert(List<T>& list, int index, T value);

template <typename T>
T ListRemoveHead(List<T>& list);


template <typename T>
T ListGetItem(List<T> list, int index);

template <typename T>
void ListPrint(List<T> list);

int main()
{
    List<int> list;
    ListAddTail(list, 100);
    ListAddTail(list, 200);
    ListAddTail(list, 300);
    ListAddTail(list, 400);
    ListAddTail(list, 500);
    ListAddTail(list, 600);
    ListAddTail(list, 700);
    ListAddTail(list, 800);
    
    ListPrint(list);

    ListAddHead(list, 900);

    ListPrint(list);

    ListInsert(list, 3, 1000);

    ListPrint(list);

    std::cout << ListGetItem(list, 7) << "\n";
}

template<typename T>
void ListAddHead(List<T>& list, T value)
{
    Node<T>* nodeNew = new Node<T>;
    nodeNew->value = value;

    if (!list.size)
    {
        list.head = nodeNew;
        list.tail = nodeNew;
    }
    else
    {
        nodeNew->next = list.head;
        list.head->prev = nodeNew;
        list.head = nodeNew;
    }
    list.size++;
}

template<typename T>
void ListAddTail(List<T>& list, T value)
{
    Node<T>* nodeNew = new Node<T>;
    nodeNew->value = value;

    if (!list.size)
    {
        list.head = nodeNew;
        list.tail = nodeNew;
    }
    else
    {
        nodeNew->prev = list.tail;
        list.tail->next = nodeNew;
        list.tail = nodeNew;
    }
    list.size++;
}

template<typename T>
void ListInsert(List<T>& list, int index, T value)
{
    if (index <= 0)
    {
        ListAddHead(list, value);
        return;
    }

    if (index >= list.size)
    {
        ListAddTail(list, value);
        return;
    }

    Node<T>* nodeCurrent;
    
    if (index <= list.size / 2)
    {
        nodeCurrent = list.head;
        for (int i{}; i < index - 1; i++)
            nodeCurrent = nodeCurrent->next;
    }
    else
    {
        nodeCurrent = list.tail;
        for (int i{}; i < list.size - index; i++)
            nodeCurrent = nodeCurrent->prev;
    }

    Node<T>* nodeNew = new Node<T>;
    nodeNew->value = value;

    nodeCurrent->next->prev = nodeNew;
    nodeNew->next = nodeCurrent->next;

    nodeCurrent->next = nodeNew;
    nodeNew->prev = nodeCurrent;

    list.size++;
}


template<typename T>
T ListRemoveHead(List<T>& list)
{
    T value = list.head->value;

    if (list.size > 1)
    {
        list.head = list.head->next;
        delete list.head->prev;
        list.head->prev = nullptr;
    }
    else
    {
        delete list.head;
        list.head = nullptr;
        list.tail = nullptr;
    }

    size--;

    return value;
}


template<typename T>
T ListGetItem(List<T> list, int index)
{
    Node<T>* nodeCurrent;

    if (index <= list.size / 2)
    {
        nodeCurrent = list.head;
        for (int i{}; i < index; i++)
            nodeCurrent = nodeCurrent->next;
    }
    else
    {
        nodeCurrent = list.tail;
        for (int i{}; i < list.size - index - 1; i++)
            nodeCurrent = nodeCurrent->prev;
    }
    return nodeCurrent->value;
}

template<typename T>
void ListPrint(List<T> list)
{
    Node<T>* nodeCurrent{ list.head };
    while (nodeCurrent)
    {
        std::cout << nodeCurrent->value << "\n";
        nodeCurrent = nodeCurrent->next;
    }
    std::cout << "\n";
}
