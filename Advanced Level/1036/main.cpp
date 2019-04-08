#include <string>
#include <iostream>
using namespace std;
struct stu
{
	string name;
	string id;
	int grade;
};
int main()
{
	int n;
	cin>>n;
	stu Fmax,Mmin;
	bool flagF=0,flagM=0;
	Fmax.grade=-1;
	Mmin.grade=101;
	for (int i=0;i<n;i++) {
		string name,id;
		char gender;
		int grade;
		cin>>name>>gender>>id>>grade;
		if (gender=='F'&&grade>Fmax.grade) {
			Fmax.name=name;
			Fmax.id=id;
			Fmax.grade=grade;
			flagF=1;
		}
		else if (gender=='M'&&grade<Mmin.grade) {
			Mmin.name=name;
			Mmin.id=id;
			Mmin.grade=grade;
			flagM=1;
		}
	}
	if (flagF) cout<<Fmax.name<<' '<<Fmax.id<<endl;
	else cout<<"Absent\n";
	if (flagM) cout<<Mmin.name<<' '<<Mmin.id<<endl;
	else cout<<"Absent\n";
	if (flagF&&flagM) cout<<Fmax.grade-Mmin.grade<<endl;
	else cout<<"NA\n";
	return 0;
}
