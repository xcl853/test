MODNAME?=mycdev
KNERNELDIR := /lib/modules/3.13.0-32-generic/build/
PWD := $(shell pwd)

all:
	make -C $(KNERNELDIR) M=$(PWD) modules


clean:
	make -C $(KNERNELDIR) M=$(PWD) clean


obj-m :=$(MODNAME).o
