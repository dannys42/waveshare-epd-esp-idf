idf_component_register(SRCS
    "DEV_Config.cpp"
    "GUI_Paint.cpp"

    REQUIRES driver
    REQUIRES "stm32xx_fonts-en"
    REQUIRES "stm32xx_fonts-cn"
    INCLUDE_DIRS "include"
    )
