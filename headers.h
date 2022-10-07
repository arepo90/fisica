#include <bits/stdc++.h>
using namespace std;

double m, g, k, L, hf, h0, h, t, vix, viy, vi, a, x, mR;
double d, f, G, H, R, S, T, U, x1, x2;

double findF(double a, double b, double c){
    return ((3.0 * c / a) - ((b * b) / (a * a))) / 3.0;
}

double findG(double a, double b, double c, double d){
    return (((2.0 * (b * b * b)) / (a * a * a)) - ((9.0 * b * c) / (a * a)) + (27.0 * d / a)) /27.0;
}

double findH(double G, double f){
    return ((G * G) / 4.0 + (f * f * f) / 27.0);
}

void solveTime(){   
    double a = 12, b = 5, c = 3, d = (10.0 - L);

    f = findF(a, b, c);
    G = findG(a, b, c, d);
    H = findH(G, f);                        
        
    if(H <= 0){                             
        double i = sqrt(((G * G) / 4.0) - H); 
        double j = pow(i, (1 / 3.0));                      
        double k = acos(-(G / (2 * i)));           
        double L = j * -1.0;                              
        double M = cos(k / 3.0);                   
        double N = sqrt(3) * sin(k / 3.0);  
        double P = (b / (3.0 * a)) * -1.0;              
        double x1 = 2 * j * cos(k / 3.0) - (b / (3.0 * a));
        double x2 = L * (M + N) + P;
        double x3 = L * (M - N) + P;

        t = x1;
    }
    else{
        double R = -1.0 * (G / 2.0) + sqrt(H), S;

        if (R >= 0) S = pow(R, (1 / 3.0));
        else S = pow((-1.0 * R), (1 / 3.0)) * -1.0;

        double T = -1.0 * (G / 2.0) - sqrt(H), U;

        if(T >= 0) U = (pow(T, (1 / 3.0)));
        else U = (pow((-1.0 * T), (1 / 3.0))) * -1.0;

        double x1 = (S + U) - (b / (3.0 * a));
        double x2 = -1.0 * (S + U) / 2 - (b / (3.0 * a)) + (S - U) * sqrt(3) * 0.5;
        double x3 = -1.0 * (S + U) / 2 - (b / (3.0 * a)) - (S - U) * sqrt(3) * 0.5;

        t = x1;
    }
}

void solveQ(double A, double B, double C){
    double discriminant = (B * B) - (4 * A * C);
    if(discriminant > 0){
        x1 = (-B + sqrt(discriminant)) / (2.0 * A);
        x2 = (-B - sqrt(discriminant)) / (2.0 * A);
    }
    else{
        x1 = -B / (2.0 * A);
        x2 = x1;
    }
}

//Todavia no jala
void solve1(){
    h = hf - h0;
    vi = 1.0 / sqrt(m / k);
    mR = vi * vi / g * -1;
    double temp = 0.5 * -g * pow((L / vi), 2.0);
    cout << '\n' << temp << " " << -L << " " << (temp + h) << '\n';
    solveQ(temp, -L, (temp + h));
    cout << x1 * 180.0 / M_PI << " " << x2 * 180.0 / M_PI << '\n';
}

void solve2(){
    solveTime();
    h = hf - h0;
    vix = L / t;
    viy = -1.0 * ((0.5 * g * t * t) - h) / t;
    vi = sqrt((vix * vix) + (viy * viy));
    a = atan(viy / vix) * 180.0 / M_PI;
    x = vi * sqrt(m / k);
}