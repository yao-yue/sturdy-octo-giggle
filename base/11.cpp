//斐波那契函数 递归

#include <cstdio>

int Fiborrchi(int n) {
    if(n==0 || n==1) return 1;
    else return Fiborrchi(n-1) + Fiborrchi(n-2);
}

int main() {
    int n;
    printf("请输入fiboriich数字：");
    scanf("%d",&n);
    printf("feiborrchi(%d)的结果：%d",n, Fiborrchi(n));
    return 0;
}