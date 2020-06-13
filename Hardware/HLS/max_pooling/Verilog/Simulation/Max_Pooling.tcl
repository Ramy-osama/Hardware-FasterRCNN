
log_wave -r /
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set out_group [add_wave_group out(memory) -into $coutputgroup]
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/out_r_d0 -into $out_group -radix hex
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/out_r_we0 -into $out_group -color #ffff00 -radix hex
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/out_r_ce0 -into $out_group -color #ffff00 -radix hex
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/out_r_address0 -into $out_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set stride_group [add_wave_group stride(wire) -into $cinputgroup]
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/stride -into $stride_group -radix hex
set image_group [add_wave_group image(memory) -into $cinputgroup]
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/image_r_q1 -into $image_group -radix hex
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/image_r_ce1 -into $image_group -color #ffff00 -radix hex
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/image_r_address1 -into $image_group -radix hex
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/image_r_q0 -into $image_group -radix hex
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/image_r_ce0 -into $image_group -color #ffff00 -radix hex
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/image_r_address0 -into $image_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/ap_start -into $blocksiggroup
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/ap_done -into $blocksiggroup
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/ap_idle -into $blocksiggroup
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/ap_rst -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_Max_Pooling_top/AESL_inst_Max_Pooling/ap_clk -into $clockgroup
set testbenchgroup [add_wave_group "Test Bench Signals"]
set tbinternalsiggroup [add_wave_group "Internal Signals" -into $testbenchgroup]
set tb_simstatus_group [add_wave_group "Simulation Status" -into $tbinternalsiggroup]
set tb_portdepth_group [add_wave_group "Port Depth" -into $tbinternalsiggroup]
add_wave /apatb_Max_Pooling_top/AUTOTB_TRANSACTION_NUM -into $tb_simstatus_group -radix hex
add_wave /apatb_Max_Pooling_top/ready_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_Max_Pooling_top/done_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_Max_Pooling_top/LENGTH_image_r -into $tb_portdepth_group -radix hex
add_wave /apatb_Max_Pooling_top/LENGTH_stride -into $tb_portdepth_group -radix hex
add_wave /apatb_Max_Pooling_top/LENGTH_out_r -into $tb_portdepth_group -radix hex
set tbcoutputgroup [add_wave_group "C Outputs" -into $testbenchgroup]
set tb_out_group [add_wave_group out(memory) -into $tbcoutputgroup]
add_wave /apatb_Max_Pooling_top/out_r_d0 -into $tb_out_group -radix hex
add_wave /apatb_Max_Pooling_top/out_r_we0 -into $tb_out_group -color #ffff00 -radix hex
add_wave /apatb_Max_Pooling_top/out_r_ce0 -into $tb_out_group -color #ffff00 -radix hex
add_wave /apatb_Max_Pooling_top/out_r_address0 -into $tb_out_group -radix hex
set tbcinputgroup [add_wave_group "C Inputs" -into $testbenchgroup]
set tb_stride_group [add_wave_group stride(wire) -into $tbcinputgroup]
add_wave /apatb_Max_Pooling_top/stride -into $tb_stride_group -radix hex
set tb_image_group [add_wave_group image(memory) -into $tbcinputgroup]
add_wave /apatb_Max_Pooling_top/image_r_q1 -into $tb_image_group -radix hex
add_wave /apatb_Max_Pooling_top/image_r_ce1 -into $tb_image_group -color #ffff00 -radix hex
add_wave /apatb_Max_Pooling_top/image_r_address1 -into $tb_image_group -radix hex
add_wave /apatb_Max_Pooling_top/image_r_q0 -into $tb_image_group -radix hex
add_wave /apatb_Max_Pooling_top/image_r_ce0 -into $tb_image_group -color #ffff00 -radix hex
add_wave /apatb_Max_Pooling_top/image_r_address0 -into $tb_image_group -radix hex
save_wave_config Max_Pooling.wcfg
run all
quit

