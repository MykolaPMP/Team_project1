#include <iostream>;
#include <ctime>;
#include <cstdlib>;
using namespace std;

void output(int a[], int size);
void insertionSort(int *, int size);


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
	cout << "3. Insertion sort" << endl;
	cout << "4." << endl;
	cout << "5." << endl;
	cout << "6.End of work" << endl;

	int check;
	cout << "Size of your vector ";
	cin >> n;

	cout << "Random vector? ";
	cin >> check;
	A = new int[n];

	if (check != 1)
	{
		cout << "Please input your vector" << endl;

		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			A[i] = rand();
		}
	}

	R = new int[n];

	do
	{
		cout << "Menu item? ";
		cin >> menu;

		if (menu <= 5 && menu >= 1)
		{
			for (int i = 0; i < n; ++i)
			{
				R[i] = A[i];
			}
			cout << "Before sorting" << endl;
			output(A, n);
			start_time = clock();
		}
		switch (menu)
		{
		case 1:
		{

			break;
		}
		case 2:
		{

			break;
		}
		case 3:
		{
			cout << "Insertion sort" << endl;
			insertionSort(R, n); 
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
			cout << "Thanks for choosing our product." << endl;
			break;
		}
		default:
		{
			cout << "Please input proper value" << endl;
			break;
		}
		}
		if (menu <= 5 && menu >= 1)
		{
			end_time = clock();
			cout << "After sorting" << endl;
			output(R, n);
			cout << "And it was done in " << end_time / CLOCKS_PER_SEC - start_time / CLOCKS_PER_SEC << endl;
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

void insertionSort(int *array, int size)
{
	int temp, item;
	for (int i = 1; i < size; i++)
	{
		temp = array[i];
		item = i - 1;
		while (item >= 0 && array[item] > temp)
		{
			array[item + 1] = array[item];
			array[item] = temp;
			item--;
		}
	}
}

