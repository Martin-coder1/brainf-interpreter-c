
#include "brainfuck.h"

int brainfuck(struct BFState* state, const char* program) {
    // Implement you solution here
    int pc = 0;
    

    while (program[pc]!='\0')
    {
        switch (program[pc])
        {
        case '>':
            state->cur++;

            if(state->cur>= (state->array+state->array_len)){
                return -1;
            }
            pc++;

            break;
        case '<':
        state->cur--;
        pc++;
        if(state->cur<state->array) {return -1;}
        break;
        case '+':
        ++(*state->cur);
        ++pc;
        break;
        case '-':
        --(*state->cur);
        ++pc;
        break;
        //case '.':
        //putchar(*state->cur);
        //break;
        //case ',':
        //*state->cur = (uint8_t)getchar();
        //break;
        case '[':
       if(!*(state->cur)){
        int depth = 1;
        pc++;
        while(program[pc]!='\0'){
            if(program[pc]==']'){
                depth--;
            }
            if(program[pc]=='['){
                depth++;
            }
            if(depth==0){
                break;
            }
            pc++;
        }
        if(program[pc]=='\0'){
            return -1;
        }
        if(depth!=0){
            return-1;
        }
        
       }
       else{
        pc++;
       }
        break;

        case ']':

        
        if(*state->cur){
            int depth = -1;
        while(depth<0){

            if(pc==0) return -1;
            pc--;
            if(program[pc]=='['){
                depth++;
            }
            if(program[pc]==']'){
                depth--;
            }
        }
        
        }
        else{
            pc++;
        }
        break;
        

        default:
            pc++;
        }
    }
    
    return 0;
}