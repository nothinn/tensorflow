# Settings for RISCV 32-bit MCU toolchain.
ifeq ($(TARGET), riscv64)
  TARGET_ARCH := rv64i
  TARGET_TOOLCHAIN_PREFIX := riscv64-unknown-elf-


  PLATFORM_FLAGS = \
    -march=rv64imac \
    -mabi=lp64 \
    -DTF_LITE_MCU_DEBUG_LOG \
    -DTF_LITE_USE_GLOBAL_CMATH_FUNCTIONS \
		-fno-unwind-tables \
    -fno-builtin \
    -ffunction-sections \
    -fdata-sections \
    -funsigned-char \
    -Wvla \
    -Wall \
    -Wextra \
    -Wsign-compare \
    -Wdouble-promotion \
    -Wshadow \
    -Wunused-variable \
    -Wmissing-field-initializers \
    -Wno-unused-parameter \
    -Wno-write-strings \
    -fno-delete-null-pointer-checks \
    -fno-threadsafe-statics \
    -fomit-frame-pointer \
    -fno-use-cxa-atexit \
    -Os \
    -lm -lgcc 
    -mcmodel=medany \
    -mexplicit-relocs \
    -fno-builtin-printf \
    -fno-exceptions \
#		--no-relax
#no relax is due to lack of global pointer

  CXXFLAGS += $(PLATFORM_FLAGS) \
    -fpermissive \
    -fno-rtti \
    --std=gnu++11

  CCFLAGS += $(PLATFORM_FLAGS)

  BUILD_TYPE := micro



  MICROLITE_CC_SRCS += \
    $(wildcard tensorflow/lite/micro/riscv64/*.cc)

#  LIBWRAP_SYMS := malloc free \
#                  open lseek read write fstat stat close link unlink \
#                  execve fork getpid kill wait \
#                  isatty times sbrk _exit puts

#  LDFLAGS += $(foreach s,$(LIBWRAP_SYMS),-Wl,--wrap=$(s))
#  LDFLAGS += $(foreach s,$(LIBWRAP_SYMS),-Wl,--wrap=_$(s))
#  LDFLAGS += -L. -Wl,--start-group -lc -Wl,--end-group
#  LDFLAGS += \
#   -nostartfiles \
#   --specs=nano.specs

# These are microcontroller-specific rules for converting the ELF output
# of the linker into a binary image that can be loaded directly.
  OBJCOPY := $(TARGET_TOOLCHAIN_PREFIX)objcopy
  $(BINDIR)/%.bin: $(BINDIR)/%
		@mkdir -p $(dir $@)
		$(OBJCOPY) $< $@ -O binary
endif
