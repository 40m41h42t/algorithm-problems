#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct child_info
{
    int pre;
    int num;
    int next;
} child[1002];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 2; i < n; ++i)
    {
        child[i].pre = i - 1;
        child[i].next = i + 1;
        child[i].num = i;
    }
    child[1].pre = n, child[1].num = 1, child[1].next = 2;
    child[n].pre = n - 1, child[n].num = n, child[n].next = 1;
    int i = 1, cnt = 1;
    while (true)
    {
        if (i % k == 0 || i % 10 == k)
        {
            child[child[cnt].pre].next = child[cnt].next;
            child[child[cnt].next].pre = child[cnt].pre;
        }
        i++;
        if (child[cnt].num == child[child[cnt].next].num)
            break;
        cnt = child[cnt].next;
    }
    cout << child[cnt].num << endl;
    return 0;
    //system("pause");
}