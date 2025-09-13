idf_component_register(SRCS "WaveshareMinimal.c"
                    INCLUDE_DIRS "."
                    REQUIRES "waveshare-epd-1in54v2-demo"
                    )

idf_build_get_property(arch IDF_TARGET_ARCH)
