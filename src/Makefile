# Copyright (C) 2022  Santiago Previotto
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
# \file Makefile
# files macros #
MAIN_FILE = main
LIB_FILE = blink

# microcontroller macros #
CPU_ID = atmega328p
CPU_FREQ = 16000000UL

# programmer macros #
PROG_ID = arduino
PROG_BAUD = 57600
PROG_PORT = /dev/ttyUSB0

# compiler and uploader macros #
COMPILER = avr-gcc
UPLOADER = avrdude

# cpplint macros #
LINT_TOOL = cpplint
LINT_FLAGS = --recursive --quiet

docker:
ifndef YOUARECONTAINERIZEDBUDDY
	../tools/docker -p $(PWD)/..
else
	echo "The docker image is now available on the system!"
endif
	$(info )
	$(info Welcome to the docker image for programming AVR microcontrollers.)
	$(info )

build:
	$(COMPILER) -Wall -Os -DF_CPU=$(CPU_FREQ) -mmcu=$(CPU_ID) -c $(MAIN_FILE).c -o $(MAIN_FILE).o
	cd lib/src/ && $(COMPILER) -Wall -Os -DF_CPU=$(CPU_FREQ) -mmcu=$(CPU_ID) -c $(LIB_FILE).c -o $(LIB_FILE).o
	cd lib/src/ && mv $(LIB_FILE).o ../../
	$(COMPILER) -Wall -Os -DF_CPU=$(CPU_FREQ) -mmcu=$(CPU_ID) -o $(MAIN_FILE).elf $(MAIN_FILE).o $(LIB_FILE).o
	avr-objcopy -j .text -j .data -O ihex $(MAIN_FILE).elf $(MAIN_FILE).hex
	avr-size --format=avr --mcu=$(CPU_ID) $(MAIN_FILE).elf

flash:
	$(UPLOADER) -v -p $(CPU_ID) -c $(PROG_ID) -P $(PROG_PORT) -b $(PROG_BAUD) -U flash:w:$(MAIN_FILE).hex:i -D

lint: 
	$(LINT_TOOL) $(LINT_FLAGS) *

clean: 
	rm $(MAIN_FILE).hex $(MAIN_FILE).elf $(MAIN_FILE).o $(LIB_FILE).o
