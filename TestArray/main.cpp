//Попов Владимир 8091
#include <iostream>
#include "stack.h"

int charToInt(char c) {
	switch (c)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	default: return 10;
	}
}

int main()
{
	int sum=0;
	Stack *st;
	st = stack_create();
	int i=0;
	char exp[100];
	std::cin >> exp;
	int len = strlen(exp);
	//std::cout << len;
	len--;
	int s = 0;
	int dec = 1;
	while (len >= 0) {
		if (charToInt(exp[len]) == 10)
		{
			switch (exp[len])
			{
			case '+': {
				stack_push(st, i);
				i = 0;
				dec = 1;
				if (s == 1) {
					int tmp = stack_get(st);
					stack_pop(st);
					tmp *= stack_get(st);
					stack_pop(st);
					stack_push(st, tmp);
					s = 0;
				}
				if (s == 2) {
					int tmp = stack_get(st);
					stack_pop(st);
					int tmp2 = stack_get(st);
					stack_pop(st);
					stack_push(st, tmp / tmp2);
					s = 0;
				}
				break;

			case '-': {
				int temp = -i;
				stack_push(st, temp);
				i = 0;
				dec = 1;
				if (s == 1) {
					int tmp = stack_get(st);
					stack_pop(st);
					tmp *= stack_get(st);
					stack_pop(st);
					int temp = tmp;
					stack_push(st, temp);
					s = 0;
				}
				if (s == 2) {
					int tmp = stack_get(st);
					stack_pop(st);
					int tmp2 = stack_get(st);
					stack_pop(st);
					int temp = (tmp / tmp2);
					stack_push(st, temp);
					s = 0;
				}
				break;
			}
			case '*': {
				stack_push(st, i);
				i = 0;
				dec = 1;
				if (s == 1) {
					int tmp = stack_get(st);
					stack_pop(st);
					tmp *= stack_get(st);
					stack_pop(st);
					stack_push(st, tmp);
					s = 0;
				}
				if (s == 2) {
					int tmp = stack_get(st);
					stack_pop(st);
					int tmp2 = stack_get(st);
					stack_pop(st);
					stack_push(st, tmp / tmp2);
					s = 0;
				}
				s = 1;
				break;
			}
			case '/': {
				stack_push(st, i);
				i = 0;
				dec = 1;
				if (s == 1) {
					int tmp = stack_get(st);
					stack_pop(st);
					tmp *= stack_get(st);
					stack_pop(st);
					stack_push(st, tmp);
					s = 0;
				}
				if (s == 2) {
					int tmp = stack_get(st);
					stack_pop(st);
					int tmp2 = stack_get(st);
					stack_pop(st);
					stack_push(st, tmp / tmp2);
					s = 0;
				}
				s = 2;
				break;
			}
			}
			}
			len--;
			continue;
		}
		i += (charToInt(exp[len])*dec);
		dec *= 10;
		if (len == 0) {
			stack_push(st, i);
			if (s == 1) {
				int tmp = stack_get(st);
				stack_pop(st);
				tmp *= stack_get(st);
				stack_pop(st);
				stack_push(st, tmp);
				s = 0;
			}
			if (s == 2) {
				int tmp = stack_get(st);
				stack_pop(st);
				int tmp2 = stack_get(st);
				stack_pop(st);
				stack_push(st, tmp / tmp2);
				s = 0;
			}
		}
		len--;
	}
	while (!stack_empty(st))
	{
		sum += stack_get(st);
		stack_pop(st);
		//std::cout << sum << std::endl;
	}
	std::cout << sum;
	stack_delete(st);
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
