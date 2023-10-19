/* mactest-window.h
 *
 * Copyright 2023 Roland Lötscher
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#include <gtk/gtk.h>
#include "mactest-application.h"

G_BEGIN_DECLS

#define MACTEST_TYPE_WINDOW (mactest_window_get_type())

G_DECLARE_FINAL_TYPE (MactestWindow, mactest_window, MACTEST, WINDOW, GtkApplicationWindow)

G_END_DECLS

MactestWindow       *mactest_window_new          (MactestApplication *app);
void                 mactest_window_open         (MactestWindow *win, GFile *file);
void                 mactest_window_set_text     (MactestWindow *win, const char *text);

