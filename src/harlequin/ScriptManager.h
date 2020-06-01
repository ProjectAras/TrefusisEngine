//
// Created by elsa on 21.04.2020.
//

#ifndef TREFUSISENGINE_SCRIPTMANAGER_H
#define TREFUSISENGINE_SCRIPTMANAGER_H
#include <python3.8/Python.h>
#include <string>
#include <iostream>
#include "harlequin_api.h"

class ScriptManager {
private:
    PyObject *pModule;
public:
    ScriptManager();
    ~ScriptManager();
    void loadScript(std::string fileName);

};


#endif //TREFUSISENGINE_SCRIPTMANAGER_H
