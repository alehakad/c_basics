static PyObject *st_minus_st(PyObject *self, PyObject *args){
  PyObject *pList;
  PyObject *pList1;
  int i;
  Py_ssize_t n;


  if (!PyArg_ParseTuple(args, "O!O!", &PyList_Type, &pList, &PyList_Type,&pList1)) {
    PyErr_SetString(PyExc_TypeError, "parameters are wrong.");
    return NULL;
    }



  n = PyList_Size(pList);
  for(i=0;i<n;i++)
  {
	PyList_SetItem(pList,i,Py_BuildValue("d",PyFloat_AsDouble(PyList_GetItem(pList,i))-PyFloat_AsDouble(PyList_GetItem(pList1,i))));
		};
  Py_INCREF(pList);






  return pList;
}

