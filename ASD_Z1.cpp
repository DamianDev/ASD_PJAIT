#include <iostream>
#include <cstdio>

using namespace std;

int wielkosc;
int liczba;
char c;
bool finish;


inline int read() {
	liczba = 0;
	c = getchar();
	while (c != 32 && c != 10) {
		wielkosc++;
		liczba = liczba * 10 + c - '0';
		c = getchar();
	}
	if(c == 10)
        finish = false;
	return liczba;
}

int main()
{
    finish = true;


    //Variables
    int num = 0;
    int prev = -1;

    long long int countAsc = 0;
    long long int countDsc = 0;
    long long int countMax = 0;

    long long int sumAsc = 0;
    long long int sumDsc = 0;
    long long int sumMax = 0;

    //Init
    prev = read();

    countAsc = 1;
    countDsc = 1;
    sumAsc = prev;
    sumDsc = prev;



    while(finish) {

        num = read();

        if(prev == num){
            countAsc++;
            countDsc++;
            sumAsc += num;
            sumDsc += num;
            continue;
        }
        else if(prev > num) {

            if(countAsc > countMax) {
                countMax = countAsc;
                sumMax = sumAsc;
            }
            countAsc = 1;
            sumAsc = num;

            countDsc++;
            sumDsc += num;
            prev = num;
        }
        else {

            if(countDsc > countMax) {
                countMax = countDsc;
                sumMax = sumDsc;
            }
            countDsc = 1;
            sumDsc = num;

            countAsc++;
            sumAsc += num;
            prev = num;
        }
    }

    if(countAsc > countMax) {
        countMax = countAsc;
        sumMax = sumAsc;
    }

    if(countDsc > countMax) {
        countMax = countDsc;
        sumMax = sumDsc;
    }


    cout << countMax << " " << sumMax << endl;
    cout << wielkosc;

    return 0;
}
