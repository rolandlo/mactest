/* mactest-window.c
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

#include "mactest-window.h"

struct _MactestWindow
{
	GtkApplicationWindow  parent_instance;

	/* Template widgets */
	GtkLabel            *label;
};

G_DEFINE_FINAL_TYPE (MactestWindow, mactest_window, GTK_TYPE_APPLICATION_WINDOW)

static void
mactest_window_class_init (MactestWindowClass *klass)
{
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

	gtk_widget_class_set_template_from_resource (widget_class, "/com/github/xournalpp/mactest/mactest-window.ui");
	gtk_widget_class_bind_template_child (widget_class, MactestWindow, label);
}

static void
mactest_window_init (MactestWindow *self)
{
	gtk_widget_init_template (GTK_WIDGET (self));
}

MactestWindow *mactest_window_new (MactestApplication *app)
{
    return MACTEST_WINDOW(g_object_new (MACTEST_TYPE_WINDOW, "application", app, (char*)0));
}

void mactest_window_set_text(MactestWindow *win, const char *text) {
    gtk_label_set_text(win->label, text);
}
