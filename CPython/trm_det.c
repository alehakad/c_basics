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
