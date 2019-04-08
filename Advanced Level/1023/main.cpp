/*
1.认真读题，不仅数字要一样，而且数字出现的次数要一样
        注意理解 permutation 那一段
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
	string n,ans;
	unordered_map<char,int> my;
	bool flag=1;
	cin>>n;
	reverse(n.begin(),n.end());
	int carry=0;
	for (int i=0; i<n.length(); i++) {
		my[n[i]]++;
		int cheng=(n[i]-'0')*2+carry;
		ans.insert(ans.begin(),(char)(cheng%10+'0'));
		carry=cheng/10;
	}
	while (carry>0) {
		ans.insert(ans.begin(),(char)(carry%10+'0'));
		carry/=10;
	}
	for (int i=0; i<ans.length(); i++)
		if (my.find(ans[i])==my.end()) {
			flag=0;
			cout<<"No\n";
			break;
		} else {
			my[ans[i]]--;
			if (my[ans[i]]<0) {
				flag=0;
				cout<<"No\n";
				break;
			}
		}
	if (flag) cout<<"Yes\n";
	cout<<ans<<endl;
	return 0;
}
