
/*
  
  Reference: https://gist.github.com/nasamuffin/a52e2b0c0eb97a9f5b75
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <linux/fb.h>

#define GPIO0_BASE 0x44E07000
#define GPIO1_BASE 0x4804C000
#define GPIO2_BASE 0x481AC000
#define GPIO3_BASE 0x481AE000

#define GPIO_SIZE  0x00000FFF

// OE: 0 is output, 1 is input
#define GPIO_OE  0x14d
#define GPIO_IN  0x14e
#define GPIO_OUT 0x14f

#define USR0_LED (1<<21)
#define USR1_LED (1<<22)
#define USR2_LED (1<<23)
#define USR3_LED (1<<24)

int mem_fd;
char *gpio_mem, *gpio_map;

// I/O access
volatile unsigned *gpio;

static void io_setup(void)
{
    // Enable all GPIO banks
    // Without this, access to deactivated banks (i.e. those with no clock source set up) will (logically) fail with SIGBUS
    // Idea taken from https://groups.google.com/forum/#!msg/beagleboard/OYFp4EXawiI/Mq6s3sg14HoJ
    system("echo 5 > /sys/class/gpio/export");
    system("echo 65 > /sys/class/gpio/export");
    system("echo 105 > /sys/class/gpio/export");

    /* open /dev/mem */
    if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
            printf("can't open /dev/mem \n");
            exit (-1);
    }

    /* mmap GPIO */
    gpio_map = (char *)mmap(
            0,
            GPIO_SIZE,
            PROT_READ|PROT_WRITE,
            MAP_SHARED,
            mem_fd,
            GPIO1_BASE
    );
    if (gpio_map == MAP_FAILED) {
            printf("mmap error %d\n", (int)gpio_map);
            exit (-1);
    }

    // Always use the volatile pointer!
    gpio = (volatile unsigned *)gpio_map;

    // Get direction control register contents
    unsigned int creg = *(gpio + GPIO_OE);

    // Set outputs
    creg = creg & (~USR0_LED);
    creg = creg & (~USR1_LED);
    creg = creg & (~USR2_LED);
    creg = creg & (~USR3_LED);

    // Set new direction control register contents
    *(gpio + GPIO_OE) = creg;
}



int main(int argc, char **argv)
{
    io_setup();
    while (1) {
        // Set LEDs
        *(gpio + GPIO_OUT) = *(gpio + GPIO_OUT) | USR0_LED;
        *(gpio + GPIO_OUT) = *(gpio + GPIO_OUT) | USR1_LED;
        *(gpio + GPIO_OUT) = *(gpio + GPIO_OUT) | USR2_LED;
        *(gpio + GPIO_OUT) = *(gpio + GPIO_OUT) | USR3_LED;

        sleep(1);

        // Clear LEDs
        *(gpio + GPIO_OUT) = *(gpio + GPIO_OUT) & (~USR0_LED);
        *(gpio + GPIO_OUT) = *(gpio + GPIO_OUT) & (~USR1_LED);
        *(gpio + GPIO_OUT) = *(gpio + GPIO_OUT) & (~USR2_LED);
        *(gpio + GPIO_OUT) = *(gpio + GPIO_OUT) & (~USR3_LED);

        sleep(1);
    }

    return 0;
}