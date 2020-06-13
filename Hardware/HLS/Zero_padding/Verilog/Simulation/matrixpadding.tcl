
log_wave -r /
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set matrix_paded_group [add_wave_group matrix_paded(memory) -into $coutputgroup]
add_wave /apatb_matrixpadding_top/AESL_inst_matrixpadding/matrix_paded_d0 -into $matrix_paded_group -radix hex
add_wave /apatb_matrixpadding_top/AESL_inst_matrixpadding/matrix_paded_we0 -into $matrix_paded_group -color #ffff00 -radix hex
add_wave /apatb_matrixpadding_top/AESL_inst_matrixpadding/matrix_paded_ce0 -into $matrix_paded_group -color #ffff00 -radix hex
add_wave /apatb_matrixpadding_top/AESL_inst_matrixpadding/matrix_paded_address0 -into $matrix_paded_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set matrix_input_group [add_wave_group matrix_input(memory) -into $cinputgroup]
add_wave /apatb_matrixpadding_top/AESL_inst_matrixpadding/matrix_input_q0 -into $matrix_input_group -radix hex
add_wave /apatb_matrixpadding_top/AESL_inst_matrixpadding/matrix_input_ce0 -into $matrix_input_group -color #ffff00 -radix hex
add_wave /apatb_matrixpadding_top/AESL_inst_matrixpadding/matrix_input_address0 -into $matrix_input_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_matrixpadding_top/AESL_inst_matrixpadding/ap_start -into $blocksiggroup
add_wave /apatb_matrixpadding_top/AESL_inst_matrixpadding/ap_done -into $blocksiggroup
add_wave /apatb_matrixpadding_top/AESL_inst_matrixpadding/ap_idle -into $blocksiggroup
add_wave /apatb_matrixpadding_top/AESL_inst_matrixpadding/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_matrixpadding_top/AESL_inst_matrixpadding/ap_rst -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_matrixpadding_top/AESL_inst_matrixpadding/ap_clk -into $clockgroup
set testbenchgroup [add_wave_group "Test Bench Signals"]
set tbinternalsiggroup [add_wave_group "Internal Signals" -into $testbenchgroup]
set tb_simstatus_group [add_wave_group "Simulation Status" -into $tbinternalsiggroup]
set tb_portdepth_group [add_wave_group "Port Depth" -into $tbinternalsiggroup]
add_wave /apatb_matrixpadding_top/AUTOTB_TRANSACTION_NUM -into $tb_simstatus_group -radix hex
add_wave /apatb_matrixpadding_top/ready_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_matrixpadding_top/done_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_matrixpadding_top/LENGTH_matrix_input -into $tb_portdepth_group -radix hex
add_wave /apatb_matrixpadding_top/LENGTH_matrix_paded -into $tb_portdepth_group -radix hex
set tbcoutputgroup [add_wave_group "C Outputs" -into $testbenchgroup]
set tb_matrix_paded_group [add_wave_group matrix_paded(memory) -into $tbcoutputgroup]
add_wave /apatb_matrixpadding_top/matrix_paded_d0 -into $tb_matrix_paded_group -radix hex
add_wave /apatb_matrixpadding_top/matrix_paded_we0 -into $tb_matrix_paded_group -color #ffff00 -radix hex
add_wave /apatb_matrixpadding_top/matrix_paded_ce0 -into $tb_matrix_paded_group -color #ffff00 -radix hex
add_wave /apatb_matrixpadding_top/matrix_paded_address0 -into $tb_matrix_paded_group -radix hex
set tbcinputgroup [add_wave_group "C Inputs" -into $testbenchgroup]
set tb_matrix_input_group [add_wave_group matrix_input(memory) -into $tbcinputgroup]
add_wave /apatb_matrixpadding_top/matrix_input_q0 -into $tb_matrix_input_group -radix hex
add_wave /apatb_matrixpadding_top/matrix_input_ce0 -into $tb_matrix_input_group -color #ffff00 -radix hex
add_wave /apatb_matrixpadding_top/matrix_input_address0 -into $tb_matrix_input_group -radix hex
save_wave_config matrixpadding.wcfg
run all
quit

