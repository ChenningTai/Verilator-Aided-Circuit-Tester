#include <verilated.h>          // Defines common routines
#include <iostream>             // Need std::cout
#include <VALU32Bit_f.h>          // From Verilating "top.v"
#include <fstream>
#include <sstream>
#include<sys/stat.h> //stat
#include <stdlib.h> //atoi
#include <vector> //split
//pipe
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h>
#include <sys/types.h>
using namespace std;
vector<string> split(string str, char iden) {
    istringstream in(str);
    string tmp_str;
    vector<string> vec;

    while (getline(in, tmp_str, iden)) {
    vec.push_back(tmp_str);
    }
    return vec;
}

string int2s(string name, unsigned int i) {
    char st[50];
    snprintf(st, 50, "%d",i);
    string str(st);
    if (name == "")
    {
        return str;
    }else str = name + " " + str +"\n";
    return str;
}
//

VALU32Bit_f *top;                      // Instantiation of module

vluint64_t main_time = 0;       // Current simulation time
        // This is a 64-bit integer to reduce wrap over issues and
        // allow modulus.  You can also use a double, if you wish.

double sc_time_stamp () {       // Called by $time in Verilog
    return main_time;           // converts to double, to match
                                // what SystemC does
}


int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);   // Remember args
    top = new VALU32Bit_f;             // Create instance
//pipe
    int fd1; 
    // FIFO file path 
    char * myfifo = "/home630/cnTai19/ALU/Example_clk/myfifo";
    // mkfifo(<pathname>,<permission>) 
    mkfifo(myfifo, 0666); 
    char str1[80], str2[80]; 
    char result_str[80];
    
    int simu_ccls = 1000;

    while (!Verilated::gotFinish()) {
//pipe read
        fd1 = open(myfifo,O_RDONLY); 
        read(fd1, str1, 80);
        close(fd1); 
//pattern operation
        vector<string> lines;
        lines = split(str1, '\n');
        vector<string> test;
        int size = 4;//sizeof(lines)/sizeof(lines[0]);
        const char* test2[size];//variable name
        unsigned int test3[size];//variable value
        for (int i = 0; i < size; ++i)
        {
            test = split(lines[i], ' ');
            test2[i] = test[0].c_str(); //variable name
            test3[i] = atoi(test[1].c_str()); //variable value
        }
        //calculation
        cout << "slave:  ---[" << main_time << "]---" << endl;
        cout << "  A: " << test3[0];
        cout << "  B: " << test3[1];
        cout << "  ALUControl: " << test3[2];
        cout << "  CLK: " << test3[3];
        top->A = test3[0];
        top->B = test3[1];
        top->ALUControl = test3[2];
        top->CLK = test3[3];
        top->eval();            // Evaluate model
        cout << "  ALUResult: " << top->ALUResult << endl;
        snprintf(result_str, 80, "%u", top->ALUResult);
        //pipe
        fd1 = open(myfifo,O_WRONLY); 
        write(fd1, result_str, strlen(result_str)+1); 
        close(fd1); 
        
        main_time++;            // Time passes...
        if (main_time == simu_ccls){
            Verilated::gotFinish(1);
        }
    } //while end
        top->final();               // Done simulating
         delete top;
}