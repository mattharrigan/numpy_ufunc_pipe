from distutils.core import setup, Extension
import numpy
from Cython.Distutils import build_ext

setup(
    cmdclass={'build_ext': build_ext},
    ext_modules=[Extension("blocked_alg",
                 sources=["_sum_of_squares.pyx", "sum_of_squares.c"],
                 include_dirs=[numpy.get_include()])],
    			 extra_compile_args=["-O3"]
)
