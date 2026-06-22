void delay(void) {
    volatile int i;
    for(i = 0; i < 300000000; i++);
}

int main() {
    volatile unsigned int *tx     = (volatile unsigned int*)0xFF000030;
    volatile unsigned int *status = (volatile unsigned int*)0xFF00002C;
    volatile unsigned int *flag   = (volatile unsigned int*)0x50000000;

    char *pong = "Pong!\r\n";
    char *p;

    while(1) {
        while(*flag != 1); // Core 0'ın "Ping" yazmasını bekle
        
        p = pong;
        while(*p) {
            while(*status & 0x10);
            *tx = *p++;
        }
        
        delay();
        *flag = 0; // Core 0'a söyle
        
    }
    return 0;
}
