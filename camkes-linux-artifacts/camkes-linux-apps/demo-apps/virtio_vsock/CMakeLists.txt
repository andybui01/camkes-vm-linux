#
# Copyright 2022, UNSW (ABN 57 195 873 179)
#
# SPDX-License-Identifier: BSD-2-Clause
#

cmake_minimum_required(VERSION 3.8.2)

project(virtiovsock C)

add_executable(vm0 vm0.c)
add_executable(vm1 vm1.c)
target_link_libraries(vm0 -static-libgcc -static)
target_link_libraries(vm1 -static-libgcc -static)
