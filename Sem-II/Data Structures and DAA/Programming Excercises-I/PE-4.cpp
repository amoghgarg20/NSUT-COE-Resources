#include <bits/stdc++.h>
using namespace std;

//Precedence Function
int pred(char c) {
	if(c == '$')
		return 3;
	else if(c == '*' || c == '/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}
string infixToPostfix(string s) {
	stack<char> st; //Using built-in stack
	string ans;
	for(int i=0; i<s.length();i++){
		char c = s[i];
		if(c >= '0' && c <= '9'){
			 ans+=c;
		}
		else if(c == '('){
			st.push('(');
		}
		else if(c == ')') {
			while(!st.empty() && st.top() != '(')
			{
				char temp =st.top();
				st.pop();
				ans+=temp;
			}
			st.pop(); //To pop '('
		}
		else {
			while(!st.empty() && pred(c)<pred(st.top())){
				char temp=st.top();
				st.pop();
				ans+=temp;
			}
			st.push(c);
		}
	}
	// Pop remaining elements from the stack
	while(!st.empty()) {
		char temp=st.top();
		st.pop();
		ans+=temp;
	}

	return ans;
}
int evalpostfix(string exp){
    stack<int> st;
    for(int i=0;i<exp.length();i++){
        if (exp[i] >= '0' && exp[i] <= '9') {
            st.push(exp[i] - '0');
        }
        else {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            if (exp[i] == '+') {
                st.push(y + x);
            }
            else if (exp[i] == '-') {
                st.push(y - x);
            }
            else if (exp[i] == '*') {
                st.push(y * x);
            }
            else if (exp[i] == '/') {
                st.push(y / x);
            }
            else if (exp[i] == '$'){
            	st.push(pow(y,x));
            }
        }
    }
    return st.top();
}
int main() {
	string exp;
	cout<<"Enter the infix expression:";
	cin>>exp;
	string pf=infixToPostfix(exp);
	cout<<"Postfix Expression:";
	cout<<pf<<endl;
	cout<<"Value of Postfix Expression:";
	cout<<evalpostfix(pf)<<endl;

	return 0;
}
