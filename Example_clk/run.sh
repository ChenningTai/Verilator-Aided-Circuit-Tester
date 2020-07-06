cd /home630/cnTai19/ALU/Example_clk/slave/
echo "-----------------------------"
verilator -Wall --cc ALU32Bit_f.v --exe sim_main_clk_slave.cpp
make -j -C obj_dir -f VALU32Bit_f.mk VALU32Bit_f
obj_dir/VALU32Bit_f &
cd /home630/cnTai19/ALU/Example_clk/
echo "-----------------------------"
verilator -Wall --cc ALU32Bit_test.v --exe sim_main_clk.cpp
make -j -C obj_dir -f VALU32Bit_test.mk VALU32Bit_test
obj_dir/VALU32Bit_test

