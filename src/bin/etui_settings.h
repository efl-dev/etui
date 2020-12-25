/* Etui - Multi-document rendering application using the EFL
 * Copyright (C) 2013-2017 Vincent Torri
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

#ifndef ETUI_BIN_SETTINGS_H
#define ETUI_BIN_SETTINGS_H


Eina_Bool etui_settings_active_get(void);
void etui_settings_toggle(Evas_Object *win, Evas_Object *bg);

void etui_settings_behavior(Evas_Object *stbox, Evas_Object *win);
void etui_settings_elm(Evas_Object *stbox, Evas_Object *win);


#endif /* ETUI_BIN_SETTINGS_H */
