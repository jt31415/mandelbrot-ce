#include <ti/getcsc.h>
#include <sys/util.h>
#include <graphx.h>

void draw() {

    uint16_t x;
    uint8_t y;
    uint16_t i;

    double a, b, na, nb, xa;

    for (x = 0; x < GFX_LCD_WIDTH; x++) {
        for (y = 0; y < GFX_LCD_HEIGHT; y++) {
            i = 0;
            a = (x / (float)GFX_LCD_WIDTH - 0.5) * 4;
            b = (y / (float)GFX_LCD_HEIGHT - 0.5) * 4;
            na = a;
            nb = b;
            while (na*na + nb*nb < 4 && i < 1000) {
                xa = na * na - nb * nb + a;
                nb = 2 * na * nb + b;
                na = xa;
                i++;
            }
            /* gfx_SetColor(gfx_RGBTo1555((uint24_t)(i/1000.0f*255),(uint24_t)(i/1000.0f*255),(uint24_t)(i/1000.0f*255))); */
            gfx_SetColor(i % 256);
            gfx_SetPixel(x,y);

            if (os_GetCSC() == sk_Clear) return;
        }
    }
}

int main(void)
{

    gfx_Begin();

    draw();

    while (!os_GetCSC());

    gfx_End();

    return 0;
}
