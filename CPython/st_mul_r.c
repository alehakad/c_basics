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