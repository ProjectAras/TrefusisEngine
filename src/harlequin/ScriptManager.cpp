//
// Created by elsa on 21.04.2020.
//

#include "ScriptManager.h"
#ifdef DEBUG
#include <iostream>
#endif
#include "../trefusisInternals/TrefusisConfig.h"

ScriptManager::ScriptManager() {
    PyImport_AppendInittab("harlequin", &PyInit_harlequin);
    Py_Initialize();
    PyRun_SimpleString("import sys;import os;sys.path.append(os.getcwd() + '/../resources/scripts/')");
}

void ScriptManager::loadScript(std::string mapName) {
    PyObject* pName, *pFunc;
#ifdef DEBUG
    std::cout << "DEBUG: Importing " << mapName << " from " << TrefusisConfig::scriptFile << "\n";
#endif
    pName = PyUnicode_DecodeFSDefault("main");
    if (pName == NULL) {
        std::cout << "ERROR: This error should not be here. Please panic.\n";
        return;
    }
    this->pModule = PyImport_Import(pName);
    if (pModule == NULL) {
        std::cout << "ERROR: Module could not be imported, perhaps path is wrong or ends with .py?\n";
        return;
    }
    pFunc = PyObject_GetAttrString(this->pModule, mapName.c_str());
#ifdef DEBUG
    if (pFunc == NULL)
        std::cout << "ERROR: Function import failed, did you named your function correctly?";
#endif
    PyObject_CallObject(pFunc, NULL);
    Py_DECREF(pFunc);
}

ScriptManager::~ScriptManager() {
    Py_DECREF(pModule);
}