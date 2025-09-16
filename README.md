# Waveshare EPaper demo for Espressif IoT Development Framework

This project converts some of the demo files from [Waveshare](https://www.waveshare.com)'s sample code to build cleanly under ESP IDF without requiring the Arduino component.

Currently only these devices are converted:
* 13in3k
* 1in54v2

Please consider submitting PR's for other sizes.  See the above as references for the structure of components and include paths.  The process is fairly straightforward, but they have a lot of examples.  Please submit PR if you've tested with your device.

## Process for integrating Waveshare example to IDF
1. Download [Waveshare Sample code](https://github.com/waveshareteam/e-Paper)
2. Create a component for the display.  For the 1.54" display:
    a. idf.py create-component -C components waveshare-epd-1in54v2
    b. rm components/waveshare-epd-1in54v2/*.c components/waveshare-epd-1in54v2/include/*.h
    c. mkdir -p components/waveshare-epd-1in54v2/include/epd-1in54v2
    d. cp Waveshare-E-Paper_ESP32_Driver_Board_Code/examples/esp32-waveshare-epd/src/utility/EPD_1in54_V2.cpp components/waveshare-epd-1in54v2
    e. cp Waveshare-E-Paper_ESP32_Driver_Board_Code/examples/esp32-waveshare-epd/src/utility/EPD_1in54_V2.h components/include/epd-1in54v2/epd-1in54v2.h
3. Create a component for the demo:
    a. idf.py create-component -C components waveshare-epd-1in54v2-demo
    b. rm components/waveshare-epd-1in54v2-demo/*.c components/waveshare-epd-1in54v2-demo/include/*.h
    c. mkdir -p components/waveshare-epd-1in54v2-demo/include/epd-1in54v2-demo/
    d. cp Waveshare-E-Paper_ESP32_Driver_Board_Code/examples/esp32-waveshare-epd/examples/epd1in54_V2-demo/ImageData.* components/waveshare-epd-1in54v2-demo
    e. cp Waveshare-E-Paper_ESP32_Driver_Board_Code/examples/esp32-waveshare-epd/examples/epd1in54_V2-demo/epd1in54_V2-demo.ino components/waveshare-epd-1in54v2-demo/epd1in54_V2-demo.cc
    f. delete the empty `loop()` function
    g. rename `setup()` to `epd_1in54_v2_demo()`
    f. create components/waveshare-epd-1in54v2-demo/include/epd-1in54v2-demo/epd-1in54v2-demo.h
4. Update main to call the demo
5. idf.py build flash monitor

You'll have to update a few `#include` paths and add relevant `CMakeLists.txt` files as well.


# References

* [Original Waveshare Sample code](https://github.com/waveshareteam/e-Paper)
* 
