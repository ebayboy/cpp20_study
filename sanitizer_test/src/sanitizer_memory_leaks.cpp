#include <stdlib.h>

char func4() {
    char *x = (char*)malloc(10 * sizeof(char*));
    return x[5];
}

int main(int argc, char *argv[]) {
    func4();
    return 0;
}

