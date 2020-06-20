#pragma once
#ifndef The_Main_Thermal_Parameters_Determined_H
#define The_Main_Thermal_Parameters_Determined_H

#include<iostream>
#include<cmath>

#define IOS ios::sync_with_stdio(false)

using namespace std;

double Reactor_Coolant_System_Operating_Pressure = 15.5;
double Saturation_Temperature_Corresponding_to_Coolant_Pressure;		/*Check the water and steam meter to determine*/
double Reactor_Outlet_Coolant_Supercooling = 17.5;
double Reactor_Outlet_Coolant_Temperature;			/*function of Calculate_of_Reactor_Outlet_Coolant_Temperature*/
double Reactor_Inletand_Outlet_Coolant_Temperature_Rise = 40;
double Reactor_Inlet_Coolant_Temperature;		/*funstion of Calculate_of_Reactor_Inlet_Coolant_Temperature*/
double Saturated_Steam_Pressure_of_Steam_Generator = 7.0;
double Saturated_Steam_Temperature_of_Steam_Generator;	/*For the saturation temperature corresponding to the saturated steam pressure of the steam generator, check the physical property parameter table*/
double Saturated_Steam_Enthalpy_of_Steam_Generator;	/*According to the pressure difference of the steam generator*/
double Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator;	/*According to the pressure and dryness, the physical property parameter table can be obtained*/
double Logarithmic_Average_Temperature_Difference_Between_the_First_and_Second_Sides;	/*function of Calculate_of_Logarithmic_Average_Temperature_Difference_Between_the_First_and_Second_Sides*/
double Temperature_Rise_of_Circulating_Cooling_Water_in_Condenser = 7;
double Heat_Transfer_End_Difference_of_Condenser = 6.5;
double Condensate_Saturation_Temperature_of_Condenser;	/*function of Calculate_of_Condensate_Saturation_Temperature_of_Condenser*/
double Operating_Pressure_of_Condenser;	/*For the saturation pressure corresponding to the saturation temperature of the condenser condensate, check the physical property parameter table*/
double Condensate_Enthalpy;	/*Query the enthalpy of saturated water corresponding to the operating pressure of the condenser*/
double High_Pressure_Cylinder_Inlet_Steam_Pressure;	/*function of Calculate_of_High_Pressure_Cylinder_Inlet_Steam_Pressure*/
double Imported_Steam_Dryness_of_High_Pressure_Cylinder;		/*Ignoring the heat loss of the pipeline, the flow in the heat transfer tube is considered to be an enthalpy process, according to the inlet pressure, the specific enthalpy is checked*/
double High_Pressure_Cylinder_Inlet_Steam_Specific_Entropy;		/*According to the inlet steam pressure and specific enthalpy of the high-pressure cylinder*/
double High_Pressure_Cylinder_Exhaust_Pressure;					/*Selected partial pressure ratio 13% high pressure cylinder inlet steam pressure*/
double Ideal_Enthalpy_of_High_Pressure_Cylinder_Exhaust_Steam;	/*Isentropic process, according to specific entropy and exhaust pressure*/
double Ideal_Enthalpy_Drop_of_Steam_in_High_Pressure_Cylinder;	/*The steam enthalpy value at the inlet of the high-pressure cylinder minus the ideal enthalpy value at the outlet of the high-pressure cylinder*/
double Actual_Enthalpy_Drop_of_Steam_in_High_Pressure_Cylinder;	/*The efficiency in the high-pressure cylinder is multiplied by the ideal enthalpy drop of the steam working medium in the high-pressure cylinder*/
double Actual_Enthalpy_of_High_Pressure_Cylinder_Exhaust_Steam;	/*Steam inlet enthalpy value of high pressure cylinder minus actual enthalpy drop of steam of high pressure cylinder*/
double High_Pressure_Cylinder_Exhaust_Steam_Dryness;			/*According to the actual specific enthalpy of the high-pressure cylinder exhaust steam and the outlet pressure*/
double Steam_Pressure_of_Steam_water_Separator_Inlet;			/*Regardless of the pressure drop and enthalpy drop from the exhaust of the high-pressure cylinder to the inlet of the steam-water separator, the steam parameters at these two locations are considered equal*/
double Steam_Dryness_of_Steam_water_Separator_Inlet;			/*Regardless of the pressure drop and enthalpy drop from the exhaust of the high-pressure cylinder to the inlet of the steam-water separator, the steam parameters at these two locations are considered equal*/
struct Reheater
{
	double Reheat_Steam_Inlet_Pressure;							
	double Reheat_Steam_Inlet_Dryness;							/*The steam-water separator can remove 98% of the water discharged from the high-pressure cylinder*/
	double Reheat_Steam_Inlet_Enthalpy;
	double Reheat_Steam_Inlet_Temperature;
	double Heating_Steam_Inlet_Temperature;
	double Heating_Steam_Inlet_Pressure;						
	double Heating_Steam_Inlet_Dryness;
	double Heating_Steam_Inlet_Enthalpy;
	double Reheat_Steam_Outlet_Pressure;						
	double Reheat_Steam_Outlet_Temperature;						
	double Reheat_Steam_Outlet_Enthalpy;
}First_Stage_Reheater, Second_Stage_Reheater;
double Steam_Water_Separator_Pressure_Loss = 0.01;
double Water_Removal_Coefficient_of_Steam_Water_Separator = 0.98;
double Primary_Reheater_Pressure_Loss = 0.01;
double Pressure_Loss_of_Secondary_Reheater = 0.01;
double Reheat_Steam_Temperature_Difference = 14;
struct Low_Pressure_Cylinder
{
	double Inlet_Steam_Pressure;								
	double Inlet_Steam_Temperature;								/*Ignoring the heat loss of the pipeline, the flow in the heat transfer tube is considered to be an enthalpy process, which is checked based on the inlet pressure and specific enthalpy*/
	double Inlet_Steam_Enthalpy;
	double Inlet_Steam_Entropy;
	double Exhaust_Steam_Pressure;								/*function of Calculate_of_Exhaust_Steam_Pressure*/
	double Exhaust_Steam_Dryness;								
	double Exhaust_Steam_Ideal_Enthalpy;						/*Isentropic process, according to specific entropy and exhaust pressure*/
	double Exhaust_Steam_Actual_Enthalpy;						/*Calculated from adiabatic enthalpy drop and internal efficiency calculation formula*/
}Low_Pressure_Cylinder;
const int Regeneration_Level = 7;											/*Selected*/
const int Low_Pressure_Feed_Water_Heater_Stages = 4;						/*Selected*/
const int High_Pressure_Feed_Water_Heater_Stages = 2;						/*Selected*/
double Enthalpy_Rise;	/*function of Calculate_of_Enthalpy_Rise*/
double The_Best_Enthalpy_of_Water_Supply;	/*function of Calculate_of_The_Best_Enthalpy_of_Water_Supply*/
double Optimal_Feed_Water_Temperature;	/*Determined according to pressure and specific enthalpy*/
double Actual_Temperature_Calibration_Coefficient = 0.85;
double Actual_Feed_Water_Temperature;	/*function of Calculate_of_Actual_Feed_Water_Temperature*/
double Actual_Feed_Water_Enthalpy;	/*Determined according to pressure and actual feed water temperature*/
double First_Feed_Water_Recuperation_Distribution;	/*function of Calculate_of_First_Feed_Water_Recuperation_Distribution*/
/*double Second_Feed_Water_Recuperation_Distribution;*/
double Enthalpy_Rise_of_High_Pressure_Heater_Feed_Water;	/*function of Calculate_of_Enthalpy_Rise_of_High_Pressure_Heater_Feed_Water*/
double Deaerator_and_Low_Feed_Water_Enthalpy_Rise;	/*function of Calculate_of_Deaerator_and_Low_Feed_Water_Enthalpy_Rise*/
double Coefficient_of_Outlet_Pressure_of_Condensate_Pump = 3.1;
double Condensate_Pump_Outlet_Pressure;	/*function of Calculate_of_Condensate_Pump_Outlet_Pressure*/
double Low_Pressure_Heater_Feed_Water_Pressure_Drop;	/*function of Calculate_of_Low_Pressure_Heater_Feed_Water_Pressure_Drop*/
struct Low_Pressure_Heater_Feed_Water
{
	double Outlet_Feed_Water_Pressure;	/*function of Calculate_of_Outlet_Feed_Water_Pressure*/
	double Imported_Feed_Water_Specific_Enthalpy;	/*function of Calculate_of_Imported_Feed_Water_Specific_Enthalpy*/
	double Specific_Enthalpy_of_Outlet_Water_Supply;	/*function of Calculate_of_Specific_Enthalpy_of_Outlet_Water_Supply*/
	double Inlet_Feed_Water_Temperature;	/*From the import specific enthalpy and low pressure heater pressure query physical property parameter table*/
	double Outlet_Feed_Water_Temperature;	/*Obtained from the physical property parameter table of the outlet specific enthalpy and low pressure heater pressure*/
}Low_Pressure_Heater_Feed_Water[Low_Pressure_Feed_Water_Heater_Stages];
double Inlet_Pressure_Loss_of_Deaerator = 0.93;
struct Deaerator
{
	double Imported_Feed_Water_Specific_Enthalpy;	/*function of Calculate_of_Imported_Feed_Water_Specific_Enthalpy*/
	double Specific_Enthalpy_of_Outlet_Water_Supply;	/*function of Calculate_of_Specific_Enthalpy_of_Outlet_Water_Supply*/
	double Outlet_Feed_Water_Temperature;	/*Saturated water temperature corresponding to outlet feed water specific enthalpy*/
	double Operating_Pressure;	/*Saturation pressure corresponding to outlet feed water temperature*/
	double Outlet_Feed_Water_Entropy;	/*According to the pressure and enthalpy value*/
}Deaerator;
double Pressure_Coefficient_of_Feed_Pump = 1.2;
double Feed_Water_Pump_Outlet_Pressure;	/*function of Calculate_of_Feed_Water_Pump_Outlet_Pressure*/
double High_Pressure_Heater_Feed_Water_Pressure_Drop;	/*function of Calculate_of_Low_Pressure_Heater_Feed_Water_Pressure_Drop*/
struct High_Pressure_Heater_Feed_Water
{
	double Water_Supply_Side_Pressure;
	double Outlet_Feed_Water_Pressure;	/*function of _Calculate_of_Outlet_Feed_Water_Pressure*/
	double Imported_Feed_Water_Specific_Enthalpy;	/*function of Calculate_of_Imported_Feed_Water_Specific_Enthalpy*/
	double Specific_Enthalpy_of_Outlet_Water_Supply;	/*function of Calculate_of_Specific_Enthalpy_of_Outlet_Water_Supply*/
	double Inlet_Feed_Water_Temperature;	/*From the import specific enthalpy and low pressure heater pressure query physical property parameter table*/
	double Outlet_Feed_Water_Temperature;	/*Obtained from the physical property parameter table of the outlet specific enthalpy and low pressure heater pressure*/
}High_Pressure_Heater_Feed_Water[High_Pressure_Feed_Water_Heater_Stages];
struct High_Pressure_Cylinder_Steam_Extraction
{
	double Temperature;	/*function of Calculate_of_The_Temperature_of_Steam_Extraction*/
	double Pressure;	/*function of Calculate_of_The_Pressure_of_Steam_Extraction*/
	double Ideal_Enthalpy;
	double Ideal_Enthalpy_Drop;
	double Actual_Enthalpy_Drop;
	double Actual_Enthalpy;
	double Dryness;	/*Based on specific entropy and internal efficiency*/
}High_Pressure_Cylinder_Steam_Extraction[High_Pressure_Feed_Water_Heater_Stages];
struct Low_Pressure_Cylinder_Steam_Extraction
{
	double Temperature;	/*function of Calculate_of_The_Temperature_of_Steam_Extraction*/
	double Pressure;	/*function of Calculate_of_The_Pressure_of_Steam_Extraction*/
	double Ideal_Enthalpy;
	double Actual_Enthalpy;
	double Dryness;	/*Based on specific entropy and internal efficiency*/
}Low_Pressure_Cylinder_Steam_Extraction[Low_Pressure_Feed_Water_Heater_Stages];

double Calculate_of_Reactor_Outlet_Coolant_Temperature(double Saturation_Temperature_Corresponding_to_Coolant_Pressure, double Reactor_Outlet_Coolant_Supercooling) {
	return Saturation_Temperature_Corresponding_to_Coolant_Pressure - Reactor_Outlet_Coolant_Supercooling;
}

double Calculate_of_Reactor_Inlet_Coolant_Temperature(double Reactor_Outlet_Coolant_Temperature, double Reactor_Inletand_Outlet_Coolant_Temperature_Rise) {
	return Reactor_Outlet_Coolant_Temperature - Reactor_Inletand_Outlet_Coolant_Temperature_Rise;
}

double Calculate_of_Logarithmic_Average_Temperature_Difference_Between_the_First_and_Second_Sides(double Reactor_Outlet_Coolant_Temperature, double Reactor_Inlet_Coolant_Temperature, double Saturated_Steam_Temperature_of_Steam_Generator) {
	return (Reactor_Outlet_Coolant_Temperature - Reactor_Inlet_Coolant_Temperature) / log10((Reactor_Outlet_Coolant_Temperature - Saturated_Steam_Temperature_of_Steam_Generator) / (Reactor_Inlet_Coolant_Temperature - Saturated_Steam_Temperature_of_Steam_Generator));
}

double Calculate_of_Condensate_Saturation_Temperature_of_Condenser(double Circulating_Cooling_Water_Inlet_Temperature, double Temperature_Rise_of_Circulating_Cooling_Water_in_Condenser, double Heat_Transfer_End_Difference_of_Condenser) {
	return Circulating_Cooling_Water_Inlet_Temperature + Temperature_Rise_of_Circulating_Cooling_Water_in_Condenser + Heat_Transfer_End_Difference_of_Condenser;
}

double Calculate_of_High_Pressure_Cylinder_Inlet_Steam_Pressure(double Saturated_Steam_Pressure_of_Steam_Generator, double New_Steam_Pressure_Loss_Coefficient) {
	return Saturated_Steam_Pressure_of_Steam_Generator * (1 - New_Steam_Pressure_Loss_Coefficient);
}

double Calculate_of_First_Feed_Water_Recuperation_Distribution(double Actual_Feed_Water_Temperature, double Condensate_Enthalpy, int Regeneration_Level) {
	return (Actual_Feed_Water_Temperature - Condensate_Enthalpy) / Regeneration_Level;
}

double Calculate_of_Enthalpy_Rise_of_High_Pressure_Heater_Feed_Water(double Actual_Feed_Water_Temperature, double Specific_Enthalpy_of_Feed_Water_at_the_Outlet_of_Deaerator, int High_Pressure_Feed_Water_Heater_Stages) {
	return (Actual_Feed_Water_Temperature - Specific_Enthalpy_of_Feed_Water_at_the_Outlet_of_Deaerator) / High_Pressure_Feed_Water_Heater_Stages;
}

double Calculate_of_Deaerator_and_Low_Feed_Water_Enthalpy_Rise(double Specific_Enthalpy_of_Feed_Water_at_the_Outlet_of_Deaerator, double Condensate_Enthalpy, int Low_Pressure_Feed_Water_Heater_Stages) {
	return (Specific_Enthalpy_of_Feed_Water_at_the_Outlet_of_Deaerator - Condensate_Enthalpy) / (Low_Pressure_Feed_Water_Heater_Stages + 1);
}

double Calculate_of_Imported_Feed_Water_Specific_Enthalpy(double Specific_Enthalpy_of_Outlet_Water_Supply) {
	return Specific_Enthalpy_of_Outlet_Water_Supply;
}

double Calculate_of_Specific_Enthalpy_of_Outlet_Water_Supply(double Imported_Feed_Water_Specific_Enthalpy, double Deaerator_and_Low_Feed_Water_Enthalpy_Rise) {
	return Imported_Feed_Water_Specific_Enthalpy + Deaerator_and_Low_Feed_Water_Enthalpy_Rise;
}

double Calculate_of_High_Pressure_Cylinder_Exhaust_Pressure(double High_Pressure_Cylinder_Inlet_Steam_Pressure) {
	return 0.13 * High_Pressure_Cylinder_Inlet_Steam_Pressure;
}

double Calculate_of_Ideal_Enthalpy_Drop_of_Steam_in_High_Pressure_Cylinder(double Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator, double Ideal_Enthalpy_of_High_Pressure_Cylinder_Exhaust_Steam) {
	return Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator - Ideal_Enthalpy_of_High_Pressure_Cylinder_Exhaust_Steam;
}

double Calculate_of_Actual_Enthalpy_Drop_of_Steam_in_High_Pressure_Cylinder(double High_Pressure_Cylinder_Efficiency, double Ideal_Enthalpy_Drop_of_Steam_in_High_Pressure_Cylinder) {
	return High_Pressure_Cylinder_Efficiency * Ideal_Enthalpy_Drop_of_Steam_in_High_Pressure_Cylinder;
}

double Calculate_of_Actual_Enthalpy_of_High_Pressure_Cylinder_Exhaust_Steam(double Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator, double Actual_Enthalpy_Drop_of_Steam_in_High_Pressure_Cylinder) {
	return Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator - Actual_Enthalpy_Drop_of_Steam_in_High_Pressure_Cylinder;
}

double Calculate_of_Reheat_Steam_Inlet_Pressure(double Steam_Water_Separator_Pressure_Loss, double Steam_Pressure_of_Steam_water_Separator_Inlet) {
	return Steam_Pressure_of_Steam_water_Separator_Inlet * (1 - Steam_Water_Separator_Pressure_Loss);
}

double Calculate_of_Reheat_Steam_Inlet_Dryness_in_First_Stage_Reheater(double Steam_Dryness_of_Steam_water_Separator_Inlet, double Water_Removal_Coefficient_of_Steam_Water_Separator) {
	return 1 - (1 - Steam_Dryness_of_Steam_water_Separator_Inlet) * (1 - Water_Removal_Coefficient_of_Steam_Water_Separator);
}

double Calculate_of_Reheat_Steam_Outlet_Temperature(double Saturated_Steam_Temperature_of_Steam_Generator, double Reheat_Steam_Temperature_Difference) {
	return Saturated_Steam_Temperature_of_Steam_Generator - Reheat_Steam_Temperature_Difference;
}

double Calculate_of_Enthalpy_of_Secondary_Reheater_Inlet(double Enthalpy_of_the_First_Stage_Reheater, double Enthalpy_of_the_Second_Stage_Reheater) {
	return (Enthalpy_of_the_First_Stage_Reheater + Enthalpy_of_the_Second_Stage_Reheater) / 2;
}

double Calculate_of_Low_Pressure_Cylinder_Inlet_Steam_Pressure(double Low_Pressure_Cylinder_Exhaust_Steam_Pressure_Loss_Coefficient, double Reheat_Steam_Outlet_Pressure) {
	return Reheat_Steam_Outlet_Pressure * (1 - Low_Pressure_Cylinder_Exhaust_Steam_Pressure_Loss_Coefficient);
}

double Calculate_of_Exhaust_Steam_Pressure(double Operating_Pressure_of_Condenser, double Low_Pressure_Cylinder_Exhaust_Steam_Pressure_Loss_Coefficient) {
	return (1 + Low_Pressure_Cylinder_Exhaust_Steam_Pressure_Loss_Coefficient) * Operating_Pressure_of_Condenser;
}

double Calculate_of_Exhaust_Steam_Actual_Enthalpy(double Enthalpy_of_Imported_Steam, double Exhaust_Steam_Ideal_Enthalpy, double Low_Pressure_Cylinder_Efficiency) {
	return Enthalpy_of_Imported_Steam - (Enthalpy_of_Imported_Steam - Exhaust_Steam_Ideal_Enthalpy) * Low_Pressure_Cylinder_Efficiency;
}

double Calculate_of_Enthalpy_Rise(double Saturated_Steam_Enthalpy_of_Steam_Generator, double Condensate_Enthalpy, int Regeneration_Level) {
	return (Saturated_Steam_Enthalpy_of_Steam_Generator - Condensate_Enthalpy) / (Regeneration_Level + 1);
}

double Calculate_of_The_Best_Enthalpy_of_Water_Supply(double Condensate_Enthalpy, double Enthalpy_Rise, int Regeneration_Level) {
	return Condensate_Enthalpy + Regeneration_Level * Enthalpy_Rise;
}

double Calculate_of_Actual_Feed_Water_Temperature(double Optimal_Feed_Water_Temperature, double Actual_Temperature_Calibration_Coefficient) {
	return Optimal_Feed_Water_Temperature * Actual_Temperature_Calibration_Coefficient;
}

double Calculate_of_Operating_Pressure_of_Deaerator(double High_Pressure_Cylinder_Exhaust_Pressure, double Inlet_Pressure_Loss_of_Deaerator) {
	return High_Pressure_Cylinder_Exhaust_Pressure * Inlet_Pressure_Loss_of_Deaerator;
}

double Calculate_of_Condensate_Pump_Outlet_Pressure(double Deaerator_Operating_Pressure, double Coefficient_of_Outlet_Pressure_of_Condensate_Pump) {
	return Deaerator_Operating_Pressure * Coefficient_of_Outlet_Pressure_of_Condensate_Pump;
}

double Calculate_of_Low_Pressure_Heater_Feed_Water_Pressure_Drop(double Condensate_Pump_Outlet_Pressure, double Deaerator_Operating_Pressure, int Low_Pressure_Feed_Water_Heater_Stages) {
	return (Condensate_Pump_Outlet_Pressure - Deaerator_Operating_Pressure) / (Low_Pressure_Feed_Water_Heater_Stages + 1);
}

double Calculate_of_Outlet_Feed_Water_Pressure(double Upper_Level_Outlet_Pressure, double Pressure_Heater_Feed_Water_Pressure_Drop) {
	return Upper_Level_Outlet_Pressure - Pressure_Heater_Feed_Water_Pressure_Drop;
}

double Calculate_of_Feed_Water_Pump_Outlet_Pressure(double Saturated_Steam_Pressure_of_Steam_Generator, double Pressure_Coefficient_of_Feed_Pump) {
	return Saturated_Steam_Pressure_of_Steam_Generator * Pressure_Coefficient_of_Feed_Pump;
}

double Calculate_of_High_Pressure_Heater_Feed_Water_Pressure_Drop(double Feed_Water_Pump_Outlet_Pressure, double Saturated_Steam_Pressure_of_Steam_Generator, int High_Pressure_Feed_Water_Heater_Stages) {
	return (Feed_Water_Pump_Outlet_Pressure - Saturated_Steam_Pressure_of_Steam_Generator) / (High_Pressure_Feed_Water_Heater_Stages + 1);
}

double Calculate_of_The_Temperature_of_Steam_Extraction(double Outlet_Feed_Water_Temperature, double Feed_Water_Heater_Outlet_End_Difference) {
	return Outlet_Feed_Water_Temperature + Feed_Water_Heater_Outlet_End_Difference;
}

double Calculate_of_The_Pressure_of_Steam_Extraction(double Saturation_Pressure_Corresponding_to_Hydrophobic_Temperature, double Regeneration_Steam_Extraction_Pressure_Loss_Coefficient) {
	return Saturation_Pressure_Corresponding_to_Hydrophobic_Temperature / (1 - Regeneration_Steam_Extraction_Pressure_Loss_Coefficient);
}


#endif