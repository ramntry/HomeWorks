#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include "comparator.h"
#include "sorter.h"

using namespace std;

void comparatorsTest()
{
    cout << "(5, 2):\t\t\t"                          << StandartComparator<int>()(5, 2) << endl;
    cout << "<string>(\"hi\", \"hi\"):\t\t"          << StandartComparator<string>()("hi", "hi") << endl;
    cout << "<const char*>(\"hello\", \"world\"):\t" << StandartComparator<const char*>()("hello", "world") << endl;

    const int comparatorsLength = 3;
    StandartComparator<double> *comparators[comparatorsLength];
    comparators[0] = new StandartComparator<double>;
    comparators[2] = new StandartComparator<double>(0.001);
    comparators[1] = new StandartComparator<double>(0.01);

    for (int i = 0; i < comparatorsLength; i++)
        cout << "(" << comparators[i]->eps() << ")"
             << "(2./3., 2.01/3.):\t" << (*comparators[i])(2./3., 2.01/3.) << endl;

    for (int i = 0; i < comparatorsLength; i++)
        delete comparators[i];
}

void bubbleSortTest(double *a)
{
    int size = 10;
    int mod = 10;
    double eps = 2.0;

    cout << "BubbleSort Test:\nBefore:\t\t";
    for (int i = 0; i < size; i++)
        cout << (a[i] = random() % mod + 1.0/mod * (random() % mod)) << "  ";
    cout << endl;

    Sorter<double> *sorter = new BubbleSorter<double>();
    sorter->comparator().setEps(eps);
// ERROR [FIXED]: "В строке выше поле epsilon компаратора вроде бы меняется, если верить отладчику. Но в строке ниже
//        оно уже имеет значение по умолчанию. Мне совершенно не ясно, в чем же дело."
// SOLUTION: Нужно было возвращать компаратор из метода по ссылке, а не значению - копирующий конструктор, имея
//           значение epsilon по умолчанию, переписывал его.
    sorter->sort(a, size);

    cout << "After (eps = " << sorter->comparator().eps() << "):\t";
    for (int i = 0; i < size; i++)
        cout << a[i] << "  ";
    cout << endl;

    delete sorter;
}

void sortersTest()
{
    srand(time(0));
    double *a = new double[10];

    bubbleSortTest(a);

    delete[] a;
}

int main()
{
    cout << "Testing of comparators:\n" << endl;
    comparatorsTest();

    cout << "\n\nTesting of sorters:\n" << endl;
    sortersTest();

    return 0;
}
