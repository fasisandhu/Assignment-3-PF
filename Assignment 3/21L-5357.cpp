//MUHAMMAD FASEEH
//l215357@lhr.nu.edu.pk
#include <iostream>
using namespace std;
//question 1**********
//insert operation
void insert(int a[], int size,int& s)
{
	int n;
	cout << "Enter the element to be inserted: ";
	cin >> n;
	if (s == 0)
	{
		a[0] = n;
		cout << "Inserted ";
		s++;
	}
	//it will insert the element simple
	else if (s > 0 && s < size)
	{
		a[s] = n;
		cout << "Inserted ";
		s++;
		//now it will sort it
		//for sorting
		for (int i = 0; i < s; i++)
		{
			int min = i;
			for (int j = i+1; j < s; j++)
			{
				if (a[min] > a[j])
				{
					min = j;
				}
				
			}
			if (min != i)
			{
				int temp;
				temp = a[i];
				a[i] = a[min];
				a[min] = temp;
			}
		}
	}
	else if (s == size)
	{
		cout << "Array is full"<<endl;
	}
	
}

//delete operation
void deleteoper(int a[], int size, int& s)
{
	int n,index,c=0;
	cout << "Enter the element to be deleted: ";
	cin >> n;
	//for searching
	for (int i = 0; i < s; i++) 
	{
		for (int j = 0; j < s; j++)
		{
			if (a[j] == n)
			{
				index = j;
				for (int k = index; k < s; k++)
				{
					a[k] = a[k + 1];
				}
				a[s] = 0;
				s--;
				c = 1;
			}
			//else
			//	c++
		}
	}
	if (c != 1)
	{
		cout << "Element not found" << endl;;
	}
	else
	{
		cout << "Deleted"<<endl;
	}

}

//update operatOn
void update(int a[], int size, int& s)
{
	int n,n1, index, c = 0;
	cout << "Enter the element to be updated: ";
	cin >> n;
	cout << "Enter the number to which it is updated: ";
	cin >> n1;
	//for searching
	for (int i = 0; i < s; i++)
	{
		if (a[i] == n)
		{
			index = i;
			c++;
		}
	}
	//if found
	if (c != 0)
	{
		a[index] = n1;
		cout << "Updated ";
	}
	else
		cout << "Not Found";
}
//question 1 main.............
void question1()
{
	int a[20];
	int s = 0;
	int choice;
	
	cout << "Enter the no of elements to be entered: "<<endl;
	cin >> s;
	for (int i = 0; i < s; i++)
	{
		cout << "Enter the number for index " << i << ":";
		cin >> a[i];
	}
	//for sorting
	for (int i = 0; i < s; i++)
	{
		int min = i;
		for (int j = i + 1; j < s; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp;
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
	
	//Menu
	cout << "1.Insert" << endl;
	cout << "2.Delete" << endl;
	cout << "3.Update" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	//calling insert operation
	{
		insert(a, 20, s);
	}

	else if (choice == 2)
	//calling delete operation
	{
		deleteoper(a, 20, s);
	}

	else if (choice == 3)
	//calling update operation
	{
		update(a, 20, s);
	}
	else
		cout << "Wrong Choice ";
	//for printing
	for (int i = 0; i < s; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//ending question 1


//starting question 2****************
void question2()
{
	int a[10];
	int b[10];
	int uniarray[20], interarray[10];
	cout << "Input values of 1st array " << endl;
	//inputing 1st array
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter the number for index " << i << ":";
		cin >> a[i];
	}
	cout << "Input values of 2nd array " << endl;
	//inputing 2nd array
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter the number for index " << i << ":";
		cin >> b[i];
	}

	//for union
	//inputting 1st array into union array
	for (int i = 0; i < 10; i++)
	{
		uniarray[i] = a[i];
	}
	//inputting 2nd array into union array
	for (int i = 10; i < 20; i++)
	{
		uniarray[i] = b[i-10];
	}
	//using distinct array concept
	int disarray[20],c1=0;
	int d = 0;//index for distinct array
	for (int i = 0; i < 20; i++)
	{
		if (i == 0)
		{
			disarray[d] = uniarray[i];
			d++;
			
		}
		else
		{
			for (int j = 0; j < d; j++)
			{
				if (uniarray[i] == disarray[j])
				{
					c1++;
				}
			}

			if (c1 == 0)
			{
				disarray[d] = uniarray[i];
				d++;
			}
		}
		c1 = 0;
	}
	//printing union array
	cout << "Union Array" << endl;

	for (int i = 0; i < d; i++)
	{
		cout << disarray[i] << " ";
	}
	cout << endl;
	//for intersection
	int chked[10],chk=0; //for inputting the already checked variables
	int k = 0,c=0;
	for (int i = 0; i < 10; i++)
	{
		chked[chk] = a[i];
		chk++;
		if (i != 0)
		{
			for (int l = 0; l < chk-1; l++)
			{
				if (a[i] == chked[l])
				{
					c++;
				}
			}
		}
		if (c == 0)
		{
			c = 0;
			for (int j = 0; j < 10; j++)
			{

				if (a[i] == b[j])
				{
					interarray[k] = a[i];
					k++;
					break;
				}
			}
		}
		//c = 0;
	}
	//Printing Intersection Array
	cout << "Intersection Array" << endl;
	for (int i = 0; i < k; i++)
	{
		cout << interarray[i] << " ";
	}
	

}
//MAIN FUNCTION
int main()
{
	int n;
	cout << "1.Question 1" << endl;
	cout << "2.Question 2" << endl;

	cout << "Enter your choice: ";
	cin >> n;
	if (n == 1) 
	{
		question1();
	}
	else if (n == 2)
	{
		question2();
	}

	system("pause");
	return 0;
}