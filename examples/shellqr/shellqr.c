/**
 *  QRCode
 *
 *  A quick example of generating a QR code.
 *
 *  This prints the QR code to the bash shell solid blocks. Each module
 *  is two characters wide, since the monospace font used in the serial monitor
 *  is approximately twice as tall as wide.
 *
 */
#include <stdio.h>
#include <time.h>
#include "qrcode.h"

#define BIT1 "\u2588\u2588"
#define BIT0 "  "
#define MARGIN 4

void print_header_footer(int width)
{
    for (int i = 0; i < MARGIN; ++i) {
      for (int j = 0; j < width + 2 * MARGIN; ++j)
        printf("%s", BIT1);
      printf("\n");
    }
}

void print_margin(void)
{
    for (int i = 0; i < MARGIN; ++i)
        printf("%s", BIT1);
}

void print_a_qr_code(unsigned char *str, uint8_t version, uint8_t ecc)
{
    // Create the QR code
    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(version)];
    printf("\nQR code version: %d; ecc: %d\n", version, ecc);
    qrcode_initText(&qrcode, qrcodeData, version, ecc, str);
    printf("QR code size: %d\n\n", qrcode.size);

    // Top quiet zone
    print_header_footer(qrcode.size);

    for (uint8_t y = 0; y < qrcode.size; y++) {

        // Left quiet zone
        print_margin();

        // Each horizontal module
        for (uint8_t x = 0; x < qrcode.size; x++) {

            // Print each module (UTF-8 \u2588 is a solid block)
            printf(qrcode_getModule(&qrcode, x, y) ? BIT0 : BIT1);

        }

        // Right quiet zone
        print_margin();
        printf("\n");
    }

    // Bottom quiet zone
    print_header_footer(qrcode.size);
}

void main()
{
  // TODO: take string, version, ecc from command line.
  unsigned char str[] = "HELLO WORLD";
  print_a_qr_code(str, 3, 0);
}
