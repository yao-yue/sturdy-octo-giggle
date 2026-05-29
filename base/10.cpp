// patA1025
// 考场信息录入并且进行排序
// 掌握信息输出  排序基本

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    char id[15];
    int score;
    int location_number; // 考场号
    int local_rank;      // 考场排名
} stu[10010];

bool cmp(Student a, Student b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.id, b.id) < 0; // 基本用法  字典序降序
}

int main()
{
    int n, k, num = 0;
    printf("输入考场数量: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("输入%d考场的人数: ", i);
        scanf("%d", &k);
        printf("输入%d考场的id及其分数: ", i);
        for (int j = 0; j < k; j++)
        {
            //stu[num].score 是变量的值，不是地址，所以必须用 & 取地址。 传入的是值所以需要取地址
            //字符数组	char id[15]	❌ 不需要	数组名本身就是地址
            scanf("%s %d", stu[num].id, &stu[num].score);
            stu[num].location_number = i;
            num++;
        }
        // C++ 使用 左闭右开区间 [begin, end)
        //  sort(stu + num - k, stu + num, cmp);
        //       ↑ 起始位置      ↑ 结束位置（不包含）
        sort(stu + num - k, stu + num, cmp); // 将该考场的考生进行排序 从 num-k 到 num-1）
        stu[num - k].local_rank = 1;         // 将考场第一名的人的rank设置为1
        for (int j = num - k + 1; j < num; j++)
        {
            // 与前一名考生对比，同分的rank一致
            if (stu[j].score == stu[j - 1].score)
            {
                stu[j].local_rank = stu[j - 1].local_rank;
            }
            // 不同分的rank 为该考场内前面考生的人数  num-k为之前所有考场的人数
            else
                // j：当前考生在全局数组中的索引
                //  num - k：当前考场第一个考生在全局数组中的索引
                //  j - (num - k)：当前考生在考场内的相对位置（从0开始）
                //  +1：转换为排名（从1开始
                stu[j].local_rank = j + 1 - (num - k);
        }
    }
    printf("总考生人数为： %d\n", num); // 输出总考生人数
    std::sort(stu, stu + num, cmp);
    int r = 1;
    printf("总排名\t准考证号\t总分\t考场号\t考场内排名\n");
    for (int i = 0; i < num; i++)
    {
        if (i > 0 && stu[i].score != stu[i - 1].score)
        {
            r = i + 1;
        }
        printf("%d\t%s\t%d\t%d\t%d\n", r, stu[i].id, stu[i].score,
               stu[i].location_number, stu[i].local_rank);
    }
    return 0;
}
/*
输出示例：
总考生人数为： 10
总排名  准考证号        总分    考场号  考场内排名
1       123456789007    100     2       1
2       123456789002    98      1       1
2       123456789010    98      3       1
4       123456789001    95      1       2
5       123456789008    88      3       2
6       123456789005    86      1       3
7       123456789009    75      3       3
8       123456789003    61      1       4
9       123456789004    53      1       5
10      123456789006    45      2       2
*/