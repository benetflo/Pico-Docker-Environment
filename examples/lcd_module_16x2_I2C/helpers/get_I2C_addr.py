from machine import Pin, I2C

def scan_for_addr(sda_pin,scl_pin) :
    sda = Pin(sda_pin)
    scl = Pin(scl_pin)
    i2c = I2C(0,sda=sda, scl=scl, freq=400000)
    addr = i2c.scan()
    return addr[0]


print(scan_for_addr(4,5))
