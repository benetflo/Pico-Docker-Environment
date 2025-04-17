#include "hardware/pio.h"
#include "ir_receiver.pio.h"

static PIO pio = pio0;
static int sm;  // State machine

// Funktion för att initiera IR-receiver PIO-programmet
void ir_receiver_init() {
    uint offset = pio_add_program(pio, &ir_reciever_program);

    sm = pio_claim_unused_sm(pio, true);  // Hämta en ledig state machine

    pio_sm_config sm_config = ir_reciever_program_get_default_config(offset);
    sm_config.pin_base = 16;  // Pin för IR-mottagaren (ändra till den du använder)

    pio_sm_init(pio, sm, offset, &sm_config);
    pio_sm_set_enabled(pio, sm, true);  // Starta state machine
}

// Funktion för att läsa IR-data från PIO
uint32_t ir_receiver_read_data() {
    if (!pio_sm_is_rx_fifo_empty(pio, sm)) {
        return pio_sm_get(pio, sm);  // Läsa data från FIFO
    }
    return 0;  // Ingen data tillgänglig
}

// Funktion för att stoppa IR-mottagaren
void ir_receiver_deinit() {
    pio_sm_set_enabled(pio, sm, false);  // Stäng av state machine
    pio_sm_clear_fifos(pio, sm);         // Rensa FIFO
}
