/*
 * Created By : Team Fluffy
 * File Name : gsk_test.cpp
 * Creation Date : Wed 27 Jan 2016 10:16:43 AM PST
 * Last Modified : Mon 22 Feb 2016 12:27:19 PM PST
 * Purpose : this is a simple test program for the 
 * gsk classes.
 */
#include <map>
#include <cstdlib>
#include <pthread.h>
#include <mutex>
#include <condition_variable>
#include <iostream> 
#include <ctime>
#include "fluffy.h"
#include "gsk.h"
//#include <gsk>
#define VERNUM	1
#define DEBUG		1

/*
 *
 class FluffyMsg
 {
 public:
 Hdr hdr;
 Security security;
 Addr to;
 Addr from;
 Payload pyld;
 }
 *
 *
 */

int main(int argc, const char *argv[])
{
	
	PyObject *pName, *pModule, *pDict, *pFunc;
    PyObject *pArgs, *pValue;
    int i;
    if (argc < 2) {
        fprintf(stderr,"Usage: call funcname [args]\n");
        return 1;
    }

    Py_Initialize();
    //PyRun_SimpleString("import sys\n"
    //"sys.path.append(\".\")\n");
    pName = PyString_FromString("fluffy");

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, argv[1]);

        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(argc - 2);
            for (i = 0; i < argc - 2; ++i) {
	            pValue = PyString_FromString(argv[i + 2]);
                if (!pValue) {
                    Py_DECREF(pArgs);
                    Py_DECREF(pModule);
                    fprintf(stderr, "Cannot convert argument\n");
                    return 1;
                }

                PyTuple_SetItem(pArgs, i, pValue);
            }
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
	            //printf("Result of call: %ld\n", PyInt_AsLong(pValue));
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return 1;
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", argv[2]);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
        return 1;
    }
    
    Py_Finalize();
    return 0;
}

