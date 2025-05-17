#include <linux/init.h>
#include <linux/module.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/net.h>
#include <linux/in.h>
#include <linux/inet.h>
#include <net/sock.h>
#include <linux/icmp.h>

#define HOST_IP "127.0.0.1"
#define HOST_PORT 5678

MODULE_AUTHOR("John Doe");
MODULE_DESCRIPTION("ICMP protocoll handler");
MODULE_LICENSE("GPL");

static size_t set_socket(void){
    //creating socket
    static struct socket *sock = NULL;
    size_t socket_fd = sock_create(AF_INET, SOCK_RAW, IPPROTO_ICMP, &sock);
    if(socket_fd<0) pr_err("Socket fd was not given");
    return socket_fd;
}

static struct sockaddr_in set_addr(void){
    //setting up an address to send data
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(HOST_PORT);
    address.sin_addr.s_addr = in_aton(HOST_IP);
    return address;
}

static struct icmphdr set_icmp(void){
    struct icmphdr icmp_hdr;
    memset(&icmp_hdr, 0, sizeof(icmp_hdr));
    icmp_hdr.type = ICMP_ECHO;
    icmp_hdr.checksum = 0;
    icmp_hdr.un.echo.id = 1;
    icmp_hdr.un.echo.sequence = 1234;
    return icmp_hdr;
}

static int __init start(void) {
    pr_info(KERN_INFO "ICMP Module succesfully loaded"); //should be deleted
    size_t sock_fd = set_socket();
    struct sockaddr_in addr = set_addr();
    struct icmphdr icmp = set_icmp();
    return 0;
}

static void __exit finish(void) {
    pr_info(KERN_INFO "ICMP Module deactivated"); //should be deleted
}

module_init(start);
module_exit(finish);
