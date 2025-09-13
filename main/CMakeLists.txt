idf_component_register(SRCS "WaveshareMinimal.c"
                    INCLUDE_DIRS "."
                    REQUIRES "waveshare-epd_1in54_v2-demo"
                    )

idf_build_get_property(arch IDF_TARGET_ARCH)
