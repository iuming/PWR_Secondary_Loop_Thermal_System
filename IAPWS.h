#pragma once
#ifndef IAPWS_H
#define IAPWS_H

#include "Python.h"
#include<fstream>

using namespace std;

double Calculate_Saturation_Temperature(double pressure) {
    double temperature;
    ofstream Pressure_Output;
    Pressure_Output.open("pressure.txt");
    Pressure_Output << pressure;
    Pressure_Output.close();
    PyRun_SimpleString("f=open('pressure.txt','r')");
    PyRun_SimpleString("Pressure=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('temperature.txt','w',encoding='utf8')");
    PyRun_SimpleString("s=str(IAPWS97(P=Pressure, x=0).T)");
    PyRun_SimpleString("f.write(s)");
    PyRun_SimpleString("f.close()");
    ifstream fin;
    fin.open("temperature.txt");
    fin >> temperature;
    fin.close();
    return temperature - 273.15;
}

double Calculate_Temperature_ph(double pressure, double enthalpy) {
    double temperature;
    ofstream Pressure_Output;
    Pressure_Output.open("pressure.txt");
    Pressure_Output << pressure;
    Pressure_Output.close();
    ofstream Enthalpy_Output;
    Enthalpy_Output.open("enthalpy.txt");
    Enthalpy_Output << enthalpy;
    Enthalpy_Output.close();
    PyRun_SimpleString("f=open('pressure.txt','r')");
    PyRun_SimpleString("Pressure=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('enthalpy.txt','r')");
    PyRun_SimpleString("Enthalpy=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('Temperature.txt','w',encoding='utf8')");
    PyRun_SimpleString("s=str(IAPWS97(P=Pressure, h=Enthalpy).T)");
    PyRun_SimpleString("f.write(s)");
    PyRun_SimpleString("f.close()");
    ifstream fin;
    fin.open("Temperature.txt");
    fin >> temperature;
    fin.close();
    return temperature - 273.15;
}

double Calculate_Saturation_Pressure(double temperature) {
    double pressure;
    ofstream Pressure_Output;
    Pressure_Output.open("temperature.txt");
    Pressure_Output << temperature + 273.15;
    Pressure_Output.close();
    PyRun_SimpleString("f=open('temperature.txt','r')");
    PyRun_SimpleString("Temperature=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('pressure.txt','w',encoding='utf8')");
    PyRun_SimpleString("s=str(IAPWS97(T=Temperature, x=0).P)");
    PyRun_SimpleString("f.write(s)");
    PyRun_SimpleString("f.close()");
    ifstream fin;
    fin.open("pressure.txt");
    fin >> pressure;
    fin.close();
    return pressure;
}

double Calculate_Enthalpy_pt(double pressure, double temperature) {
    double enthalpy;
    ofstream Pressure_Output;
    Pressure_Output.open("pressure.txt");
    Pressure_Output << pressure;
    Pressure_Output.close();
    ofstream Temperature_Output;
    Temperature_Output.open("temperature.txt");
    Temperature_Output << temperature + 273.15;
    Temperature_Output.close();
    PyRun_SimpleString("f=open('pressure.txt','r')");
    PyRun_SimpleString("Pressure=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('temperature.txt','r')");
    PyRun_SimpleString("Temperature=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('enthalpy.txt','w',encoding='utf8')");
    PyRun_SimpleString("s=str(IAPWS97(T=Temperature, P=Pressure).h)");
    PyRun_SimpleString("f.write(s)");
    PyRun_SimpleString("f.close()");
    ifstream fin;
    fin.open("enthalpy.txt");
    fin >> enthalpy;
    fin.close();
    return enthalpy;
}

double Calculate_Enthalpy_px(double pressure, double dryness) {
    double enthalpy;
    ofstream Pressure_Output;
    Pressure_Output.open("pressure.txt");
    Pressure_Output << pressure;
    Pressure_Output.close();
    ofstream Temperature_Output;
    Temperature_Output.open("dryness.txt");
    Temperature_Output << dryness;
    Temperature_Output.close();
    PyRun_SimpleString("f=open('pressure.txt','r')");
    PyRun_SimpleString("Pressure=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('dryness.txt','r')");
    PyRun_SimpleString("Dryness=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('enthalpy.txt','w',encoding='utf8')");
    PyRun_SimpleString("s=str(IAPWS97(P=Pressure, x=Dryness).h)");
    PyRun_SimpleString("f.write(s)");
    PyRun_SimpleString("f.close()");
    ifstream fin;
    fin.open("enthalpy.txt");
    fin >> enthalpy;
    fin.close();
    return enthalpy;
}

double Calculate_Enthalpy_tx(double temperature, double dryness) {
    double enthalpy;
    ofstream Pressure_Output;
    Pressure_Output.open("temperature.txt");
    Pressure_Output << temperature + 273.15;
    Pressure_Output.close();
    ofstream Temperature_Output;
    Temperature_Output.open("dryness.txt");
    Temperature_Output << dryness;
    Temperature_Output.close();
    PyRun_SimpleString("f=open('temperature.txt','r')");
    PyRun_SimpleString("Temperature=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('dryness.txt','r')");
    PyRun_SimpleString("Dryness=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('enthalpy.txt','w',encoding='utf8')");
    PyRun_SimpleString("s=str(IAPWS97(T=Temperature, x=Dryness).h)");
    PyRun_SimpleString("f.write(s)");
    PyRun_SimpleString("f.close()");
    ifstream fin;
    fin.open("enthalpy.txt");
    fin >> enthalpy;
    fin.close();
    return enthalpy;
}

double Calculate_Enthalpy_ps(double pressure, double entropy) {
    double enthalpy;
    ofstream Pressure_Output;
    Pressure_Output.open("pressure.txt");
    Pressure_Output << pressure;
    Pressure_Output.close();
    ofstream Temperature_Output;
    Temperature_Output.open("entropy.txt");
    Temperature_Output << entropy;
    Temperature_Output.close();
    PyRun_SimpleString("f=open('pressure.txt','r')");
    PyRun_SimpleString("Pressure=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('entropy.txt','r')");
    PyRun_SimpleString("Entropy=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('enthalpy.txt','w',encoding='utf8')");
    PyRun_SimpleString("s=str(IAPWS97(P=Pressure, s=Entropy).h)");
    PyRun_SimpleString("f.write(s)");
    PyRun_SimpleString("f.close()");
    ifstream fin;
    fin.open("enthalpy.txt");
    fin >> enthalpy;
    fin.close();
    return enthalpy;
}

double Calculate_Dryness(double pressure, double enthalpy) {
    double dryness;
    ofstream Pressure_Output;
    Pressure_Output.open("pressure.txt");
    Pressure_Output << pressure;
    Pressure_Output.close();
    ofstream Enthalpy_Output;
    Enthalpy_Output.open("enthalpy.txt");
    Enthalpy_Output << enthalpy;
    Enthalpy_Output.close();
    PyRun_SimpleString("f=open('pressure.txt','r')");
    PyRun_SimpleString("Pressure=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('enthalpy.txt','r')");
    PyRun_SimpleString("Enthalpy=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('dryness.txt','w',encoding='utf8')");
    PyRun_SimpleString("s=str(IAPWS97(P=Pressure, h=Enthalpy).x)");
    PyRun_SimpleString("f.write(s)");
    PyRun_SimpleString("f.close()");
    ifstream fin;
    fin.open("dryness.txt");
    fin >> dryness;
    fin.close();
    return dryness;
}

double Calculate_Entropy(double pressure, double enthalpy) {
    double entropy;
    ofstream Pressure_Output;
    Pressure_Output.open("pressure.txt");
    Pressure_Output << pressure;
    Pressure_Output.close();
    ofstream Enthalpy_Output;
    Enthalpy_Output.open("enthalpy.txt");
    Enthalpy_Output << enthalpy;
    Enthalpy_Output.close();
    PyRun_SimpleString("f=open('pressure.txt','r')");
    PyRun_SimpleString("Pressure=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('enthalpy.txt','r')");
    PyRun_SimpleString("Enthalpy=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('entropy.txt','w',encoding='utf8')");
    PyRun_SimpleString("s=str(IAPWS97(P=Pressure, h=Enthalpy).s)");
    PyRun_SimpleString("f.write(s)");
    PyRun_SimpleString("f.close()");
    ifstream fin;
    fin.open("entropy.txt");
    fin >> entropy;
    fin.close();
    return entropy;
}

double Calculate_Density_tx(double temperature ,double dryness) {
    double density;
    ofstream Pressure_Output;
    Pressure_Output.open("dryness.txt");
    Pressure_Output << dryness;
    Pressure_Output.close();
    ofstream Temperature_Output;
    Temperature_Output.open("temperature.txt");
    Temperature_Output << temperature + 273.15;
    Temperature_Output.close();
    PyRun_SimpleString("f=open('dryness.txt','r')");
    PyRun_SimpleString("Dryness=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('temperature.txt','r')");
    PyRun_SimpleString("Temperature=float(f.read())");
    PyRun_SimpleString("f.close()");
    PyRun_SimpleString("f=open('density.txt','w',encoding='utf8')");
    PyRun_SimpleString("s=str(IAPWS97(T=Temperature, x=Dryness).rho)");
    PyRun_SimpleString("f.write(s)");
    PyRun_SimpleString("f.close()");
    ifstream fin;
    fin.open("density.txt");
    fin >> density;
    fin.close();
    return density;
}

#endif