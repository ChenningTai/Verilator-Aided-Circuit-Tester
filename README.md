# Verilator Aided Circuit Tester
這是一個基於一個開源軟體Verilator，能以C++對電路進行模擬並能測試錯誤電路的工具。
## Instruction
> 底線部分為使用相同電路，僅Example之路徑不同所需修改部分。
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
**1. 電路檔(.v)**
**2. testbench檔(.v)**
**3. main_simulation檔(sim_main.cpp):** 需使用者撰寫。
### slave資料夾
此區負責處理代替fault simulation tool的功能。裡面會有兩個檔案：
**1. main slave simulation檔(sim_main_slave.cpp):** 需使用者撰寫。
**2. 錯誤電路檔(.v)**
## Example
### 目錄
Example資料夾中會包含：
#### 檔案：
**sim_main.cpp**: 電路模擬之控制檔案，控制模擬中的所有流程。需使用者自行撰寫。
**run.sh**: 所有執行指令的bash檔。檔案就緒後僅須執行此檔案即可執行模擬，其中包含verilator轉檔、編譯、執行等所有步驟，內部指令詳見verilator官方說明書：。
**report.txt**: 測試後產生的報告，包含每個時間點的電路IO狀態與比較。
**myfifo**: pipe。
**ALU32Bit_test.v**: 欲測試電路之testbench。
**ALU32Bit_t_test_old**: 修改格式前原始的testbench。
**ALU32Bit.v**: 欲測試電路。
#### 資料夾：
**slave**: 替代fault simulation tool之功能。內部為處理錯誤電路的模擬。詳見下方。
**obj_dir**: verilator轉檔後自動產生之資料夾，內部包括電路轉檔後之.cpp檔、標頭檔、執行檔等。
#### slave資料夾中：
**sim_main_slave.cpp**: 錯誤電路模擬之控制檔案。需使用者自行撰寫。
**ALU32Bit_f.v**: 錯誤電路。
### 執行方式
在底層目錄example/執行：
```linux
$ tcsh run.sh
```
## Related Projects
### Verilator：
#### Manual：
https://www.veripool.org/projects/verilator/wiki/Manual-verilator
#### Github：
https://github.com/verilator/verilator
