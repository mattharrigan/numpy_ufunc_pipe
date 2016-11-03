""" Example of wrapping a C function that takes C double arrays as input using
    the Numpy declarations from Cython """

# cimport the Cython declarations for numpy
cimport numpy as np

# if you want to use the Numpy-C-API from Cython
# (not strictly necessary for this example, but good practice)
np.import_array()

# cdefine the signature of our c function
cdef extern from "sum_of_squares.h":
    double c_sum_of_squares (double * ary, int ary_size, int block_size, double y0)

# create the wrapper code, with numpy type annotations
def sum_of_squares(np.ndarray[double, ndim=1, mode="c"] ary not None,
                     int block_size, double y0):
    return c_sum_of_squares(<double*> np.PyArray_DATA(ary),
                ary.shape[0],
                block_size,
                y0)
