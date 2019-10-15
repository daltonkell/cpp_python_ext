#define PY_SSIZE_T_CLEAN

#include "Python.h" // PyObject, PyLong_FromLong, PyMethodDef, PyModuleDef, PyModuleDef_HEAD_INIT PyMODINIT_FUNC

/* Simple C++ extension for Python. Create a module "getone" and define a
 * function that simply returns the integer 1.
**/

static PyObject *method_getone(PyObject *self){
    return PyLong_FromLong(1);
}

/* Python interpreter needs to know about the methods, so we tell it which ones
 * are able to be called from this module here.
**/
static PyMethodDef GetOneMethods[] = { // array of structs 
    {
        "getone",                             // method name
        (PyCFunction)method_getone,           // method itself; must be cast as a function;
                                              //   in C, this does not need to happen
        METH_NOARGS,
        "Return 1, called from a C++ program" // docstring
    },
    {NULL, NULL, 0, NULL} // I don't know what this does yet
};

/* A struct used to define how the module is represented
 * when imported in Python.
**/
static struct PyModuleDef getonemodule = {
    PyModuleDef_HEAD_INIT,
    "getone", // name of module
    "Demonstration of a Python interface to a C++ program",
    -1, // indicates no support for sub-interpretation
    GetOneMethods // reference to methods in the module
};

/* When Python imports this module, this method will be called. */
PyMODINIT_FUNC PyInit_getone(void){
    return PyModule_Create(&getonemodule);
}
