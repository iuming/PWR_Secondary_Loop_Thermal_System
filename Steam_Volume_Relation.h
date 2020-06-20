#pragma once
#ifndef STEAM_VOLUME_RELATION_H
#define STEAM_VOLUME_RELATION_H

#include "Known_Conditions_and_Given_Parameters.h"
#include "The_Main_Thermal_Parameters_Determined.h"
#include "IAPWS.h"

#define re register

double Assume_Power_Plant_Efficiency = 0.3;
double Reactor_Thermal_Power;   /*function of Calculate_of_Reactor_Thermal_Power*/
double Calculate_of_Reactor_Thermal_Power(double Nuclear_Power_Plant_Output_Electric_Power, double Assume_Power_Plant_Efficiency) {
    return Nuclear_Power_Plant_Output_Electric_Power / Assume_Power_Plant_Efficiency;
}
double Steam_Output_of_Steam_Generator; /*function of Calculate_of_Steam_Output_of_Steam_Generator*/
double Calculate_of_Steam_Output_of_Steam_Generator(double Reactor_Thermal_Power, double Primary_Circuit_Energy_Utilization_Coefficient, double Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator, double Saturated_Steam_Enthalpy_of_Steam_Generator, double Blowdown_Rate_of_Steam_Generator, double Actual_Feed_Water_Enthalpy) {
    return (Reactor_Thermal_Power * Primary_Circuit_Energy_Utilization_Coefficient) / ((Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator - Saturated_Steam_Enthalpy_of_Steam_Generator) + (1 + Blowdown_Rate_of_Steam_Generator) * (Saturated_Steam_Enthalpy_of_Steam_Generator - Actual_Feed_Water_Enthalpy));
}
double Steam_Generator_Feed_Water_Flow; /*function of Calculate_of_Steam_Generator_Feed_Water_Flow*/
double Calculate_of_Steam_Generator_Feed_Water_Flow(double Blowdown_Rate_of_Steam_Generator, double Steam_Output_of_Steam_Generator) {
    return (1 + Blowdown_Rate_of_Steam_Generator) * Steam_Output_of_Steam_Generator;
}
double Blowdown_of_Steam_Generator; /*function of Calculate_of_Blowdown_of_Steam_Generator*/
double Calculate_of_Blowdown_of_Steam_Generator(double Blowdown_Rate_of_Steam_Generator, double Steam_Output_of_Steam_Generator) {
    return Blowdown_Rate_of_Steam_Generator * Steam_Output_of_Steam_Generator;
}
double Assumed_Value_of_Condenser_Outlet_Flow = 1000;
double Calculated_Value_of_Condenser_Outlet_Flow = 1200;
double Feed_Water_Heater_Steam_Extraction[Regeneration_Level];   /*function of Calculate_of_Feed_Water_Heater_Steam_Extraction*/
double Calculate_of_Feed_Water_Heater_Steam_Extraction(double Feedwater_Flow_of_Feedwater_Heater, double Feedwater_Heater_Inlet_Enthalpy, double Feedwater_Heater_Outlet_Enthalpy, double Enthalpy_of_Steam_for_Heating_Water_Heater, double Enthalpy_of_Heating_Water_Heater, double Thermal_Efficiency_of_Feedwater_Heater) {
    return (Feedwater_Flow_of_Feedwater_Heater * (Feedwater_Heater_Outlet_Enthalpy - Feedwater_Heater_Inlet_Enthalpy)) / ((Enthalpy_of_Steam_for_Heating_Water_Heater - Enthalpy_of_Heating_Water_Heater) * Thermal_Efficiency_of_Feedwater_Heater);
}
double Condensate_Flow_at_the_Condenser_Outlet; /*function of Calculate_of_Condensate_Flow_at_the_Condenser_Outlet*/
double Calculate_of_Condensate_Flow_at_the_Condenser_Outlet(double Calculate_of_Steam_Output_of_Steam_Generator, double* Feed_Water_Heater_Steam_Extraction, int Regeneration_Level) {
    double Condensate_Flow_at_the_Condenser_Outlet = Calculate_of_Steam_Output_of_Steam_Generator;
    for (re int i = 0; i < Regeneration_Level; ++i) {
        Condensate_Flow_at_the_Condenser_Outlet -= Feed_Water_Heater_Steam_Extraction[i];
    }
    return Condensate_Flow_at_the_Condenser_Outlet;
}
double Steam_Consumption_of_Steam_Turbine;  /*function Calculate_of_Steam_Consumption_of_Steam_Turbine*/
double Calculate_of_Steam_Consumption_of_Steam_Turbine(double Steam_Output_of_Steam_Generator, double Condensate_Flow_at_the_Condenser_Outlet) {
    return Steam_Output_of_Steam_Generator - Condensate_Flow_at_the_Condenser_Outlet;
}
double Steam_Specific_Enthalpy[Regeneration_Level + 2];
double Internal_Power_of_Steam_Turbine_with_Z_Level_Extraction; /*function of Calculate_of_Internal_Power_of_Steam_Turbine_with_Z_Level_Extraction*/
double Calculate_of_Internal_Power_of_Steam_Turbine_with_Z_Level_Extraction(double Total_Steam_Consumption_of_Steam_Turbine, double* Feed_Water_Heater_Steam_Extraction, double* Steam_Specific_Enthalpy, int Regeneration_Level) {
    double Internal_Power_of_Steam_Turbine_with_Z_Level_Extraction = 0;
    for (re int c = 0; c < Regeneration_Level + 1; ++c) {
        double Steam_Extraction = 0;
        for (re int i = 0; i < c + 1; ++i) {
            Steam_Extraction += Feed_Water_Heater_Steam_Extraction[i];
        }
        Internal_Power_of_Steam_Turbine_with_Z_Level_Extraction += (Total_Steam_Consumption_of_Steam_Turbine - Steam_Extraction) * (Steam_Specific_Enthalpy[c] - Steam_Specific_Enthalpy[c + 1]);
    }
    return Internal_Power_of_Steam_Turbine_with_Z_Level_Extraction;
}
double Feed_Pump_Head;  /*function of Calculate_of_Feed_Pump_Head*/
double Calculate_of_Feed_Pump_Head(double Deaerator_Operating_Pressure, double Feedwater_Pump_Outlet_Pressure) {
    return Feedwater_Pump_Outlet_Pressure - Deaerator_Operating_Pressure;
}
double Effective_Output_Power_of_Feed_Pump; /*function of Calculate_of_Effective_Output_Power_of_Feed_Pump*/
double Calculate_of_Effective_Output_Power_of_Feed_Pump(double Feed_Pump_Mass_Flow, double Feed_Pump_Head, double Water_Density) {
    return (1000 * Feed_Pump_Mass_Flow * Feed_Pump_Head) / Water_Density;
}
double Theoretical_Power_of_Feed_Pump_Turbine;  /*function of Calculate_of_Theoretical_Power_of_Feed_Pump_Turbine*/
double Calculate_of_Theoretical_Power_of_Feed_Pump_Turbine(double Effective_Output_Power_of_Feed_Pump, double Feed_Pump_Efficiency, double Feedwater_Pump_Turbine_Internal_Efficiency, double Feedwater_Pump_Turbine_Mechanical_Efficiency, double Reducer_Efficiency_of_Feed_Pump_Steam_Turbine) {
    return Effective_Output_Power_of_Feed_Pump / (Feed_Pump_Efficiency * Feedwater_Pump_Turbine_Internal_Efficiency * Feedwater_Pump_Turbine_Mechanical_Efficiency * Reducer_Efficiency_of_Feed_Pump_Steam_Turbine);
}
double Steam_Consumption_of_Feed_Pump_Turbine; /*function of Calculate_of_Steam_Consumption_of_Feed_Pump_Turbine*/
double Calculate_of_Steam_Consumption_of_Feed_Pump_Turbine(double Theoretical_Power_of_Feed_Pump_Turbine, double Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator, double Exhaust_Enthalpy_of_High_Pressure_Cylinder) {
    return Theoretical_Power_of_Feed_Pump_Turbine / (Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator - Exhaust_Enthalpy_of_High_Pressure_Cylinder);
}
double Low_Pressure_Cylinder_Steam_Consumption; /*function of Calculate_of_Low_Pressure_Cylinder_Steam_Consumption*/
double Calculate_of_Low_Pressure_Cylinder_Steam_Consumption(double Condenser_Outlet_Flow, double Blowdown_of_Steam_Generator, double Steam_Consumption_of_Feed_Pump_Turbine, double* Feed_Water_Heater_Steam_Extraction) {
    return Condenser_Outlet_Flow - Blowdown_of_Steam_Generator - Steam_Consumption_of_Feed_Pump_Turbine - Feed_Water_Heater_Steam_Extraction[0] - Feed_Water_Heater_Steam_Extraction[1] - Feed_Water_Heater_Steam_Extraction[2] - Feed_Water_Heater_Steam_Extraction[3];
}
double Low_Pressure_Cylinder_Power; /*function of Calculate_of_Low_Pressure_Cylinder_Power*/
double Actual_Enthalpy_of_Extraction_Steam[Low_Pressure_Feed_Water_Heater_Stages];
double Calculate_of_Low_Pressure_Cylinder_Power(double Low_Pressure_Cylinder_Steam_Consumption, double* Feed_Water_Heater_Steam_Extraction, double Enthalpy_of_Inlet_Steam_of_Low_Pressure_Cylinder, double Actual_Enthalpy_of_Low_Pressure_Cylinder_Exhaust_Steam, double* Actual_Enthalpy_of_Extraction_Steam, int Low_Pressure_Feed_Water_Heater_Stages = 4) {
    double Low_Pressure_Cylinder_Power = 0;
    double Steam_Extraction = Low_Pressure_Cylinder_Steam_Consumption;
    for (re int i = 0; i < Low_Pressure_Feed_Water_Heater_Stages; ++i) {
        Low_Pressure_Cylinder_Power += Feed_Water_Heater_Steam_Extraction[i] * (Enthalpy_of_Inlet_Steam_of_Low_Pressure_Cylinder - Actual_Enthalpy_of_Extraction_Steam[i]);
        Steam_Extraction -= Feed_Water_Heater_Steam_Extraction[i];
    }
    Low_Pressure_Cylinder_Power += Steam_Extraction * (Enthalpy_of_Inlet_Steam_of_Low_Pressure_Cylinder - Actual_Enthalpy_of_Low_Pressure_Cylinder_Exhaust_Steam);
    return Low_Pressure_Cylinder_Power;
}
const int Reheat_Series = 2;
double Reheater_Steam_Consumption[Reheat_Series]; /*function of Calculate_of_Reheater_Steam_Consumption*/
double Calculate_of_Reheater_Steam_Consumption(double Reheat_Steam_Volume, double Enthalpy_of_Reheater_Inlet, double Enthalpy_of_Reheater_Outlet, double Enthalpy_of_Reheater_Heating_Steam, double Enthalpy_of_Reheater_Hydrophobic, double Heater_Efficiency) {
    return (Reheat_Steam_Volume * (Enthalpy_of_Reheater_Outlet - Enthalpy_of_Reheater_Inlet)) / (Heater_Efficiency * (Enthalpy_of_Reheater_Heating_Steam - Enthalpy_of_Reheater_Hydrophobic));
}
double Steam_Water_Separator_Hydrophobic_Flow;  /*function of Calculate_of_Steam_Water_Separator_Hydrophobic_Flow*/
double Calculate_of_Steam_Water_Separator_Hydrophobic_Flow(double Low_Pressure_Cylinder_Steam_Consumption, double Imported_Dryness_of_the_First_Reheater, double Inlet_Dryness_of_Steam_Water_Separator) {
    return (Low_Pressure_Cylinder_Steam_Consumption * (Imported_Dryness_of_the_First_Reheater - Inlet_Dryness_of_Steam_Water_Separator)) / Inlet_Dryness_of_Steam_Water_Separator;
}
double High_Pressure_Cylinder_Steam_Consumption;    /*function of Calculate_of_High_Pressure_Cylinder_Steam_Consumption*/
double Calculate_of_High_Pressure_Cylinder_Steam_Consumption(double Generator_Efficiency, double Steam_Turbine_Mechanical_Efficiency, double Low_Pressure_Cylinder_Power, double First_High_Pressure_Heater_Extraction_Steam, double Second_High_Pressure_Heater_Extraction_Steam, double First_Reheat_Steam_Extraction, double Enthalpy_of_Steam_at_High_Pressure_Cylinder_Inlet, double Enthalpy_of_Steam_at_High_Pressure_Cylinder_Outlet, double First_Hydrophobic_Enthalpy, double Second_Hydrophobic_Enthalpy, double Enthalpy_of_the_First_Reheated_Steam) {
    return ((1e6 / (Generator_Efficiency * Steam_Turbine_Mechanical_Efficiency) - Low_Pressure_Cylinder_Power) - First_High_Pressure_Heater_Extraction_Steam * (Enthalpy_of_Steam_at_High_Pressure_Cylinder_Inlet - First_Hydrophobic_Enthalpy) - Second_High_Pressure_Heater_Extraction_Steam * (Enthalpy_of_Steam_at_High_Pressure_Cylinder_Inlet - Second_Hydrophobic_Enthalpy) - First_Reheat_Steam_Extraction * (Enthalpy_of_Steam_at_High_Pressure_Cylinder_Inlet - Enthalpy_of_the_First_Reheated_Steam)) / (Enthalpy_of_Steam_at_High_Pressure_Cylinder_Inlet - Enthalpy_of_Steam_at_High_Pressure_Cylinder_Outlet) + First_High_Pressure_Heater_Extraction_Steam + Second_High_Pressure_Heater_Extraction_Steam + First_Reheat_Steam_Extraction;
}
double Total_Exhaust_Steam_Flow_at_High_Pressure_Cylinder_Outlet;   /*function of Calculate_of_Total_Exhaust_Steam_Flow_at_High_Pressure_Cylinder_Outlet*/
double Calculate_of_Total_Exhaust_Steam_Flow_at_High_Pressure_Cylinder_Outlet(double High_Pressure_Cylinder_Steam_Consumption, double First_High_Pressure_Cylinder_Recuperation_Steam_Extraction, double Second_High_Pressure_Cylinder_Recuperation_Steam_Extraction, double First_Reheater_Steam_Consumption) {
    return High_Pressure_Cylinder_Steam_Consumption - First_High_Pressure_Cylinder_Recuperation_Steam_Extraction - Second_High_Pressure_Cylinder_Recuperation_Steam_Extraction - First_Reheater_Steam_Consumption;
}
double Deaerator_Steam_Consumption; /*function of Calculate_of_Deaerator_Steam_Consumption*/
double Calculate_of_Deaerator_Steam_Consumption(double Total_Exhaust_Steam_Flow_at_High_Pressure_Cylinder_Outlet, double Low_Pressure_Cylinder_Steam_Consumption, double Steam_Water_Separator_Hydrophobic_Flow) {
    return Total_Exhaust_Steam_Flow_at_High_Pressure_Cylinder_Outlet - Low_Pressure_Cylinder_Steam_Consumption - Steam_Water_Separator_Hydrophobic_Flow;
}
double New_Steam_Consumption;   /*function of Calculate_of_New_Steam_Consumption*/
double Calculate_of_New_Steam_Consumption(double Total_Steam_Consumption_of_Steam_Turbine, double Steam_Consumption_of_Feed_Pump_Turbine, double Second_Stage_Reheater_Steam_Consumption) {
    return Total_Steam_Consumption_of_Steam_Turbine + Steam_Consumption_of_Feed_Pump_Turbine + Second_Stage_Reheater_Steam_Consumption;
}
double Calculated_the_Thermal_Power_of_the_Reactor;  /*function of Calculate_of_Calculated_the_Thermal_Power_of_the_Reactor*/
double Calculate_of_Calculated_the_Thermal_Power_of_the_Reactor(double New_Steam_Consumption, double Blowdown_Rate_of_Steam_Generator, double Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator, double Saturated_Steam_Enthalpy_of_Steam_Generator, double Actual_Feed_Water_Enthalpy, double Primary_Circuit_Energy_Utilization_Coefficient) {
    return (New_Steam_Consumption * (Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator - Actual_Feed_Water_Enthalpy) + Blowdown_Rate_of_Steam_Generator * New_Steam_Consumption * (Saturated_Steam_Enthalpy_of_Steam_Generator - Actual_Feed_Water_Enthalpy)) / Primary_Circuit_Energy_Utilization_Coefficient;
}
double Calculated_Efficiency_of_Nuclear_Power_Plant = 0.32;      /*function of Calculate_of_Calculated_Efficiency_of_Nuclear_Power_Plant*/
double Calculate_of_Calculated_Efficiency_of_Nuclear_Power_Plant(double Nuclear_Power_Plant_Output_Electric_Power, double Calculated_the_Thermal_Power_of_the_Reactor) {
    return Nuclear_Power_Plant_Output_Electric_Power / Calculated_the_Thermal_Power_of_the_Reactor;
}

#endif