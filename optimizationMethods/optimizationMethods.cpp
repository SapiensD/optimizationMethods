#include <iostream>
#include <conio.h>
using namespace std;

// Инициализация переменных
double a = -3, b = 7;	// section
double eps = 0.5;		// fault
double delta = 0.2;

// Меню
void clearConsole() { system("cls"); }
void mainMenu();
void singleMethodsMenu();
void nMethodsMenu();

// Одномерная оптимизация
void halfDivision(double, double, double);
void uniformSearch(double, double, double);
void dichotomy(double, double, double);
void goldenRation(double, double, double);
void fibonaci(double, double, double, double);

// Многомерная безусловная оптимизация
//

// Условная оптимизация
//

double f(double x) { return 2 * x * x + 2 * x + 3.5; } // My Function to single methods
void showFunc() {
	cout << "1 : f(x) = 2x^2 +2x + 3.5" << endl
		<< "[" << a << "; " << b << "]" << endl
		<< "Eps = " << eps << endl << endl;
}	   // красивый вывод исходной функции
void out(double a, double b) { cout << endl << "x* = " << (a + b) / 2 << " +- " << (b - a) / 2 << endl; }


// Menu functions
void nMethodsMenu() {
	bool flag = true;
	cout << endl << "Меню выбора многомерных методов : " << endl;
	cout << " " << endl;
	cout << "0 - вернуться в главное меню" << endl << endl;
	while (flag) {
		if (_kbhit())
		{
			switch (_getch())
			{
			case '1':
				break;
			case '0':
				mainMenu();
				break;
			}
			flag = false;
		}
	}

}
void singleMethodsMenu() {
	cout << endl << "Меню выбора одномерных методов: " << endl;
	cout << "1 - Равномерный поиск" << endl;
	cout << "2 - Половинное деление" << endl;
	cout << "3 - Дихотомия" << endl;
	cout << "4 - Золотое сечение" << endl;
	cout << "5 - Фибоначчи" << endl;
	cout << "0 - вернуться в главное меню" << endl << endl;
	cout << "C - Очистка консоли" << endl;
	bool flag = true;
	while (flag) {
		if (_kbhit())
		{
			switch (_getch())
			{
			case '1':
				uniformSearch(a, b, eps);
				break;
			case '2':
				halfDivision(a, b, eps);
				break;
			case '3':
				dichotomy(a, b, eps);
				break;
			case '4':
				goldenRation(a, b, eps);
				break;
			case '5':
				fibonaci(a, b, eps, delta);
				break;
			case '0':
				flag = false;
				mainMenu();
				break;
			case 'c':
				clearConsole();
				break;
			}
			flag = false;
			singleMethodsMenu();
		}
	}
}
void mainMenu() {
	bool flag = true;
	clearConsole();
	cout << endl << "Главное меню : " << endl;
	cout << "Выберите какие методы необходимо использовать : " << endl << endl;
	cout << "1 - Одномерной оптимизации" << endl;
	cout << "2 - Многомерной безусловной оптимизации" << endl;
	cout << "3 - Условной оптимизации" << endl;
	cout << "0 - Выйти из приложения" << endl;
	cout << "C - Очистка консоли" << endl;
	while (flag) {
		if (_kbhit())
		{
			switch (_getch())
			{
			case '1':
				singleMethodsMenu();
				break;
			case '2':
				nMethodsMenu();
				break;
			case '0':
				break;
			case 'c':
				mainMenu();
				break;
			}
			flag = false;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	mainMenu();
}

// Одномерная оптимизация
void uniformSearch(double a, double b, double eps) {
	showFunc();
	cout << "1 - Неоьходимо определить кол-во итераций, для этого вычислим число N по формуле : N = (b-a)/Eps-1 с округлением в большую сторону";
	int N = ceil((b - a) / eps - 1);
	cout << " N = " << N << endl;
	double Xi = 0;
	double minXi = 0;
	double minI = 0;
	double minFXi = f(a);
	cout << "2 - Необходимо на каждом шаге в каждой вычисленной точке вычислить значение функции и найти min(F) из вычисленных" << endl;
	for (int i = 1; i < N + 1; i++) {
		Xi = a + i * (b - a) / (N + 1);
		cout << "X" << i << " = " << Xi << " f(x) = " << f(Xi) << endl;
		if (minFXi > f(Xi)) {
			minXi = Xi;
			minFXi = f(Xi);
			minI = i;
		}
	}
	cout << "3 - Находим минимальное значение функции : " << minXi << " f(x) = " << minFXi << endl;
	cout << "k = " << N << " | ";
	out(a + (minI - 1) * (b - a) / (N + 1), a + (minI + 1) * (b - a) / (N + 1));
}
void halfDivision(double a, double b, double eps) {
	showFunc();
	// Инициализация переменных
	double Xmd = (a + b) / 2;
	double Yk = 0, Zk = 0;
	double L2k = abs(b - a);
	int k = -1;
	double fXmd = f(Xmd);
	double fYk = 0;
	double fZk = 0;
	//double fYk = 0, fZk = 0;
	// Метод
	do {
		k++;
		cout << endl << "k = " << k << endl;
		Yk = a + (L2k / 4);
		Zk = b - (L2k / 4);
		fYk = f(Yk);
		fZk = f(Zk);
		cout << "Yk = " << Yk << endl << "Zk = " << Zk << endl;
		if (fYk < fXmd) {
			cout << "f(Yk) < f(Xmd) in step 7" << endl;
			b = Xmd;
			Xmd = Yk;
			fXmd = fYk;

		}
		else {
			cout << "f(Yk) >= f(Xmd) in step 6" << endl;
			if (fZk < fXmd) {
				cout << "f(Zk) < f(Xmd) in step 7" << endl;
				a = Xmd;
				Xmd = Zk;
				fXmd = fZk;
			}
			else {
				cout << "f(Zk) >= f(Xmd) in step 7" << endl;
				a = Yk;
				b = Zk;
			}
		}
		L2k = abs(b - a);
		cout << "L2k = " << L2k << endl;
		if (L2k > eps) cout << "L2k > eps => продолжаем итерации, возвращая на шаг 5" << endl;
	} while (L2k > eps);
	cout << "L2k < eps => мы нашли промежуток с заданной точностью : (" << a << "; " << b << ")" << endl;
	cout << "k = " << k << " | ";
	out(a, b);
}
void dichotomy(double a, double b, double eps) {
	double Yk = 0, Zk = 0;
	double L2k = 0;
	double fYk = 0, fZk = 0;
	int k = -1;
	showFunc();
	cout << "2 : ";
	do {
		k++;
		cout << endl << "k = " << k << endl;
		Yk = (a + b - delta) / 2;
		Zk = (a + b + delta) / 2;
		fYk = f(Yk); fZk = f(Zk);
		cout << "3 : Вычисляем т. Yk, Zk и значения функции f(Yk) и f(Zk) :" << endl;
		cout << "Yk = (a + b - eps) / 2 = " << Yk << endl << "Zk = (a + b + eps) / 2 = " << Zk << endl;
		cout << "f(Yk) = " << fYk << endl << "f(Zk) = " << fZk << endl;
		cout << endl << "4 : Сравниваем f(Yk) и f(Zk)" << endl;
		if (fYk <= fZk) {
			cout << "fYk <= fZk		=>	b = Zk" << endl;
			b = Zk;
		}
		else {
			cout << "fYk > fZk		=>	a = Yk" << endl;
			a = Yk;
		}
		cout << "[" << a << "; " << b << "]" << endl;
		L2k = abs(b - a);
		cout << "L2k = " << L2k << endl;
		if (L2k > 2 * eps) cout << "L2k > 2*eps	=> идём к шагу 3 и счиатем k = k+1" << endl;
	} while (L2k > 2 * eps);
	cout << "k = " << k << " | ";
	out(a, b);

}
void goldenRation(double a, double b, double eps) {
	int k = -1;
	double L2k = 0;
	double gold = (3 - sqrt(5)) / 2;
	double Yk = a + gold * (b - a),
		Zk = a + b - Yk;
	double fYk = f(Yk), fZk = f(Zk);
	showFunc();
	cout << "2 : k = 0" << endl;
	cout << "3 : Вычисляем y0 = a0 + (3 - sqrt(5))/2 * (b0-a0) " << endl;
	cout << "Y0 = " << Yk << " Z0 = " << Zk << endl;
	cout << "4 : Вычислим f(Yk) f(Zk) :: " << "f(Yk) = " << f(Yk) << "; f(Zk) = " << f(Zk) << endl;
	do {
		k++;
		cout << endl << "5 : Сравниваем f(Yk) и f(Zk) : " << endl;
		if (fYk <= fZk) {
			cout << "fYk <= fZk		=> b = Zk " << endl << "Z|k+1 = Yk" << endl
				<< "Y|k+1  = a|k+1 + b|k+1 -Z|k";
			b = Zk;
			Zk = Yk;
			fZk = fYk;
			Yk = a + b - Yk;
			cout << "Yk = " << Yk << endl;
			fYk = f(Yk);

		}
		else {
			a = Yk;
			cout << "fYk <= fZk		=> Yk = Zk" << endl;
			Yk = Zk;
			fYk = fZk;
			Zk = a + b - Zk;
			fZk = f(Zk);
		}
		L2k = abs(b - a); // Дельта
		if (L2k > eps) cout << "Delta > eps	=> возвращаемся к шагу 4 и считаем, что k = k+1" << endl;
	} while (L2k > eps);
	cout << "k = " << k << " | ";
	out(a, b);
}
void fibonaci(double a, double b, double eps, double delta) {
	// определение числа N и вычисление чисел Фибоначчи
	double temp = abs(b - a) / (2 * eps);
	double Fnl = 1; // Fn last
	double Fn = 1;
	int N = 1;
	showFunc();
	// определяем кол-во чисел Фибоначчи
	double fibNums[100];
	fibNums[0] = 1; fibNums[1] = 1;
	int i = 2;
	while (Fn < temp) {
		double t = Fn;
		Fn += Fnl;
		fibNums[i] = Fn;
		Fnl = t;
		N++; i++;
	}
	cout << "Вычислили N = " << N << "; по формуле Fn < |b-a|/(2*Eps), где Fn - n число Фибоначчи" << endl;
	int k = -1;
	double Yk = a + fibNums[N - 2] / fibNums[N] * (b - a);
	double Zk = a + fibNums[N - 1] / fibNums[N] * (b - a);
	double fYk = f(Yk), fZk = f(Zk);
	do {
		k++;
		if (fYk <= fZk) {
			b = Zk;
			Zk = Yk;
			fZk = fYk;
			Yk = a + fibNums[N - k - 3] / fibNums[N - k - 1] * (b - a);
			fYk = f(Yk);
		}
		else {
			a = Yk;
			Yk = Zk;
			fYk = fZk;
			Zk = a + fibNums[N - k - 2] / fibNums[N - k - 1] * (b - a);
			fZk = f(Zk);
		}
	} while (k != N - 3);
	Yk = (a - b) / 2;
	Zk = Yk + eps;
	fYk = f(Yk);
	fZk = f(Zk);
	if (fYk <= fZk)
		b = Zk;
	else
		a = Yk;
	cout << "k = " << k << " | ";
	out(a, b);
}

// Многомерная безусловная оптимизация
void fastestDescent(double a, double b, double eps, double delta) {

}

// Условная оптимизация