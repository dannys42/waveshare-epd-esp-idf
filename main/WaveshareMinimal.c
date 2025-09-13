#include <stdio.h>

#include "epd-1in54v2-demo/epd-1in54v2-demo.h"

/* Entry point ----------------------------------------------------------------*/

void app_main(void)
{
    printf("* Start of WaveshareMinimal\n");

    epd_1in54_v2_demo();

    printf("* Program complete\n");
}
