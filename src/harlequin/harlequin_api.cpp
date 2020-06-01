#include "harlequin_api.h"

int getArgNumber(PyObject* arg) {
    return sizeof(arg)/sizeof(PyObject);
}

PyObject* harlequin_add_dialog(PyObject* self, PyObject* args) {
    const char* dialog_text;
    if (PyArg_ParseTuple(args, "s", dialog_text)) {
        Dialog dialog {"", dialog_text};
        DialogManager::addDialog(dialog);
        return NULL;
    } else {
        return NULL;
    }
}