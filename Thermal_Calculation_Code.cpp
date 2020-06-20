#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <fstream>
#include "Python.h"
#include "IAPWS.h"
#include "Known_Conditions_and_Given_Parameters.h"
#include "The_Main_Thermal_Parameters_Determined.h"
#include "Parameters_Output.h"
#include "Steam_Volume_Relation.h"
#include "Thermal_Efficiency_Calculation.h"

#define re register
#define IOS ios::sync_with_stdio(false)


using namespace std;

int main()
{
	IOS;
    Py_SetPythonHome(L"G:\\ProgramData\\Miniconda3");
    Py_Initialize();
    //PyRun_SimpleString("import sys");
    //PyRun_SimpleString("sys.path.append('./')");
    PyRun_SimpleString("from iapws import IAPWS97");
    Known_Conditions_and_Given_Parameters_Output();
    The_Main_Thermal_Parameters_Determined_Output();
    Thermal_Efficiency_Calculate();
    Py_Finalize();
	return 0;
}