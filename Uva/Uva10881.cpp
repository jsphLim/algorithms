#include <iostream>  
#include <algorithm>  
  
using namespace std;  
  
#define MAXN 10000  
  
struct Ant  
{  
    int id;     //���������  
    int origin; //���λ��  
    int dir;    //����-1��������0����ת���У�1��������  
    int dest;   //�յ�λ��  
    bool operator < (const Ant &a) const  
    {  
        return origin < a.origin;  
    }  
}ants[MAXN+5];  
  
char dirName[][10] = {"L", "Turning", "R"};  
  
int order[MAXN+5];  
  
void Swap(int i, int j) //����id�ţ��������ϵ�������Ϣ  
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
  
        sort(ants, ants+n); //�������λ�ô�С��������  
  
        bool finish = false;  
        while (!finish)  
        {  
            finish = true;  
            for (i = 0, j = 1; j < n; i++, j++)  
            {  
                if (ants[i].dir == 1 && ants[j].dir == -1 //ֻ��������е����ϲſ��ܽ�����Ϣ  
                    && ants[i].origin < ants[j].origin && ants[i].dest > ants[j].dest) //����λ�úͷ��������  
                {  
                    Swap(i, j);  
                    finish = false;  
                }  
            }  
        }  
        //�������������е����ϳ���  
        for (i = 0, j = 1; j < n; i++, j++)  
        {  
            if (ants[i].dest == ants[j].dest)  
            {  
                ants[i].dir = ants[j].dir = 0;  
            }  
        }  
        //��¼�������  
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
