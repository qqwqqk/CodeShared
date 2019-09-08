#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

//解析行数据
vector<int> analyzeLine(string str);

//输出全排列
vector<vector<int>> analyzePermutation(vector<int> array);

//斐波那契数列通项公式
double getFibonacci(int n);

//阶乘公式
int getFactorial(int n);

//排序函数
bool sortFun(int x, int y);

//质数判断
bool is_prime(int n);

//n进制数进位
vector<int> decimalcarry(vector<int> nums, int n);