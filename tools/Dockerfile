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
# \file Dockerfile 
FROM debian:buster-slim
RUN apt-get update && apt upgrade -y \
    && apt-get install make -y \
    && apt-get install gcc-avr avr-libc avrdude -y \
    && apt-get install python python3-pip -y \
    && pip3 install cpplint \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
