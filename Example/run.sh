cd /home630/cnTai19/ALU/Example/slave/
echo "-----------------------------"
verilator -Wall --cc ALU32Bit_f.v --exe sim_main_slave.cpp
make -j -C obj_dir -f VALU32Bit_f.mk VALU32Bit_f
obj_dir/VALU32Bit_f &
cd /home630/cnTai19/ALU/Example/
echo "-----------------------------"
verilator -Wall --cc ALU32Bit_test.v --exe sim_main.cpp
make -j -C obj_dir -f VALU32Bit_test.mk VALU32Bit_test
obj_dir/VALU32Bit_test


