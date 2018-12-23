/********************************************************************* 
** Description: The implementation
*********************************************************************/ 

// citation in hpp file

// finds the nth fibonacci number recursively
int fibonacciRecursive(int n){

 	if(n==0) {

 		return 0;

 	} else if(n==1) {

 		return 1;

	}

 	return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

// finds the nth fibonacci number iteratively
int fibonacciIterative(int n) {

	int first =0;
	int second=1;
	int counter=2;
	while(counter < n)
	{
		int temp=second;
		second=first+second;
		first=temp;
		++counter;
	}
	if(n==0)
		return 0;
	else
		return first+second;


}
