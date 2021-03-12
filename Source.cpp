#include <iostream> //1 лаба на треугольники
#include <math.h>
#include <cmath>

using namespace std;

/* 0;3 
  -2;-3
  -6;1 */

int main() {

	setlocale(LC_ALL, "Rus");

	const float eps = 1.0e-5;

	float x1, y1, x2, y2, x3, y3;

	float height, space, half_perimetr;

	int max, min, average;

	cout << endl << endl << endl;

	cout << "Введите координаты:" << endl;

	cout << "Первые координаты" << endl;
	cin >> x1 >> y1;

	cout << "Вторые координаты"<< endl;
	cin>> x2 >> y2;

	cout << "Третьи координаты" << endl;
	cin>> x3>> y3;

	float a, b, c;

	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));

	if (a > b) {
		float tmp = a;
		a = b;
		b = tmp;
	}

	if (a > c) {
		float tmp = a;
		a = c;
		c = tmp;
	}

	if (b > c) {
		float tmp = b;
		b = c;
		c = tmp;
	}

	if (a + b > c) {
		cout << "\t"<<"Треугольник можно построить" << endl;

	    cout << "\t"<<"Стороны треугольника в порядке убываяния: "<< c << " " << b << " " << a << " " << endl;

	    half_perimetr = (a + b + c) / 2; //Значение полупериметра

	    float cos_c; //Значение косинуса

	    cos_c = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a*b);

		if (cos_c < -eps) { //проверять только на тупогуольность
			cout << "\t" << "Треугольник тупогольный" << endl;

			if (a == b) {
				cout << "\t" << "Треугольник равнобедренный" << endl;
				space = sqrt(half_perimetr*(half_perimetr - a)*(half_perimetr - b)*(half_perimetr - c));
				height = (2 * space) / a;

				    cout << "\t" << "Площадь,высота,наибольшая сторона в порядке убывания равны: ";

				    if (height < space) {
					    float tmp = space;
					    space = height;
					    height = tmp;
				    }

				    if (height < c) {
					    float tmp = c;
					    c = height;
					    height = tmp;
				    }

				    if (space < c) {
					    float tmp = c;
					    c = space;
					    space = tmp;
				    }


				    cout << endl << endl;
				    cout << "Площадь,высота,наибольшая сторона в порядке убывания равны: \n" << height << " " << space << " " << c << endl;

			     }  else cout << "\t" << "Треугольник не равнобедренный" << endl;

		}  else cout <<"\t"<<"Треугольник не тупоугольный" << endl;

	}  else  cout <<"\t"<<"ТРЕУГОЛЬНИК ПОСТРОИТЬ НЕЛЬЗЯ!" << endl;


	cin.ignore();
	cin.get();
	return 0;
}
