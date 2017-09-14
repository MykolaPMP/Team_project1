#include <iostream>;
#include <ctime>;
#include <cstdlib>;
using namespace std;

void output(int a[], int size);
void Merge(int A[], int l, int m, int r, int size);
void MergeSort(int A[], int left, int right, int size);
void main()
{
	int menu, n;
	int *A = new int[0];
	int *R = new int[0];
	double start_time, end_time;
	srand(time(NULL));

	cout << "Menu:" << endl;
	cout << "1.Merge_sort" << endl;
	cout << "2." << endl;
	cout << "3." << endl;
	cout << "4." << endl;
	cout << "5." << endl;
	cout << "6.End of work" << endl;

	int check;
	cout << "Size of your vector ";
	cin >> n;

	cout << "Enter 1 , to randomize vector  ";
	cin >> check;
	A = new int[n];

	if (check != 1)
	{
		cout << "Please input your vector " << endl;

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
		cout << "Choose Menu item ";
		cin >> menu;

		if (menu <= 5 && menu >= 1)
		{
			for (int i = 0; i < n; ++i)
			{
				R[i] = A[i];
			}
			cout << "Before sorting : ";
			output(A, n);
			cout << endl;
			start_time = clock();
		}
		switch (menu)
		{
		case 1:
		{
			MergeSort(R, 0, n - 1, n);
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
void Merge(int A[], int l, int m, int r, int size)
{
	int *B = new int[size];
	int i = l, j = m + 1, k = l;

	while (i <= m &&j <= r)
	{
		if (A[i] <= A[j])
		{
			B[k] = A[i];
			++i;
		}
		else
		{
			B[k] = A[j];
			++j;
		}
		++k;
	}

	while (i <= m)
	{
		B[k] = A[i];
		++i;
		++k;
	}

	while (j <= r)
	{
		B[k] = A[j];
		++j;
		++k;
	}

	for (int z = l; z <= r; ++z)
	{
		A[z] = B[z];
	}

	delete[] B;
}
void MergeSort(int A[], int left, int right, int size)
{
	if (right - left < 1)
	{
		return;
	}
	int mid = (right + left) / 2;
	if (right - left > 1)
	{
		MergeSort(A, left, mid, size);
		MergeSort(A, mid + 1, right, size);
	}
	Merge(A, left, mid, right, size);
}
