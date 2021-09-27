// #include <iostream>

// using namespace std;

// int main(){

// 	int x = 10;
// 	cout<<(&x)<<endl;                    // address of x.Address is stored in hexadecimal value.it is of 16 bytes (0123456789abcdef)

// 	int *xptr = &x;                      //a variable xptr that stores the address of x

// 	cout<<xptr<<endl;

// 	cout<<(&xptr)<<endl;                   //address of xptr.

// 	cout<<(*xptr)<<endl;                   //dereference(i.e. address ka value)
// 	cout<<x<<endl;                          //directly returns the value of x
// 	cout<<10<<endl;

// 	cout<<"******Float******"<<endl;

// 	float f = 10.78;
// 	float* fptr = &f;                       // fptr is avariable that store the address of f

// 	cout<<&f<<endl;                           //it returns the address of f
// 	cout<<fptr<<endl;                          //it returns the address at which fptr is stored

// 	cout<<(*fptr)<<endl;                       //de reference(i.e. address ka value)

// 	char ch = 'A';
// 	char* cptr;                                 
// 	cptr = &ch; 

// 	cout<<&ch<<endl;                       //It does not return the address.it will print the characters only (reason:-operator overloading)                                 

// 	cout<<(void*)cptr<<endl;                // explict typecasting from char* to void*
// 	cout<<&ch<<endl;

// 	cout<<"********INT*******"<<endl;

	// int x = 10;
	// int* xptr = &x;

	// cout<<xptr<<endl;                         
	// cout<<(xptr+1)<<endl;

	// cout<<"********LONG*******"<<endl;

	// long l = 20;
	// long*lptr = &l;

	// cout<<lptr<<endl;
	// cout<<(lptr + 1)<<endl;

	// int x = 10;
	// int &z = x; // z is alloted same location as x

	// z++;

	// cout<<x<<endl;

	// return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// 	int* a=NULL;
// 	int n;
// 	cin>>n;                             // dynamic allocation of an array.
// 	a =new int[n];
// 	for(int i=0;i<n;i++)
// 	{
// 		a[i]=0;
// 		cout<<a[i]<<endl;
// 	}
// 	cout<<sizeof(a)<<endl; 

// 	delete [] a; // deletes the array from the heap memory



// 	return 0;
// }

//Dynamic allocation of a 2d array

#include <bits/stdc++.h>
using namespace std;

int main()
{
	//create a (3*4) array dynamically

	int **arr=new int*[3]; //create a primary array in the heap area

	for(int i=0;i<3;i++)
	{
		arr[i]=new int[4]; //create the secondary array
	}

	int counter=0;

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
           arr[i][j]=counter;
           counter++;
		}
	}

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<arr[i][j]<<" ";
		}

		cout<<endl;
	}

	//disallocate memory from the heap

	for(int i=0;i<3;i++)
	{
		delete [] arr[i];    //iterate over the primary array to delete the secondary array
	}

	delete [] arr; //delete the primary array.

	cout<<"hello"<<endl;

	return 0;
}