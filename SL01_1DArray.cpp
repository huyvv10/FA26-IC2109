#include <iostream>
#include <algorithm>
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

int getMax(int a[], int n){
	int max=a[0];
	for (int i=1; i<n; i++)
		if (a[i]>max) max=a[i];
	return max;	
}

int getMin(int a[], int n){
	int min=a[0];
	for (int i=1; i<n; i++)
		if (a[i]<min) min=a[i];
	return min;	
}
//Return the postion first found x within the array
//Return -1 in case find not found.
int getFirstPosOfValue(int a[], int n, int x){
	int pos=-1;
	for (int i=0; i<n; i++)
		if (a[i]==x) {
			pos=i; break;
		}
	return pos;	
}
//Return the position the-k of x in the array
//Return -1 incase find not found or out of the range
int getPosTheK(int a[], int n, int x, int theK){
	int pos=-1, count=0;
	if (theK<0 || theK>=n) return pos;
	for (int i=0; i<n; i++)
		if (a[i]==x){
			count++;
			if (count==theK){
				pos=i; break;
			}
		}
	return pos;	
}
//Sort the array in ascending order
void sortAsc(int a[], int n){
	for (int i=0; i<n-1;i++)
		for (int j=n-1; j>i; j--)
			if (a[j-1]>a[j]){
				int tmp = a[j]; a[j]=a[j-1]; a[j-1]=tmp;
			}
}
void sortAsc2(int a[], int n){
	sort(a, a+n);
}
//Sort the array in descending order
void sortDesc(int a[], int n){
	for (int i=0; i<n-1;i++)
		for (int j=n-1; j>i; j--)
			if (a[j-1]<a[j]){
				int tmp = a[j]; a[j]=a[j-1]; a[j-1]=tmp;
			}
}

//Sort the elements within the range from pos1 to pos2 in
//asceding order. Keep the remain unchange.
void sortInRangeAsc(int a[], int n, int pos1, int pos2){
	if (pos1>pos2){
		int tmp = pos1; pos1=pos2; pos2=tmp;
	}
	for (int i=pos1; i<pos2;i++)
		for (int j=pos2; j>i; j--)
			if (a[j-1]>a[j]){
				int tmp = a[j]; a[j]=a[j-1]; a[j-1]=tmp;
			}	
	
}

int main(){
	int n;
	cin>>n;
	int a[n];
	inputArray(a,n);
	cout<<"OUTPUT"<<endl;
	displayArray(a,n);
	cout<<"The maximum value: "<<getMax(a,n)<<endl;
	cout<<"The minimum value: "<<getMin(a,n)<<endl;
	int x, pos;
	cout<<"Input a searching value: "; cin>>x;
	pos = getFirstPosOfValue(a, n, x);
	if (pos!=-1)
		cout<<"The position first found "<<x<<" in the array is "<<pos<<endl;
	else
		cout<<"Find not found "<<x<<" in the array."<<endl;
		
	cout<<"The position of the first max: "<<getFirstPosOfValue(a, n, getMax(a,n))<<endl;		
	int theK;
	cout<<"Input theK: "; cin>>theK;
	pos = getPosTheK(a, n, x, theK);
	if (pos!=-1)
		cout<<"The position the-"<<theK<<" of "<<x<<" is: "<<pos<<endl;
	else
		cout<<"Find not found the position the"<<theK<<" of "<<x<<" in the array."<<endl;
//	cout<<"Sort in Asc"<<endl;
//	sortAsc(a,n);
//	displayArray(a,n);
//	cout<<"Sort in Desc"<<endl;
//	sortDesc(a, n);
//	displayArray(a,n);
	cout<<"Sort in range"<<endl;
	int pos1, pos2;
	pos1 = getPosTheK(a, n, getMin(a, n), 1);
	pos2 = getPosTheK(a, n, getMax(a, n), 3);
	sortInRangeAsc(a, n, pos1, pos2);
	displayArray(a,n);
		
	return 0;
}
