#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");

		int countgiven;

		do {		
				cout << "Введите 1 для суммы заданного числа слогаемых" << endl;
				cout << "Введите 2 для суммы с заданной точностью" << endl;
				cout << "Введите 3 для завершения работы" << endl;

		bool error;

			do {
				cout << "-> ";
				cin >> countgiven;

				if (countgiven < 1 || countgiven >3)
				{
					cout << "Введите значение от 1 до 3" << endl;
					error = true;
				}
				else
				{
					error = false;
				}

			} while (error);

			if (countgiven != 3) {

				cout << "Введите значение аргумента x:" << endl;
				float x;
				cin >> x;
				cout << endl;
				cout << endl;

				if (countgiven == 1) {

					cout << "Введите количество слогаемых n:" << endl;
					int n;
					cin >> n;
					double a = 1;
					double result = 0;

					for (int i = 0; i < n; i++)
					{
						result = result + a;
						a *= -x*x / ((2 * i + 1) * (2 * i + 2));
					}

					cout << setw(25) << left << "Приближенное значение" << setprecision(20) << result << endl;
					cout << setw(25) << left << "Точное значение" << setprecision(20) << cos(x) << endl;
				}
				else
				{
						double e;
						cout << "Введите точность e:" << endl;
						cin >> e;
						cout << endl;

						double a = 1;
						double result = 0;
						int i = 0;
						for (int j = 0; j < 2; j++)
						{
							while (fabs(a) > e)
							{
									result += a;
								a *= -x*x / ((2 * i + 1) * (2 * i + 2));
								i++;
							}
							cout << "Точность E= " << e << endl;
							cout << setw(25) << left << "Приближенное значение" << setprecision(20) << result << endl;
							cout << setw(25) << left << "Точное значение" << setprecision(20) << cos(x) << endl;
							cout << "Количество слогаемых: " << i << endl;
							e /= 10;
						}
				}

				cout << "Завершить работу? (Y/N)" << endl;
				char exit;
				cin >> exit;
				if (exit == 'Y' || exit == 'y')
				{
					countgiven = 3;
				}
			}

	} while (countgiven != 3);

	return 0;
}
