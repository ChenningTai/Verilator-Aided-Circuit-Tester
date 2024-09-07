# Verilator Aided Circuit Tester
這是一個基於一個開源軟體Verilator，能以C++對電路進行模擬並能測試錯誤電路的工具。(This is a tool based on the open-source software Verilator, which can simulate circuits in C++ and test faulty circuits.)
## Instruction
> 可將不同的input檔輸入相同電路，粗體部分為使用相同電路，僅與Example之路徑不同所需修改部分。
### Step 1: 修改testbench：
- 將testbench改寫成tester可使用之形式，如範例ALU43Bit_test.v。其中修改包含：
    1. 將電路之IO加入到testbench的IO中。
    2. 加入一個input為system_clk，並將電路always block之觸發條件為"posedge sys_clk or negedge sys_clk"。
    3. 指定時間以"case:"改寫如範例ALU43Bit_test.v，而不使用"#"。
### Step 2: 以範例修改main simulation file (sim_main.cpp) 
- 修改#include標頭檔，將#include <VALU32Bit_f.h>改為#include <V電路名稱.h>。
- __修改變數myfifo與main_path，為pipe之位置以及此底層目錄之路徑。__
- 修改simu_ccls變數之值為欲執行的時間(對應到testbench的$time長度)。
- 在read file的IO部分中，宣告所有電路IO的對應變數，型別為string.
- 在pipe write file部分中，以"IO變數 = int2s(變數名稱, top->電路中變數名)"為格式列舉所有inputs。並在下面的written中加入所有變數。
- 在result operation部分中，修改顯示結果為變數名稱以及對應之值。
- 在report部分中，修改顯示結果為變數名稱以及對應之值。
### Step 3: 以範例修改在slave資料夾中的sim_main_slave：
- __修改變數myfifo，為pipe之位置以及此底層目錄之路徑。__
- 修改simu_ccls變數之值為欲執行的時間(對應到testbench的$time長度)，與sim_main.cpp中相同。
- 修改size變數為所有IO的總數。
- 目前儲存IO變數名稱與值之各個char變數目前size皆為80(程式碼中所有"80")。此部分可根據實際電路之IO大小調整。
- 在pattern operation的calculation部分，修改印出的資訊，以及將pipe中讀到的值指派給電路IO，依照sim_main.cpp寫入pipe的順序。
### Step 4: 修改run.sh檔案路徑：
- __修改底層目錄路徑與slave路徑(Example之路徑與slave之路徑)。__
### Step 5: 在底層目錄執行：
```linux
$ tcsh run.sh
```
## File Discription
### 底層目錄：
此區負責主要測試的控制與正確電路模擬。會有三個檔案
- **電路檔(.v)**
- **testbench檔(.v)**
- **main_simulation檔(sim_main.cpp):** 需使用者撰寫。
### slave資料夾
此區負責處理代替fault simulation tool的功能。裡面會有兩個檔案：
- **main slave simulation檔(sim_main_slave.cpp):** 需使用者撰寫。
- **錯誤電路檔(.v)**
## Example
### 目錄
Example資料夾中會包含：
#### 檔案：
**sim_main.cpp**: 電路模擬之控制檔案，控制模擬中的所有流程。需使用者自行撰寫。<br>
**run.sh**: 所有執行指令的bash檔。檔案就緒後僅須執行此檔案即可執行模擬，其中包含verilator轉檔、編譯、執行等所有步驟，內部指令詳見verilator官方說明書：https://www.veripool.org/projects/verilator/wiki/Manual-verilator。<br>
**report.txt**: 測試後產生的報告，包含每個時間點的電路IO狀態與比較。<br>
**myfifo**: pipe。<br>
**ALU32Bit_test.v**: 欲測試電路之testbench。<br>
**ALU32Bit_t_test_old**: 修改格式前原始的testbench。<br>
**ALU32Bit.v**: 欲測試電路。<br>
#### 資料夾：
**slave**: 替代fault simulation tool之功能。內部為處理錯誤電路的模擬。詳見下方。<br>
**obj_dir**: verilator轉檔後自動產生之資料夾，內部包括電路轉檔後之.cpp檔、標頭檔、執行檔等。<br>
#### slave資料夾中：
**sim_main_slave.cpp**: 錯誤電路模擬之控制檔案。需使用者自行撰寫。<br>
**ALU32Bit_f.v**: 錯誤電路。<br>
### 執行方式
在底層目錄example/執行：
```linux
$ tcsh run.sh
```
## Related Projects
### Verilator
#### Manual：
https://www.veripool.org/projects/verilator/wiki/Manual-verilator
#### Github：
https://github.com/verilator/verilator

English Version:

# Verilator Aided Circuit Tester
This is a tool based on the open-source software Verilator. This tool can simulate circuits in C++ and test faulty circuits.

## Instructions
> Different input files can be applied to the same circuit. The files in bold font indicate modifications required when using the same circuit but with different paths in the Example.

### Step 1: Modify the testbench:
- Rewrite the testbench to a format usable by the tester, such as the example **ALU43Bit_test.v**. Modifications include:
    1. Add the circuit's IO to the testbench's IO.
    2. Add an input for the system clock (`system_clk`) and set the always block trigger condition to `"posedge sys_clk or negedge sys_clk"`.
    3. Rewrite the timing specification using `case:` instead of `#`, as in **ALU43Bit_test.v**.

### Step 2: Modify the main simulation file (`sim_main.cpp`):
- Modify the `#include` header file, changing `#include <VALU32Bit_f.h>` to `#include <V<CircuitName>.h>`.
- __Change the variables `myfifo` and `main_path` to specify the location of the pipe and the path to the root directory.__
- Modify the `simu_ccls` variable value to match the desired execution time (which corresponds to the `$time` length in the testbench).
- In the read file's IO section, declare all the circuit IO as corresponding variables of type string.
- In the pipe write file section, list all inputs using the format `"IO_variable = int2s(variable_name, top->circuit_variable_name)"`. Also, add all variables to the written section.
- In the result operation section, modify the output to display the variable names and their corresponding values.
- In the report section, modify the output to display the variable names and their corresponding values.

### Step 3: Modify the `sim_main_slave` in the slave folder:
- __Change the `myfifo` variable to specify the location of the pipe and the path to the root directory.__
- Modify the `simu_ccls` variable value to match the desired execution time (which corresponds to the `$time` length in the testbench) to be consistent with `sim_main.cpp`.
- Modify the `size` variable to match the total number of IOs.
- Adjust the size of the `char` variables storing the IO names and values (currently set to 80 in the code). This size can be adjusted based on the actual IO size of the circuit.
- In the pattern operation's calculation section, modify the printed information and assign the values read from the pipe to the circuit's IOs, following the order in which the values were written to the pipe in `sim_main.cpp`.

### Step 4: Modify the paths in the `run.sh` file:
- __Change the root directory path and the slave path (Example path and slave path).__

### Step 5: Run in the root directory:
```bash
$ tcsh run.sh
```
## File Description
### Root Directory:
This section is responsible for the main test control and correct circuit simulation. There will be three files:
- **Circuit file (.v)**
- **Testbench file (.v)**
- **Main simulation file (`sim_main.cpp`)**: Written by the user.

### Slave Folder:
This section is responsible for handling the functions of the fault simulation tool. It contains two files:
- **Main slave simulation file (`sim_main_slave.cpp`)**: Written by the user.
- **Faulty circuit file (.v)**

## Example
### Directory:
The Example folder contains:

#### Files:
- **`sim_main.cpp`**: The control file for the circuit simulation, managing the entire simulation process. Written by the user.<br>
- **`run.sh`**: A bash script for executing all commands. After all files are ready, this script is all that needs to be executed to run the simulation. It includes Verilator conversion, compilation, execution, and more. See the Verilator official manual for detailed instructions: [https://www.veripool.org/projects/verilator/wiki/Manual-verilator](https://www.veripool.org/projects/verilator/wiki/Manual-verilator).<br>
- **`report.txt`**: The report generated after testing, including the circuit IO status and comparisons at each time point.<br>
- **`myfifo`**: The pipe.<br>
- **`ALU32Bit_test.v`**: The testbench for the circuit.<br>
- **`ALU32Bit_t_test_old`**: The original testbench before format modification.<br>
- **`ALU32Bit.v`**: The circuit to be tested.<br>

#### Folders:
- **`slave`**: Replaces the fault simulation tool. It handles the simulation of faulty circuits. See below for details.<br>
- **`obj_dir`**: Automatically generated folder after Verilator converts the circuit, containing the converted `.cpp` files, header files, executables, etc.<br>

#### In the `slave` folder:
- **`sim_main_slave.cpp`**: The control file for simulating faulty circuits. Written by the user.<br>
- **`ALU32Bit_f.v`**: The faulty circuit.<br>

### Execution:
In the root directory of `example/`, execute:
```bash
$ tcsh run.sh
```
## Related Projects
### Verilator
#### Manual:
[https://www.veripool.org/projects/verilator/wiki/Manual-verilator](https://www.veripool.org/projects/verilator/wiki/Manual-verilator)
#### GitHub:
[https://github.com/verilator/verilator](https://github.com/verilator/verilator)
