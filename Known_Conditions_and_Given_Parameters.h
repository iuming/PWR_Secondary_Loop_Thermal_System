#pragma once
#ifndef Known_Conditions_and_Given_Parameters_H
#define Known_Conditions_and_Given_Parameters_H

#include<iostream>
using namespace std;

double Nuclear_Power_Plant_Output_Electric_Power = 1000;
double Primary_Circuit_Energy_Utilization_Coefficient = 0.995;
double Steam_Dryness_of_Steam_Generator_Outlet = 0.9975;
double Blowdown_Rate_of_Steam_Generator = 0.0105;
double High_Pressure_Cylinder_Efficiency = 0.8207;
double Low_Pressure_Cylinder_Efficiency = 0.8359;
double Steam_Turbine_Mechanical_Efficiency = 0.985;
double Generator_Efficiency = 0.985;
double New_Steam_Pressure_Loss_Coefficient = 0.05;
double Reheat_Steam_Pressure_Loss_Coefficient = 0.05;
double Regeneration_Steam_Extraction_Pressure_Loss_Coefficient = 0.04;
double Low_Pressure_Cylinder_Exhaust_Steam_Pressure_Loss_Coefficient = 0.05;
double High_Pressure_Feed_Water_Heater_Outlet_End_Difference = 3;
double Low_Pressure_Feed_Water_Heater_Outlet_End_Difference = 2;
double Heater_Efficiency = 0.98;
double Feed_Pump_Efficiency = 0.58;
double Feedwater_Pump_Turbine_Internal_Efficiency = 0.80;
double Feedwater_Pump_Turbine_Mechanical_Efficiency = 0.90;
double Reducer_Efficiency_of_Feed_Pump_Steam_Turbine = 0.98;
double Circulating_Cooling_Water_Inlet_Temperature = 24;

#endif