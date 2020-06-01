#include "tensorflow/lite/micro/examples/micro_speech/main_functions.h"

int main(){
    setup();
    while(true){
        loop();
    }
}