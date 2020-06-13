
log_wave -r /
set designtopgroup [add_wave_group "Design Top Signals"]
set cinoutgroup [add_wave_group "C InOuts" -into $designtopgroup]
set conv_op_group [add_wave_group conv_op(memory) -into $cinoutgroup]
add_wave /apatb_convo_top/AESL_inst_convo/conv_op_q1 -into $conv_op_group -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/conv_op_ce1 -into $conv_op_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/conv_op_address1 -into $conv_op_group -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/conv_op_q0 -into $conv_op_group -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/conv_op_d0 -into $conv_op_group -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/conv_op_we0 -into $conv_op_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/conv_op_ce0 -into $conv_op_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/conv_op_address0 -into $conv_op_group -radix hex
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set out_group [add_wave_group out(memory) -into $coutputgroup]
add_wave /apatb_convo_top/AESL_inst_convo/out_r_d0 -into $out_group -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/out_r_we0 -into $out_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/out_r_ce0 -into $out_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/out_r_address0 -into $out_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set kernel_group [add_wave_group kernel(memory) -into $cinputgroup]
add_wave /apatb_convo_top/AESL_inst_convo/kernel_q0 -into $kernel_group -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/kernel_ce0 -into $kernel_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/kernel_address0 -into $kernel_group -radix hex
set input_image_group [add_wave_group input_image(memory) -into $cinputgroup]
add_wave /apatb_convo_top/AESL_inst_convo/input_image_q0 -into $input_image_group -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/input_image_ce0 -into $input_image_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/AESL_inst_convo/input_image_address0 -into $input_image_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_convo_top/AESL_inst_convo/ap_start -into $blocksiggroup
add_wave /apatb_convo_top/AESL_inst_convo/ap_done -into $blocksiggroup
add_wave /apatb_convo_top/AESL_inst_convo/ap_idle -into $blocksiggroup
add_wave /apatb_convo_top/AESL_inst_convo/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_convo_top/AESL_inst_convo/ap_rst -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_convo_top/AESL_inst_convo/ap_clk -into $clockgroup
set testbenchgroup [add_wave_group "Test Bench Signals"]
set tbinternalsiggroup [add_wave_group "Internal Signals" -into $testbenchgroup]
set tb_simstatus_group [add_wave_group "Simulation Status" -into $tbinternalsiggroup]
set tb_portdepth_group [add_wave_group "Port Depth" -into $tbinternalsiggroup]
add_wave /apatb_convo_top/AUTOTB_TRANSACTION_NUM -into $tb_simstatus_group -radix hex
add_wave /apatb_convo_top/ready_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_convo_top/done_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_convo_top/LENGTH_input_image -into $tb_portdepth_group -radix hex
add_wave /apatb_convo_top/LENGTH_kernel -into $tb_portdepth_group -radix hex
add_wave /apatb_convo_top/LENGTH_conv_op -into $tb_portdepth_group -radix hex
add_wave /apatb_convo_top/LENGTH_out_r -into $tb_portdepth_group -radix hex
set tbcinoutgroup [add_wave_group "C InOuts" -into $testbenchgroup]
set tb_conv_op_group [add_wave_group conv_op(memory) -into $tbcinoutgroup]
add_wave /apatb_convo_top/conv_op_q1 -into $tb_conv_op_group -radix hex
add_wave /apatb_convo_top/conv_op_ce1 -into $tb_conv_op_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/conv_op_address1 -into $tb_conv_op_group -radix hex
add_wave /apatb_convo_top/conv_op_q0 -into $tb_conv_op_group -radix hex
add_wave /apatb_convo_top/conv_op_d0 -into $tb_conv_op_group -radix hex
add_wave /apatb_convo_top/conv_op_we0 -into $tb_conv_op_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/conv_op_ce0 -into $tb_conv_op_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/conv_op_address0 -into $tb_conv_op_group -radix hex
set tbcoutputgroup [add_wave_group "C Outputs" -into $testbenchgroup]
set tb_out_group [add_wave_group out(memory) -into $tbcoutputgroup]
add_wave /apatb_convo_top/out_r_d0 -into $tb_out_group -radix hex
add_wave /apatb_convo_top/out_r_we0 -into $tb_out_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/out_r_ce0 -into $tb_out_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/out_r_address0 -into $tb_out_group -radix hex
set tbcinputgroup [add_wave_group "C Inputs" -into $testbenchgroup]
set tb_kernel_group [add_wave_group kernel(memory) -into $tbcinputgroup]
add_wave /apatb_convo_top/kernel_q0 -into $tb_kernel_group -radix hex
add_wave /apatb_convo_top/kernel_ce0 -into $tb_kernel_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/kernel_address0 -into $tb_kernel_group -radix hex
set tb_input_image_group [add_wave_group input_image(memory) -into $tbcinputgroup]
add_wave /apatb_convo_top/input_image_q0 -into $tb_input_image_group -radix hex
add_wave /apatb_convo_top/input_image_ce0 -into $tb_input_image_group -color #ffff00 -radix hex
add_wave /apatb_convo_top/input_image_address0 -into $tb_input_image_group -radix hex
save_wave_config convo.wcfg
run all
quit

