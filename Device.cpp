#include "Device.h"
#include <libusb.h>


class Device
{
    //подготовка устройства
    libusb_device** devs;
    libusb_device_handle* dev_handle;
    libusb_context* ctx = NULL;
    unsigned char* data;
public:
	 Device() {
        libusb_init(&ctx);
        libusb_set_debug(ctx, 3);
        dev_handle = libusb_open_device_with_vid_pid(ctx, 0x0483, 0x5750);
        libusb_claim_interface(dev_handle, 0);
        data = new unsigned char[8];
        data[0] = '0x00';
        data[1] = '0x00';
        data[2] = '0x20';


	}


    void sendCommand() {
        libusb_bulk_transfer(dev_handle, 0x01, data, 64, NULL, 1000);
    }


    ~Device() {
        libusb_close(dev_handle);
    }

};

