#include <cstdio>
const int maxn = 100010;
int school[maxn] = {0};  
int main() {
    int n,schID,score;
    printf("please inout school num:");
    scanf("%d", &n);
    printf("school score entry:\n");
    for(int i = 0; i<n; i++) {
        scanf("%d%d",&schID,&score);
        school[schID] += score; 
    }
    int k = 1,MAX = -1;
    for(int i  = 1; i<= n; i++) {
        if(school[i]>MAX) {
            MAX = school[i];
            k = i;
        }
    }
    printf("总分最高的学校id及总分：%d %d\n",k,MAX);
    return 0;
}
