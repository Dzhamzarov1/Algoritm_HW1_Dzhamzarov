/*2.3  Даны два массива неубывающих целых чисел, упорядоченные по возрастанию. A[0..n-1] и B[0..m-1]. n >> m. Найдите их пересечение.
Требования: Время работы: O(m * log k), где k - позиция элемента B[m-1] в массиве A.. В процессе поиска очередного элемента B[i] в массиве A пользуйтесь результатом поиска элемента B[i-1]. Внимание! В этой задаче для каждого B[i] сначала нужно определить диапазон для бинарного поиска размером порядка k с помощью экспоненциального поиска, а потом уже в нем делать бинарный поиск.



Джамзаров Дамир
*/
#include <iostream>
using namespace std;

void input(int *array, int size) {
    for(int i=0;i<size;i++) {
        cin >> array[i];
    }
}


int binary_search(int *array, int interval1, int interval2, int n) {
    int first = interval1;
    int last = interval2;
    while (first < last) {
        int mid = (first + last) / 2;
        if(array[mid] < n) 
            first = mid + 1;
        else 
            last = mid;
    }
        return (first == interval2 || array[first] != n) ? -1: first;
    
}


int exp_search(int *array, int interval1, int interval2, int n) {
    // Если искомый элемент находится на индексе interval с которого начинается поиск, то возвращаем индекс 0.
    if(array[interval1] == n) return interval1;
    for(int i=1, j=i*2;i+interval1<interval2;i=i*2, j=j*2) {
        // Если правый интервал выходит за границу, то интервал равен границе
        if(interval1+j >= interval2) {
            return binary_search(array, i+interval1, interval2, n);
        }
        if(array[i+interval1]<=n && n<array[j+interval1])
            return binary_search(array, i+interval1, j+interval1, n);
    }
    return -1;
}

int vst(int *array1, int size1, int *array2, int size2) {
    int last = 0;
    for(int i=0;i<size2;i++) {
        last = exp_search(array1, last, size1, array2[i]);
        if(last != -1)
            cout << array1[last] << " ";
    }
    cout << endl;
    return 0;
}

void memory_use(int size1, int size2) {
	int *array1 = new int[size1];
    int *array2 = new int[size2];
    input(array1, size1);
    input(array2, size2);
    vst(array1, size1, array2, size2);
    delete [] array1;
    delete [] array2;
}

int main() {
    int size1, size2; 
    cin >> size1 >> size2;
   	memory_use(size1, size2);
    return 0;
}
