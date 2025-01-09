#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    int num_d;
    libusb_context *ctx;
    libusb_device **device_list;
    struct libusb_device_descriptor *desc;
    // struct libusb_config_descriptor *config;
    libusb_device_handle *dev_handle;
    unsigned char *data;
    data = malloc(sizeof(char) * 1000);
    libusb_init_context(&ctx, NULL, 0);
    num_d = libusb_get_device_list(ctx, &device_list);
    for(int i = 0; i < num_d; i++) {
        libusb_get_device_descriptor(device_list[i], desc);
        // libusb_get_active_config_descriptor(device_list[i], &config);
        printf("%d\n", desc->idVendor);
        printf("%d\n", desc->idProduct);
        // printf("%c\n", config->);
        libusb_open(device_list[i], &dev_handle);
        libusb_get_string_descriptor_ascii(dev_handle, desc->iManufacturer, data, 1000);
        printf("%s\n", data);
        libusb_get_string_descriptor_ascii(dev_handle, desc->iProduct, data, 1000);
        printf("%s\n", data);
        libusb_get_string_descriptor_ascii(dev_handle, desc->iSerialNumber, data, 1000);
        printf("%s\n", data);
        // libusb_free_config_descriptor(config);
        libusb_close(dev_handle);
        // libusb_get_descriptor(dev_handle, uint8_t desc_type, uint8_t desc_index, unsigned char *data, int length)
    }
    free(data);
    libusb_free_device_list(device_list, 1);
    libusb_exit(ctx);
    printf("Starting...\n");
    return 0;
}
