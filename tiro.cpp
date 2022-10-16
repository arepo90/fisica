#include "headers.h"

void getData(){
    cout << "Masa: "; cin >> m;
    cout << "Gravedad (+): "; cin >> g; g *= -1;
    cout << "Constante del resorte: "; cin >> k;
    cout << "Altura del objetivo: "; cin >> hf;
    cout << "Altura del disparador: "; cin >> h0;
    cout << "Distancia: "; cin >> L;
}

int main(){
    getData();
    solve1();
    if(safetyCheck()){
        cout << "Error, intentando segundo metodo...\n";   
        solve2();
    }
    cout << "Angulo: " << a << " Compresion: " << x << "\nDebug? (y/n) ";
    char op; cin >> op;
    if(op == 'y') cout << "Tiempo: " << t << "\nVelocidad inicial: " << vi << "\nVix: " << vix << "\nViy: " << viy << "\nDelta Y: " << h << '\n';
    return 0;
}