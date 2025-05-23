CONFIG_MODULE_SIG=n
obj-m += dvt-driver.o

all:
	sudo apt-get install --reinstall -y linux-headers-$(uname -r)
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	sudo insmod dvt-driver.ko

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -rf *.c *.o *.ko *.mod *.mod.c
