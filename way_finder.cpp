#include<iostream>
using namespace std;

int a[] = {0,0},b[] = {0,8};
int c[] = {0,4};

void checkx()
{
    if(a[0]>b[0])
    {
        a[0] = a[0] - 1;
    }else
    {
        a[0] = a[0] + 1;
    }
}
void checky()
{
    if(a[1]>b[1])
    {
        a[1] = a[1] - 1;
    }else
    {
        a[1] = a[1] + 1;
    }
}
int main()
{
    if(a[0] == c[0] && a[1] == c[1])
    {
        cout<<"Error: Obstacle at the entrance";
        return 0;
    }
    if(b[0] == c[0] && b[1] == c[1])
    {
        cout<<"Error: Obstacle at the destination";
        return 0;
    }
    int count = 0;
    string str = "";
    str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
    int dirx,diry;
    while(a[0] != b[0] || a[1] != b[1])
    {
        dirx=0;diry=0;
        if(a[1]>=b[1])
        {
            if(a[1] == b[1])
            {
                dirx = 1;
            }else
            {
                dirx = 0;
            }
        }
        else
        {
            dirx = 2;
        }x:
        if(b[1] == c[1])
        {
            if(dirx == 2 && (a[1]+1 != c[1] || a[0] != c[0]) && a[0] >= b[0])
            {
                a[1] = a[1] + 1;
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
            }
            else if(dirx == 2 && a[1]+1 == c[1])
            {
                checkx();
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
                goto x;
            }
            else if(dirx == 0 && (a[1]-1 != c[1] || a[0] != c[0]) && a[0] >= b[0])
            {
                a[1] = a[1] - 1;
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
            }
            else if(dirx == 0 && a[1]-1 == c[1])
            {
                checkx();
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
                goto x;
            }
        }
        else
        {
            if(dirx == 2 && (a[1]+1 != c[1] || a[0] != c[0]))
            {
                a[1] = a[1] + 1;
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
            }
            else if(dirx == 2 && a[1]+1 == c[1])
            {
                checkx();
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
                goto x;
            }
            else if(dirx == 0 && (a[1]-1 != c[1] || a[0] != c[0]))
            {
                a[1] = a[1] - 1;
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
            }
            else if(dirx == 0 && a[1]-1 == c[1])
            {
                checkx();
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
                goto x;
            }
        }
        if(a[0]>=b[0])
        {
            if(a[0] == b[0])
            {
                diry = 1;
            }else
            {
                diry = 0;
            }
        }
        else
        {
            diry = 2;
        }y:
        if(b[0] == c[0])
        {
            if(diry == 2 && (a[0]+1 != c[0] || a[1] != c[1]) && a[1] >= b[1])
            {
                a[0] = a[0] + 1;
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
            }
            else if(diry == 2 && a[0]+1 == c[0])
            {
                checky();
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
                goto y;
            }
            else if(diry == 0 && (a[0]-1 != c[0] || a[1] != c[1]) && a[1] >= b[1])
            {
                a[0] = a[0] - 1;
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
            }
            else if(diry == 0 && a[0]-1 == c[0])
            {
                checky();
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
                goto y;
            }
        }
        else
        {
            if(diry == 2 && (a[0]+1 != c[0] || a[1] != c[1]))
            {
                a[0] = a[0] + 1;
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
            }
            else if(diry == 2 && a[0]+1 == c[0])
            {
                checky();
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
                goto y;
            }
            else if(diry == 0 && (a[0]-1 != c[0] || a[1] != c[1]))
            {
                a[0] = a[0] - 1;
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
            }
            else if(diry == 0 && a[0]-1 == c[0])
            {
                checky();
                str = str + to_string(a[0]) + "," + to_string(a[1]) + "\n";
                count++;
                goto y;
            }
        }
    }
    cout<<"PATH\n"<<str;
    cout<<"COUNT:"<<count;
    return 0;
}
