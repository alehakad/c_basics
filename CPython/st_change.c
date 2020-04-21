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
