#include <Python.h>

static PyObject *py_plus(PyObject *self, PyObject *args){/*без (PyObject *self, PyObject *args) не заработало*/
  PyObject *pList;
  PyObject *pItem;
  Py_ssize_t n;
 

  if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &pList)) { /*считывание списка с проверкой*/
    PyErr_SetString(PyExc_TypeError, "parameter must be a list.");
    return NULL;
    }
  
  n = PyList_Size(pList);/*тут все методы работы со списком https://docs.python.org/3/c-api/list.html#c.PyList_GetItem*/
  return Py_BuildValue("n",n); /*возвращать надо PyObject, видимо, каждый раз надо конвертировать обратно*/
}
  

/* Описывает методы модуля */
static PyMethodDef ownmod_methods[] = {
{ 
    "pluss",          // название функции внутри python
     py_plus,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "plus function" // документация для функции внутри python
},
{ NULL, NULL, 0, NULL } 
// так называемый sentiel. Сколько бы элементов структуры 
// у вас не было, этот нулевой элемент должен быть всегда, и при этом быть последним
};

/* Описываем наш модуль */
static PyModuleDef simple_module = {    
    PyModuleDef_HEAD_INIT,   // обязательный макрос
    "my_pluss",               // my_plus.__name__
    "amazing documentation", // my_plus.__doc__
    -1,
    ownmod_methods           // сюда передаем методы модуля
};

// в названии функции обязательно должен быть префикс PyInit
PyMODINIT_FUNC PyInit_my_pluss(void) {
      PyObject* m;
      // создаем модуль
      m = PyModule_Create(&simple_module);
      // если все корректно, то эта проверка не проходит
      if (m == NULL)
          return NULL;
      return m;
}
