#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int a, b;
	cin>>a;
	cin>>b;
	cout<<a+b<<endl;
	cout<<a-b<<endl;
	cout<<a*b<<endl;
	if (b!=0)
		cout<<fixed<<setprecision(2)<<(float)a/b<<endl;
	else
		cout<<"Divide by zero"<<endl;	
	return 0;
}
