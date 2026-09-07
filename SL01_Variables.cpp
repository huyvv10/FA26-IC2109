#include <iostream>

using namespace std;

int main(){
	int n;
	char vC;
	float vF, cF2 = 7.5f;
	double vD, vD2 = 8.8;
	string S;
	bool flag = true;
	
	cout<<"Input n = "; cin>>n;
	cout<<"Input c = "; cin>>vC;
	cout<<"Input a float f = "; cin>>vF;
	cout<<"Input a double d = "; cin>>vD; 
	cin.ignore() ;
	cout<<"Input a string: "; getline(cin, S);
	
	cout<<"Inputed n = "<<n<<endl;
	cout<<"Inputed c = "<<vC<<endl;
	cout<<"Inputed float = "<<vF<<endl;
	cout<<"Inputed double = "<<vD<<endl;
	cout<<"Inputed String = "<<S<<endl;
		
	return 0;
}