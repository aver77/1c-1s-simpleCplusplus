#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));

	int number;
	do {
		cout << endl << "Введите номер задачи: 1 или 2" << endl;
		cout << "Введите 3 для завершения программы" << endl;
		cout << "->";
		cin >> number;
		
		int n;
		if (number != 3) 
		{
			cout << "Вв количество элементов" << endl;
			cin >> n;
		}

			int chosendigit = NULL;
			bool error;	
			if (number != 3) {
				do
				{
					cout << "Способ создания последовательности:" << endl;
					cout << "Введите 1 для ввода послед с клавиатуры" << endl;
					cout << "Введите 2 для генерации послед случ образом" << endl;
					cout << "->";
					cin >> chosendigit;

					if (chosendigit < 1 || chosendigit > 2)
					{
						error = true;
					}
					else
					{
						error = false;
					}

				} while (number != 3 && error == true);
			}

			int A, B, count, digit;
			if (number == 1)
			{
					cout << "Введите диапазон от A до B" << endl;
					cin >> A >> B;
					count = 0;
					if (chosendigit == 1) cout << "Вводите " << n << " элементов с клавиатуры поочередно через пробел" << endl;
					if (chosendigit == 2) cout << "Последовательность случайных чисел: " << endl;
					for (int i = 1; i <= n; i++)
					{
						switch (chosendigit)
						{
						case 1:
							cin >> digit;
							cout << digit << " ";
							break;
						case 2:
							digit = rand() % 20 - 10;
							cout << digit << " ";
							break;
						}
						if (digit >= A && digit <= B) 
						{
							count++;
						}
					}
					cout << endl << "Количество чисел в диапазоне=" << count << endl;
			}
			else if (number == 2) 
			{
				int firstdigit;
				bool check = true;
				if (chosendigit == 1) 
				{
					cout << "Вводите " << n << " элементов с клавиатуры поочередно через пробел" << endl;
					cin >> digit;
				}
				if (chosendigit == 2)
				{
					cout << "Последовательность случайных чисел: " << endl;
					digit = rand() % 20 - 10;
				}

				int i = 1;
				if (i > n-1) { cout << digit; }

				while ((i <= n - 1) && (check)) 
				{
					switch (chosendigit)
					{
						firstdigit = digit;
						case 1:
						{
							firstdigit = digit;
							cin >> digit;
							if (i == 1) cout << firstdigit << " "; cout << digit << " ";

							if (firstdigit*digit < 0)
							{
								i++;
							}
							else check = false;
							break;
						}
						case 2:
						{
							firstdigit = digit;
							digit = rand() % 20 - 10;
							if (i == 1) cout << firstdigit << " "; cout << digit << " ";

							if (firstdigit*digit < 0)
							{
								i++;
							}
							else check = false;
							break;
						}
					}
				} cout << endl;

				if (check == true)
				{
					cout << endl << "Последовательность знакочередуется" << endl;
				}
				else 
				{
					cout << endl << "Последовательность не знакочередуется" << endl;
				}
			}

			if (number!= 3) 
			{
				cin.ignore(255);
			}

	} while (number != 3);

	system("pause");

	return 0;
}