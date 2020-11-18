#pragma once

template<typename T>
void deepCopy(T*& dest, const T* src, const int srcSize=0){
	if (src) {
		dest = new T[srcSize]{};
		for (int i = 0; i < srcSize; i++) {
			dest[i] = src[i];
		}
	}
}


int len(const char* arr){
  int i=0;
  while(arr[i]!='\0'){
    i++;
  }
  return i;
}


void clearArr(char*& dest){
  for(int i=0; i<len(dest);i++){
    dest[i]='\0';
  }
}
