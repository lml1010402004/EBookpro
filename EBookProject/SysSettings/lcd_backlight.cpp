#include <QFile>
#include <QDebug>
#include "syssettings.h"


#define DISP_OUTPUT_TYPE_LCD  1
#define	DISP_LCD_SET_BRIGHTNESS     0x102
#define	DISP_LCD_GET_BRIGHTNESS     0x103
#define DISP_LCD_BACKLIGHT_ENABLE   0x104
#define DISP_LCD_BACKLIGHT_DISABLE  0x105


#define LCD_LIGHT_FILE      "/dev/disp"

Lcd_backlight::Lcd_backlight()
{

}



/**
 *
 * get light value
 * @brief Lcd_backlight::getLight
 * @return
 */
int Lcd_backlight::getLight()
{

    int value = -1;
    int fd;
    fd = open(LCD_LIGHT_FILE, O_RDONLY);
    if(fd > 0)
    {
       value = ioctl(fd, DISP_LCD_GET_BRIGHTNESS);
    }

    return value;
}


/**
 * set a int value to the light file
 *
 * @brief Lcd_backlight::setLight
 * @param value
 */
void Lcd_backlight::setLight(int value)
{
    unsigned int cmd[8] = {0};
    cmd[1] = value;

    int fd = open(LCD_LIGHT_FILE, O_WRONLY);
    if(fd>0){
        int fd1 = ioctl(fd, DISP_LCD_SET_BRIGHTNESS, cmd);
    }
    close(fd);
}



void Lcd_backlight::enableLight()
{
    unsigned int cmd[8] = {0};

    int fd = open(LCD_LIGHT_FILE, O_RDWR);
    int sss = ioctl(fd, DISP_LCD_BACKLIGHT_ENABLE, cmd);
    close(fd);
}

void Lcd_backlight::disableLight()
{
    unsigned int cmd[8] = {0};

    int fd = open(LCD_LIGHT_FILE, O_RDWR);
    int sss = ioctl(fd, DISP_LCD_BACKLIGHT_DISABLE, cmd);
    close(fd);
}
