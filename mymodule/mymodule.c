#define PY_SSIZE_T_CLEAN
#include <Python.h>

// C 함수를 정의합니다.
static int square(int x) {
    return x * x;
}

// C 함수를 Python 함수로 래핑합니다.
static PyObject* py_square(PyObject* self, PyObject* args) {
    int x;

    if (!PyArg_ParseTuple(args, "i", &x)) {
        return NULL;
    }

    int result = square(x);

    return PyLong_FromLong(result);
}

// 모듈의 메서드 테이블을 정의합니다.
static PyMethodDef SquareMethods[] = {
    {"square",  py_square, METH_VARARGS, "Calculate the square of a number."},
    {NULL, NULL, 0, NULL}  // Sentinel
};

// 모듈 정의를 만듭니다.
static struct PyModuleDef squaremodule = {
   PyModuleDef_HEAD_INIT,
   "square",   // name of module
   NULL,       // module documentation, may be NULL
   -1,         // size of per-interpreter state of the module
   SquareMethods
};

// 모듈 초기화 함수를 정의합니다.
PyMODINIT_FUNC PyInit_mymodule(void)
{
    return PyModule_Create(&squaremodule);
}