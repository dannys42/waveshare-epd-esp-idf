idf_component_register(SRCS "WaveshareMinimal.c"
                    INCLUDE_DIRS "."
                    PRIV_REQUIRES "waveshare"
                    )

idf_build_get_property(arch IDF_TARGET_ARCH)
