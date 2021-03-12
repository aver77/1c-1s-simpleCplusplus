#include <iostream>
#include <ctime>
#include <cmath>
#include <math.h>

using namespace std;

void fillarray(float *arr, int n);
int countarray(float *arr, int n, int K);
//float sumarray(float *arr, int n);
bool summa(float *arr, int n, float &summa);
void sortarray(float *arr, int n);
void printarray(float *arr, int n);
void deletearray(float *arr, int n);

int main() 
{
	srand(time(NULL));
	setlocale(LC_ALL, "Ru");
	int number;
	do 
	{
		bool error;
		do
		{
			cout << "������� 1 ��� ���������� ���������� ��������� �������,� ������� " << endl << "������ ����� ������������ ����� ����� K" << endl << endl;
			cout << "������� 2 ��� ���������� ����� ��������� �������,������������� " << endl << "�� ������������ ��������" << endl << endl;
			cout << "������� 3 ��� �������������� ��������� ������� �� �������� ������� " << endl << "�������� ������� ������� �������" << endl << endl;
			cout << "������� 0 ��� ���������� ���������" << endl << endl;
			cout << "->";
			cin >> number;
			cout << endl;

			if (number >= 0 && number <= 3) 
				error = false;
			else 
				error = true;
		} while (error);
		if (number != 0) 
		{
			cout << "������� ���������� ��������� �������" << endl << endl;
			int n;
			cin >> n; cout << endl;
			float *arr = new float[n];
			fillarray(arr, n);
			if (number == 1)
			{
				cout << "������:" << endl << endl;
				printarray(arr, n); cout << endl << endl;
				cout << "������� ����� K" << endl << endl;
				int K;
				cin >> K; cout << endl;
				cout << "���������� ����� ��������� �������=" << countarray(arr, n, K) << endl << endl;
			}
			if (number == 2)
			{
				cout << "������:" << endl << endl;
				printarray(arr, n); cout << endl;
				float sum = 0;
				if (!summa(arr, n, sum)) { cout << endl; cout << "����������� ������� �� ������" << endl << endl; }
				else {
					cout << endl; cout << "����� ��-��,������������� �� ������������=" << sum << endl << endl;
				}
			}
			if (number == 3)
			{
				cout << "��������������� ������:" << endl << endl;
				printarray(arr, n);
				cout << endl << endl; cout << "������������� ������:" << endl << endl;
				sortarray(arr, n);
				printarray(arr, n); cout << endl << endl;
			}
			deletearray(arr, n);
		}
		number = 0;
	} while (number != 0);
	return 0;
}

void fillarray(float *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0.1*(rand() % 2000 - 1000) ;  
	}
}
int countarray(float *arr, int n, int K)
{
	int count = 0;
	int b, c;
	for (int i = 0; i < n; i++)
	{
		c = int(abs(arr[i])*10) % 10;
		if (c == K)
		{
			count += 1;
		}
	}
	return count;
}
/*float sumarray(float *arr, int n)
{
	int size = 0;
	float min = arr[1];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			size = i;
		}
	}

	float sum = 0;
	for (int j = 0; j < size - 1; j++)
	{
		sum = sum + arr[j];
	}

	return sum;
} */

bool summa(float *arr, int n, float &summa) 
{
	bool result;
	int size = 0;
	float min = arr[1];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			size = i;
		}
	}

	if (size == 0) 
	{
		result = false;
	}
	else 
	{
		float sum = 0;
		for (int j = 0; j < size - 1; j++)
		{
			sum = sum + arr[j];
		}
		return result;
	}
}

void sortarray(float *arr, int n)  // ���������� ������� ������� �������
{
	float tmp;
	for (int i = 1; i < n; i++)
	{
		if (abs(arr[i]) > abs(arr[i - 1]))
		{
			tmp = arr[i];
			int j;
			for (j = i - 1; j >= 0 && abs(arr[j]) < abs(tmp); j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = tmp;
		}
	}
}
void printarray(float *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " " << " ";
	}
}
void deletearray(float *arr, int n)
{
	delete[]arr;
}