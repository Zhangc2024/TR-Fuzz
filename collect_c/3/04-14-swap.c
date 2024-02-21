#include <stdio.h>
#define swap(t, x, y) {	t _z;   \
                        _z = y; \
                        y = x;  \
                        x = _z; \
                       }

main(){
	int x = 1;
	int y = 2;
	printf ("x=%d y=%d\n", x, y);
	swap(int, x, y);
	printf ("x=%d y=%d", x, y);
}
