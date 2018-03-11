#include <iostream>  
#include <algorithm>  
  
using namespace std;  
  
#define MAXN 10000  
  
struct Ant  
{  
    int id;     //输入次序编号  
    int origin; //起点位置  
    int dir;    //朝向，-1代表向左，0代表转向中，1代表向右  
    int dest;   //终点位置  
    bool operator < (const Ant &a) const  
    {  
        return origin < a.origin;  
    }  
}ants[MAXN+5];  
  
char dirName[][10] = {"L", "Turning", "R"};  
  
int order[MAXN+5];  
  
void Swap(int i, int j) //除了id号，交换蚂蚁的所有信息  
{  
    Ant tmp = ants[i];  
    ants[i] = ants[j];  
    ants[i].id = tmp.id;  
    tmp.id = ants[j].id;  
    ants[j] = tmp;  
}  
  
int main(void)  
{  
    int ncases;  
    cin >> ncases;  
  
    int caseID = 1;  
    while (ncases-- != 0)  
    {  
        int l, t, n;  
        cin >> l >> t >> n;  
  
        int i, j;  
        for (i = 0; i < n; i++)  
        {  
            char dir;  
            cin >> ants[i].origin >> dir;  
  
            ants[i].id = i;  
            ants[i].dir = (dir == 'L' ? -1 : 1);  
            ants[i].dest = ants[i].origin + ants[i].dir*t;  
        }  
  
        sort(ants, ants+n); //按照起点位置从小到大排序  
  
        bool finish = false;  
        while (!finish)  
        {  
            finish = true;  
            for (i = 0, j = 1; j < n; i++, j++)  
            {  
                if (ants[i].dir == 1 && ants[j].dir == -1 //只有相向而行的蚂蚁才可能交换信息  
                    && ants[i].origin < ants[j].origin && ants[i].dest > ants[j].dest) //交换位置和方向的条件  
                {  
                    Swap(i, j);  
                    finish = false;  
                }  
            }  
        }  
        //更改正在相遇中的蚂蚁朝向  
        for (i = 0, j = 1; j < n; i++, j++)  
        {  
            if (ants[i].dest == ants[j].dest)  
            {  
                ants[i].dir = ants[j].dir = 0;  
            }  
        }  
        //记录输出次序  
        for (i = 0; i < n; i++)  
        {  
            order[ants[i].id] = i;  
        }  
          
        cout << "Case #" << caseID++ << ":" << endl;  
        for (i = 0; i < n; i++)  
        {  
            int j = order[i];  
            if (ants[j].dest < 0 || ants[j].dest > l)  
            {  
                cout << "Fell off" << endl;  
            }  
            else  
            {  
                cout << ants[j].dest << ' ' << dirName[ants[j].dir+1] << endl;  
            }  
        }  
        cout << endl;  
    }  
    return 0;  
}  
