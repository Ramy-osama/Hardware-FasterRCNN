
set PATH=
call D:/xiliinx/Vivado/2019.2/bin/xelab xil_defaultlib.apatb_relu_top glbl -prj relu.prj -L smartconnect_v1_0 -L axi_protocol_checker_v1_1_12 -L axi_protocol_checker_v1_1_13 -L axis_protocol_checker_v1_1_11 -L axis_protocol_checker_v1_1_12 -L xil_defaultlib -L unisims_ver -L xpm --initfile "D:/xiliinx/Vivado/2019.2/data/xsim/ip/xsim_ip.ini" --lib "ieee_proposed=./ieee_proposed" -s relu -debug wave
call D:/xiliinx/Vivado/2019.2/bin/xsim --noieeewarnings relu -tclbatch relu.tcl

