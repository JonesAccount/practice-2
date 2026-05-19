// kernel.c - minimal 32-bit kernel

int main(void) {
        char *video = (char *) 0xb8000;
        const char *msg = "ProtoOS >_";
        int offset = (13 * 80 + 25) * 2; // row and column

        int i = 0;
        while (msg[i] != 0) {
                video[offset + i * 2] = msg[i];
                video[offset + i * 2 + 1] = 0x17; // white on blue
                i++;
        }

        while (1) {} // halt forever
}