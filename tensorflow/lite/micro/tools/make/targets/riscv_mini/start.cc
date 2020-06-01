
extern "C"{
    extern int main(int, char* []);


    __asm volatile("la gp, __global_pointer$");
    __asm volatile("la sp, __stack_top$");
    void _start()__attribute__ ((section (".text.init")));

    void _start() {
        main(1, (char**)0);
    }
}