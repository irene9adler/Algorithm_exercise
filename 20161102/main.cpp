#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int N = 410;
struct Node{
    int integer[N];
    int decimal[N];
    Node() {
        memset(integer,0,sizeof(integer));
        memset(decimal,0,sizeof(decimal));
    }
};
void getInteger(int integer[],char str[]) {
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		integer[i] = str[len - 1 - i] - '0';
	}
}
void getFloat(int decimal[],char str[]) {
	int len = strlen(str);
	for(int i = 0,j = 1; i < len; i++) {
		decimal[j++] = str[i] - '0';
	}
}
void add(char a[],char b[]) {
	char ia[N],ib[N];
	char fa[N],fb[N];
	memset(ia,0,sizeof(ia));
	memset(ib,0,sizeof(ib));
	memset(fa,0,sizeof(fa));
	memset(fb,0,sizeof(fb));
	int len1,len2;
	int point1 = -1,point2 = -1;
	len1 = strlen(a);
	for(int i = 0; i < len1; i++) {
		if(a[i] == '.') {
			point1 = i;
			break;
		}
	}
	if(point1 == -1) {
		strcpy(ia,a);
	}
	else {
		for(int i = 0; i < point1; i++) {
			ia[i] = a[i];
		}
		for(int i = point1 + 1, j = 0; i < len1; i++) {
			if(isdigit(a[i])) {
				fa[j++] = a[i];
			}
		}
	}
	len2 = strlen(b);
	for(int i = 0; i < len2; i++) {
		if(b[i] == '.') {
			point2 = i;
			break;
		}
	}
	if(point2 == -1) {
		strcpy(ib,b);
	}
	else {
		for(int i = 0; i < point2; i++) {
			ib[i] = b[i];
		}
		for(int i = point2 + 1, j = 0; i < len2; i++) {
			if(isdigit(b[i])) {
				fb[j++] = b[i];
			}
		}
	}
	Node ta,tb;
	getInteger(ta.integer,ia);
	getFloat(ta.decimal,fa);
	getInteger(tb.integer,ib);
	getFloat(tb.decimal,fb);
	int lenia = strlen(ia);int lenfa = strlen(fa);
	int lenib = strlen(ib);int lenfb = strlen(fb);
	int maxleni = max(lenia,lenib);
	int maxlenf = max(lenfa,lenfb);
	int sumi[N],sumf[N];
	memset(sumi,0,sizeof(sumi));
	memset(sumf,0,sizeof(sumf));
	for(int i = maxlenf + 1; i > 0; i--) {
		sumf[i] += (ta.decimal[i] + tb.decimal[i]);
		if(sumf[i] >= 10) {
			sumf[i - 1] += sumf[i]/10;
			sumf[i] = sumf[i]%10;
		}
	}
	int cnt = maxlenf + 1;
	for(int i = maxlenf + 1; i > 0; i--) {
		if(sumf[i] == 0) {
			cnt--;
		}
		else {
			break;
		}
	}
	if(sumf[0] > 0) {
		sumi[0] += sumf[0];
	}
	for(int i = 0; i < maxleni; i++) {
		sumi[i] += (ta.integer[i] + tb.integer[i]);
		if(sumi[i] >= 10) {
			sumi[i + 1] += sumi[i]/10;
			sumi[i] = sumi[i]%10;
		}
	}
	if(sumi[maxleni] > 0) {
		printf("%d",sumi[maxleni]);
	}
	for(int i = maxleni -1; i >= 0; i--) {
		printf("%d",sumi[i]);
	}
	if(cnt) {
		printf(".");
	}
	for(int i = 1; i < cnt + 1; i++) {
		printf("%d",sumf[i]);
	}
	printf("\n");

}
int main() {
	char a[N],b[N];
	while(scanf("%s%s",a,b) != EOF) {
		add(a,b);
	}
	return 0;
}
