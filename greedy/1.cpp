// 简单贪心  月饼
// 总是考虑在当前情况下最优

#include <algorithm>
#include <cstdio>
using namespace std;

struct mooncake {
    double store;
    double sell;
    double price;
} cake[1010];

bool cmp(mooncake a, mooncake b) {
    if (a.price != b.price) {
        return a.price > b.price;
    } else {
        return a.store > b.store;
    }
}

int main() {
    int n;
    double D;
    scanf("%d %lf", &n, &D);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &cake[i].store);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &cake[i].sell);
        //避免除0误差
        if(cake[i].store==0) {
            cake[i].price = 0;
        }else {
            cake[i].price = cake[i].sell / cake[i].store;
        }
    }
    std::sort(cake, cake + n, cmp);
    double res = 0;
    for (int i = 0; i < n; i++) {
        // 如果需求量高于月饼库存
        if (cake[i].store -D <= 1e-8) {
            D -= cake[i].store;
            res += cake[i].sell;
        } else {
            res += cake[i].price * D;
            break;
        }
    }
    printf("赚取利润为：%0.2f\n", res);
    return 0;
}

/**
 *
 * note:
 * %lf:是什么意思  %lf 是 C/C++ 中用于 double 类型的格式化符号  %f是单精度浮点
 * %0.2f  是小数点后面保留2位
 * 格式符	示例输出 (num=3.14)	说明
    %f	3.140000	默认6位小数
    %.2f	3.14	2位小数
    %5.2f	" 3.14"	宽度5，空格填充
    %05.2f	03.14	宽度5，0填充   //%05.2f 中的 5 是总宽度，包括：所有数字、小数点、负号（如果有）
    %-5.2f	3.14 "	左对齐
    %+5.2f	+3.14	显示正号
    % 5.2f	3.14	正号位置为空格
 * break是退出一个循环，如果在两个for循环里面呢？只会跳出它所在的那一层循环，不会跳出外层循环。
 */