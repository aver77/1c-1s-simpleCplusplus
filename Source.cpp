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
		cout << endl << "������� ����� ������: 1 ��� 2" << endl;
		cout << "������� 3 ��� ���������� ���������" << endl;
		cout << "->";
		cin >> number;
		
		int n;
		if (number != 3) 
		{
			cout << "�� ���������� ���������" << endl;
			cin >> n;
		}

			int chosendigit = NULL;
			bool error;	
			if (number != 3) {
				do
				{
					cout << "������ �������� ������������������:" << endl;
					cout << "������� 1 ��� ����� ������ � ����������" << endl;
					cout << "������� 2 ��� ��������� ������ ���� �������" << endl;
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
					cout << "������� �������� �� A �� B" << endl;
					cin >> A >> B;
					count = 0;
					if (chosendigit == 1) cout << "������� " << n << " ��������� � ���������� ���������� ����� ������" << endl;
					if (chosendigit == 2) cout << "������������������ ��������� �����: " << endl;
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
					cout << endl << "���������� ����� � ���������=" << count << endl;
			}
			else if (number == 2) 
			{
				int firstdigit;
				bool check = true;
				if (chosendigit == 1) 
				{
					cout << "������� " << n << " ��������� � ���������� ���������� ����� ������" << endl;
					cin >> digit;
				}
				if (chosendigit == 2)
				{
					cout << "������������������ ��������� �����: " << endl;
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
					cout << endl << "������������������ ���������������" << endl;
				}
				else 
				{
					cout << endl << "������������������ �� ���������������" << endl;
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