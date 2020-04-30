#include <Python.h>

static PyObject *st_div_r(PyObject *self, PyObject *args){
  PyObject *pList;
  PyObject *nList;
  Py_ssize_t n;
  double x;
  int i;

  if (!PyArg_ParseTuple(args, "O!d", &PyList_Type, &pList, &x)) {
    PyErr_SetString(PyExc_TypeError, "parameters are wrong.");
    return NULL;
    }



  n = PyList_Size(pList);
  nList = PyList_New(n);
  for(i=0;i<n;i++)
  {
	PyList_SetItem(nList,i,Py_BuildValue("d",PyFloat_AsDouble(PyList_GetItem(pList,i))/x));
		};
  Py_INCREF(pList);
  return nList;
}
static PyObject *st_mul_r(PyObject *self, PyObject *args){
  PyObject *pList;
  PyObject *nList;
  Py_ssize_t n;
  double x;
  int i;

  if (!PyArg_ParseTuple(args, "O!d", &PyList_Type, &pList, &x)) {
    PyErr_SetString(PyExc_TypeError, "parameters are wrong.");
    return NULL;
    }



  n = PyList_Size(pList);
  nList = PyList_New(n);
  for(i=0;i<n;i++)
  {
	PyList_SetItem(nList,i,Py_BuildValue("d",PyFloat_AsDouble(PyList_GetItem(pList,i))*x));
		};
  Py_INCREF(pList);
  return nList;
}
static PyObject *st_change(PyObject *self, PyObject *args){
  PyObject *pList;
  PyObject *tmp1;
  PyObject *tmp2;
  int i,j;
  Py_ssize_t n;


  if (!PyArg_ParseTuple(args, "O!ll", &PyList_Type, &pList,&i,&j)) {
    PyErr_SetString(PyExc_TypeError, "parameters are wrong.");
    return NULL;
    }



  n = PyList_Size(pList);
  tmp1 = PyList_GetItem(pList,i);
  tmp2 = PyList_GetItem(pList,j);
  Py_INCREF(tmp1);
  Py_INCREF(tmp2);
  PyList_SetItem(pList,i,tmp2);
  PyList_SetItem(pList,j,tmp1);
  Py_INCREF(pList);





  return pList;
}
static PyObject *st_minus_st(PyObject *self, PyObject *args){
  PyObject *pList;
  PyObject *pList1;
  PyObject *nList;
  
  int i;
  Py_ssize_t n;


  if (!PyArg_ParseTuple(args, "O!O!", &PyList_Type, &pList, &PyList_Type,&pList1)) {
    PyErr_SetString(PyExc_TypeError, "parameters are wrong.");
    return NULL;
    }



  n = PyList_Size(pList);
  nList = PyList_New(n);
  for(i=0;i<n;i++)
  {
	PyList_SetItem(nList,i,Py_BuildValue("d",PyFloat_AsDouble(PyList_GetItem(pList,i))-PyFloat_AsDouble(PyList_GetItem(pList1,i))));
		};
  Py_INCREF(pList);






  return nList;
}
static PyObject *trm_det(PyObject *self, PyObject *args){
  PyObject *pList;
  int i;
  double res = 1.0;
  Py_ssize_t n;


  if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &pList)) {
    PyErr_SetString(PyExc_TypeError, "parameters are wrong.");
    return NULL;
    }



  n = PyList_Size(pList);
  for(i=0;i<n;i++)
  {
	res = res*PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(pList,i),i));
		};







  return Py_BuildValue("d",res);
}
static PyObject *det(PyObject *self, PyObject *args){
  PyObject *pList;
  PyObject *tuple1;
  PyObject *tuple2;
  PyObject *tuple3;
  PyObject *tuple4;
  PyObject *list1;
  PyObject *list2;
  PyObject *list3;
  PyObject *first_list;
  PyObject *second_list;
  int i,j;
  Py_ssize_t n;


  if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &pList)) {
    PyErr_SetString(PyExc_TypeError, "parameters are very wrong.");
    return NULL;
    }



  n = PyList_Size(pList);

for(j=0;j<n-1;j++){  
  	first_list =  PyList_GetItem(pList, j);
  	tuple1 = PyTuple_New(2);
  	PyTuple_SetItem(tuple1, 0, first_list);
  	PyTuple_SetItem(tuple1, 1, PyList_GetItem(first_list,j));
  	list1 = st_div_r(pList, tuple1); 

  	for(i=j+1;i<n;i++){
  
  		second_list =  PyList_GetItem(pList, i);
  		tuple3 = PyTuple_New(2);
  		PyTuple_SetItem(tuple3, 0, list1);
  		PyTuple_SetItem(tuple3, 1, PyList_GetItem(second_list, j));
  		list2 = st_mul_r(pList, tuple3);
  		tuple2 = PyTuple_New(2);
  		PyTuple_SetItem(tuple2, 0, second_list);
  		PyTuple_SetItem(tuple2, 1, list2);
  		list3 = st_minus_st(pList,tuple2);
  

  		PyList_SetItem(pList , i, list3);
	}
}	 
  
 
  Py_INCREF(pList); 
  tuple4 = PyTuple_New(1);
  PyTuple_SetItem(tuple4, 0, pList);
  
  return trm_det(pList,tuple4);
}



/* ќписывает методы модул€ */
static PyMethodDef ownmod_methods[] = {
{
    "st_div_r",          // название функции внутри python
     st_div_r,        // функци€ C
     METH_VARARGS,   // макрос, по€сн€ющий, что функци€ у нас с аргументами
     "divides string by real number, creating a new list" // документаци€ дл€ функции внутри python
},
{
    "st_mul_r",          // название функции внутри python
     st_mul_r,        // функци€ C
     METH_VARARGS,   // макрос, по€сн€ющий, что функци€ у нас с аргументами
     "multiplies string by real number, creating a new list" // документаци€ дл€ функции внутри python
},
{
    "st_change",
     st_change,
     METH_VARARGS,
     "changes two str in a matrix"

},
{
     "trm_det",
     trm_det,
     METH_VARARGS,
     "counts det of tr matrix"



},
{
    "st_minus_st",
     st_minus_st,
     METH_VARARGS,
     "list minus list, creating a new list"

},
{
    "det",
     det,
     METH_VARARGS,
     "counts det"



},
{ NULL, NULL, 0, NULL }
// так называемый sentiel. —колько бы элементов структуры
// у вас не было, этот нулевой элемент должен быть всегда, и при этом быть последним
};

/* ќписываем наш модуль */
static PyModuleDef simple_module = {
    PyModuleDef_HEAD_INIT,   // об€зательный макрос
    "my_det",               // my_plus.__name__
    "amazing documentation", // my_plus.__doc__
    -1,
    ownmod_methods           // сюда передаем методы модул€
};

// в названии функции об€зательно должен быть префикс PyInit
PyMODINIT_FUNC PyInit_my_det(void) {
      PyObject* m;
      // создаем модуль
      m = PyModule_Create(&simple_module);
      // если все корректно, то эта проверка не проходит
      if (m == NULL)
          return NULL;
      return m;
}
