#
# Copyright 2022, UNSW (ABN 57 195 873 179)
#
# SPDX-License-Identifier: BSD-2-Clause
#

cmake_minimum_required(VERSION 3.8.2)

project(virtiovsock C)

add_executable(vm_host vm_host.c)
add_executable(vm_client vm_client.c)
target_link_libraries(vm_host -static-libgcc -static)
target_link_libraries(vm_client -static-libgcc -static)
