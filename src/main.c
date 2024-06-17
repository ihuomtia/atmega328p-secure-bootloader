#include <Arduino.h>
#include <stdint.h>
#include "uart.h"
#include "keys.h"
#include "functions.h"

#define IS_READY             0x00
#define OK_DEVICE_READY      0x01
#define DO_RECEIVE_DATA      0x02
#define DO_PROGRAM_FLASH     0x03
#define DO_CHECK_DATA        0x04
#define DO_UPDATE_PKEY       0x05
#define DO_SELF_CHECK        0x06
#define DO_RESET_SZ_COUNTER  0x0E
#define ERR_SIZE_TOO_BIG     0x07
#define ERR_SIZE_TOO_SMALL   0x08
#define ERR_MALICIOUS_DATA   0x09
#define ERR_NOT_IMPLEMENTED  0x0A
#define OK_SAFE_DATA         0x0B
#define OK_DATA_RECEIVED     0x0C
#define OK_PROGRAM_FLASHED   0x0D
#define MAX_DATA_SIZE        256
#define MIN_DATA_SIZE        49

int main()
{
    USART_Init(UBRR);
    uint8_t c;
    uint16_t size = 0;
    size_t total_programmed = 0;
    uint8_t data[MAX_DATA_SIZE];

    while (1)
    {
        c = USART_Receive();
        switch(c)
        {
            case IS_READY:
                USART_Transmit(OK_DEVICE_READY);
                break;

            case DO_RECEIVE_DATA:
                size = (USART_Receive() << 8) | USART_Receive();
                if (size > MAX_DATA_SIZE)
                {
                    USART_Transmit(ERR_SIZE_TOO_BIG);
                }
                else if (size < MIN_DATA_SIZE)
                {
                    USART_Transmit(ERR_SIZE_TOO_SMALL);
                }
                else
                {
                    read_from_serial(data, size);
                    USART_Transmit(OK_DATA_RECEIVED);
                }
                break;

            case DO_CHECK_DATA:
                if (size < MIN_DATA_SIZE)
                {
                    USART_Transmit(ERR_SIZE_TOO_SMALL);
                }
                else if (verify_image(data, size))
                {
                    USART_Transmit(OK_SAFE_DATA);
                }
                else
                {
                    USART_Transmit(ERR_MALICIOUS_DATA);
                }
                break;

            case DO_PROGRAM_FLASH:
                if (size < MIN_DATA_SIZE)
                {
                    USART_Transmit(ERR_SIZE_TOO_SMALL);
                }
                else if (verify_image(data, size))
                {
                    write_program(total_programmed, data + NUM_ECC_DIGITS * 2, size - NUM_ECC_DIGITS * 2);
                    total_programmed += size - NUM_ECC_DIGITS * 2;
                    USART_Transmit(OK_PROGRAM_FLASHED);
                }
                else
                {
                    USART_Transmit(ERR_MALICIOUS_DATA);
                }
                break;

            default:
                USART_Transmit(ERR_NOT_IMPLEMENTED);
                break;
        }
    }
}
