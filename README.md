# kernel-delirium

## What is it? 
My main goal in doing this project is to gain experience in developing modules for the Linux kernel and in general a better understanding of the operating system by developing a program that will be difficult to track while it will transmit data. The potential for using such software is low because for this you already need to have root rights in the system, so it makes sense to do this only when you want to quietly gain a foothold in the system without giving any indication

## How to stay undetectable?
For this task I decided to just not allow any commands to spoil my script working by any means. For example, using ls, lsmod, top and all the others that could somehow compromise the program. For that first step was to somehow edit the output of any commands which is achievable only after manipulating the stdout file descriptor which I've done using c.

## Usage
This python script will generate the vulnerable module and hide the traces of it's work 
```bash
sudo python3 clean_and_load.py
```

## Status
The software is not yet operational and is under active development.
