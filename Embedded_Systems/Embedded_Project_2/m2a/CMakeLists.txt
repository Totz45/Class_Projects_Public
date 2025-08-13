cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(my_project)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project
add_executable(m2a
    m2a.c
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(m2a pico_stdlib)

function(pico_add_dis_output2 TARGET)
    add_custom_command(TARGET ${TARGET} POST_BUILD
        COMMAND ${CMAKE_OBJDUMP} -S $<TARGET_FILE:${TARGET}> >$<IF:$<BOOL:$<TARGET_PROPERTY:${TARGET},OUTPUT_NAME>>,$<TARGET_PROPERTY:${TARGET},OUTPUT_NAME>,$<TARGET_PROPERTY:${TARGET},NAME>>.dis2)

    if (PICO_COMPILER STREQUAL "pico_arm_gcc")
        pico_find_compiler(PICO_COMPILER_SIZE ${PICO_GCC_TRIPLE}-size)
        add_custom_command(TARGET ${TARGET} POST_BUILD
            COMMAND ${PICO_COMPILER_SIZE} ${CMAKE_CURRENT_LIST_DIR}/../build/src/$<IF:$<BOOL:$<TARGET_PROPERTY:${TARGET},OUTPUT_NAME>>,$<TARGET_PROPERTY:${TARGET},OUTPUT_NAME>,$<TARGET_PROPERTY:${TARGET},NAME>>.elf
            VERBATIM
        )
    endif()
endfunction()

#target_compile_definitions(m2a PRIVATE
#	PLL_SYS_REFDIV=2 
#	PLL_SYS_VCO_FREQ_HZ=1050000000 
#	PLL_SYS_POSTDIV1=7   
#	PLL_SYS_POSTDIV2=6   
#)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(m2a)
# also create additional disassembled file
pico_add_dis_output2(m2a)
