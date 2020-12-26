/* Etui - Multi-document rendering application using the EFL
 * Copyright (C) 2013-2014 Vincent Torri
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <config.h>

#include <Elementary.h>

#include "etui_private.h"
#include "etui_config.h"
#include "etui_win.h"
#include "etui_theme.h"


/*============================================================================*
 *                                  Local                                     *
 *============================================================================*/


static char *etui_theme_default_get(Etui *etui);

static void
_etui_theme_reload_cb(void *data EINA_UNUSED, Evas_Object *obj, const char *emission EINA_UNUSED, const char *source EINA_UNUSED)
{
    void (*func)(void *d);
    void *func_data;
    const char *file;
    const char *group;

   edje_object_file_get(obj, &file, &group);
   edje_object_file_set(obj, file, group);
   func = evas_object_data_get(obj, "theme_reload_func");
   func_data = evas_object_data_get(obj, "theme_reload_func_data");
   if (func) func(func_data);
}

static char *
etui_theme_default_get(Etui *etui)
{
    int size;

    if (etui->theme_file)
        return etui->theme_file;

    size = snprintf(NULL, 0,
                    "%s/etui/themes/default.edj", elm_app_data_dir_get());
    etui->theme_file = (char *)malloc(size + 2);
    if (!etui->theme_file)
        return NULL;

    snprintf(etui->theme_file, size + 1,
             "%s/etui/themes/default.edj", elm_app_data_dir_get());

    return etui->theme_file;
}


/*============================================================================*
 *                                 Global                                     *
 *============================================================================*/


Eina_Bool
etui_theme_apply(Evas_Object *win, const char *group)
{
    Etui *etui;

    if ((!win) || (!group))
        return EINA_FALSE;

    etui = evas_object_data_get(win, "etui");
    if (!etui)
        return EINA_FALSE;

    if (elm_layout_file_set(etui->layout, etui_theme_default_get(etui), group))
        return EINA_TRUE;

    return EINA_FALSE;
}

void
etui_theme_reload(Evas_Object *win)
{
    Etui *etui;

    if (!win)
        return;

    etui = evas_object_data_get(win, "etui");
    if (!etui)
        return;

    edje_object_signal_callback_add(etui->layout, "edje,change,file", "edje",
                                    _etui_theme_reload_cb, NULL);
}


/*============================================================================*
 *                                   API                                      *
 *============================================================================*/
