#include <math.h>

/*  Compute the sum of (ary - y0)**2 */
double c_sum_of_squares(double * ary, int ary_size, int buf_size, double y0){
    int ary_idx, buf_idx, from, to;

    if (buf_size < 1){
    	buf_size = ary_size;
    }

    double * buffer;
    buffer = (double *) malloc(ary_size*sizeof(double));
    if (!buffer){
    	// TODO actual exception, but should probably
    	// allocate using python anyways
    	return NAN;
    }

    double result = 0;
    for (from=0 ; from < ary_size ; from+=buf_size){
    	to = from + buf_size;
    	if (to > ary_size){
    		to = ary_size;
    	}

    	// subtract y0 from each element in this block
    	// similiar to numpy.subtract
    	buf_idx = 0;
    	for (ary_idx=from ; ary_idx < to ; ary_idx++){
    		buffer[buf_idx] = ary[ary_idx] - y0;
    		buf_idx++;
    	}

    	// compute the square of each element in this block
    	// similar to numpy.square
    	for (buf_idx=0 ; buf_idx<(to-from) ; buf_idx++){
    		buffer[buf_idx] = buffer[buf_idx] * buffer[buf_idx];
    	}

    	// compute the sum of elements in this block
    	// similar to numpy.add.reduce
    	for (buf_idx=0 ; buf_idx<(to-from) ; buf_idx++){
    		result += buffer[buf_idx];
    	}
    }

    return result;
}
