#include <iostream>
#include <string>
using namespace std;
int main()
{
	string correct;
	int n;
	cin>>correct>>n;
	cin.ignore();
	while(1) {
		string inputstr;
		getline(cin,inputstr,'\n');
		if (inputstr=="#") return 0;
		if (inputstr==correct&&n>0) {
			cout<<"Welcome in\n";
			return 0;
		}
		else {
			cout<<"Wrong password: "<<inputstr<<endl;
			n--;
			if (n==0) {
				cout<<"Account locked\n";
				return 0;
			}
		}
	}
	return 0;
}
