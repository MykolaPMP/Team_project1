#include <iostream>;
#include <ctime>;
#include <cstdlib>;
using namespace std;

void output(int a[], int size);
void initialization(int a[], int& size);

void main()
{
	int menu, n;
	int *A = new int[0];
	int *R = new int[0];
	double start_time, end_time;
	srand(time(NULL));

	cout << "Menu:" << endl;
	cout << "1." << endl;
	cout << "2." << endl;
	cout << "3." << endl;
	cout << "4." << endl;
	cout << "5." << endl;
	cout << "6.End of work" << endl;

	initialization(A, n);
	R = new int[n];

	do
	{
		cout << "Choose Menu item  ";
		cin >> menu;

		if (menu <= 5 && menu >= 1)
		{
			for (int i = 0; i < n; ++i)
			{
				cout << i;
				R[i] = A[i];
			}
			cout << "Before sorting :  " ;
			output(A, n);
			start_time = clock();
		}
		switch (menu)
		{
		case 1:
		{
			int *b = new int[0];
			copy(A, b, n);
			int  c;
			int m = n / 2;
			for (int i = 0; i<m - 1; i++)
			{
				for (int j = 0; j<m - i - 1; j++)
				{
					if (b[j]>b[j + 1]) {
						c = b[j];
						b[j] = b[j + 1];
						b[j + 1] = c;
					}
				}
			}
			for (int i = m; i<n - 1; i++) {
				for (int j = m; j<n - (i - m) - 1; j++)
				{
					if (b[j]>b[j + 1]) {
						c = b[j];
						b[j] = b[j + 1];
						b[j + 1] = c;
					}
				}
			}
			for (int i = 0; i<n; cout << b[i] << ends, i++);
			cout << endl;
			int l = 0, r = m, k = 0;

			while (k<n)
			{
				if (l<m - 1 && r<m)
				{
					if (b[l]<b[r])
					{
						R[k] = b[l];
						++l;
					}
					else
					{
						R[k] = b[r]; ++r;
					}
				}
				else
				{
					if (l<m - 1)
					{
						R[k] = b[l];
						l++;
					}
					else
					{
						R[k] = b[r];
						r++;
					}
				}
				k++;
			}

			delete[] b;
			break;
		}
		case 2:
		{

			break;
		}
		case 3:
		{

			break;
		}
		case 4:
		{

			break;
		}
		case 5:
		{

			break;
		}
		case 6:
		{
			delete[] A; delete[] R;
			cout << "Thanks for choosing our product ^.^ " << endl;
			break;
		}
		default:
		{
			cout << "Please input proper value " << endl;
			break;
		}
		}
		if (menu <= 5 && menu >= 1)
		{
			end_time = clock();
			cout << "After sorting" << endl;
			output(R, n);
			cout << "And it was done in " << end_time / CLOCKS_PER_SEC - start_time / CLOCKS_PER_SEC << " sec ";
		}
	} while (menu != 6);

	system("pause");
}

void output(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
void initialization(int a[], int& size)
{
	int check;
	cout << "Size of your vector ";
	cin >> size;

	cout << "Enter 1 , to randomize vector ";
	cin >> check;
	a = new int[size];

	if (check == 0)
	{
		cout << "Please input your vector" << endl;

		for (int i = 0; i < size; ++i)
		{
			cin >> a[i];
		}
	}
	else
	{
		for (int i = 0; i < size; ++i)
		{
			a[i] = rand();
		}
	}
}
