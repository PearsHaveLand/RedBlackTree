#include "pow.h"
unsigned long pow(int height){
	unsigned long ret = 1;
	for(int i = 0; i < height; i++){
		ret *= 2;
	}
	return ret;
}
