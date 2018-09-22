#include <iostream>
using namespace std;
const int MAX = 10;
class arrayS
{

public:
	int arr[MAX];
	int count;


	arrayS()
	{
		count = 0;
		for (int i = 0; i < MAX; i++)
			arr[i] = 0;
	}
	//void add(int item);
	/*int getcount();
	static int split(int *, int, int);
	void quiksort(int lower, int upper);
	void display();
	int binarySearch(int arr[], int l, int r, int x);*/

	
	void add(int item)
	{
		if (count < MAX)
		{
			arr[count] = item;
			count++;
		}
		else
			cout << "\nArray is full" << endl;
	}
	int getcount()
	{
		return count;
	}
	void quiksort(int lower, int upper)
	{
		if (upper > lower)
		{
			int i = split(arr, lower, upper);
			quiksort(lower, i - 1);
			quiksort(i + 1, upper);
		}
	}
	int split(int *a, int lower, int upper)
	{
		int i, p, q, t;

		p = lower + 1;
		q = upper;
		i = a[lower];
		while (q >= p)
		{
			while (a[p] < i)
				p++;
			while (a[q] > i)
				q--;
			if (q > p)
			{
				t = a[p];
				a[p] = a[q];
				a[q] = t;
			}
		}
		t = a[lower];
		a[lower] = a[q];
		a[q] = t;
		return q;
	}
	void display()
	{
		for (int i = 0; i < count; i++)
			cout << arr[i] << "  ";
		cout << endl;

	}
	int binarySearch(int arr[], int lower, int upper, int y)
	{
		if (upper >= lower)
		{
			int mid = lower + (upper - lower) / 2;


			if (arr[mid] == y)
				return mid;


			if (arr[mid] > y)
				return binarySearch(arr, lower, mid - 1, y);


			return binarySearch(arr, mid + 1, upper, y);
		}


		return -1;
	}
};

void main()
{
	
	arrayS a;
	a.add(11);
	a.add(2);
	a.add(9);
	a.add(13);
	a.add(57);
	a.add(25);
	a.add(17);
	a.add(1);
	a.add(90);
	a.add(3);
	cout << "\nQuik sort.\n";
	cout << "\nArray before sorting:" << endl;
	a.display();
	int c = a.getcount();
	a.quiksort(0, c - 1);
	cout << "\nArray after quick sorting:" << endl;
	a.display();
	
	int result = a.binarySearch(a.arr, 0, 9,25);
	cout <<"found at index of "<< result;
	
}