#include <stdio.h>
#include <msx.h>
#include <graphics.h>
#include <conio.h>
#include "font.h"

#define SMARTKEYS_ATTR(x) (MODE2_ATTR + 5376 + (x << 8)) // Beginning of line (x) for attribute memory

#define SMARTKEYS_KEY_ATTR         0xF1 // White on black
#define SMARTKEYS_LEGEND_ATTR_ODD  0xF5 // White on light blue
#define SMARTKEYS_LEGEND_ATTR_EVEN 0xF4 // White on dark blue
#define SMARTKEYS_END_ATTR_SIZE    48   // 6 8x8 tiles
#define SMARTKEYS_MID_ATTR_SIZE    40   // 5 8x8 tiles
#define SMARTKEYS_ATTR_POS_I       0    // Smartkey attr position 1
#define SMARTKEYS_ATTR_POS_II      48   // Smartkey attr position 2
#define SMARTKEYS_ATTR_POS_III     88   // Smartkey attr position 3
#define SMARTKEYS_ATTR_POS_IV     128   // Smartkey attr position 4
#define SMARTKEYS_ATTR_POS_V      168   // Smartkey attr position 5
#define SMARTKEYS_ATTR_POS_VI     208   // Smartkey attr position 6

void smartkeys_text(void)
{
  msx_color(15,4,7);
  gotoxy(27,22);
  cprintf("BOOT");
  msx_color(15,5,7);
  gotoxy(1,22);
  cprintf("SETUP");
}

void smartkeys_caps(void)
{
  /* Draw the keycaps one pixel at a time. */
  /* Yes, this routine is insane, it will be rewritten. */
  msx_color(15,1,7);
  
  /* I */
  pset(27,168);
  pset(28,168);
  pset(29,168);
  pset(28,169);
  pset(28,170);
  pset(28,171);
  pset(28,172);
  pset(28,173);
  pset(28,174);
  pset(27,174);
  pset(29,174);

  /* II */
  pset(66,168);
  pset(67,168);
  pset(68,168);
  pset(69,168);
  pset(70,168);
  pset(67,169);
  pset(69,169);
  pset(67,170);
  pset(69,170);
  pset(67,171);
  pset(69,171);
  pset(67,172);
  pset(69,172);
  pset(67,173);
  pset(69,173);
  pset(66,174);
  pset(67,174);
  pset(68,174);
  pset(69,174);
  pset(70,174);

  /* III */
  pset(104,168);
  pset(105,168);
  pset(106,168);
  pset(107,168);
  pset(108,168);
  pset(109,168);
  pset(110,168);
  pset(105,169);
  pset(107,169);
  pset(109,169);
  pset(105,170);
  pset(107,170);
  pset(109,170);
  pset(105,171);
  pset(107,171);
  pset(109,171);
  pset(105,172);
  pset(107,172);
  pset(109,172);
  pset(105,173);
  pset(107,173);
  pset(109,173);
  pset(104,174);
  pset(105,174);
  pset(106,174);
  pset(107,174);
  pset(108,174);
  pset(109,174);
  pset(110,174);

  /* IV */
  pset(144,168);
  pset(145,168);
  pset(146,168);
  pset(145,169);
  pset(145,170);
  pset(145,171);
  pset(145,172);
  pset(145,173);
  pset(144,174);
  pset(145,174);
  pset(146,174);
  pset(147,168);
  pset(151,168);
  pset(147,169);
  pset(151,169);
  pset(147,170);
  pset(151,170);
  pset(147,171);
  pset(151,171);
  pset(148,172);
  pset(150,172);
  pset(148,173);
  pset(150,173);
  pset(149,174);

  /* V */
  pset(185,168);
  pset(189,168);
  pset(185,169);
  pset(189,169);
  pset(185,170);
  pset(189,170);
  pset(185,171);
  pset(189,171);
  pset(186,172);
  pset(188,172);
  pset(186,173);
  pset(188,173);
  pset(187,174);

  /* VI */
  pset(229,168);
  pset(230,168);
  pset(231,168);
  pset(230,169);
  pset(230,170);
  pset(230,171);
  pset(230,172);
  pset(230,173);
  pset(229,174);
  pset(230,174);
  pset(231,174);  
  pset(224,168);
  pset(228,168);
  pset(224,169);
  pset(228,169);
  pset(224,170);
  pset(228,170);
  pset(224,171);
  pset(228,171);
  pset(225,172);
  pset(227,172);
  pset(225,173);
  pset(227,173);
  pset(226,174);
}

/**
 * Set up VRAM attribute memory colors for SmartKeys display
 */
void smartkeys_attrs(void)
{
  int line=0;

  // Set the key legend attributes
  for (line=0; line<3; line++)
    {
      msx_vfill(SMARTKEYS_ATTR(line)+SMARTKEYS_ATTR_POS_I,   SMARTKEYS_LEGEND_ATTR_ODD,  SMARTKEYS_END_ATTR_SIZE);
      msx_vfill(SMARTKEYS_ATTR(line)+SMARTKEYS_ATTR_POS_II,  SMARTKEYS_LEGEND_ATTR_EVEN, SMARTKEYS_MID_ATTR_SIZE);
      msx_vfill(SMARTKEYS_ATTR(line)+SMARTKEYS_ATTR_POS_III, SMARTKEYS_LEGEND_ATTR_ODD,  SMARTKEYS_MID_ATTR_SIZE);
      msx_vfill(SMARTKEYS_ATTR(line)+SMARTKEYS_ATTR_POS_IV,  SMARTKEYS_LEGEND_ATTR_EVEN, SMARTKEYS_MID_ATTR_SIZE);
      msx_vfill(SMARTKEYS_ATTR(line)+SMARTKEYS_ATTR_POS_V,   SMARTKEYS_LEGEND_ATTR_ODD,  SMARTKEYS_MID_ATTR_SIZE);
      msx_vfill(SMARTKEYS_ATTR(line)+SMARTKEYS_ATTR_POS_VI,  SMARTKEYS_LEGEND_ATTR_EVEN, SMARTKEYS_END_ATTR_SIZE);
    }

  // Add legend trim
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_I-256+7,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_I-256+7+8,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_I-256+7+16,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_I-256+7+24,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_I-256+7+32,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_I-256+7+40,SMARTKEYS_LEGEND_ATTR_ODD);

  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_II-256+7,SMARTKEYS_LEGEND_ATTR_EVEN);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_II-256+7+8,SMARTKEYS_LEGEND_ATTR_EVEN);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_II-256+7+16,SMARTKEYS_LEGEND_ATTR_EVEN);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_II-256+7+24,SMARTKEYS_LEGEND_ATTR_EVEN);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_II-256+7+32,SMARTKEYS_LEGEND_ATTR_EVEN);

  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_III-256+7,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_III-256+7+8,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_III-256+7+16,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_III-256+7+24,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_III-256+7+32,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_III-256+7+40,SMARTKEYS_LEGEND_ATTR_ODD);

  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_IV-256+7,SMARTKEYS_LEGEND_ATTR_EVEN);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_IV-256+7+8,SMARTKEYS_LEGEND_ATTR_EVEN);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_IV-256+7+16,SMARTKEYS_LEGEND_ATTR_EVEN);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_IV-256+7+24,SMARTKEYS_LEGEND_ATTR_EVEN);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_IV-256+7+32,SMARTKEYS_LEGEND_ATTR_EVEN);

  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_V-256+7,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_V-256+7+8,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_V-256+7+16,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_V-256+7+24,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_V-256+7+32,SMARTKEYS_LEGEND_ATTR_ODD);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_V-256+7+40,SMARTKEYS_LEGEND_ATTR_ODD);

  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_VI-256+7,SMARTKEYS_LEGEND_ATTR_EVEN);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_VI-256+7+8,SMARTKEYS_LEGEND_ATTR_EVEN);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_VI-256+7+16,SMARTKEYS_LEGEND_ATTR_EVEN);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_VI-256+7+24,SMARTKEYS_LEGEND_ATTR_EVEN);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_VI-256+7+32,SMARTKEYS_LEGEND_ATTR_EVEN);
  vpoke(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_VI-256+7+40,SMARTKEYS_LEGEND_ATTR_EVEN);
  
  // Now set attributes for the key caps
  msx_vfill(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_I+16, SMARTKEYS_KEY_ATTR, 24);
  msx_vfill(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_II+8, SMARTKEYS_KEY_ATTR, 24);
  msx_vfill(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_III+8, SMARTKEYS_KEY_ATTR, 24);
  msx_vfill(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_IV+8, SMARTKEYS_KEY_ATTR, 24);
  msx_vfill(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_V+8, SMARTKEYS_KEY_ATTR, 24);
  msx_vfill(SMARTKEYS_ATTR(0)+SMARTKEYS_ATTR_POS_VI+8, SMARTKEYS_KEY_ATTR, 24);
}

void main(void)
{
  msx_color(1,7,7); // Set default SmartWriter like colors, black, cyan bkg, cyan border
  msx_set_mode(2); // Reset mode so that vram will be filled with background color

  cprintf("           HOST SLOTS           ");
  cprintf(" 1| FUJINET.ONLINE\n");
  cprintf(" 2| ADAM-APPS.IRATA.ONLINE\n");
  cprintf(" 3| ATARIAGE.COM\n");
  cprintf(" 4| <EMPTY>\n");
  cprintf(" 5| <EMPTY>\n");
  cprintf(" 6| <EMPTY>\n");
  cprintf(" 7| <EMPTY>\n");
  cprintf(" 8| <EMPTY>\n\n\n");
  cprintf("          DEVICE SLOTS          ");
  cprintf("D1: AdamCalc.ddp\n");
  cprintf("D2: Financials.ddp\n");
  cprintf("D3: Donkey Kong Jr.ddp\n");
  cprintf("D4: <EMPTY>\n\n\n\n");
  cprintf("  WELCOME TO #FUJINET FOR ADAM  ");

  msx_vfill(MODE2_ATTR,0xF5,256);
  msx_vfill(MODE2_ATTR+2816,0xF5,256);
  msx_vfill(MODE2_ATTR+256,0x1F,2304);
  msx_vfill(MODE2_ATTR+3072,0x1F,1792-256);
  msx_vfill(MODE2_ATTR+256,0x1B,256);
  smartkeys_attrs();
  smartkeys_caps();
  smartkeys_text();
  for (;;) { }
}
