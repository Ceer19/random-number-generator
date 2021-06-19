

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));

b:cout << "Enter array  size: " << endl;   // (b)
	int size, limits;
	cout << endl;

	cin >> size;
	cout << "\n";

	cout << "Within what limits to generate numbers? : ";

	cin >> limits;

	cout << "\n";

	if (size < 1)
	{
		cout << "\nError: 101 (You entered a number less than one)" << endl;
		cin.get(); 
		system("pause");
		cout << "\n";

		goto b;      // 11 line

	}
	if (limits < size)
	{
		cout << "Error(101) Not enough numbers" << endl << endl;

		system("pause");
		cout << "\n";

		goto b;      //  11 line
	}
	

	int* arr = new int [size];

	for (int i = 0; i < size; i++)
	{

	a:arr[i] = rand() % limits;    //Метка (b)

		for (int j = 0; j < i; j++)
		{

			if (arr[i] == arr[j]) goto a;    // line 50 

		}

	}

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] <<'\t';


		}
	
		int 	max = arr[0];
		int 	min = arr[0];
		for (int r = 0; r < size; r++)
		{
			if (max > arr[r])max = arr[r];
			if (min < arr[r])min = arr[r];
		}
		cout << "\n\nMax number: " << max;
		cout << "\nMin number: " << min << endl << endl;

	s:cout << "Do you want to perform manipulations with the minimum and maximum number?\n\n Addition (1)\n Subtraction (2)\n Multiplication (3)\n Division (4)" << endl << endl; //  Mark (s)

		int Switch_Key;

		cin >> Switch_Key;

		cout << "\n";

		switch (Switch_Key)
		{
		case 1:

			cout << "Sum addition:  " << (max + min) << endl;
			break;

		case 2:
		
			cout << "Sum subtraction:  " << (max - min) << endl;
			break;

		case 3:

			cout << "Sum multiplication:  " << (max * min) << endl;
			break;

		case 4:

			cout << "Sum division:  " << (max / min) << endl;
			break;

		default:

			cout << "Error (101) You entered the wrong value : Repeat entering the number" << endl;
		
			system("pause");

			goto s;  //  78 line

		}

	delete [] arr;
   
}


