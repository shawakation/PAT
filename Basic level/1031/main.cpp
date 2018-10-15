#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	int n;
	bool isright=true;
	int quan[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char jiao[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	cin>>n;
	for (int i=0;i<n;i++) {
		string num;
		int Z;
		cin>>num;
		int sum=0;
		for (int j=0;j<17;j++) {
			if (isdigit(num[j])) sum+=(num[j]-'0')*quan[j];
			else {
				cout<<num<<endl;
				isright=false;
				goto aa;
			}
		}
		Z=sum%11;
		if (jiao[Z]!=num[17]) {
			cout<<num<<endl;
			isright=false;
		}
		aa:;
	}
	if (isright) cout<<"All passed\n";
	return 0;
}
