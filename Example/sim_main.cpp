#include <verilated.h>          // Defines common routines
#include <iostream>             // Need std::cout
#include <VALU32Bit_test.h>     // From Verilating "top.v"
#include <fstream>
#include<sys/stat.h> //stat
#include <stdlib.h> //atoi
//pipe
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h>
#include <sys/types.h>
using namespace std;


VALU32Bit_test *top;                      // Instantiation of module

vluint64_t main_time = 0;       // Current simulation time
        // This is a 64-bit integer to reduce wrap over issues and
        // allow modulus.  You can also use a double, if you wish.
//path
string main_path = "/home630/cnTai19/ALU/Example/";

double sc_time_stamp () {       // Called by $time in Verilog
    return main_time;           // converts to double, to match
                                // what SystemC does
}
string int2s(string name, unsigned int i) {
    char st[80];
    snprintf(st, 80, "%u",i);
    string str(st);
    if (name == "")
    {
        return str;
    }else str = name + " " + str +"\n";
    return str; // format: "<name> <value>\n"
}
char* nowtime(){
   time_t now = time(0);
   char* dt = ctime(&now);
   return dt;
}
int main(int argc, char** argv) {
//report
    fstream report;
    report.open((main_path + "report.txt").c_str(), ios::out);
            if(report.fail())
                cout << "report opening error!!" << endl;
            report << "--------------------Report--------------------" << endl;
            report.close();

    Verilated::commandArgs(argc, argv);   // Remember args

    top = new VALU32Bit_test;             // Create instance

    top->sys_clk = 0;
//read file
    unsigned int slave_result; //convert to uint
    //answer
    int simu_ccls = 8000; //simulation cycles
    int correct[simu_ccls];
    //IO
    string topA;
    string topB;
    string topALUControl;
//pipe
    int fd; 
        // FIFO file path 
    char * myfifo = "/home630/cnTai19/ALU/Example/myfifo";
        // mkfifo(<pathname>,<permission>) 
    mkfifo(myfifo, 0666); 
  
    char arr1[80]; 
    uint master_result;
    while (!Verilated::gotFinish()) {
        top->sys_clk = ~top->sys_clk & 0x1;
        top->eval();            // Evaluate model
        master_result = unsigned(top->ALUResult);
//pipe write file
        //type operation:
        topA = int2s("A", top->A);
        topB = int2s("B", top->B);
        topALUControl = int2s("ALUControl", top->ALUControl);
        const char* writtenW = (topA + topB + topALUControl).c_str();
        fd = open(myfifo, O_WRONLY); 
        write(fd, writtenW, strlen(writtenW)+1);
        close(fd);
//pipe read
        fd = open(myfifo, O_RDONLY); 
        read(fd, arr1, sizeof(arr1)); 
        close(fd); 
//result operation
        slave_result = atoi(arr1);
        cout << "master: ---[" << main_time << "]---" << endl;
        cout <<   "  A: " << unsigned(top->A) << "  B: " << unsigned(top->B) << "  ALUControl: " << unsigned(top->ALUControl) << endl;
        cout << "master result: " << master_result << "  slave result: " << slave_result << endl;
        if(1){ //every single cycle
            if (unsigned(top->ALUResult) != slave_result)
            {
                cout << "Error!!!" << endl;
                correct[main_time/2] = 0;
                // Verilated::gotFinish(1);
            }else{
                cout << "correct!!" << endl;
                correct[main_time/2] = 1;
            }
            cout << "---------------------------------------------" << endl;
            report.open((main_path + "report.txt").c_str(), ios::out | ios::app);
            if(report.fail())
                cout << "report opening error while writing result!!" << endl;
            report << "[" << main_time << "]";
            report << "  master A: " << unsigned(top->A) << "  master B: " << unsigned(top->B) << "  master ALUControl: " << unsigned(top->ALUControl);
            report << "  master result: " << master_result << "  slave result: " << slave_result;
            report << "      correct? " << correct[main_time/2] << endl;
            report.close();
        }
            main_time++;            // Time passes...
            if (main_time == simu_ccls){
                Verilated::gotFinish(1);
        }
    } //while end
//report
        report.open((main_path + "report.txt").c_str(), ios::out | ios::app);
        if(report.fail()) {cout << "report opening error wihle endding!!" << endl;}
        report << "-------------------report end-------------------" << endl;
        report << nowtime() << endl;
        report.close();
        top->final();               // Done simulating
         delete top;
    }
