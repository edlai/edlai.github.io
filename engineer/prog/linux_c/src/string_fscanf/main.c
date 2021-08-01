#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEBUG 0
#if 1 /* 1,run it*/
#define _system(msg, args...) \
	do                          \
	{                           \
		system(msg);              \
	} while (0)
#else
#define _system(msg, args...) \
	do                          \
	{                           \
	} while (0)
#endif
#define SUPPORT_I2C_LCM_TEST 0
unsigned long byte = 0;
unsigned long baseByte = 0;
#define WAN_DEV "ppp0"
//#define WAN_DEV	"eth0"
#define CHECK_TIME 5 //5: milliseconds
static int c = 1;		 // the first 30sec or the 2nd 30secs in 1 min
/* ***************************************
 *		Export Diagnostic program PID
 * ***************************************/
void export_pid()
{
	FILE *f;
	f = fopen("/var/run/wwan-led.pid", "w");
	fprintf(f, "%d", getpid());
	fclose(f);
}
// ****************************************
int is_devices_exist(void)
{
	// ------ Is devices exist
	int ret;
	int inet_sock;
	struct ifreq ifr;
	inet_sock = socket(AF_INET, SOCK_DGRAM, 0);
	strcpy(ifr.ifr_name, WAN_DEV);
	if (ioctl(inet_sock, SIOCGIFADDR, &ifr) < 0)
	{
#if DEBUG
		printf("Cannot get %s ip_addr\n", WAN_DEV);
#endif
		ret = 0;
	}
	else
	{
		//printf("%s\n", inet_ntoa(((struct sockaddr_in*)&(ifr.ifr_addr))->sin_addr));
#if DEBUG
		printf("Got %s ip_addr\n", WAN_DEV);
#endif
		ret = 1;
	}
	close(inet_sock);
	return ret;
}
// *****************************************
int is_rx_packets_increase(void)
{
	FILE *net_devs;
	char buf[1024];
	char interface[32];
	int ret = 0;
	net_devs = fopen("/proc/net/dev", "r");
	if (net_devs == NULL)
	{
#if DEBUG
		printf("Can't open /proc/net/dev for reading\n");
#endif
		ret = 0;
		goto ret_main;
	}
	while (1)
	{
		if (fscanf(net_devs, "%32s %lu %1024[^\n]", interface, &byte, buf) <= 0)
		{
			break;
		}
		if (strstr(interface, WAN_DEV) > 0)
		{
#if DEBUG
			printf("(org)%lu <=> %lu\n", baseByte, byte);
#endif
			if (baseByte != byte)
			{
#if DEBUG
				printf("--> no equ \n");
#endif
				baseByte = byte;
				ret = 1;
			}
			else
			{
				;
				// not equ
#if DEBUG
				printf("--> equ \n");
#endif
			}
		}
		else
		{
			//printf("no ppp0 \n");
		}
	}
	fclose(net_devs);
ret_main:
	return ret;
}
/************************

*/
/////////////////////////
int is_rx_tx_zero(void)
{ /* ezro,1; not zero,0 */

	FILE *net_devs;
	char buf[1024];
	char interface[32];
	int ret = 0;
	net_devs = fopen("/proc/net/dev", "r");
	if (net_devs == NULL)
	{
#if DEBUG
		printf("Can't open /proc/net/dev for reading\n");
#endif
		ret = 0;
		goto ret_main;
	}
	while (1)
	{
		unsigned long Txbyte = 0;
		unsigned long Rxbyte = 0;

		unsigned long tmp[7];

		/* ex:face |bytes    packets errs drop fifo frame compressed multicast|bytes    packets */
		/* ppp0:     410      11    0    0    0     0          0         0      575      14 */
		if (fscanf(net_devs, "%32s %lu %lu %lu %lu %lu %lu %lu %lu %lu %1024[^\n]", interface, &Rxbyte,
							 tmp, tmp + 1, tmp + 2, tmp + 3, tmp + 4, tmp + 5, tmp + 6, &Txbyte, buf) <= 0)
		{
			break;
		}
		if (strstr(interface, WAN_DEV) > 0)
		{
			if (0 == Rxbyte && 0 == Txbyte)
				ret = 1; /* yes, no packet*/
		}
		else
		{
			;
			//printf("no ppp0 \n");
		}
	}
	fclose(net_devs);
ret_main:
	return ret;
}
//-------------------------------------------------------------------------
void get_current_time(void)
{
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv, &tz);
	printf("tv_sec:%d", tv.tv_usec);
	//printf("c(%d)\n",c);
}
void wan_led_off(void)
{
#if DEBUG
	printf("-X-\n");
#endif
	_system("gpio 1 1 3 0"); // turn-off wwan-led
}
void wan_led_on(void)
{
#if DEBUG
	printf("-O-\n");
#endif
	_system("gpio 1 1 3 3"); // turn-on wwan-led
}

//-------------------------------------------------------------------------
void onoff_led(void)
{
#if DEBUG
	printf("************************************** \n");
#endif

	if (1 == c)
	{
		if (is_devices_exist() && !is_rx_tx_zero())
		{
			// devices work
			wan_led_on(); // turn-on wwan-led
		}
		else
		{
			wan_led_off(); // turn-off wwan-led
		}
		c = 0;
	}
	else
	{
		if (is_devices_exist() && !is_rx_tx_zero())
		{
			// devices work
			if (is_rx_packets_increase())
			{
				wan_led_off(); // turn-off wwan-led
			}
			else
			{
				wan_led_on(); // turn-on wwan-led
			}
		}
		else
		{
			wan_led_off(); // turn-off wwan-led
		}
		c = 1;
#if SUPPORT_I2C_LCM_TEST
		_system("echo \"  `date | awk '{print $4}'`\" > /dev/lcm");
#endif
	}
}

//-------------------------------------------------------------------------
void sigroutine(int signo)
{
	switch (signo)
	{
	case SIGALRM:
		//printf("Catch a signal --- SIGALRM \n");
		signal(SIGALRM, sigroutine);
#if DEBUG
		get_current_time();
#endif
		onoff_led();
		break;
	}
	return;
}

//-------------------------------------------------------------------------
int main()
{

	struct itimerval value, ovalue;

	export_pid();
	printf("[WWAN-LED] %s\n", __TIME__);

	signal(SIGALRM, sigroutine);
	value.it_value.tv_sec = 0;
	value.it_value.tv_usec = 100000 * CHECK_TIME;
	value.it_interval.tv_sec = 0;
	value.it_interval.tv_usec = 100000 * CHECK_TIME;
	setitimer(ITIMER_REAL, &value, &ovalue);
	for (;;)
		;
	return 0;
}
