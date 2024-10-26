/*1.2 Вернуть значение бита в числе N по его номеру K.
Формат входных данных. Число N, номер бита K

Джамзаров Дамир
*/
#include <iostream>
using namespace std;

int check_bit(unsigned int n, unsigned int k) {
	int result = (n & (1 << k));
    if (result == 0) return 0;
    return 1;
}

int main() {
    unsigned int inp1; 
    unsigned int inp2;
    cin >> inp1 >> inp2;
    cout << check_bit(inp1, inp2);
    return 0;
}