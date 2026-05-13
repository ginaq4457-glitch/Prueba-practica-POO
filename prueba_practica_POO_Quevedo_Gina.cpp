#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

string obtenerFecha() {
    time_t t = time(0); tm *m = localtime(&t);
    char b[20]; strftime(b, 20, "%d/%m/%Y %H:%M", m);
    return string(b);
}

void mostrarPortada() {
    cout << "==========================================================" << endl;
    cout << "          UNIVERSIDAD TECNICA DE AMBATO" << endl;
    cout << "   Facultad de Ingenieria en Sistemas e Industrial" << endl;
    cout << "           Carrera de Software - Algoritmos" << endl;
    cout << "==========================================================" << endl;
    cout << "          APLICATIVO DE GESTION ACADEMICA" << endl;
    cout << "==========================================================" << endl;
}

void registrarNotas() {
    string nombres[] = {
        "ACOSTA SOLIS HANNA AIDE", "ANDRADE SANCHEZ HUGO ALEXANDER", "ATIENCIA CHERRES JOSUE ALEXANDER",
        "BALAREZO PEREZ DIEGO SEBASTIAN", "BARRIONUEVO MONTESDEOCA JOB GABRIEL", "BEDOYA MAZO JUAN MANUEL",
        "BRAVO LOPEZ JORDAN SAMUEL", "CAJIAO VALDIVIESO PAULO ALESSANDRO", "CALVOPIÑA HERRERA BRANDON ISRAEL",
        "CASTELO BERRONES KATHERINE NICOL", "CHACHA CHANGO VICTOR MANUEL", "CHILUIZA QUISHPE DIEGO STEED",
        "DOMINGUEZ LESCANO DANIEL SEBASTIAN", "FREIRE AREBALO ALAN ANDERSON", "GUALLE AUCANSHALA ABISAG LISENIA",
        "GUAMAN CHANAHUANO HAMILTON ALEXANDER", "GUANGA ALTAMIRANO EDWIN SEBASTIAN", "GUANOTOA ESCOBAR KARLA LEONELA",
        "LANDETA TAPIA EDISON PAUL", "LARA BALSECA KAREN ARACELY", "LOOR VELEZ JHON ALEJANDRO",
        "LOPEZ SANCHEZ WASHINGTON STEVEN", "MIRANDA GARCES ALAN IMANOL", "MONAR PARCO JHAIR ALEXANDER",
        "MUYULEMA MOYOLEMA MATEO ALEXANDER", "NARVAEZ GAVILANES ANTONELLA NICOLE", "NUÑEZ ESPIN BRYAN SEBASTIAN",
        "PILCO FLORES MARIO DAVID", "POMAQUERO CHANGO KATHERINE SOLEDAD", "QUEVEDO GINA ANAHI",
        "RIVADENEYRA ULLOA MATIAS SEBASTIAN", "ROCHA ROCHA CAROLINA ESTEFANIA", "SANCHEZ LEMA ISAAC ADRIAN",
        "SEGOVIA GARCIA JOSEPH ANDRE", "SUPE GARCES JOAN SEBASTIAN", "TOAPANTA IZA KEVIN MATIAS",
        "VERDESOTO AZOGUE KEVIN ALEXANDER", "VILLACRES TOALOMBO JOSUE ALEJANDRO", "VITERI CAMINO MAYDELIN SHANTAL"
    };

    double nt[5], suma, mayor, menor;
    int ap; char op;
    ofstream arch("resultados.txt", ios::app);

    for(int j = 0; j < 39; j++) {
        suma = 0; ap = 0;
        cout << "\n>>> REGISTRO: " << nombres[j] << " (" << j + 1 << "/39)" << endl;

        for(int i = 0; i < 5; i++) {
            do {
                cout << "    Nota " << i + 1 << ": "; cin >> nt[i];
            } while(nt[i] < 0 || nt[i] > 10);
            suma += nt[i];
            if(nt[i] >= 7) ap++;
            if(i == 0) { mayor = nt[0]; menor = nt[0]; }
            if(nt[i] > mayor) mayor = nt[i];
            if(nt[i] < menor) menor = nt[i];
        }

        double prom = suma / 5.0;
        arch << left << setw(35) << nombres[j]
             << " | PROMEDIO: " << fixed << setprecision(2) << setw(5) << prom
             << " | MAX: " << mayor << " | MIN: " << menor
             << " | FECHA: " << obtenerFecha() << endl;

        cout << "\n--- RESUMEN ACTUAL ---" << endl;
        cout << " Estudiante: " << nombres[j] << endl;
        cout << " Promedio: " << prom << endl;
        cout << " Aprobadas: " << ap << endl;

        cout << "\n¿Continuar con el siguiente? (s/n): "; cin >> op;
        if(op == 'n' || op == 'N') break;
    }
    arch.close();
}

int main() {
    int opcion;
    mostrarPortada();
    do {
        cout << "\n[ MENU DE OPCIONES ]" << endl;
        cout << "1. Operaciones Matematicas" << endl;
        cout << "2. Registro de Calificaciones" << endl;
        cout << "3. Finalizar Programa" << endl;
        cout << "Seleccione: ";
        if (!(cin >> opcion)) { cin.clear(); cin.ignore(1000, '\n'); continue; }

        if(opcion == 2) registrarNotas();
    } while(opcion != 3);

    cout << "\nGracias por usar el sistema. Saliendo..." << endl;
    return 0;
}
