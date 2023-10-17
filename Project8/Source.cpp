#include<iostream>
#include<Windows.h>
#include<iomanip>
using std::cin;
using std::cout;
using std::left;
using std::setw;
using std::fixed;
using std::pow;
using std::endl;
using std::setprecision;


int main()
{
	SetConsoleOutputCP(1251);
	short choice;
	bool isError;
	do
	{
		cout << "Меню" << endl;
		cout << "1. Сумма заданного количества слагаемых" << endl;
		cout << "2. Сумма с заданной точностью" << endl;
		cout << "3. Завершение работы" << endl;
		isError = false;
		do
		{
			isError = false;
			cout << "->";

			if (!(cin >> choice && choice >= 1 && choice <= 3))
			{
				cout << "Значение должно быть в диапазоне от 1 до 3." << endl;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				isError = true;
			}
		} while (isError);
		if (choice != 3)
		{
			double x;
			do
			{
				isError = true;

				cout << "Введите x (|x|<1): ";
				if (cin >> x && abs(x) < 1)
					isError = false;
				else
				{
					cout << "Ошибка! x должен удовлетворять условию |x| < 1!" << endl;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
				}
			} while (isError);
			cout << setw(28) << left << "Точное значение" << " = " << fixed << setprecision(11) << 1 / (1+x) << endl;
			if (choice == 1)
			{
				int n;
				cout << "Введите количество слагаемых: ";
				cin >> n;
				double a = 1, sum = 0;
				for (int i = 0; i < n; ++i)
				{
					sum += a;
					a *= (-x);
				}
				cout << setw(22) << left << "Приближенное значение" << " = " << fixed << setprecision(11) << sum << endl;
			}
			else
			{
				double eps;
				cout << "Введите точность вычисления: ";
				cin >> eps;
				int n = 0;
				double a = 1, sum = 0;
				for (int i = 0; i < 2; ++i)
				{
					while (abs(a) > eps)
					{
						sum += a;
						a *= (-x);
						n += 1;
					}
					cout << setw(22) << left << "Приближенное значение" << " = " << fixed << setprecision(11) << sum << endl;
					cout << "Слагаемых потребовалось = " << n << endl;
					eps /= 10.;
				}
			}
			cout << "Завершить работу? (Y(y) - завершить/любая другая клавиша - продолжить работу): ";
			char isExit;
			cin >> isExit;
			if (isExit == 'Y' || isExit == 'y')
				choice = 3;
		}
	} while (choice != 3);
	return 0;
}
