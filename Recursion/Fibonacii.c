#include <iostream>

using namespace std;

int fibonacii(int n){
	if (n<2)
		return n;
	else
		return fibonacii(n-1)+fibonacii(n-2);	
}

int main(){
	int n;
	cout<<"Input n = "; cin>>n;
	for (int i=0; i<=n; i++)
		cout<<fibonacii(i)<<" "<<endl;
	
	return 0;
}
