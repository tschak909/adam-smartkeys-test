#include <stdio.h>
#include <msx.h>
#include <graphics.h>

#define SMARTKEYS_ATTR(x) (MODE2_ATTR + 5120 + (x << 8)) // Beginning of line (x) for attribute memory

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

void smartkeys_caps(void)
{
  /* Draw the keycaps one pixel at a time. */
  /* Yes, this routine is insane, it will be rewritten. */
  msx_color(15,1,7);

  /* I */
  pset(27,160);
  pset(28,160);
  pset(29,160);
  pset(28,161);
  pset(28,162);
  pset(28,163);
  pset(28,164);
  pset(28,165);
  pset(28,166);
  pset(27,166);
  pset(29,166);

  /* II */
  pset(66,160);
  pset(67,160);
  pset(68,160);
  pset(69,160);
  pset(70,160);
  pset(67,161);
  pset(69,161);
  pset(67,162);
  pset(69,162);
  pset(67,163);
  pset(69,163);
  pset(67,164);
  pset(69,164);
  pset(67,165);
  pset(69,165);
  pset(66,166);
  pset(67,166);
  pset(68,166);
  pset(69,166);
  pset(70,166);

  /* III */
  pset(104,160);
  pset(105,160);
  pset(106,160);
  pset(107,160);
  pset(108,160);
  pset(109,160);
  pset(110,160);
  pset(105,161);
  pset(107,161);
  pset(109,161);
  pset(105,162);
  pset(107,162);
  pset(109,162);
  pset(105,163);
  pset(107,163);
  pset(109,163);
  pset(105,164);
  pset(107,164);
  pset(109,164);
  pset(105,165);
  pset(107,165);
  pset(109,165);
  pset(104,166);
  pset(105,166);
  pset(106,166);
  pset(107,166);
  pset(108,166);
  pset(109,166);
  pset(110,166);

  /* IV */
  pset(144,160);
  pset(145,160);
  pset(146,160);
  pset(145,161);
  pset(145,162);
  pset(145,163);
  pset(145,164);
  pset(145,165);
  pset(144,166);
  pset(145,166);
  pset(146,166);
  pset(147,160);
  pset(151,160);
  pset(147,161);
  pset(151,161);
  pset(147,162);
  pset(151,162);
  pset(147,163);
  pset(151,163);
  pset(148,164);
  pset(150,164);
  pset(148,165);
  pset(150,165);
  pset(149,166);

  /* V */
  pset(185,160);
  pset(189,160);
  pset(185,161);
  pset(189,161);
  pset(185,162);
  pset(189,162);
  pset(185,163);
  pset(189,163);
  pset(186,164);
  pset(188,164);
  pset(186,165);
  pset(188,165);
  pset(187,166);

  /* VI */
  pset(229,160);
  pset(230,160);
  pset(231,160);
  pset(230,161);
  pset(230,162);
  pset(230,163);
  pset(230,164);
  pset(230,165);
  pset(229,166);
  pset(230,166);
  pset(231,166);  
  pset(224,160);
  pset(228,160);
  pset(224,161);
  pset(228,161);
  pset(224,162);
  pset(228,162);
  pset(224,163);
  pset(228,163);
  pset(225,164);
  pset(227,164);
  pset(225,165);
  pset(227,165);
  pset(226,166);
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

  printf("ADAM Smartkeys\n");
  printf("Render test.\n\n");
  printf("Now to write a proportional\n");
  printf("font draw routine.\n");
  
  smartkeys_attrs();
  smartkeys_caps();
  for (;;) { }
}
