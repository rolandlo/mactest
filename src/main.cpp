/* main.c
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

int
main (int   argc, char *argv[])
{
	MactestApplication* app = mactest_application_new ("com.github.rolandlo.mactest", G_APPLICATION_HANDLES_OPEN);
	g_object_set(G_OBJECT(app), "register-session", true, (char*)0);	
	int ret = g_application_run (G_APPLICATION (app), argc, argv);
	
	return ret;
}
