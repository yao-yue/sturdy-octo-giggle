//找x

#include <cstdio>
const int maxn = 210;
int a[maxn] ;
int main() {
    int n,x;
    printf("please input a num of n:");
    scanf("%d",&n);
    printf("please input different num of n:");
    while (n!=EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
            /* code */
        }
        printf("please input the num what you want find: ");
        scanf("%d",&x);
        int k;
        for ( k = 0; k< n; k++)
        {
            if(a[k] == x) {
                printf("find the num index is: %d\n",k);
                break;
            }
        }
        if(k==n){
            printf("-1\n");
        }
        
    }
    
    return 0;
}