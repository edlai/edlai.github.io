//Based on https://www.kernel.org/doc/Documentation/i2c/dev-interface
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>

#include <linux/types.h>

#include <linux/i2c-dev.h>

#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h>


int main() {
    const int adapter_nr = 2;
    char filename[20];
    snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
    const int file = open(filename, O_RDWR);
    if (file < 0) {
        printf("Oh dear, something went wrong with open()! %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // The I2C address. Got it from `i2cdetect -y 2;`
    const int addr = 0x3f;

    if (ioctl(file, I2C_SLAVE, addr) < 0) {
        printf("Oh dear, something went wrong with ioctl()! %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Device register to access.
    const __u8 reg = 0x10;
    // Using SMBus commands
    const __s32 result = i2c_smbus_read_byte_data(file, reg);
    if (result < 0) {
         // ERROR HANDLING: i2c transaction failed
         printf("Oh dear, something went wrong with i2c_smbus_read_byte_data()>i2c_smbus_access()>ioctl()! %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        // res contains the read word
        printf("0x%+02x\n", result);
    }

    close(file);

    return(EXIT_SUCCESS);
}