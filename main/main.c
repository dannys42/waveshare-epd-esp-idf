#include <stdio.h>

// #include "epd-1in54v2-demo/epd-1in54v2-demo.h"
#include "epd-13in3k-demo/epd-13in3k-demo.h"

/* Entry point ----------------------------------------------------------------*/

void app_main(void)
{
    printf("* Start of WaveshareMinimal\n");

    //epd_1in54_v2_demo();
    epd_13in3k_demo();

    printf("* Program complete\n");
}
