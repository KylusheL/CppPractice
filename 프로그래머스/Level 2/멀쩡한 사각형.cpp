#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if(b % a == 0) return a;
    else return gcd(a, b - a);
}

long long solution(int w,int h) {
    long long answer = (long long)w * (long long)h;
    int g = gcd(w, h);
    w /= g;
    h /= g;
    int i = 1, j = 1, whiteSpace = 0;
    while(i <= w) {
        whiteSpace++;
        if((long long)i * (long long)h <= (long long)w * (long long)j) i++;
        else j++;
    }
    answer -= (long long)whiteSpace * (long long)g;
    return answer;
}
