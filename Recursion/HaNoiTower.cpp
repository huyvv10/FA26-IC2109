#include <iostream>
using namespace std;

void hanoiTower(int n, char S, char D, char T){
	if (n==1)
		cout<<"Move disk "<<n<< " from "<<S<<" to "<<D<<endl;
	else{
		hanoiTower(n-1, S, T, D);
		cout<<"Move disk "<<n<< " from "<<S<<" to "<<D<<endl;
		hanoiTower(n-1, T, D, S);		
	}
			
}
int main(){
	int n;
	cin>>n;
	hanoiTower(n, 'A', 'C', 'B');
	return 0;
}
