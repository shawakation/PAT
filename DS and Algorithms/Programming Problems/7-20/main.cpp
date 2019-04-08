#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int> op;
struct node
{
	float num;
	char op;
	bool flag; //1->num 0->operator
	node (float _num,char _op,bool _f) {
		num=_num;op=_op;flag=_f;
	}
};
float strtoflt(string s)
{
	stringstream ss(s);
	float a;
	ss>>a;
	return a;
}
int main()
{
	op['+']=op['-']=1;
	op['*']=op['/']=2;
	string in;
	stack<char> st;
	vector<node> ans;
	getline(cin,in,'\n');
	//特殊情况一：遇到负数，在前面加个0
	for (int i=0;i<in.length();i++) {
		if (in[i]=='-'&&(i==0||!isdigit(in[i-1]))) {
			in.insert(i,"0");
			i++;
		}
	}
	for (int i=0;i<in.length();) {
		if (isdigit(in[i])) {
			int k=i;
			//特殊情况二：遇到小数
			while ((isdigit(in[k])||in[k]=='.')&&k<in.length()) k++;
			float tt=strtoflt(in.substr(i,k-i));
			ans.push_back(node(tt,'\0',1));
			i=k;
		}
		else if (in[i]=='(') {
			st.push(in[i]);
			i++;
		}
		else if (in[i]==')') {
			while (st.top()!='(') {
				ans.push_back(node(0,st.top(),0));
				st.pop();
			}
			st.pop();
			i++;
		}
		else {
			if (st.empty()) st.push(in[i]);
			else {
				while (!st.empty()&&op[st.top()]>=op[in[i]]) {
					ans.push_back(node(0,st.top(),0));
					st.pop();
				}
				st.push(in[i]);
			}
			i++;
		}
	}
	while (!st.empty()) {
		ans.push_back(node(0,st.top(),0));
		st.pop();
	}
	for (int i=0;i<ans.size();i++) {
		if (ans[i].flag) printf("%g",ans[i].num);
		else printf("%c",ans[i].op);
		if (i<ans.size()-1) printf(" ");
	}
	return 0;
}
