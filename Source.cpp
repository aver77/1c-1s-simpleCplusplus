#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");

		int countgiven;

		do {		
				cout << "������� 1 ��� ����� ��������� ����� ���������" << endl;
				cout << "������� 2 ��� ����� � �������� ���������" << endl;
				cout << "������� 3 ��� ���������� ������" << endl;

		bool error;

			do {
				cout << "-> ";
				cin >> countgiven;

				if (countgiven < 1 || countgiven >3)
				{
					cout << "������� �������� �� 1 �� 3" << endl;
					error = true;
				}
				else
				{
					error = false;
				}

			} while (error);

			if (countgiven != 3) {

				cout << "������� �������� ��������� x:" << endl;
				float x;
				cin >> x;
				cout << endl;
				cout << endl;

				if (countgiven == 1) {

					cout << "������� ���������� ��������� n:" << endl;
					int n;
					cin >> n;
					double a = 1;
					double result = 0;

					for (int i = 0; i < n; i++)
					{
						result = result + a;
						a *= -x*x / ((2 * i + 1) * (2 * i + 2));
					}

					cout << setw(25) << left << "������������ ��������" << setprecision(20) << result << endl;
					cout << setw(25) << left << "������ ��������" << setprecision(20) << cos(x) << endl;
				}
				else
				{
						double e;
						cout << "������� �������� e:" << endl;
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
							cout << "�������� E= " << e << endl;
							cout << setw(25) << left << "������������ ��������" << setprecision(20) << result << endl;
							cout << setw(25) << left << "������ ��������" << setprecision(20) << cos(x) << endl;
							cout << "���������� ���������: " << i << endl;
							e /= 10;
						}
				}

				cout << "��������� ������? (Y/N)" << endl;
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