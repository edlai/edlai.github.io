// https://blog.csdn.net/fengbingchun/article/details/100834902
// https://leetcode.com/discuss/interview-question/operating-system/129663/what-is-the-difference-between-poll-epoll-and-select
/*
不像socket中connect、accept、recv這幾個函數屬於阻塞方式，而select函數屬於非阻塞方式。在使用select函數時，會經常用到四個宏FD_SET(將一個指定的文件描述符加入集合)、FD_CLR(將一個指定的文件描述符從集合中刪除)、FD_ISSET(檢查一個指定的文件描述符是否在集合中)、FD_ZERO(清空集合)。類型fd_set存放的是一組文件描述符的集合，在Linux系統中，如設備、管道、FIFO等都可通過文件描述符的形式來訪問。文件描述符在形式上是一個非負整數，實際上，它是一個索引值。套接字也是文件描述符。
*/