/**
 * 区间贪心
 */

#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 110;
struct Interval {
    int x, y;
} I[maxn];
bool cmp(Interval a, Interval b) {
    // 先按左端点从大到小排序
    // 左端点相同的 右端点从小到大优先。
    if (a.x != b.x)
        return a.x > b.x;
    else
        return a.y < b.y;
}

int main() {
    int n;
    while (scanf("%d", &n), n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &I[i].x, &I[i].y);
        }
        std::sort(I, I + n, cmp);
        // res 记录不相交的区间个数  lastx来记录上一个被选中区间的左端点
        int res = 1, lastx = I[0].x;
        for (int i = 1; i < n; i++) {
            if (I[i].y <= lastx) {
                lastx = I[i].x;
                res++;
            }
        }
        printf("有%d个区间没有交集\n", res);
    }
    return 0;
}