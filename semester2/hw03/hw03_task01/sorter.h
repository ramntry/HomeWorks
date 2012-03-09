#pragma once
#include "comparator.h"

template <typename E>
void swap(E &a, E &b)
{
    E c(a);
    a = b;
    b = c;
}

template <typename T, typename C = StandartComparator<T> >
class Sorter
{
public:
    Sorter()
        : mComparator(new C())
    {}
    ~Sorter() { delete mComparator; }
    virtual void sort(T* data, size_t size) = 0;
    C comparator() { return *mComparator; }

private:
    C *mComparator;
};

//Test derive:
template <typename T, typename C = StandartComparator<T> >
class BubbleSorter : public Sorter<T, C>
{
public:
    void sort(T* data, size_t size)
    {
        for (int i = size - 1; i > 1; --i)
            for (int j = 0; j < i; j++)
                if (Sorter<T, C>::comparator()(data[j], data[j + 1]) > 0)
                    swap(data[j], data[j + 1]);
    }
};
