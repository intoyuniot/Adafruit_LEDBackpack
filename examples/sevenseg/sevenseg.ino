#include <Adafruit_LEDBackpack.h>

Adafruit_7segment matrix = Adafruit_7segment();

void setup()
{
    Serial.begin(115200);
    Serial.println("7 Segment Backpack Test");
    matrix.begin(0x70); //器件默认I2C地址为0x70
}

void loop()
{
    // 输出一个长整数
    matrix.print(10000, DEC);
    matrix.writeDisplay();
    delay(500);

    // 显示一个16进制数
    matrix.print(0xBEEF, HEX);
    matrix.writeDisplay();
    delay(500);

    // print a floating point
    /* this isnt working yet, still hacking on it!
    matrix.print(12.34);
    matrix.writeDisplay();
    delay(500);
    */

    // 使用print/println
    for (uint16_t counter = 0; counter < 9999; counter++)
    {
        matrix.println(counter);
        matrix.writeDisplay();
        delay(10);
    }

    // 画每个数字
    uint16_t blinkcounter = 0;
    boolean drawDots = false;
    for (uint16_t counter = 0; counter < 9999; counter ++)
    {
        matrix.writeDigitNum(0, (counter / 1000), drawDots);
        matrix.writeDigitNum(1, (counter / 100) % 10, drawDots);
        matrix.drawColon(drawDots);
        matrix.writeDigitNum(3, (counter / 10) % 10, drawDots);
        matrix.writeDigitNum(4, counter % 10, drawDots);

        blinkcounter+=50;
        if (blinkcounter < 500)
        {
            drawDots = false;
        }
        else if (blinkcounter < 1000)
        {
            drawDots = true;
        }
        else
        {
            blinkcounter = 0;
        }
        matrix.writeDisplay();
        delay(10);
    }
}
