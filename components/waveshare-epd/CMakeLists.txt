idf_component_register(SRCS
    "DEV_Config.c"
    "GUI_Paint.c"

    REQUIRES driver
    REQUIRES "stm32xx_fonts-en"
    REQUIRES "stm32xx_fonts-cn"
    INCLUDE_DIRS "include"
    )
