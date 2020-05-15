rtlwifi_new
===========
### A repo for the newest Realtek rtlwifi codes.

This code will build on any kernel 4.2 and newer as long as the distro has not modified
any of the kernel APIs. IF YOU RUN UBUNTU, YOU CAN BE ASSURED THAT THE APIs HAVE CHANGED.
NO, I WILL NOT MODIFY THE SOURCE FOR YOU. YOU ARE ON YOUR OWN!!!!!

Note: If your kernel is 4.17 or newer, AND your card is not an RTL8723DE, then you should NOT be
using the external driver. The built-in one is the same.

It includes drivers for the following cards:

RTL8822BE, RTL8822CE, AND RTL8723DE.

#### Installation instruction

You will need to install "make", "gcc", "kernel headers", "kernel build essentials", and "git".

If you are running Ubuntu, then

 sudo apt-get install linux-headers-generic build-essential git

Please note the first paragraph above.

For all distros:
git clone https://github.com/lwfinger/rtlwifi_new.git -b rtw88
cd rtlwifi_new
make
sudo make install
sudo modprobe  <dev_name> where <dev_name> is rtw_8822be, rtw_8822ce, or rtw_8723de

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

These drivers will not build for kernels older than 4.14.
