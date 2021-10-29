#include <map>
#include <iostream>

using namespace std;

int main()
{
	map<pair<char, int>, int> m = { {{'+', 0}, 1},
		{{'0', 1}, 2},{{'1', 1}, 3},{{'-', 1}, 6},
		{{'0', 2}, 2},{{'1', 2}, 3},{{'!', 2}, 5},{{'-', 2}, 6},
		{{'0', 3}, 2},{{'1', 3}, 3},{{'?', 3}, 4},{{'-', 3}, 6},
		{{'0', 4}, 2},{{'1', 4}, 3},{{'?', 4}, 4},{{'-', 4}, 6},
		{{'0', 5}, 2},{{'1', 5}, 3},{{'!', 5}, 5},{{'-', 5}, 6}}; // задание таблицы КА
	string str, str_stat=""; // str - строка для ввода, str_stat - проверяемая строка
	int status=0, test=0; // состояния
	cout << "Enter the string:" << endl;
	cin >> str;
	for (int j = 0; j < str.size(); j++) { // цикл для посимвольного прохода по введённой строке
		for (int i = j; i < str.size(); i++) { // вложенный цикл для проверки подходит ли строка нашему КА
			if (m.count({ str[i], status })) // переход в следующей состояние, если возможно
			{
				status = m[{ str[i], status }];
				str_stat += str[i];
			}
			else // подстрока не подходит
			{
				status = 0; 
				str_stat = "";
				break;
			}
			if (status == 6) // вывод подходящей подстроки
			{
				cout << i + 1 - str_stat.size() << " :  " << str_stat << endl;
				status = 0, str_stat = "";
				test++;
				break;
			}
		}
	}
	if (test == 0) // если нет подходящих подстрок
	{
		cout << "No matches" << endl;
	}
	return 0;
}


