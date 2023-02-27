#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func1(void)
{
    char *p = (char*)calloc(1, sizeof(char) * 24);  // | 8 | 8 | 8 | red-zone1[24,32) | red-zone2 [32,40) | red-zone3 [40, 48)
	memset(p, 0x01, sizeof(*p));

	//write to red-zone1  [0,23)
	//p[24] = 0x00;  //=>0x0c067fff8000: fa fa 00 00 00 fa fa fa 00 00 00[fa]fa fa fa fa
	//p[31] = 0x00;  //=>0x0c067fff8000: fa fa 00 00 00 fa fa fa 00 00 00[fa]fa fa fa fa
	
	//write to red-zone3  [40,48) 
	//p[40] = 0x00;		//=>0x0c067fff8000: fa fa 00 00 00 fa fa fa 00 00 00 fa fa[fa]fa fa
	p[47] = 0x00;		//=>0x0c067fff8000: fa fa 00 00 00 fa fa fa 00 00 00 fa fa[fa]fa fa

	free(p);

	return 0;
}

int main(int argc, char *argv[])
{
    func1();
    return 0;
}
