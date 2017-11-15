#include <Adafruit_LEDBackpack.h>

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

void setup()
{
    Serial.begin(115200);
    Serial.println("8x8 LED Matrix Test");

    matrix.begin(0x70);  // 器件默认I2C地址为0x70
}

const uint8_t  smile_bmp[] =
{
    0B00111100,
    0B01000010,
    0B10100101,
    0B10000001,
    0B10100101,
    0B10011001,
    0B01000010,
    0B00111100
};

const uint8_t  neutral_bmp[] =
{
    0B00111100,
    0B01000010,
    0B10100101,
    0B10000001,
    0B10111101,
    0B10000001,
    0B01000010,
    0B00111100
};

const uint8_t  frown_bmp[] =
{
    0B00111100,
    0B01000010,
    0B10100101,
    0B10000001,
    0B10011001,
    0B10100101,
    0B01000010,
    0B00111100
};

void loop()
{
    matrix.clear();
    matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(500);

    matrix.clear();
    matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(500);

    matrix.clear();
    matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(500);

    matrix.clear();         // 清屏
    matrix.drawPixel(0, 0, LED_ON);
    matrix.writeDisplay();  // 显示
    delay(500);

    matrix.clear();
    matrix.drawLine(0,0, 7,7, LED_ON);
    matrix.writeDisplay();
    delay(500);

    matrix.clear();
    matrix.drawRect(0,0, 8,8, LED_ON);
    matrix.fillRect(2,2, 4,4, LED_ON);
    matrix.writeDisplay();
    delay(500);

    matrix.clear();
    matrix.drawCircle(3,3, 3, LED_ON);
    matrix.writeDisplay();
    delay(500);

    matrix.setTextSize(1);
    matrix.setTextWrap(false);
    matrix.setTextColor(LED_ON);
    for (int8_t x=0; x>=-36; x--)
    {
        matrix.clear();
        matrix.setCursor(x,0);
        matrix.print("Hello");
        matrix.writeDisplay();
        delay(100);
    }
    matrix.setRotation(3);
    for (int8_t x=7; x>=-36; x--)
    {
        matrix.clear();
        matrix.setCursor(x,0);
        matrix.print("World");
        matrix.writeDisplay();
        delay(100);
    }
    matrix.setRotation(0);
}
