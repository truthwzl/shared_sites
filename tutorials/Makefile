
C_SRCS += \
./test.c \
./gk_logger.c

OBJS += \
./test.o \
./gk_logger.o

C_DEPS += \
./test.d \
./gk_logger.d

LIBS=-ldl
TAERGET=test
# Each subdirectory must supply rules for building sources it contributes //-MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"
%.o: ./%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Compiler'
	$(CC) -O3 -Wall -c -fmessage-length=0 -MMD -MP  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
# All Target
all: $(TAERGET)

# Tool invocations
$(TAERGET): $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	$(CC) -o "$(TAERGET)" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS) $(C_DEPS) $(EXECUTABLES) $(TAERGET)
	-@echo ' '
		