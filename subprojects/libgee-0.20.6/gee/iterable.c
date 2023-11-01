/* iterable.c generated by valac 0.56.3, the Vala compiler
 * generated from iterable.vala, do not modify */

/* iterable.vala
 *
 * Copyright (C) 2007-2008  Jürg Billeter
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Jürg Billeter <j@bitron.ch>
 */

#include "gee.h"
#include <glib-object.h>
#include <glib.h>

static GType gee_iterable_get_type_once (void);

/**
 * Returns a {@link Iterator} that can be used for simple iteration over a
 * collection.
 *
 * @return a {@link Iterator} that can be used for simple iteration over a
 *         collection
 */
GeeIterator*
gee_iterable_iterator (GeeIterable* self)
{
	GeeIterableIface* _iface_;
	g_return_val_if_fail (self != NULL, NULL);
	_iface_ = GEE_ITERABLE_GET_INTERFACE (self);
	if (_iface_->iterator) {
		return _iface_->iterator (self);
	}
	return NULL;
}

static void
gee_iterable_default_init (GeeIterableIface * iface,
                           gpointer iface_data)
{
}

/**
 * An object that can provide an {@link Iterator}.
 */
static GType
gee_iterable_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (GeeIterableIface), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gee_iterable_default_init, (GClassFinalizeFunc) NULL, NULL, 0, 0, (GInstanceInitFunc) NULL, NULL };
	GType gee_iterable_type_id;
	gee_iterable_type_id = g_type_register_static (G_TYPE_INTERFACE, "GeeIterable", &g_define_type_info, 0);
	g_type_interface_add_prerequisite (gee_iterable_type_id, G_TYPE_OBJECT);
	g_type_interface_add_prerequisite (gee_iterable_type_id, GEE_TYPE_TRAVERSABLE);
	return gee_iterable_type_id;
}

GType
gee_iterable_get_type (void)
{
	static volatile gsize gee_iterable_type_id__once = 0;
	if (g_once_init_enter (&gee_iterable_type_id__once)) {
		GType gee_iterable_type_id;
		gee_iterable_type_id = gee_iterable_get_type_once ();
		g_once_init_leave (&gee_iterable_type_id__once, gee_iterable_type_id);
	}
	return gee_iterable_type_id__once;
}

