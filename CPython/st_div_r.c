static PyObject *st_div_r(PyObject *self, PyObject *args){
  PyObject *pList;

  Py_ssize_t n;
  double x;
  int i;

  if (!PyArg_ParseTuple(args, "O!d", &PyList_Type, &pList, &x)) {
    PyErr_SetString(PyExc_TypeError, "parameter are wrong.");
    return NULL;
    }



  n = PyList_Size(pList);
  for(i=0;i<n;i++)
  {
	PyList_SetItem(pList,i,Py_BuildValue("d",PyFloat_AsDouble(PyList_GetItem(pList,i))/x));
		};
  Py_INCREF(pList);// чтобы вернуть лист
  return pList;
}
