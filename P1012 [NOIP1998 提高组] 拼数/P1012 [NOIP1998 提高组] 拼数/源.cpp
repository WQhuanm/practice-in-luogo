#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>   //cin与cout的头文件
#include <stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

//
//有了 string 类，我们可以使用 + 或 += 运算符来直接拼接字符串，非常方便，再也不需要使用C语言中的 strcat()、strcpy()、malloc() 等函数来拼接字符串了，再也不用担心空间不够会溢出了。
//
//用 + 来拼接字符串时，运算符的两边可以都是 string 字符串，也可以是一个 string 字符串和一个C风格的字符串，还可以是一个 string 字符串和一个字符数组，或者是一个 string 字符串和一个单独的字符


bool cmp(string a, string b) {
	return a + b > b + a;   //表示a在前，或者b在前
}


string arr[30];
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i)cin >> arr[i];
	sort(arr + 1, arr + 1 + n, cmp);
	
	
	for (int i = 1; i <= n; ++i)cout << arr[i];
	return 0;
}












//
//
//设有 nn 个正整数 a_1 \dots a_na
//1
//​
//…a
//n
//​
//，将它们联接成一排，相邻数字首尾相接，组成一个最大的整数。
//
//输入格式
//第一行有一个整数，表示数字个数 nn。
//
//第二行有 nn 个整数，表示给出的 nn 个整数 a_ia
//i
//​
//。
//
//输出格式
//一个正整数，表示最大的整数