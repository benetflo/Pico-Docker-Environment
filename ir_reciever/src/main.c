#include "pico/stdlib.h"
#include "ir_receiver.h"

int main() {
    stdio_init_all();

    // Initialisera IR-mottagaren
    ir_receiver_init();

    uint32_t ir_data = 0;

    while (1) {
        // Läs IR-data
        ir_data = ir_receiver_read_data();

        // Om data är mottagen, gör något (t.ex. skriv ut den)
        if (ir_data != 0) {
            printf("Mottagen IR-data: %u\n", ir_data);
            // Här kan du implementera kod för att tolka IR-koder och reagera
        }

        sleep_ms(100);  // Vänta lite innan nästa iteration
    }

    // Stäng av IR-mottagaren när programmet avslutas
    ir_receiver_deinit();

    return 0;
}
