#include "uss64.h"
#include "settings.h"
#include "sm64.h"
#include "gz/src/gz/menu.h"
#include "gz/src/gz/gfx.h"
#include "gz/src/gz/input.h"
#include "gz/src/gz/resource.h"

struct command_info command_info[COMMAND_MAX] =
{
  {"show/hide menu",    NULL,               CMDACT_PRESS_ONCE},
  {"return from menu",  NULL,               CMDACT_PRESS_ONCE},
  {"file select",       command_fileselect, CMDACT_PRESS_ONCE},
  {"reload level",      command_reload,     CMDACT_PRESS_ONCE},
  {"star select",       command_starselect, CMDACT_PRESS_ONCE},
  {"reset lag counter", command_resetlag,   CMDACT_PRESS_ONCE},
};

void uss64_apply_settings()
{
  struct gfx_font *font = resource_get(settings->bits.font_resource);
  menu_set_font(uss64.menu_main, font);
  menu_set_cell_width(uss64.menu_main, font->char_width + font->letter_spacing);
  menu_set_cell_height(uss64.menu_main, font->char_height + font->line_spacing + settings->line_spacing);
  gfx_mode_set(GFX_MODE_DROPSHADOW, settings->bits.drop_shadow);
  if (settings->bits.font_resource == RES_FONT_FIPPS)
    gfx_mode_configure(GFX_MODE_TEXT, GFX_TEXT_NORMAL);
  else
    gfx_mode_configure(GFX_MODE_TEXT, GFX_TEXT_FAST);
  menu_set_pxoffset(uss64.menu_main, settings->menu_x);
  menu_set_pyoffset(uss64.menu_main, settings->menu_y);
  menu_imitate(uss64.menu_global, uss64.menu_main);
}

void uss64_show_menu(void)
{
  menu_signal_enter(uss64.menu_main, MENU_SWITCH_SHOW);
  uss64.menu_active = 1;
  input_reserve(BUTTON_D_UP | BUTTON_D_DOWN | BUTTON_D_LEFT | BUTTON_D_RIGHT |
                BUTTON_L);
  input_reservation_set(1);
}

void uss64_hide_menu(void)
{
  menu_signal_leave(uss64.menu_main, MENU_SWITCH_HIDE);
  uss64.menu_active = 0;
  input_free(BUTTON_D_UP | BUTTON_D_DOWN | BUTTON_D_LEFT | BUTTON_D_RIGHT |
             BUTTON_L);
  input_reservation_set(0);
}

void command_fileselect(void)
{

}

void command_reload(void)
{

}

void command_starselect(void)
{

}

void command_resetlag(void)
{
  uss64.frame_counter = 0;
  uss64.lag_vi_offset = -(int32_t)SM64_sNumVblanks;
}