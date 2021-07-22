//https://www.itread01.com/content/1533296448.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>   // gettimeofday sleep usleep
#include <sys/types.h> // open
#include <sys/stat.h>  // open
#include <fcntl.h>     // open
#include <errno.h>      // error
#include <unistd.h>     // close
#include <linux/rtc.h>  // rtc_commadn RTC_IRQP_SET / RTC_PIE_ON / RTC_PIE_OFF
#include <sys/ioctl.h>  // ioctl
/**g++ -o timer_test time_test.cc*/

/* 定義log輸出宏 */
#define DEB_LOG(fmat,...)  printf("%s:%d_%s() "fmat"\n", \
    __FILE__, __LINE__, __FUNCTION__,##__VA_ARGS__)

/*設定時鐘頻率，頻率可用範圍是2~8192，一定要是2的n次方，8192時，一次約122微妙，*/
#define FREQ 8192
#define USEC_PER_SECOND 1000000
/*根據輸入的等待待時間（毫秒）,計算循環次數*/
#define CALC_CNT(millseconds) (millseconds * 1000.0 / USEC_PER_SECOND * FREQ + 0.5)


struct timeval tvs, tve;
void showTime(int startStop, long sleepT, const char* msg) {
    if (1 == startStop) {
        gettimeofday(&tvs, 0);   // 記錄定時器開始時間
    } else {
        gettimeofday(&tve, 0);   // 記錄定時器結束時間
        DEB_LOG("%s:    [%ldus] [%ldus]", msg, sleepT,
                (tve.tv_sec - tvs.tv_sec) * 1000000LL
                        + (tve.tv_usec - tvs.tv_usec));
    }
}

/* * 打開RTC時鐘設備
 * freq： RTC 時鐘的頻率
 * fd：  讀取RTC時鐘的fd * */
int openRTC(int freq, int* fd) {
    /* 打開 RTC 時間設備 */
    *fd = open("/dev/rtc", O_RDONLY);
    if (*fd < 0) {
        DEB_LOG("open /dev/rtc NG, errno=%d msg=%s", errno, strerror(errno));
        return -1;
    }

    /* 設定 RTC 的時鐘頻率   2~8192Hz，最小精度為123微秒*/
    if (ioctl(*fd, RTC_IRQP_SET, freq) < 0) {
        DEB_LOG("ioctl(RTC_IRQP_SET)");
        close(*fd);
        return -1;
    }
    /* 啟動 RTC 時鐘  */
    if (ioctl(*fd, RTC_PIE_ON, 0) < 0) {
        DEB_LOG("ioctl(RTC_PIE_ON)");
        close(*fd);
        return -1;
    }
    return 0;
}

/* * 關閉RTC時鐘設備
 * fd：  讀取RTC時鐘的fd * */
void closeRTC(int fd) {
    /* 關閉 RTC 時鐘計時  */
    ioctl(fd, RTC_PIE_OFF, 0);
    /* 關閉 RTC 裝置 */
    close(fd);
}

/*使用ioctl的情況下的，計時器函數*/
int rtcTimer(int millseconds, int fd) {
    int loopNum = CALC_CNT(millseconds);
    unsigned long data = 0;
    for (int i = 0; i < loopNum; i++) {
        /*read一次的時間 = 1秒/時鐘頻率 (頻率範圍 2~8192,最小精度為123微秒)*/
        if (read(fd, &data, sizeof(unsigned long)) < 0) {
            return -1;
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    int sleepMs = 3;       // ms
    int sleepLoop = 5000;
    long sleepT = sleepMs * sleepLoop * 1000;
    /*##############  sleep ############################*/
    sleep(1);       // sleep 1秒

    /*##############  使用 usleep 做定時 #################*/
    showTime(1,sleepT,"usleep");
    for (int i = 0; i < sleepLoop; ++i) {
        usleep(sleepMs * 1000); // 等待單位微秒
    }
    showTime(2,sleepT,"usleep");

    /*##############  使用 select 做定時 ###################*/
    showTime(1,sleepT,"select");
    struct timeval wait_time;
    gettimeofday(&tvs, 0);
    for (int i = 0; i < sleepLoop; i++) {
        wait_time.tv_sec = 0;                     //秒
        wait_time.tv_usec = sleepMs * 1000;       //微妙
        select(0, NULL, NULL, NULL, &wait_time);  //使用select等待   ，10
    }
    showTime(2,sleepT,"select");

    /*##############  使用實時時鐘 RTC 做定時 ################*/
    // 打開 RTC 時鐘
    int fd;
    int ret = openRTC(FREQ, &fd);
    if (0 != ret) {
        DEB_LOG("openRTC error");
        return -1;
    }
    /* 使用 RTC 時鐘計時   */
    showTime(1,sleepT,"ioctl RTC");
    for (int i = 0; i < sleepLoop; ++i) {
        rtcTimer(sleepMs, fd); /* 調用定時器函數 */
    }
    showTime(2,sleepT,"ioctl RTC");
    closeRTC(fd); //關閉 RTC 時鐘
    return 0;
}