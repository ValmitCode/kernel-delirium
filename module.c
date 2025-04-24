#define DEBUG true
#define SUCCESS 0
#define FAILURE 1
#define OUTPUT_FD 1
#define INPUT_FD 0
#define ERROR_FD 2
#define IP_HOST 127.0.0.1
#define PORT_HOST 87

#include <linux/module.h>


static int __init start(void)
{
if (DEBUG) pr_info("STARTED IN DEBUG MODE\n");
return SUCCESS;
spy();
}

static int 
static int spy(void){
    char[] msg = find_data();
    send_data(msg, IP_HOST, PORT_HOST);
    return SUCCESS;
}

static int output_modifier(void){
    freopen("funny-input.txt", "rt", stdin);
}


static void __exit end(void)
{
if (DEBUG) pr_info("WE'RE DONE\n");
}

module_init(start);
module_exit(end);