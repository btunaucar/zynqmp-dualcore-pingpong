void delay(void) {
    volatile int i;
    for(i = 0; i < 300000000; i++);
}

int main() {
    volatile unsigned int *tx     = (volatile unsigned int*)0xFF000030;
    volatile unsigned int *status = (volatile unsigned int*)0xFF00002C;
    volatile unsigned int *flag   = (volatile unsigned int*)0x50000000;

    char *ping = "Ping!\r\n";
    char *p;

    *flag = 0;

    while(1) {
        while(*flag != 0);
        
        p = ping;
        while(*p) {
            while(*status & 0x10);
            *tx = *p++;
        }
        
        delay();
        *flag = 1;
        
    }
    return 0;
}
