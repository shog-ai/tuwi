/**** tuwi.h ****
 *
 *  Copyright (c) 2023 Shoggoth Systems
 *
 * Part of the Tuwi framework, under the MIT License.
 * See LICENCE file for license information.
 * SPDX-License-Identifier: MIT
 *
 ****/

#ifndef TUWI_H
#define TUWI_H

#include <netlibc.h>
#include <netlibc/error.h>
#include <netlibc/fs.h>
#include <netlibc/log.h>
#include <netlibc/string.h>

#ifdef _WIN32
#else
#include <termios.h>
#endif

#include <wchar.h>

typedef struct RGB {
  u8 r;
  u8 g;
  u8 b;
} rgb_t;

typedef struct WINDOW_CORDS {
  u32 col;
  u32 row;
} cords_t;

typedef enum {
  BLACK,
  GREEN,
  YELLOW,
  MAGENTA,
  CYAN,
  WHITE,
  BLUE,
  RED,
  DEFAULT
} color_t;

typedef enum {
  SHAPE_DEFAULT,
  SHAPE_BLOCK,
  SHAPE_UNDERLINE,
  SHAPE_BAR
} cursor_shape_t;

typedef enum {
  STYLE_NORMAL,
  STYLE_BLINKING,
  STYLE_STEADY,
  STYLE_INVISIBLE
} cursor_style_t;

cords_t tuwi_get_terminal_size();

bool tuwi_terminal_resized(cords_t former_size);

rgb_t rgb(u8 r, u8 g, u8 b);

void tuwi_reset_terminal();

void tuwi_flush_terminal();

void tuwi_clear_terminal();

void tuwi_put_char(u64 line, u64 column, wchar_t ch);

void tuwi_put_str(u64 line, u64 column, char *str);

void tuwi_put_str_raw(u64 line, u64 column, char *str);

void tuwi_clear_line(u64 line);

void tuwi_clear_current_line();

void tuwi_clear_col(u64 line, u64 col);

void tuwi_set_cursor(u64 line, u64 col);

void tuwi_set_cursor_shape(cursor_shape_t shape);

void tuwi_set_cursor_style(cursor_style_t style);

void tuwi_set_color_rgb(rgb_t color);

void tuwi_set_bgcolor_rgb(rgb_t color);

void tuwi_set_row_bgcolor_rgb(u64 row, u64 row_size, rgb_t color);

void tuwi_set_color(color_t color);

void tuwi_reset_color();

void tuwi_reset_background_color();

void tuwi_set_background_color(color_t color);

void tuwi_enable_mouse_reporting();

void tuwi_disable_mouse_reporting();

#endif