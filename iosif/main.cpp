#include <iostream>
#include <ctime>
#include "array.h"
using namespace std;

int josephus(int N, int k)
{
    setlocale(LC_ALL, "Russian");
    Array arr(N);

    // заполняем контейнер числами от 1 до N
    for (int i = 1; i <= N; i++)
        arr.insert(i);

    int pos = 0; // текущая позиция

    // удаляем элементы, пока не останется один
    while (arr.getSize() > 1)
    {
        // вычисляем позицию удаляемого элемента
        pos = (pos + k - 1) % arr.getSize();
        arr.remove(pos);
    }

    return arr[0]; // возвращаем найденный элемент1
}

int main()
{
    int N, k;
    cout << "Введите N (количество элементов): ";
    cin >> N;
    cout << "Введите k (шаг удаления): ";
    cin >> k;

    // время выполнения
    clock_t start = clock();
    int result = josephus(N, k);
    clock_t end = clock();

    double time = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nПоследний оставшийся элемент: " << result << endl;
    cout << "Время расчета: " << time << " сек" << endl;

    return 0;
}