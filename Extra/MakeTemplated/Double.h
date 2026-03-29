// Simple file with a templated function

#ifndef DOUBLE_H
#define DOUBLE_H

template<typename T>
T doubleIt(T val) {
  return 2 * val;
}

#endif // DOUBLE_H
