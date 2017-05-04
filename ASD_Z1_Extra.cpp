#include <iostream>
#include <cstdio>
#define gc getchar_unlocked

using namespace std;

int wielkosc;
int liczba;
char c;
bool finish;

void scan_integer( int &x )
{
    register int c = getchar();
    x = 0;
    for( ; ((c<48 || c>57)); c = getchar() );
    for( ;c>47 && c<58; c = getchar() ) {
        x = (x << 1) + (x << 3) + c - 48;
        wielkosc++;
    }
}


int main()
{
    int n = 0;

    scan_integer(n);

    int num=0, max=0, min=0, index=0;
    long long int fuel = 0;


    for(int i = 0; i < n; i++) {
        scan_integer(num);
        fuel += num;
        scan_integer(num);
        fuel -= num;

        if(fuel > max)
            max = fuel;
        if(fuel < min) {
            min = fuel;
            index = i;
        }
    }


            cout << index + 1 << " " << max - min << endl;
            cout << wielkosc;
    return 0;
}
