#include "iostream"
#include "string"
#include "math.h"
using namespace std;

class t4k {
public:
	double x, y;
	string name;
	void ne_constructor() {
		cout << "Имя точки: ";
		cin >> name;
		cout << "Координата по оси абсцисс: ";
		cin >> x;
		cout << "Координата по оси ординат: ";
		cin >> y;
		cout << endl;
	}
	void out() {
		cout << name << "(" << x << "," << y << ");" << endl;
	}
};


class triangle {
public:
	string name;
	t4k a, b, c;
	double P, S;
	triangle() {
		cout << "Имя треугольника: ";
		cin >> name;
		cout << endl;
		a.ne_constructor();
		b.ne_constructor();
		c.ne_constructor();
		P = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) + sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y)) + sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y));
		S = sqrt((P / 2) * ((P / 2) - sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))) * ((P / 2) - sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y))) * ((P / 2) - sqrt((b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y))));
	}
	void out() {
		cout << name << ":\n";
		a.out();
		b.out();
		c.out();
		cout << "Периметр треугольнка равен " << P << endl;
		cout << "Площадь треугольнка равна " << S << endl;
		cout << endl;
	}
};

void qsort(triangle* mas, int size) {
	int i = 0;
	int j = size - 1;
	double mid = mas[size / 2].P;
	do {
		while (mas[i].P < mid) {
			i++;
		}
		while (mas[j].P > mid) {
			j--;
		}
		if (i <= j) {
			triangle t = mas[i];
			mas[i] = mas[j];
			mas[j] = t;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		qsort(mas, j + 1);
	}
	if (i < size) {
		qsort(&mas[i], size - i);
	}
}

int main()
{
	setlocale(0, "");

	int N;
	cout << "Сколько будет треугольников: ";
	cin >> N;
	cout << endl;
	triangle* mas = new triangle[N];
	qsort(mas, N);
	for (int i = 0; i < N; i++) {
		mas[i].out();
	}

	delete[] mas;
	cout << "\n\n\n";
	return 0;
}

