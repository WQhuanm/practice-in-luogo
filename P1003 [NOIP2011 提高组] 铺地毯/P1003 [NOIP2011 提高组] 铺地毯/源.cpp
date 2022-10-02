#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
          
                  //显然，当知道我们要的目标时，围绕它来铺更方便，但是他是最后的输入，可是这不意味我们一定要填表后再搞他，我们可以先把前面的数存起来（避免填表爆空间），再围绕目标来搞
struct room {
	int a;
	int b;
	int g;
	int k;
}arr[10010];  //因为是4个一个整体，所以用结构组

int main() {
	int n;
	scanf("%d", &n);
	memset(arr, 0, sizeof(arr));
	
	for (int i = 1; i <= n; ++i)scanf("%d %d %d %d", &arr[i].a, &arr[i].b, &arr[i].g, &arr[i].k);

	int x, y;
	scanf("%d %d", &x, &y); int m = 0;
	for (int i = 1; i <= n; ++i) {
		if (x >= arr[i].a && x < arr[i].a + arr[i].g && y >= arr[i].b && y < arr[i].b + arr[i].k)m = i;


	}



	if (m)printf("%d\n", m);
	else printf("-1\n");

	return 0;
}









//
//
//为了准备一个独特的颁奖典礼，组织者在会场的一片矩形区域（可看做是平面直角坐标系的第一象限）铺上一些矩形地毯。一共有 nn 张地毯，编号从 11 到 nn。现在将这些地毯按照编号从小到大的顺序平行于坐标轴先后铺设，后铺的地毯覆盖在前面已经铺好的地毯之上。
//
//地毯铺设完成后，组织者想知道覆盖地面某个点的最上面的那张地毯的编号。注意：在矩形地毯边界和四个顶点上的点也算被地毯覆盖。
//
//输入格式
//输入共 n + 2n + 2 行。
//
//第一行，一个整数 nn，表示总共有 nn 张地毯。
//
//接下来的 nn 行中，第 i + 1i + 1 行表示编号 ii 的地毯的信息，包含四个整数 a, b, g, ka, b, g, k，每两个整数之间用一个空格隔开，分别表示铺设地毯的左下角的坐标(a, b)(a, b) 以及地毯在 xx 轴和 yy 轴方向的长度。
//
//第 n + 2n + 2 行包含两个整数 xx 和 yy，表示所求的地面的点的坐标(x, y)(x, y)。
//
//输出格式
//输出共 11 行，一个整数，表示所求的地毯的编号；若此处没有被地毯覆盖则输出 - 1。