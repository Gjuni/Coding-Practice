// 202010836
// June

#include <stdio.h>

int main(void)
{
    int rgb = 0;
    int red, green, blue;
    int ch_red, ch_green, ch_blue;
    char answer;
    char ch_rgb;

    printf("input rgb for 16 binary : ");
    scanf("%x", &rgb);

    red = rgb >> 16; 
    green = rgb >> 8&0x00ff; 
    blue = rgb&0x0000ff;

    printf("R,G,B Value is (%d, %d, %d) \n", red, green, blue);

    
    do {
        printf("change RGB color R, G, B : ");
        scanf(" %c", &ch_rgb);

        while(ch_rgb != 'R' || ch_rgb != 'r' || ch_rgb != 'b' || ch_rgb != 'B' || ch_rgb != 'G' || ch_rgb != 'g')
        {
                if(ch_rgb == 'R' || ch_rgb == 'r')
            {
                printf("change R color Value : ");
                scanf("%d", &ch_red);
                red = red + ch_red;

                if(red > 255)
                {
                    red = 255;
                }
                else if(red < 0)
                {
                    red = 0;
                }
                break;

            }
            else if (ch_rgb == 'G' || ch_rgb == 'g')
            {
                printf("change G color Value  : ");
                scanf("%d", &ch_green);
                green = green + ch_green;

                if(green > 255)
                {
                    green = 255;
                }
                else if(green < 0)
                {
                    green = 0;
                }
                break;
            }
            else if (ch_rgb == 'B' || ch_rgb == 'b')
            {
                printf("change B color Value  : ");
                scanf("%d", &ch_blue);
                blue = blue + ch_blue;

                if(blue>255)
                {
                    blue = 255;
                }
                else if(blue < 0)
                {
                    blue = 0;
                }
                break;
            }
            else 
            {
                printf("please input RGB again");

                printf("\nchange RGB color R, G, B : ");
                scanf(" %c", &ch_rgb);
            }

        }

        rgb = (red << 16) | (green <<8) | (blue);

        printf("changed RGB Value is (%d, %d, %d) and for 16 Binary is %#06x \n", red, green, blue, rgb);
        printf("Continue to change RGB color? (Y/N)");
        scanf(" %c", &answer);
        

    } while(answer == 'Y' || answer == 'y');

    


    return 0;
}