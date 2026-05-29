// n皇后问题
// 求合法的方案数
// 回溯

#include <cstdio>
#include <algorithm>

const int maxn = 11;
int count = 0;
int n, P[maxn], hashTable[maxn] = {false};
void generateP(int index)
{
    if (index == n + 1)
    {
        bool flag = true;
        // i是行 j是他的下一行  遍历任意两个皇后
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (abs(i - j) == abs(P[i] - P[j]))
                {
                    flag = false;
                }
            }
        }
        if (flag)
            count++;
        return;
    }
    // 对当前index列 进行每一行的试探
    for (int x = 1; x <= n; x++)
    {
        if (hashTable[x] == false)
        {
            P[index] = x;
            hashTable[x] = true;
            generateP(index + 1);
            hashTable[x] = false;
        }
    }
}

// 回溯法
void generatePro(int index)
{
    if (index == n + 1)
    {
        count++;
        return;
    }
    for (int x = 1; x <= n; x++)
    {
        if (hashTable[x] == false)
        {
            bool flag = true;
            // 遍历之前的皇后  pre为列  对应的x为行
            for (int pre = 1; pre <index; pre++)
            {
                if (abs(index - pre) == abs(x - P[pre])) {
                    //与之前的皇后在一条直线上，冲突
                    flag = false;
                    break;
                }
            }
            if(flag) {
                    //index列对应x行
                    P[index] = x;
                    hashTable[x] = true;
                    generatePro(index +1);
                    hashTable[x] = false;
                }
        }
    }
}

int main()
{
    n = 5;
    generateP(1);
    printf("%d皇后对应的合法方案数为: %d \n", n, count);
    n = 8;
    count = 0;
    generatePro(1);
    printf("%d皇后对应的合法方案数为(回溯法): %d", n, count);
    return 0;
}


/*总结
回溯法：
核心三部曲：选择、递归、撤销选择（彻底清理当前选择的影响，为尝试下一个选项做准备。）
递归函数写对了
状态重置别忘了
边界条件处理好
*/