rtlwifi_new
===========
### A repo for the newest Realtek rtlwifi codes.

This code will build on any kernel 4.2 and newer as long as the distro has not modified
any of the kernel APIs. IF YOU RUN UBUNTU, YOU CAN BE ASSURED THAT THE APIs HAVE CHANGED.
NO, I WILL NOT MODIFY THE SOURCE FOR YOU. YOU ARE ON YOUR OWN!!!!!

Note: If your kernel is 4.17 or newer, AND your card is not an RTL8723DE, then you should NOT be
using the external driver. The built-in one is the same.

It includes drivers for the following cards:

RTL8822BE, RTL8822CE, AND RTL8723DE. Code for the RTL8821CE is starting to be applied.

#### Installation instruction

You will need to install "make", "gcc", "kernel headers", "kernel build essentials", and "git".

If you are running Ubuntu, then

 sudo apt-get install linux-headers-generic build-essential git

Please note the first paragraph above about some of the things that Ubuntu does.

For all distros:
git clone https://github.com/lwfinger/rtlwifi_new.git -b rtw88
cd rtlwifi_new
make
sudo make install

Some distros provide RTL8723DE drivers. To use this driver, that one MUST be
blacklisted. How to do that is left as an exercise as learning that will be very beneficial.

If your system has ANY conflicting drivers installed, you must blacklist them as well. For kernels
5.6 and newer, this will include drivers such as rtw88_xxxx.

Once you have reached this point, then reboot. Use the command lsmod and check for any
conflicting drivers. The correct ones are

rtw_8723de  rtw_8723d  rtw_8822be  rtw_8822b  rtw_8822ce  rtw_8822c  rtw_core  and rtw_pci

Any others WILL interfere!

#### Option configuration
If it turns out that your system needs one of the configuration options, then do the following:

sudo nano /etc/modprobe.d/<dev_name>.conf 

There, enter the line below:
options <dev_name> <<driver_option_name>>=<value>`

***********************************************************************************************

When your kernel changes, then you need to do the following:
cd ~/rtlwifi_new
git pull
make
sudo make install

Remember, this MUST be done whenever you get a new kernel - no exceptions.

These drivers will not build for kernels older than 4.14. If you must use an older kernel,
submit a GitHub issue with a listing of the build errors. Without the errors, the issue
will be ignored. I am not a mind reader.

