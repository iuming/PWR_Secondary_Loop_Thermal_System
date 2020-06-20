#pragma once
#ifndef THERMAL_EFFICIENCY_CALCULATE_H
#define THERMAL_EFFICIENCY_CALCULATE_H

#include <fstream>
#include "IAPWS.h"
#include "Known_Conditions_and_Given_Parameters.h"
#include "The_Main_Thermal_Parameters_Determined.h"
#include "Parameters_Output.h"
#include "Steam_Volume_Relation.h"

#define Relative_Error 0.01
#define Absolute_Error 0.001

using namespace std;

void Thermal_Efficiency_Calculate() {
    ofstream fout;
    fout.open("Thermal_Efficiency_Calculation_Parameters.csv");
    do
    {
        Assume_Power_Plant_Efficiency = Calculated_Efficiency_of_Nuclear_Power_Plant;
        fout << "Assume_Power_Plant_Efficiency" << ',' << Assume_Power_Plant_Efficiency << endl;
        Reactor_Thermal_Power = Calculate_of_Reactor_Thermal_Power(Nuclear_Power_Plant_Output_Electric_Power, Assume_Power_Plant_Efficiency);
        fout << "Reactor_Thermal_Power" << ',' << Reactor_Thermal_Power << endl;
        Steam_Output_of_Steam_Generator = 1e3 * Calculate_of_Steam_Output_of_Steam_Generator(Reactor_Thermal_Power, Primary_Circuit_Energy_Utilization_Coefficient, Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator, Saturated_Steam_Enthalpy_of_Steam_Generator, Blowdown_Rate_of_Steam_Generator, Actual_Feed_Water_Enthalpy);
        fout << "Steam_Output_of_Steam_Generator" << ',' << Steam_Output_of_Steam_Generator << endl;
        Steam_Generator_Feed_Water_Flow = Calculate_of_Steam_Generator_Feed_Water_Flow(Blowdown_Rate_of_Steam_Generator, Steam_Output_of_Steam_Generator);
        fout << "Steam_Generator_Feed_Water_Flow" << ',' << Steam_Generator_Feed_Water_Flow << endl;
        Blowdown_of_Steam_Generator = Calculate_of_Blowdown_of_Steam_Generator(Blowdown_Rate_of_Steam_Generator, Steam_Output_of_Steam_Generator);
        fout << "Blowdown_of_Steam_Generator" << ',' << Blowdown_of_Steam_Generator << endl;
        Feed_Pump_Head = Calculate_of_Feed_Pump_Head(Deaerator.Operating_Pressure, Feed_Water_Pump_Outlet_Pressure);
        fout << "Feed_Pump_Head" << ',' << Feed_Pump_Head << endl;
        Effective_Output_Power_of_Feed_Pump = Calculate_of_Effective_Output_Power_of_Feed_Pump(Steam_Generator_Feed_Water_Flow, Feed_Pump_Head, Calculate_Density_tx(Deaerator.Outlet_Feed_Water_Temperature, 0));
        fout << "Effective_Output_Power_of_Feed_Pump" << ',' << Effective_Output_Power_of_Feed_Pump << endl;
        Theoretical_Power_of_Feed_Pump_Turbine = Calculate_of_Theoretical_Power_of_Feed_Pump_Turbine(Effective_Output_Power_of_Feed_Pump, Feed_Pump_Efficiency, Feedwater_Pump_Turbine_Internal_Efficiency, Feedwater_Pump_Turbine_Mechanical_Efficiency, Reducer_Efficiency_of_Feed_Pump_Steam_Turbine);
        fout << "Theoretical_Power_of_Feed_Pump_Turbine" << ',' << Theoretical_Power_of_Feed_Pump_Turbine << endl;
        Steam_Consumption_of_Feed_Pump_Turbine = Calculate_of_Steam_Consumption_of_Feed_Pump_Turbine(Theoretical_Power_of_Feed_Pump_Turbine, Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator, Actual_Enthalpy_of_High_Pressure_Cylinder_Exhaust_Steam);
        fout << "Steam_Consumption_of_Feed_Pump_Turbine" << ',' << Steam_Consumption_of_Feed_Pump_Turbine << endl;
        do
        {
            Assumed_Value_of_Condenser_Outlet_Flow = Calculated_Value_of_Condenser_Outlet_Flow;
            fout << "Assumed_Value_of_Condenser_Outlet_Flow" << ',' << Assumed_Value_of_Condenser_Outlet_Flow << endl;
            Feed_Water_Heater_Steam_Extraction[0] = Calculate_of_Feed_Water_Heater_Steam_Extraction(Assumed_Value_of_Condenser_Outlet_Flow, Low_Pressure_Heater_Feed_Water[0].Imported_Feed_Water_Specific_Enthalpy, Low_Pressure_Heater_Feed_Water[0].Specific_Enthalpy_of_Outlet_Water_Supply, Low_Pressure_Cylinder_Steam_Extraction[0].Actual_Enthalpy, Calculate_Saturation_Temperature(Low_Pressure_Cylinder_Steam_Extraction[0].Pressure), Heater_Efficiency);
            fout << "Feed_Water_Heater_Steam_Extraction_No1" << ',' << Feed_Water_Heater_Steam_Extraction[0] << endl;
            Feed_Water_Heater_Steam_Extraction[1] = Calculate_of_Feed_Water_Heater_Steam_Extraction(Assumed_Value_of_Condenser_Outlet_Flow, Low_Pressure_Heater_Feed_Water[1].Imported_Feed_Water_Specific_Enthalpy, Low_Pressure_Heater_Feed_Water[1].Specific_Enthalpy_of_Outlet_Water_Supply, Low_Pressure_Cylinder_Steam_Extraction[1].Actual_Enthalpy, Calculate_Saturation_Temperature(Low_Pressure_Cylinder_Steam_Extraction[1].Pressure), Heater_Efficiency);
            fout << "Feed_Water_Heater_Steam_Extraction_No2" << ',' << Feed_Water_Heater_Steam_Extraction[1] << endl;
            Feed_Water_Heater_Steam_Extraction[2] = Calculate_of_Feed_Water_Heater_Steam_Extraction(Assumed_Value_of_Condenser_Outlet_Flow, Low_Pressure_Heater_Feed_Water[2].Imported_Feed_Water_Specific_Enthalpy, Low_Pressure_Heater_Feed_Water[2].Specific_Enthalpy_of_Outlet_Water_Supply, Low_Pressure_Cylinder_Steam_Extraction[2].Actual_Enthalpy, Calculate_Saturation_Temperature(Low_Pressure_Cylinder_Steam_Extraction[2].Pressure), Heater_Efficiency);
            fout << "Feed_Water_Heater_Steam_Extraction_No3" << ',' << Feed_Water_Heater_Steam_Extraction[2] << endl;
            Feed_Water_Heater_Steam_Extraction[3] = Calculate_of_Feed_Water_Heater_Steam_Extraction(Assumed_Value_of_Condenser_Outlet_Flow, Low_Pressure_Heater_Feed_Water[3].Imported_Feed_Water_Specific_Enthalpy, Low_Pressure_Heater_Feed_Water[3].Specific_Enthalpy_of_Outlet_Water_Supply, Low_Pressure_Cylinder_Steam_Extraction[3].Actual_Enthalpy, Calculate_Saturation_Temperature(Low_Pressure_Cylinder_Steam_Extraction[3].Pressure), Heater_Efficiency);
            fout << "Feed_Water_Heater_Steam_Extraction_No4" << ',' << Feed_Water_Heater_Steam_Extraction[3] << endl;
            Low_Pressure_Cylinder_Steam_Consumption = Calculate_of_Low_Pressure_Cylinder_Steam_Consumption(Assumed_Value_of_Condenser_Outlet_Flow, Blowdown_of_Steam_Generator, Steam_Consumption_of_Feed_Pump_Turbine, Feed_Water_Heater_Steam_Extraction);
            fout << "Low_Pressure_Cylinder_Steam_Consumption" << ',' << Low_Pressure_Cylinder_Steam_Consumption << endl;
            Reheater_Steam_Consumption[0] = Calculate_of_Reheater_Steam_Consumption(Low_Pressure_Cylinder_Steam_Consumption, First_Stage_Reheater.Reheat_Steam_Inlet_Enthalpy, Second_Stage_Reheater.Reheat_Steam_Inlet_Enthalpy, First_Stage_Reheater.Heating_Steam_Inlet_Enthalpy, Calculate_Enthalpy_px(First_Stage_Reheater.Heating_Steam_Inlet_Pressure, 0), Heater_Efficiency);
            fout << "Reheater_Steam_Consumption_No1" << ',' << Reheater_Steam_Consumption[0] << endl;
            Reheater_Steam_Consumption[1] = Calculate_of_Reheater_Steam_Consumption(Low_Pressure_Cylinder_Steam_Consumption, Second_Stage_Reheater.Reheat_Steam_Inlet_Enthalpy, Second_Stage_Reheater.Reheat_Steam_Outlet_Enthalpy, Second_Stage_Reheater.Heating_Steam_Inlet_Enthalpy, Calculate_Enthalpy_px(Second_Stage_Reheater.Heating_Steam_Inlet_Pressure, 0), Heater_Efficiency);
            fout << "Reheater_Steam_Consumption_No2" << ',' << Reheater_Steam_Consumption[1] << endl;
            Steam_Water_Separator_Hydrophobic_Flow = Calculate_of_Steam_Water_Separator_Hydrophobic_Flow(Low_Pressure_Cylinder_Steam_Consumption, First_Stage_Reheater.Reheat_Steam_Inlet_Dryness, Steam_Dryness_of_Steam_water_Separator_Inlet);
            fout << "Steam_Water_Separator_Hydrophobic_Flow" << ',' << Steam_Water_Separator_Hydrophobic_Flow << endl;
            for (re int i = 0; i < Low_Pressure_Feed_Water_Heater_Stages; ++i) {
                Actual_Enthalpy_of_Extraction_Steam[i] = Low_Pressure_Cylinder_Steam_Extraction[i].Actual_Enthalpy;
            }
            Low_Pressure_Cylinder_Power = Calculate_of_Low_Pressure_Cylinder_Power(Low_Pressure_Cylinder_Steam_Consumption, Feed_Water_Heater_Steam_Extraction, Low_Pressure_Cylinder.Inlet_Steam_Enthalpy, Low_Pressure_Cylinder.Exhaust_Steam_Actual_Enthalpy, Actual_Enthalpy_of_Extraction_Steam);
            fout << "Low_Pressure_Cylinder_Power" << ',' << Low_Pressure_Cylinder_Power << endl;
            Feed_Water_Heater_Steam_Extraction[5] = Calculate_of_Feed_Water_Heater_Steam_Extraction(Steam_Generator_Feed_Water_Flow, High_Pressure_Heater_Feed_Water[0].Imported_Feed_Water_Specific_Enthalpy, High_Pressure_Heater_Feed_Water[0].Specific_Enthalpy_of_Outlet_Water_Supply, High_Pressure_Cylinder_Steam_Extraction[0].Actual_Enthalpy, Calculate_Saturation_Temperature(High_Pressure_Cylinder_Steam_Extraction[0].Pressure), Heater_Efficiency);
            fout << "Feed_Water_Heater_Steam_Extraction_No6" << ',' << Feed_Water_Heater_Steam_Extraction[5] << endl;
            Feed_Water_Heater_Steam_Extraction[6] = Calculate_of_Feed_Water_Heater_Steam_Extraction(Steam_Generator_Feed_Water_Flow, High_Pressure_Heater_Feed_Water[1].Imported_Feed_Water_Specific_Enthalpy, High_Pressure_Heater_Feed_Water[1].Specific_Enthalpy_of_Outlet_Water_Supply, High_Pressure_Cylinder_Steam_Extraction[1].Actual_Enthalpy, Calculate_Saturation_Temperature(High_Pressure_Cylinder_Steam_Extraction[1].Pressure), Heater_Efficiency);
            fout << "Feed_Water_Heater_Steam_Extraction_No7" << ',' << Feed_Water_Heater_Steam_Extraction[6] << endl;
            High_Pressure_Cylinder_Steam_Consumption = Calculate_of_High_Pressure_Cylinder_Steam_Consumption(Generator_Efficiency, Steam_Turbine_Mechanical_Efficiency, Low_Pressure_Cylinder_Power, Feed_Water_Heater_Steam_Extraction[5], Feed_Water_Heater_Steam_Extraction[6], Reheater_Steam_Consumption[0], Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator, Actual_Enthalpy_of_High_Pressure_Cylinder_Exhaust_Steam, High_Pressure_Cylinder_Steam_Extraction[0].Actual_Enthalpy, High_Pressure_Cylinder_Steam_Extraction[1].Actual_Enthalpy, First_Stage_Reheater.Heating_Steam_Inlet_Enthalpy);
            fout << "High_Pressure_Cylinder_Steam_Consumption" << ',' << High_Pressure_Cylinder_Steam_Consumption << endl;
            Total_Exhaust_Steam_Flow_at_High_Pressure_Cylinder_Outlet = Calculate_of_Total_Exhaust_Steam_Flow_at_High_Pressure_Cylinder_Outlet(High_Pressure_Cylinder_Steam_Consumption, Feed_Water_Heater_Steam_Extraction[5], Feed_Water_Heater_Steam_Extraction[6], Reheater_Steam_Consumption[0]);
            fout << "Total_Exhaust_Steam_Flow_at_High_Pressure_Cylinder_Outlet" << ',' << Total_Exhaust_Steam_Flow_at_High_Pressure_Cylinder_Outlet << endl;
            Feed_Water_Heater_Steam_Extraction[4] = Calculate_of_Deaerator_Steam_Consumption(Total_Exhaust_Steam_Flow_at_High_Pressure_Cylinder_Outlet, Low_Pressure_Cylinder_Steam_Consumption, Steam_Water_Separator_Hydrophobic_Flow);
            fout << "Feed_Water_Heater_Steam_Extraction_No5" << ',' << Feed_Water_Heater_Steam_Extraction[4] << endl;
            Calculated_Value_of_Condenser_Outlet_Flow = Steam_Generator_Feed_Water_Flow - (Feed_Water_Heater_Steam_Extraction[5] + Feed_Water_Heater_Steam_Extraction[6] + Reheater_Steam_Consumption[0] + Reheater_Steam_Consumption[1]) - Steam_Water_Separator_Hydrophobic_Flow - Feed_Water_Heater_Steam_Extraction[4] + Feed_Water_Heater_Steam_Extraction[0] + Feed_Water_Heater_Steam_Extraction[1] + Feed_Water_Heater_Steam_Extraction[2] + Feed_Water_Heater_Steam_Extraction[3];
            fout << "Calculated_Value_of_Condenser_Outlet_Flow" << ',' << Calculated_Value_of_Condenser_Outlet_Flow << endl;
        } while (fabs((Calculated_Value_of_Condenser_Outlet_Flow - Assumed_Value_of_Condenser_Outlet_Flow) / Calculated_Value_of_Condenser_Outlet_Flow) > Relative_Error);
        fout << "fabs(Calculated_Value_of_Condenser_Outlet_Flow - Assumed_Value_of_Condenser_Outlet_Flow)" << ',' << fabs(Calculated_Value_of_Condenser_Outlet_Flow - Assumed_Value_of_Condenser_Outlet_Flow) << endl;
        fout << "fabs((Calculated_Value_of_Condenser_Outlet_Flow - Assumed_Value_of_Condenser_Outlet_Flow)" << ',' << fabs((Calculated_Value_of_Condenser_Outlet_Flow - Assumed_Value_of_Condenser_Outlet_Flow) / Calculated_Value_of_Condenser_Outlet_Flow) << endl;
        New_Steam_Consumption = Calculate_of_New_Steam_Consumption(High_Pressure_Cylinder_Steam_Consumption, Steam_Consumption_of_Feed_Pump_Turbine, Reheater_Steam_Consumption[1]);
        fout << "New_Steam_Consumption" << ',' << New_Steam_Consumption << endl;
        Calculated_the_Thermal_Power_of_the_Reactor = Calculate_of_Calculated_the_Thermal_Power_of_the_Reactor(New_Steam_Consumption, Blowdown_Rate_of_Steam_Generator, Enthalpy_of_Steam_at_the_Outlet_of_the_Steam_Generator, Saturated_Steam_Enthalpy_of_Steam_Generator, Actual_Feed_Water_Enthalpy, Primary_Circuit_Energy_Utilization_Coefficient);
        fout << "Calculated_the_Thermal_Power_of_the_Reactor" << ',' << Calculated_the_Thermal_Power_of_the_Reactor << endl;
        Calculated_Efficiency_of_Nuclear_Power_Plant = Calculate_of_Calculated_Efficiency_of_Nuclear_Power_Plant(Nuclear_Power_Plant_Output_Electric_Power, Calculated_the_Thermal_Power_of_the_Reactor);
        fout << "Calculated_Efficiency_of_Nuclear_Power_Plant" << ',' << Calculated_Efficiency_of_Nuclear_Power_Plant << endl;
    } while (fabs((Assume_Power_Plant_Efficiency - Calculated_Efficiency_of_Nuclear_Power_Plant) / Calculated_Efficiency_of_Nuclear_Power_Plant) > Absolute_Error);
    fout << "fabs(Assume_Power_Plant_Efficiency - Calculated_Efficiency_of_Nuclear_Power_Plant)" << ',' << fabs(Assume_Power_Plant_Efficiency - Calculated_Efficiency_of_Nuclear_Power_Plant) << endl;
    fout << "fabs((Assume_Power_Plant_Efficiency - Calculated_Efficiency_of_Nuclear_Power_Plant) / Calculated_Efficiency_of_Nuclear_Power_Plant)" << ',' << fabs((Assume_Power_Plant_Efficiency - Calculated_Efficiency_of_Nuclear_Power_Plant) / Calculated_Efficiency_of_Nuclear_Power_Plant) << endl;
    fout.close();
}

#endif // !THERMAL_EFFICIENCY_CALCULATE_H
