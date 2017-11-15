#include <Adafruit_LEDBackpack.h>

Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();

uint8_t counter = 0;

void setup()
{
    Serial.begin(115200);
    Serial.println("HT16K33 test");

    matrix.begin(0x70);  // 默认器件I2C地址为0x70
}

void loop()
{
    // paint one LED per row. The HT16K33 internal memory looks like
    // a 8x16 bit matrix (8 rows, 16 columns)
    // 填充缓存. HT16K33内部寄存器就像一个8*16 位的一个矩阵(8行  16列)
    for (uint8_t i=0; i<8; i++)
    {
        // 画一条斜线
        matrix.displaybuffer[i] = bit((counter+i) % 16) | bit((counter+i+8) % 16)  ;
    }
    // 显示
    matrix.writeDisplay();
    delay(100);

    counter++;
    if (counter >= 16) counter = 0;
}
