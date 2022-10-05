#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;



//
//                   //想得太复杂，用了太多if句子，及其容易出错，这里最终还是有一个WA
//double p[10];
//double dr[10];
//int main() {
//	double D, c, d;int n;
//	cin >> D >>c>> d >> p[0] >> n;
//	 dr[n + 1] = D; dr[0] = 0;   //终点油费p[n+1]设置为极大值，保证前往终点用的是之前的油
//	for(int i = 1; i <= n; ++i)cin >> dr[i] >> p[i];
//	double l = c * d; double sum = 0; double let = 0;//l表示满油可以行使最大距离,let表示剩余油量可以走的路程
//	for (int i = 0; i <= n; ++i) {
//		if (dr[i + 1] - dr[i] <= l) {//大前提，相邻俩站满油一定可以到，不行无结果
//			sum += (dr[i + 1] - dr[i]-let) / d * p[i];  //如果下一站价格便宜，加油到刚刚好到下一站就好，不用再判断要不要继续加(如果前面有剩余油，用掉
//			let = 0;
//			if (i < n) {   //i=n，后面只有终点，不用再判断下下站了
//				if (p[i] <= p[i + 1]) {
//					for (int j = i + 2; j <= n + 1; ++j) {
//						if (dr[j] - dr[i] <= l) {  //先判断满油能不能从i站到j站(i到j比较的邮费是p[i]与p[j-1],注意到j站用的是j-1或者之前的油
//							sum += (dr[j] - dr[j - 1]) / d * p[i];//可以就先加
//							if (p[i] <= p[j])continue;   //判断从j站到j+1站用的油哪个便宜，从而决定是否继续循环					
//							else { i = j - 1; break; }//p[j]便宜，跳出循环，目前到了j站，i=j-1,-1是因为循环过去有个++i
//						}
//
//						else {//不可以，但我至少把油加满，因为下一站油更贵，我这里虽然不能到达下下站，但是我减少下一站用贵油的费用
//							
//							sum+=( l - (dr[j - 1] - dr[i]) )/ d * p[i];//油只够到j-1站再多一些
//							let = l - (dr[j - 1] - dr[i]);  //油量剩余可以走的路程
//							i = j - 2; break;//到了j-1站
//						}
//					}
//				}
//			}
//		}
//		else { printf("No Solution"); return 0; }//无结果就程序结束
//	}printf("%.2lf", sum);
//	return 0;
//}

         
           //优化AC版
double p[10]; 
double dr[10];
int main() {
    double D, c, d; int n;
    cin >> D >> c >> d >> p[0] >> n;
    for (int i = 1; i <= n; ++i)cin >> dr[i] >> p[i];
   dr[n + 1] = D;
    double l = c * d; double left=0,sum = 0;   //终点油价不需要无穷大，0就好（最低价格），保证最后是刚刚好油用完油到达
    for (int i = 1; i <= n + 1; ++i)if (dr[i] - dr[i - 1] > l) { printf("No Solution\n"); return 0; }//油箱中的油能否跑完每一段加油站的距离   //不能打出 No Solution
    int j;
    for (int i = 0; i <= n; i = j) {
        for (j = i + 1; j <= n + 1; ++j) {
            if (dr[j] - dr[i] > l){ j--; break; } // 在l的距离内的加油站中寻找最便宜的加油站
            if (p[i] > p[j])break; // 找到更便宜的加油站就退出循环
        }
        if (p[i] > p[j]) {//有找到更便宜的加油站
            sum += (dr[j] - dr[i] - left) / d * p[i];//加刚好足够到达第j个加油站的油 
            left = 0;
        }
        else {
            sum += (l-left)/d * p[i];//加满油箱
            left = (l - (dr[j] - dr[i]));
        }

    }
    printf("%.2lf\n", sum);
    return 0;
}
















//
//题目描述
//一个旅行家想驾驶汽车以最少的费用从一个城市到另一个城市（假设出发时油箱是空的）。给定两个城市之间的距离 D_1D
//1
//​
//、汽车油箱的容量 CC（以升为单位）、每升汽油能行驶的距离 D_2D
//2
//​
//、出发点每升汽油价格PP和沿途油站数 NN（NN 可以为零），油站 ii 离出发点的距离 D_iD
//i
//​
//、每升汽油价格 P_iP
//i
//​
//（i = 1, 2, …, Ni = 1, 2, …, N）。计算结果四舍五入至小数点后两位。如果无法到达目的地，则输出 No Solution。
//
//输入格式
//第一行，D_1D
//1
//​
//，CC，D_2D
//2
//​
//，PP，NN。
//
//接下来有 NN 行。
//
//第 i + 1i + 1 行，两个数字，油站 ii 离出发点的距离 D_iD
//i
//​
//和每升汽油价格 P_iP
//i
//​
//。
//
//输出格式
//所需最小费用，计算结果四舍五入至小数点后两位。如果无法到达目的地，则输出 No Solution。