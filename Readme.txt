The project contains a serial version of a program that calculates an integral in range (0, 2*pi) ∫exp(-0.5*x)*cos(x)*dx,
as well as a parrallel version using tbb tasks. In order for the parallel version to work it requires a tbb library to be
included in the project. The serial version is calculated using a for loop in range (0, 2*pi) increasing the iterator in 
a size chosen in the "Konstante.h" header file. The parallel version is implemented based on an example of which calculates
Fibonacci's numbers using the same tasks. I've implemented a recursive function that splits the range by half, where the base
occurence (the final stage of the recursion) is when the range is less than 0.01. After that, using a for loop I sum up the results
of all the individual ranges. TBB tasks allow me to sum up those ranges in parallel making it much quicker for more accurate
calculations.

Note: The code is written in serbian language
