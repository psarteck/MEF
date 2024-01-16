#include <stdio.h>
#include <stdlib.h>

int returnQ(int t){
	if(t == 1){
		return 9;
	}
	else if(t == 2||t == 3){
		return 3;
	}
    return 0;
}
