############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project theintegratedcode
set_top convo
add_files ../../../../Desktop/projectfinal/integration/parampad.h
add_files ../../../../Desktop/projectfinal/integration/maxpoolingmm.cpp
add_files ../../../../Desktop/projectfinal/integration/matrixpadd3d.cpp
add_files ../../../../Desktop/projectfinal/integration/convpad.cpp
add_files -tb ../../../../Desktop/projectfinal/integration/convpaddtest.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7vx485t-ffg1157-1}
create_clock -period 10 -name default
#source "./theintegratedcode/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all
export_design -format ip_catalog
