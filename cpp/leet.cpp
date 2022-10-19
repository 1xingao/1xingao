/*
 * @Author: xinao_seven_
 * @Date: 2022-10-18 17:53:40
 * @LastEditTime: 2022-10-19 10:59:01
 * @LastEditors: xinao_seven_
 * @Description: 
 * @Encoding: utf8
 * @FilePath: \\1xingao\\cpp\\leet.cpp
 * 
 */
#include<bits/stdc++.h>

using namespace std;


int calc(int lhs, char op, int rhs) {
	switch (op) {
		case '+' : return lhs + rhs;
		case '-' : return lhs - rhs;
		case '*' : return lhs * rhs;
		case '/' : return lhs / rhs;
		case '>' : return lhs >> rhs;
		case '<' : return lhs << rhs;
		case '^' : return lhs ^ rhs;
		case '&' : return lhs & rhs;
		case '|' : return lhs | rhs;
		case 'x' : return pow(lhs, rhs);
	}
	return 0;
}

int getValue(string &exp) {
	int i = 0, n = exp.size(), lhs = 0;;
	while(i < n and isdigit(exp[i]) ) {
		lhs = lhs * 10 + exp[i] - '0';
		i++;
	}
	while(i < n) {
		char op = exp[i];
		i++;
		int rhs = 0;
		while(i < n and isdigit(exp[i]) ) {
			rhs = rhs * 10 + exp[i] - '0';
			i++;
		}
		lhs = calc(lhs, op, rhs);
	}
	return lhs;
}

void dfs(vector<int> &nums, vector<int> &vis1, vector<char> &ops, vector<int> &vis2, int cnt, string &exp){

	if(cnt == 7 ) {
		int v = getValue(exp);
//		cout << exp << " = " << v << endl;
		if(v == 1024) {
			cout << "ans " << exp << " = "<< v << endl;
		}
		return;
	}
	// 选一个数
	if(cnt % 2 == 0) {
		for(int i = 0; i < nums.size(); i++) {
			if(!vis1[i]) {
				int len = exp.size();
				exp += to_string(nums[i]);
				vis1[i] = 1;
				dfs(nums, vis1, ops, vis2, cnt + 1, exp);
				vis1[i] = 0;
				exp.resize(len);
			}
		}
	} 
	else { // 选一个符号
		for(int i = 0; i < ops.size(); i++) {
			if(!vis2[i]) {
				int len = exp.size();
				exp += (ops[i]);
				vis2[i] = 1;
				dfs(nums, vis1, ops, vis2, cnt + 1, exp);
				vis2[i] = 0;
				exp.resize(len);
			}
		}
	}
}

int main() {
	vector<int> nums = {2, 34 ,13,11,27,1,1024};
	vector<char> ops = {'&','+','|','<','>'};
	vector<int> vis1(nums.size(), 0), vis2(ops.size(), 0);
	string exp;
	dfs(nums, vis1, ops, vis2, 0, exp);
	
	return 0;
}

