/* mactest-application.c
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

#include "mactest-application.h"
#include "mactest-window.h"
#include <string>

struct _MactestApplication
{
	GtkApplication parent_instance;
};

G_DEFINE_TYPE (MactestApplication, mactest_application, GTK_TYPE_APPLICATION)

MactestApplication *
mactest_application_new (const char *application_id, GApplicationFlags flags)
{
	g_return_val_if_fail (application_id != nullptr, nullptr);

	return MACTEST_APPLICATION(g_object_new (MACTEST_TYPE_APPLICATION, "application-id", application_id, "flags", flags, (char*)0));
}

static void
mactest_application_activate (GApplication *app)
{
    g_message("on activate");
	g_assert (MACTEST_IS_APPLICATION (app));

	GtkWindow *window = gtk_application_get_active_window (GTK_APPLICATION (app));

	if (window == NULL)
		window = GTK_WINDOW(mactest_window_new(MACTEST_APPLICATION(app)));

	mactest_window_set_text(MACTEST_WINDOW(window), "I'm just activating");

	gtk_window_present (window);
}

static void
mactest_application_open (GApplication *app, GFile **files, gint n_files, const gchar *hint)
{
        g_assert (MACTEST_IS_APPLICATION (app));
        g_message("on open");
        if (n_files != 1) {
            g_message("Can't open more than one file");
            return;
        }

        GtkWindow *window = gtk_application_get_active_window (GTK_APPLICATION (app));
	    
		if (!window) {
		  window = GTK_WINDOW(g_object_new (MACTEST_TYPE_WINDOW, "application", app, (char*)0));
		}

        std::string msg = "I'm opening the file ";
        msg += g_file_get_path(files[0]);
	    mactest_window_set_text(MACTEST_WINDOW(window), msg.c_str());
        gtk_window_present (window);
}

static void
mactest_application_class_init (MactestApplicationClass *klass)
{
	GApplicationClass *app_class = G_APPLICATION_CLASS (klass);

	app_class->activate = mactest_application_activate;
        app_class->open = mactest_application_open;
}


static void
mactest_application_init (MactestApplication *self)
{
}
