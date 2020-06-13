############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project relu
set_top relu
add_files ../../../../Desktop/projectfinal/relu.cpp
add_files -tb ../../../../Desktop/projectfinal/relu_test.cpp
open_solution "solution1"
set_part {xc7vx485tffg1157-1}
create_clock -period 10 -name default
#source "./relu/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all
export_design -format ip_catalog
