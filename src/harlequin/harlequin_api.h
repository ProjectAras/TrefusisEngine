//
// Created by elsa on 14.05.2020
//

// An old school C header file for functions
// exposed to Python. This is the Harlequin API.
#ifndef TREFUSISENGINE_HARLEQUIN_H
#define TREFUSISENGINE_HARLEQUIN_H

#include <Python.h>
#include "DialogManager.hpp"

PyObject *harlequin_add_dialog(PyObject *self, PyObject *args);
static PyMethodDef harlequinMethods[] = {
    {"add_dialog", harlequin_add_dialog, METH_VARARGS, "Add a new dialog to the game."},
    {NULL, NULL, 0, NULL}};
static PyModuleDef harlequinModule = {
    PyModuleDef_HEAD_INIT, "harlequin", NULL, -1, harlequinMethods,
    NULL, NULL, NULL, NULL};

static PyObject *PyInit_harlequin(void)
{
    return PyModule_Create(&harlequinModule);
}
#endif