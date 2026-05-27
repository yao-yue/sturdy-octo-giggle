// D进制的A+B

#include <cstdio>

int main() {
    int a,b,d;
    scanf("%d%d%d",&a,&b,&d);
    int sum = a + b;
    int ans[31], nums = 0;
    do {
        ans[nums++] = sum % d;
        sum /= d;
    }while(sum != 0);
    //逆序输出ans数组
    for(int i = nums -1;i>=0;i--) {
        printf("%d",ans[i]);
    }
    return 0;
}