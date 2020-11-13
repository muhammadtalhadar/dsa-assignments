#pragma once
using namespace std;

template<typename T>
void deepCopy(T*& dest, const T* src, const int srcSize=0){
	if (src) {
		dest = new T[srcSize]{};
		for (int i = 0; i < srcSize; i++) {
			dest[i] = src[i];
		}
	}
}