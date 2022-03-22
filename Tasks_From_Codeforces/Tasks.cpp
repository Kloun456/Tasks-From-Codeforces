#include "Tasks.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

template <class X> void Filling_matrix_NULL(X **a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
}

template <class X> void Filling_matrix_rand(X** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand()%10;
		}
	}
}

template <class X> void Filling_Array(X *a , X n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

}

int Max_array(int *arr, const int &n, int &i1)
{
	int max;
	max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
		{
			i1 = i;
			max = arr[i];
		}
			
	}
	return max;
}

int Max(int x1, int x2, int x3)
{
	int max;
	max = x1;
	if (max < x2)
	{
		max = x2;
		if (max < x3)
			max = x3;
	}
	else if (max < x3)
	{
		max = x3;
	}
	return max;
}

void competition(const int &n)
{
	int n1 = 0, k;
	int* score = new int[n];
	cout << "Enter k: ";
	cin >> k;
	cout << "Enter scores:\n";
	Filling_Array(score, n);
	for (int i = 0; i < n; i++)
	{
		if (score[i] >= score[k-1])
			n1++;
	}
	cout << "Quantity participant: " << n1 << endl;

	delete[] score;
}

void Lock(int n)
{
	int s = 0;
	int* start = new int[n];
	int* secret = new int[n];
	cout << "Enter start position:\n";
	Filling_Array(start, n);
	cout << "Enter secret combination:\n";
	Filling_Array(secret, n);
	for (int i = 0; i < n; i++)
	{
		if (abs(secret[i] - start[i]) <= 5)
		{
			s += abs(secret[i] - start[i]);
		}
		else
		{
			s += 10 - abs(secret[i] - start[i]);
		}
	}
	cout << "\nResult: " << s << endl;

	delete[] start;
	delete[] secret;
}

void Azbuka_Borze(char* ch)
{
	int i = 0, k = 0, j;
	cout << "Enter combination:\n";
	while (i < 200)
	{
		ch[i] = getchar();
		if (ch[i] == '\n')
			break;
		i++;
	}
	// 0 передается как «.», 1 как «-.», 2 как «--»
	int* mass = new int[i] {0};
	cout << "\nResult:\n";
	for (j = 0, k = 0; k < i; k++, j++)
	{
		if (ch[j] == '.')
			mass[k] = 0;
		else if (ch[j] == '-')
		{
			if (ch[j + 1] == '.')
			{
				mass[k] = 1;
				j++;
			}
			else
			{
				mass[k] = 2;
				j++;
			}

		}
	}
	for (int j = 0; j < k - 2; j++)
		cout << mass[j];

	delete[] mass;
}

void Egor_Trenning(int n)
{
	int chest = 0, biceps = 0, back = 0;
	int* exercise = new int[n];
	cout << "Enter exercise:\n";
	for (int i = 1; i <= n; i++)
	{
		cin >> exercise[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 1)
		{
			chest += exercise[i] * n;
		}
		else if (i % 3 == 2)
		{
			biceps += exercise[i] * n;
		}
		else
		{
			back += exercise[i] * n;
		}
	}
	if (biceps > back && biceps > chest)
		cout << "\nBiceps";
	else if (back > biceps && back > chest)
		cout << "\nBack:";
	else
		cout << "\nChest";

	delete[] exercise;
}

void Crossword_of_Japan(const int& n)  // 18 min
{
	int n1 = 0, nc = 0, j = 0;
	char* symbol = new char[n];
	cout << "Enter symbol: ";
	for (int i = 0; i < n; i++)
		cin >> symbol[i];
	for (int i = 0; i < n; i++)
	{
		if (symbol[i] == 'B' && symbol[i + 1] != 'B')
		{
			n1++;
		}
	}
	int* q = new int[n1] {0};
	for (int i = 0; i < n; i++)
	{
		if (symbol[i] == 'B')
		{
			q[j] += 1;
		}
		else
			j++;
	}
	cout << "Quantity group: " << n1 << endl;
	for (int i = 0; i < n1; i++)
		cout << q[i] << "\t";

	delete[] symbol;
}

void Raven(const int& n)
{
	int* chisl = new int[n];
	int* otvet = new int[n] {0};
	cout << "Enter digits: ";
	for (int i = 0; i < n; i++)
		cin >> chisl[i];
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == n - 1)
			otvet[i] = chisl[i];
		else if (i % 2 == 0)
		{
			otvet[i] = chisl[i];
			for (int j = n - 1; j > i; j--)
			{
				if (j % 2 == 0)
					otvet[i] -= otvet[j];
				else
					otvet[i] += otvet[j];
			}
		}
		else
		{
			otvet[i] = chisl[i];
			for (int j = n - 1; j > i; j--)
			{
				if (j % 2 == 0)
					otvet[i] += otvet[j];
				else
					otvet[i] -= otvet[j];
			}
		}
	}
	cout << "Result: ";
	for (int i = 0; i < n; i++)
		cout << otvet[i] << "\t";

	delete[] chisl;
	delete[] otvet;
}

void Black_Jack(const int& n)
{
	int q = 0;
	int balls[13] = { 2,3,4,5,6,7,8,9,10,10,10,10,11 };
	for (int m = 0; m < 4; m++)
	{
		for (int i = 0; i < 13; i++)
		{
			if (10 + balls[i] == n)
			{
				q++;
			}
		}
	}
	if (n == 20)
		q--;
	cout << "Quantity variants: " << q << endl;
} // 12 min

void Taxi(const int& n)
{
	int q = 1, s = 0, s1 = 0, max = 0;
	bool b = true;
	int* group = new int[n];
	cout << "Enter group:\n";
	for (int i = 0; i < n; i++)
		cin >> group[i];

	for (int i = 0; i < n; i++)
	{
		s += group[i];
	}
	q = s % 4 + s / 4;
	cout << "\nQuantity: " << q << endl;

	delete[] group;
}

void Ahaha(const int& n)
{
	int n1, x, s = 0, j;
	for (int i = 0; i < n; i++)
	{
		cin >> n1;
		for (j = 1; j <= n1; j++)
		{
			cin >> x;
			s += x;
		}
		if (s > n1 - s)
		{
			n1 = s / 2 * 2;
			s = 1;
		}
		else
		{
			n1 = n1 - s;
			s = 0;
		}
		cout << "Result:\nn: " << n1 << endl;
		while (n1--)
			cout << s << "\t";
		cout << endl;
	}
}

void Squaresand_and_lines(const int& n) // 30 min
{
	if (n == 1)
		cout << "2";
	else if (n == 2)
		cout << "3";
	else
	{
		if (n % 2 == 0)
			cout << (n - 1) / 2 + 3;
		else
			cout << n / 2 + 3;
	}
}

void Dark_and_light() //  6 min
{
	int a, b, c;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	if ((c / a) * a + b == c || (c / b) * b + a == c || c % b == 0 || c % a == 0)
	{
		cout << "Yes";
	}
	else
		cout << "No";
}

void Rossetes() // 17 min
{
	int n, k, m, * filters, s = 0, q = 0, i1 = 0;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter m: ";
	cin >> m;
	cout << "Enter k: ";
	cin >> k;
	filters = new int[n];
	for (int i = 0; i < n; i++)
		cin >> filters[i];
	if (m == k)
	{
		cout << "-1";
	}
	else
	{
		s = m - k;
		for (int i = 0; i < n; i++)
		{
			if (s == filters[i] || s < filters[i])
			{
				q++;
				break;
			}

			else
			{
				s = s - Max_array(filters, n, i1);
				filters[i1] = 0;
				q++;
			}
		}
		cout << "Result: " << q;
	}
	delete[] filters;
}

void Vitaliy_and_pie(int n) // 30 min
{
	char* s;
	bool b;
	n = 2 * n - 2;
	s = new char[n];
	int q = 0;
	cout << "Enter string: ";
	cin >> s;
	for (int i = 0; i < n; i += 2)
	{
		b = true;
		for (int j = i + 1; j <= n; j += 2)
		{
			if ((int)s[i] == (int)s[j] + 32)
			{
				b = false;
				break;
			}
		}
		if (b)
			q++;
	}
	cout << "Quantity keys: " << q;

	delete[] s;
}

void Ilya_and_walk(const int& n) // 4 min
{
	int r = 0, * homes;
	homes = new int[n];
	for (int i = 0; i < n; i++)
		cin >> homes[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (homes[i] != homes[j] && j - i > r)
			{
				r = j - i;
			}
		}
	}
	cout << "Result: " << r;

	delete[] homes;
}

void Pigs_and_wolfs()
{
	int m, n, q = 0;
	char** matrix;
	cout << "Enter n and m: ";
	cin >> n >> m;
	matrix = new char* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new char[m];
	cout << "Enter field:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] == 'W')
			{
				if (j > 0 && matrix[i][j - 1] == 'P')
				{
					matrix[i][j - 1] = '.';
					q++;
				}
				else if (j < m && matrix[i][j + 1] == 'P')
				{
					matrix[i][j + 1] = '.';
					q++;
				}
				else if (i > 0 && matrix[i - 1][j] == 'P')
				{
					matrix[i - 1][j] = '.';
					q++;
				}
				else if (i == 0 && matrix[i + 1][j] == 'P')
				{
					matrix[i + 1][j] = '.';
					q++;
				}
			}
		}
	}
	cout << "Quantity pigs: " << q;

	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete matrix;
}

void Sweety_problem(const int& n) // 30 min
{
	int* days;
	days = new int[n] {0};
	cout << "Enter sweets:\n";
	for (int i = 0; i < n; i++)
	{
		int sweet[3];
		cin >> sweet[0] >> sweet[1] >> sweet[2];
		if (Max(sweet[0], sweet[1], sweet[2]) == sweet[0])
		{
			if (sweet[0] == sweet[1] || sweet[0] == sweet[2])
			{
				days[i] += sweet[0] + 1;
			}
			else if (sweet[1] > sweet[2])
			{
				sweet[0] -= sweet[1];
				days[i] = sweet[1];
				if (sweet[0] > sweet[2])
					days[i] += sweet[2];
				else
					days[i] += sweet[0];
			}
			else
			{
				sweet[0] -= sweet[2];
				days[i] = sweet[2];
				if (sweet[0] > sweet[1])
					days[i] += sweet[1];
				else
					days[i] += sweet[0];
			}
		}
		else if (Max(sweet[0], sweet[1], sweet[2]) == sweet[1])
		{
			if (sweet[1] == sweet[0] || sweet[1] == sweet[2])
			{
				days[i] += sweet[1] + 1;
			}
			else if (sweet[0] > sweet[2])
			{
				sweet[1] -= sweet[0];
				days[i] = sweet[0];
				if (sweet[1] > sweet[2])
					days[i] += sweet[2];
				else
					days[i] += sweet[1];
			}
			else
			{
				sweet[1] -= sweet[2];
				days[i] = sweet[2];
				if (sweet[1] > sweet[0])
					days[i] += sweet[0];
				else
					days[i] += sweet[2];
			}
		}
		else //2
		{
			if (sweet[2] == sweet[1] || sweet[2] == sweet[0])
			{
				days[i] += sweet[2] + 1;
			}
			else if (sweet[0] > sweet[1])
			{
				sweet[2] -= sweet[0];
				days[i] = sweet[0];
				if (sweet[2] > sweet[1])
					days[i] += sweet[1];
				else
					days[i] += sweet[2];
			}
			else
			{
				sweet[2] -= sweet[1];
				days[i] = sweet[1];
				if (sweet[2] > sweet[0])
					days[i] += sweet[0];
				else
					days[i] += sweet[2];
			}
		}
		cout << endl;
	}

	cout << "\nResult:\n";
	for (int i = 0; i < n; i++)
		cout << days[i] << endl;

	delete[] days;
}

void Number_on_desk(int n) // 20 min
{
	int k, s = 0, q = 0, n1 = 0;
	cout << "Enter k: ";
	cin >> k;
	while (n > 0)
	{
		s += n % 10;
		n1++;
		n /= 10;
	}
	if (s < k)
	{
		for (int i = 0; i < n1; i++)
		{
			if (s + 9 > k)
			{
				q += 1;
				break;
			}
			else
			{
				s += 9;
				q += 1;
			}
		}
		cout << "\nq = " << q << endl;
	}
	else
		cout << "\n0";
}

void Arrangement_chess(int n)
{
	int* desk = new int[n / 2];
	int* full_desk = new int[n];
	int n_even = 0, n1 = 0, pos = 0, n_odd = 0, glav = 0, i = 0, j = 1;
	cout << "Enter figures positions:\n";
	for (i = 1; i <= n / 2; i++)
		cin >> desk[i];
	cout << endl;
	if (desk[1] == 2)
		glav == desk[2];
	else
		glav = desk[1];

	for (i = 1, j = 1; i <= n; i++)
	{
		if (desk[j] == i)
		{
			full_desk[i] = 1;
			j++;
			if (i % 2 == 0)
			{
				if (glav == desk[j] - pos - 1)
				{
					pos++;
				}
				else if (glav < desk[j] && desk[j] == desk[j + 1] - 1 && glav != 1)
				{
					glav = desk[j];
				}
				n_even++;
			}
			else
			{
				if (glav == desk[j] - pos - 1)
				{
					pos++;
				}
				else if (glav < desk[j] && desk[j] == desk[j + 1] - 1 && glav != 1)
				{
					glav = desk[j];
				}
				n_odd++;
			}

		}
		else
			full_desk[i] = 0;
	}

	if (n_even == n / 2 || n_odd == n / 2)
	{
		cout << "Result: " << n1 << endl;
		exit(1);
	}
}

void Walk_under_rain(const int& n) // 30 min
{
	int* road = new int[n];
	int min, q = 0;
	bool b = true;
	cout << "Enter days:\n";
	for (int i = 0; i < n; i++)
		cin >> road[i];

	while (b)
	{
		min = 9999;
		for (int i = 0; i < n; i++)
		{
			if (road[i] > 0 && road[i] < min)
				min = road[i];
		}
		for (int i = 0; i < n; i++)
		{
			road[i] -= min;
		}
		q += min;
		for (int i = 2; i < n - 1; i += 2)
		{
			if (road[i] > 0 && road[0] > 0 && road[n - 1] > 0 || road[i - 1] > 0 && road[0] > 0 && road[n - 1] > 0)
			{
				b = true;
			}
			else
			{
				b = false;
			}
		}
		cout << "\nmin: " << min << endl;
	}
	cout << endl << q;

	delete[] road;
}

void Great_July_calendar(int n) // 10 min
{
	int max = 0, n1 = 0, temp;

	while (n > 0)
	{
		temp = n;
		max = n % 10;
		while (temp)
		{
			if (max < temp % 10)
			{
				max = temp % 10;
			}
			temp /= 10;
		}
		n -= max;
		n1++;
	}

	cout << n1;
}

void Vanya_and_lanterns(const int& n) // 15 min
{
	int l, min, j1, temp;
	int* lantern_positions = new int[n];
	float r = 0;
	cout << "Enter street length: ";
	cin >> l;
	cout << "\nEnter lantern positions:\n";
	for (int i = 0; i < n; i++)
		cin >> lantern_positions[i];
	for (int i = 0; i < n; i++)
	{
		min = lantern_positions[i];
		j1 = i;
		for (int j = i; j < n; j++)
		{
			if (min > lantern_positions[j])
			{
				min = lantern_positions[j];
				j1 = j;
			}
		}
		temp = lantern_positions[i];
		lantern_positions[i] = lantern_positions[j1];
		lantern_positions[j1] = temp;
	}
	if (lantern_positions[0] != 0)
		r = lantern_positions[0];
	else
		r = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if ((lantern_positions[i + 1] - lantern_positions[i]) / 2.0 > r)
		{
			r = (lantern_positions[i + 1] - lantern_positions[i]) / 2.0;
		}
	}
	cout << "Radius: " << r << endl;

	delete[] lantern_positions;
}

void Another_broken_keyboards(const int& n)
{
	int k, q = 0;
	bool b = false;
	string s;
	char* symbols;
	cout << "\nEnter k: ";
	cin >> k;
	symbols = new char[k];
	cout << "\nEnter string: ";
	cin >> s;
	cout << "\nEnter available symbols: ";
	cin >> symbols;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (s[i] == symbols[j])
			{
				b = true;
				q++;
				break;
			}
		}
		for (int j = i + 1; j < n; j++)
		{
			if (b)
			{
				for (int m = 0; m < k; m++)
				{
					if (s[j] == symbols[m])
					{
						q++;
						b = true;
						break;
					}
					else
					{
						b = false;
					}
				}
			}
		}
	}
	cout << q;

	delete[] symbols;
}

void Ternary_string(const int& n) // 30 min
{
	string s;
	int* q = new int[n] {0};
	bool b = false, c = false;
	int ib, ie = 0;
	cout << "Enter combination:\n";
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		q[i] = 9999;
		for (int j = 0; j < s.length(); j++)
		{
			ib = j;
			c = false;
			b = false;

			for (int k = j + 1; k < s.length(); k++)
			{
				if (s[j] == '1')
				{
					if (s[k] == '1')
						break;
					else if (s[k] == '2')
					{
						if (!c)
							b = true;
						else
						{
							b = true;
							ie = k;
							break;
						}
					}
					else
					{
						if (!b)
							c = true;
						else
						{
							c = true;
							ie = k;
							break;
						}
					}
				}
				else if (s[j] == '2')
				{
					if (s[k] == '2')
						break;
					else if (s[k] == '1')
					{
						if (!c)
							b = true;
						else
						{
							b = true;
							ie = k;
							break;
						}
					}
					else
					{
						if (!b)
							c = true;
						else
						{
							c = true;
							ie = k;
							break;
						}
					}
				}
				else
				{
					if (s[k] == '3')
						break;
					else if (s[k] == '2')
					{
						if (!c)
							b = true;
						else
						{
							b = true;
							ie = k;
							break;
						}
					}
					else
					{
						if (!b)
							c = true;
						else
						{
							c = true;
							ie = k;
							break;
						}
					}
				}
			}

			if (q[i] > ie - ib + 1 && c && b)
			{
				q[i] = ie - ib + 1;
			}
		}
		if (q[i] == 9999)
		{
			q[i] = 0;
		}
	}

	cout << endl;
	for (int i = 0; i < n; i++)
		cout << q[i] << "\t";

}

void Ball_in_BerlGU(const int& n) // 15 min
{
	int m, q = 0;
	int* boys = new int[n];
	bool b = true;
	cout << "Enter quantity girls: ";
	cin >> m;
	int* girls = new int[m];
	cout << "Enter skiils of boys:\n";
	for (int i = 0; i < n; i++)
	{
		cin >> boys[i];
	}
	cout << "Enter skiils of girls:\n";
	for (int i = 0; i < m; i++)
		cin >> girls[i];

	b = m > n ? true : false;

	if (b)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (abs(girls[i] - boys[j]) <= 1)
				{
					q++;
					boys[j] = -1;
					break;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (abs(boys[i] - girls[j]) <= 1)
				{
					q++;
					girls[j] = -1;
					break;
				}
			}
		}
	}
	cout << "Quantity: " << q;
}

void Almost_equal(const int& n)
{
	int* Numb = new int[2 * n];
	int s = 0;
	for (int i = 1; i <= 2 * n; i++)
		Numb[i] = i;

	for (int i = 1; i <= 2 * n; i++)
	{
	}

	for (int i = 1; i <= 2 * n; i++)
		cout << Numb[i];

	delete[] Numb;
}

void Checking_pants_for_dullness(const int& n) // 5 min
{
	int* Test = new int[n];
	int s = 0;
	cout << "Enter quantity questions:\n";
	for (int i = 0; i < n; i++)
		cin >> Test[i];

	for (int i = 0; i < n; i++)
	{
		if (Test[i] != 1 && i != n - 1)
			s += Test[i] + 1;
		else
			s += Test[i];
	}

	cout << "\nResult: " << s << endl;
}

void Pashmak_and_garden(const int& n) // 30 min
{
	int garden[4];
	int a = 0;
	float x1, y1, x2, y2;
	cout << "Enter coordinates:\n";
	for (int i = 0; i < 4; i++)
		cin >> garden[i];

	if (garden[0] == garden[2] || garden[1] == garden[3])
	{

		if (garden[0] == garden[2])
		{
			a = abs(garden[1] - garden[3]);
			garden[0] += a;
			garden[2] += a;
		}
		else
		{
			a = abs(garden[0] - garden[2]);
			garden[1] += a;
			garden[3] += a;
		}
	}
	else if (abs(garden[0] - garden[2]) == abs(garden[1] - garden[3]))
	{
		x1 = (garden[0] + garden[2]) / 2.0;
		y1 = (garden[1] + garden[3]) / 2.0;
		x2 = (garden[2] - garden[0]) / 2.0;
		y2 = (garden[3] - garden[1]) / 2.0;
		garden[0] = x1 + y2;
		garden[1] = y1 - x2;
		garden[2] = x1 - y2;
		garden[3] = y1 + x2;
	}
	else
	{
		cout << "-1" << endl;
		exit(1);
	}
	cout << "Result:\n";
	for (int i = 0; i < 4; i++)
		cout << garden[i] << "\t";
}

void Persian_carpet(int n)
{
	int temp = n, n1, k, q = 0, h;
	cout << "\nEnter k: ";
	cin >> k;
	cout << "\nEnter n1: ";
	cin >> n1;
	do
	{
		n -= n1;
		q++;
	} while (n1 <= n);
	h = n;
	n = 2 * n * temp - n * n;
	q *= q;
	while (n > 0)
	{
		n -= n1 * h;
		q++;
	}
	if (q <= k)
		cout << "Yes, quantity carpets: " << q << endl;
	else
		cout << "No" << endl;

}

void Happy_Birthday(const int& n)
{
	int* children = new int[n];
	int max, temp, q = 1;
	cout << "Enter children growth:\n";
	for (int i = 0; i < n; i++)
		cin >> children[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (children[i] > children[j])
			{
				temp = children[i];
				children[i] = children[j];
				children[j] = temp;
			}
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (children[i] == children[i - 1])
		{
			temp = children[i];
			children[i] = children[n - q];
			children[n - q] = temp;
			q++;
			cout << endl;
			for (int i = 0; i < n; i++)
				cout << "\t" << children[i];
		}
	}
	cout << "\nResult:\n";
	for (int i = 0; i < n; i++)
		cout << children[i];
}

void Before_exam(const int& n)
{
	int all, n1 = n;
	bool b = 1;
	int* result = new int[n];
	int** quantity_h = new int* [n];
	for (int i = 0; i < n; i++)
		quantity_h[i] = new int[2];
	cout << "Enter all hours: ";
	cin >> all;
	cout << "Enter quantity hours:\n";
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < 2; j++)
			cin >> quantity_h[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		n1--;
		if (n1 == 0)
		{
			if ((all - quantity_h[i][0]) <= 0 || (all - quantity_h[i][1]) <= 0)
			{
				result[i] = all;
				all = 0;
				break;
			}
		}
		else
		{
			if ((all - quantity_h[i][0]) / n1 <= quantity_h[i + 1][1] && quantity_h[i][0] != 0)
			{
				result[i] = quantity_h[i][0];
				all -= quantity_h[i][0];
			}
			else
			{
				if (quantity_h[i][0] < quantity_h[i][1])
				{
					quantity_h[i][0]++;
					for (quantity_h[i][0]; quantity_h[i][0] <= quantity_h[i][1]; quantity_h[i][0]++)
					{
						if ((all - quantity_h[i][0]) / n1 <= quantity_h[i + 1][1])
						{
							result[i] = quantity_h[i][0];
							all -= quantity_h[i][0];
							break;
						}
						if ((all - quantity_h[i][0]) / n1 > quantity_h[i + 1][1] && quantity_h[i][0] == quantity_h[i][1])
						{
							cout << "No";
							exit(1);
						}
					}
				}
				else
				{
					cout << "NO!";
					exit(1);
				}
			}
		}


	}

	if (!all)
	{
		cout << "\nYes!\n";
		for (int i = 0; i < n; i++)
			cout << result[i] << "\t";
	}
	else
	{
		cout << "\nNo!\n";
	}

}

void Gerb_antikubizmu(const int& n)
{
	int i1, max = -999999999, s = 0;
	int* length = new int[n];
	cout << "Enter length of kernel:\n";
	for (int i = 0; i < n; i++)
		cin >> length[i];
	for (int i = 0; i < n; i++)
	{
		if (max < length[i])
		{
			max = length[i];
			i1 = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i != i1)
			s += length[i];
	}
	cout << max - s + 1;

}

void Fishing(const int& n)
{
	int t, t1 = 0, N = 0, S = 0, E = 0, W = 0;
	bool b = 0;
	int* position = new int[4];
	string direction;
	cout << "Enter time: ";
	cin >> t;
	cout << "Enter position:\n";
	for (int i = 0; i < 4; i++)
		cin >> position[i];
	cout << "Enter direction: ";
	cin >> direction;

}

void Calevich_and_chess()
{
	// вычисляет сколько прямых линий нужно провести, чтобы получить доску с данными цветами
	// доска белая, линии черные
	int n = 8, q = 0, m, count = 0, i1;
	char** desk = new char* [n];
	for (int i = 0; i < n; i++)
		desk[i] = new char[n];
	cout << "Enter desks colors (W-white, B-black): " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> desk[i][j];
	/*char desk[8][8] = { 
	{'B','B','B','B','B','B','B','B'}, 
	{'B','B','B','B','B','B','B','B'}, 
	{'W','W','W','B','W','W','B','W'},
	{'W','W','W','B','W','W','B','W'}, 
	{'W','W','W','B','W','W','B','W'},
	{'W','W','W','B','W','W','B','W'}, 
	{'W','W','W','B','W','W','B','W'}, 
	{'W','W','W','B','W','W','B','W'} 
	};*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (desk[i][j] == 'B')
			{
				m = 1;
			}
			else
			{
				i1 = i;
				m = 0;
				break;
			}
		}
		if (m)
			q++;
	}
	for (int j = 0; j < n; j++)
	{
		if (desk[i1][j] == 'B')
			q ++;
	}

	cout << "Quantity swabs = " << q << endl;
}

void Increasing_matrix()
{
	int n , m , i1, j1, qi = 0, qj = 0; // qi кол-во нулей в строке, qj кол-во нулей в столбце
	// приводит матрицу к виду возрастающей: в строке и в столбце числа возрастают
	cout << "Enter size: n:  ";
	cin >> n;
	cout << "Enter m: ";
	cin >> m;
	int** matric = new int* [n];
	for (int i = 0; i < n; i++)
		matric[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matric[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!matric[i][j])
			{
				qj = qi = 0;
				for (j1 = j + 1; j1 < m; j1++)
				{
					if (matric[i][j1])
						break;
					qj++;
				}
				for (i1 = i + 1; i1 < n; i1++)
				{
					if (matric[i1][j])
						break;
					qi++;
				}
				if (matric[i][j1] < matric[i1][j])
					matric[i][j] = matric[i][j1] - qj - 1;
				else if (qi > qj)
					matric[i][j] = matric[i1][j] - qi - 1;
				else
					matric[i][j] = matric[i][j1] - qj - 1;
			}
		}
	}
	j1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			if (matric[i][j] >= matric[i][j + 1])
			{
				j1 = 1;
				break;
			}
			for (int l = j; l < n - 1; l++)
			{
				if (matric[j][l] >= matric[j][l + 1])
				{
					j1 = 1;
					break;
				}
			}
		}
	}
	if (j1)
		cout << "Impossible!";
	else
	{
		for (int i = 0; i < n; i++)
		{
			cout << endl;
			for (int j = 0; j < m - 1; j++)
				cout << matric[i][j] << "\t";
		}
	}
}

void Alternating_subsequence(const int& t)
{
	// t - кол-во тестов
	// вычисляет последовательность где отрицательные и положительные числа чередуются
	// максимальной длины и из этой максимальной длины, находит макс сумму
	int S = 0, S_temp = 0, len = 0, len_temp = 0, temp = 0;
	bool neg = 0, pos = 0;
	int n,* data;
	for (int l = 0; l < t; l++)
	{
		cout << "Enter n: ";
		cin >> n;
		data = new int[n];
		cout << "Enter values:\n";
		for (int i = 0; i < n; i++)
			cin >> data[i];
		for (int q = 0; q < n; q++)
		{
			if (len >= len_temp)
			{
				if (!S_temp)
					S_temp = S;
				S_temp = S > S_temp ? S : S_temp;
				len_temp = len;
			}
			S = len = 0;
			for (int i = q; i < n; i++)
			{
				if (data[i] < 0)
				{
					if (pos)
					{
						len++;
						S += (i == n - 1 ? temp + data[i] : temp);
						temp = data[i];
						neg = 1; pos = 0;
					}
					else
					{
						if (!temp)
							temp = data[i];
						else
							temp = temp > data[i] ? temp : data[i];
						if (i == n - 1)
							S += temp; len++;
						neg = 1; pos = 0;
					}
				}
				else
				{
					if (neg)
					{
						len++;
						S += (i == n - 1 ? temp + data[i] : temp);
						temp = data[i];
						pos = 1; neg = 0;
					}
					else
					{
						if (!temp)
							temp = data[i];
						else
							temp = temp > data[i] ? temp : data[i];
						if (i == n - 1)
							S += temp; len++;
						neg = 0; pos = 1;
					}
				}
			}
		}
		cout << "\nSum = " << S_temp << "\tLen = " << len_temp;
	}
}

void Game_with_telephon_number(const int& n)
{
	int q = 0;
	int* number = new int[n];
	cout << "\nEnter number: ";
	for (int i = 0; i < n; i++)
		cin >> number[i];
	for (int i = 0; i < n; i++)
	{
		if (number[i] == 8)
		{
			q++;
			if (q == (n - 11) / 2 + 1)
			{
				if (i == (n - 11))
					cout << "YES";
				else
					cout << "NO";
			}
		}
	}
}

void Alena_and_mex(const int& n)
{
	int arr[6] = { 1,6,5,3,3,2 };
	int min, i1, temp;
	for (int i = 1; i < n; i++)
	{
		i1 = i - 1;
		temp = arr[i];
		while (temp < arr[i1] && i1 >= 0)
		{
			arr[i1 + 1] = arr[i1];
			arr[i1] = temp;
			i1--;
		}
	}
	for (int j = 0; j < n; j++)
	{
		min = arr[0] + 1;
		for (int i = 1; i < n; i++)
		{
			if (min == arr[i])
				min++;
		}
		for (int i = 0; i < n; i++)
		{
			if (min < arr[i])
			{
				arr[i] = min;
				break;
			}
		}
	}
	cout << "Min: " << min << endl;
}

void Exchange_books(int& q)
{
	int* standart, * arr, n;
	while (q)
	{
		cout << "\nEnter quantity children: ";
		cin >> n;
		standart = new int [n];
		arr = new int [n];
		for (int i = 0; i < n; i++)
			standart[i] = i + 1;
		cout << "\nEnter seuence change: ";
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		
		q--;
	}

}

void Add_digits()
{
	long int a, b, n, temp_a, temp, step, quantity_digits = 0, 
		quantity_digits_immutable = 0, temp_number, number;
	bool result = false;
	cin >> a >> b >> n;
	temp_a = a;
	step = 1;
	while (temp_a / step)
	{
		quantity_digits_immutable++;
		step *= 10;
	}
	quantity_digits = quantity_digits_immutable + n;
	while (n)
	{
		temp_a = temp_a * 10 + 9;
		n--;
	}
	step = 1;

	while (!result)
	{
		temp = 0;
		while (quantity_digits != temp) 
		{
			number = b * step;
			while (number % 10 == 0 && number < temp_a)
				number = b * (++step);
			temp = 0;
			temp_number = number;
			while (temp_number)
			{
				temp_number /= 10;
				temp++;
			}
			if (temp > quantity_digits)
			{
				cout << "\n-1";
				return;
			}
			step++;
		}
		for (int i = 0; i < quantity_digits_immutable; i++)
		{
			if (((a / (int)(pow(10, quantity_digits_immutable - 1 - i))) % 10) == 
				((number / (int)(pow(10, quantity_digits - 1 - i))) % 10))
				result = true;
			else
			{
				result = false;
				break;
			}
		}

	}
	cout << number;
}