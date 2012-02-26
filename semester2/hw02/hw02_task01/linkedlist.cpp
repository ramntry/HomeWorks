#include "linkedlist.h"

LinkedList::LinkedList() : mLength(0)
{
}

void LinkedList::insert(int position, ListItem item)
{
    if (position > mLength)
        throw ListOutOfBoundsException();

    mLength++;
}

void LinkedList::remove(int position)
{
    if (position >= mLength)
        throw ListOutOfBoundsException();

    mLength--;
}

int LinkedList::find(ListItem item)
{
    return itemNotFound;
}

int LinkedList::length()
{
    return mLength;
}

ListItem & LinkedList::operator [](int position)
{
    throw ListOutOfBoundsException();
}

LinkedList::~LinkedList()
{
}
