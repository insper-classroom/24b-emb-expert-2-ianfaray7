project(mpu-data-forwarding)

add_executable(mpu-data-forwarding
        main.c
)


target_link_libraries(mpu-data-forwarding FreeRTOS-Kernel 
FreeRTOS-Kernel-Heap4 pico_stdlib hardware_i2c Fusion)

pico_add_extra_outputs(mpu-data-forwarding)
