#include <iostream>
using namespace std;

void inputArray(int a[], int n){
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
}
void displayArray(int a[], int n){
	for (int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;	
}
int main(){
	int n;
	cin>>n;
	int a[n];
	inputArray(a,n);
	cout<<"OUTPUT"<<endl;
	displayArray(a,n);
	return 0;
}
