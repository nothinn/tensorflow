# Settings for RISCV 32-bit MCU toolchain.
ifeq ($(TARGET), riscv_mini)
  RISCV_ARCH ?= rv32im
  TARGET_ARCH := $(RISCV_ARCH)
  TARGET_TOOLCHAIN_PREFIX := riscv64-unknown-elf-

  PLATFORM_FLAGS = \
    -march=$(TARGET_ARCH) \
    -mabi=ilp32 \
    -mcmodel=medany \
    -mexplicit-relocs \
    -fno-builtin-printf \
    -fno-exceptions \
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
		-lm -lgcc \
		-nostartfiles \
		-specs=nosys.specs

  CXXFLAGS += $(PLATFORM_FLAGS) \
    -fpermissive \
    -fno-rtti \
    --std=gnu++11

  CCFLAGS += $(PLATFORM_FLAGS)

  BUILD_TYPE := micro

  LDFLAGS += $(foreach s,$(LIBWRAP_SYMS),-Wl,--wrap=$(s))
  LDFLAGS += $(foreach s,$(LIBWRAP_SYMS),-Wl,--wrap=_$(s))
  LDFLAGS += -L. -Wl,--start-group -lc -Wl,--end-group
  LDFLAGS += \
   -T/home/simon/riscv-mini/program/common/program.ld \
   --specs=nano.specs \
   --specs=nosys.specs