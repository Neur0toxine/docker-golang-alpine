#include <unistd.h>
#include <fcntl.h>

int main() {
    // TODO: Use this code to test resulting images.
    // Should not call faccessat2 under the hood.
	faccessat(0, "/",  R_OK, AT_EACCESS);

	return 0;
}