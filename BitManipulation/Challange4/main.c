#include <stdio.h>

struct packed_struct
{
    unsigned int is_opaque:1;       // 0 indicates transparentcy
    unsigned int fill_color:3;      // 0Blue0Green0Red
    unsigned int :4;         
    unsigned int show_border:1;     
    unsigned int border_style:2;    // 000 solid, 001 dotted, 010 dashed
    unsigned int border_color:3;
    unsigned int :2;
};

void printPackedStruct(struct packed_struct *packed_data);

int main(void)
{
    struct packed_struct temp;
    struct packed_struct *packed_data;
    packed_data = &temp;

    packed_data->is_opaque = 1;
    packed_data->fill_color = 6; //cyan
    packed_data->show_border = 1;
    packed_data->border_style = 0;
    packed_data->border_color = 4;
    
    printf("Original Box Settings:\n");
    printPackedStruct(packed_data);

    packed_data->is_opaque = 0;
    packed_data->fill_color = 2; //green
    packed_data->show_border = 0;
    packed_data->border_style = 1;
    packed_data->border_color = 1; //red

    printf("\n\n\nModified Box Settings:\n");
    printPackedStruct(packed_data);
  
    return 0;
}

void printPackedStruct(struct packed_struct *packed_data)
{
    const char *colors[] = {"Black", "Red", "Green", "Yellow", "Blue", "Magenta", "Cyan", "White"};
    const char *borderStyle[] = {"Solid", "Dotted", "Dashed"};

    if(packed_data->is_opaque == 1)
        printf("Box is opaque\n");
    else
        printf("Box is transparent\n");
    printf("The fill color is %s\n", colors[packed_data->fill_color]);
    if(packed_data->show_border == 1)
        printf("The border is showing\n");
    else
        printf("The border is not showing\n");
    printf("The border style is %s\n", borderStyle[packed_data->border_style]);
    printf("The border color is %s\n", colors[packed_data->border_color]); 
}