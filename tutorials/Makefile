
C_SRCS += \
./test.c \
./gk_logger.c

OBJS += \
./test.o \
./gk_logger.o

C_DEPS += \
./test.d \
./gk_logger.d

LIB_SRCS += \
./my.c \
./my2.c 

LIB_OBJS += \
./my.o \
./my2.o 

LIB_C_DEPS += \
./my.d \
./my2.d 

LIBS=-ldl
TAERGET=test
MODULE_PATH=./modules
MODULE_TARGETS = $(MODULE_PATH)/libmy.so $(MODULE_PATH)/libmy2.so
# Each subdirectory must supply rules for building sources it contributes //-MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"
%.o: ./%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Compiler'
	$(CC) -O3 -Wall -c -fmessage-length=0 -MMD -MP  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
# All Target
all: $(TAERGET) libmy.so libmy2.so

# Tool invocations
$(TAERGET): $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	$(CC) -o "$(TAERGET)" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

libmy.so: my.o 
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	$(CC) --shared -o "./modules/libmy.so" my.o
	@echo 'Finished building target: $@'
	@echo ' '

libmy2.so: my2.o 
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	$(CC) --shared -o "./modules/libmy2.so" my2.o
	@echo 'Finished building target: $@'
	@echo ' '
# Other Targets
clean:
	-$(RM) $(OBJS) $(C_DEPS) $(LIB_OBJS) $(LIB_C_DEPS) $(EXECUTABLES) $(TAERGET) $(MODULE_TARGETS)
	-@echo ' '
		