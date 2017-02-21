#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include "rational.h"

class operation_on_boolean_exception : public std::runtime_error{
public:
	operation_on_boolean_exception(): runtime_error("Attempted operation on boolean"){}
};
class invalid_input_exception : public std::runtime_error{
public:
	invalid_input_exception(): runtime_error("Attempted operation on boolean"){}
};
