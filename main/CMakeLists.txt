idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS "."
                    # REQUIRES "waveshare-epd-1in54v2-demo"
                    REQUIRES "waveshare-epd-13in3k-demo"
                    )

idf_build_get_property(arch IDF_TARGET_ARCH)
