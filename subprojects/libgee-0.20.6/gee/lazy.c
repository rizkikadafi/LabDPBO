/* lazy.c generated by valac 0.56.3, the Vala compiler
 * generated from lazy.vala, do not modify */

/* lazy.vala
 *
 * Copyright (C) 2011  Maciej Piechotka
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
 * 	Maciej Piechotka <uzytkownik2@gmail.com>
 */

#include "gee.h"
#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <string.h>
#include <async.h>
#include <gobject/gvaluecollector.h>

#define GEE_LAZY_TYPE_FUTURE (gee_lazy_future_get_type ())
#define GEE_LAZY_FUTURE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GEE_LAZY_TYPE_FUTURE, GeeLazyFuture))
#define GEE_LAZY_FUTURE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GEE_LAZY_TYPE_FUTURE, GeeLazyFutureClass))
#define GEE_LAZY_IS_FUTURE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GEE_LAZY_TYPE_FUTURE))
#define GEE_LAZY_IS_FUTURE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GEE_LAZY_TYPE_FUTURE))
#define GEE_LAZY_FUTURE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GEE_LAZY_TYPE_FUTURE, GeeLazyFutureClass))

typedef struct _GeeLazyFuture GeeLazyFuture;
typedef struct _GeeLazyFutureClass GeeLazyFutureClass;
typedef struct _GeeLazyFuturePrivate GeeLazyFuturePrivate;
typedef enum  {
	GEE_LAZY_FUTURE_STATE_UNLOCK,
	GEE_LAZY_FUTURE_STATE_EVAL
} GeeLazyFutureState;

#define GEE_LAZY_FUTURE_TYPE_STATE (gee_lazy_future_state_get_type ())

#define GEE_FUTURE_TYPE_SOURCE_FUNC_ARRAY_ELEMENT (gee_future_source_func_array_element_get_type ())
typedef struct _GeeFutureSourceFuncArrayElement GeeFutureSourceFuncArrayElement;
enum  {
	GEE_LAZY_FUTURE_0_PROPERTY,
	GEE_LAZY_FUTURE_G_TYPE,
	GEE_LAZY_FUTURE_G_DUP_FUNC,
	GEE_LAZY_FUTURE_G_DESTROY_FUNC,
	GEE_LAZY_FUTURE_READY_PROPERTY,
	GEE_LAZY_FUTURE_EXCEPTION_PROPERTY,
	GEE_LAZY_FUTURE_NUM_PROPERTIES
};
static GParamSpec* gee_lazy_future_properties[GEE_LAZY_FUTURE_NUM_PROPERTIES];
#define _gee_lazy_unref0(var) ((var == NULL) ? NULL : (var = (gee_lazy_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _GeeLazyFutureWaitAsyncData GeeLazyFutureWaitAsyncData;
typedef struct _GeeParamSpecLazy GeeParamSpecLazy;

struct _GeeLazyPrivate {
	GType g_type;
	GBoxedCopyFunc g_dup_func;
	GDestroyNotify g_destroy_func;
	GeeLazyFunc _func;
	gpointer _func_target;
	GDestroyNotify _func_target_destroy_notify;
	gpointer _value;
};

struct _GeeLazyFuture {
	GObject parent_instance;
	GeeLazyFuturePrivate * priv;
};

struct _GeeLazyFutureClass {
	GObjectClass parent_class;
};

struct _GeeFutureSourceFuncArrayElement {
	GSourceFunc func;
	gpointer func_target;
	GDestroyNotify func_target_destroy_notify;
};

struct _GeeLazyFuturePrivate {
	GType g_type;
	GBoxedCopyFunc g_dup_func;
	GDestroyNotify g_destroy_func;
	GMutex _mutex;
	GCond _eval;
	GeeLazy* _lazy;
	GeeLazyFutureState _state;
	GeeFutureSourceFuncArrayElement* _when_done;
	gint _when_done_length1;
	gint __when_done_size_;
};

struct _GeeLazyFutureWaitAsyncData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GTask* _async_result;
	GeeLazyFuture* self;
	gconstpointer result;
	GeeLazy* _tmp0_;
	GeeLazyFunc _tmp1_;
	gpointer _tmp1__target;
	GeeFutureSourceFuncArrayElement _tmp2_;
	GeeLazy* _tmp3_;
	gconstpointer _tmp4_;
	gconstpointer _tmp5_;
};

struct _GeeParamSpecLazy {
	GParamSpec parent_instance;
};

static gint GeeLazy_private_offset;
static gpointer gee_lazy_parent_class = NULL;
static gint GeeLazyFuture_private_offset;
static gpointer gee_lazy_future_parent_class = NULL;
static GeeFutureIface * gee_lazy_future_gee_future_parent_iface = NULL;

static GeeLazyFuture* gee_lazy_future_new (GType g_type,
                                    GBoxedCopyFunc g_dup_func,
                                    GDestroyNotify g_destroy_func,
                                    GeeLazy* lazy);
static GeeLazyFuture* gee_lazy_future_construct (GType object_type,
                                          GType g_type,
                                          GBoxedCopyFunc g_dup_func,
                                          GDestroyNotify g_destroy_func,
                                          GeeLazy* lazy);
static GType gee_lazy_future_get_type (void) G_GNUC_CONST  G_GNUC_UNUSED ;
static GType gee_lazy_future_state_get_type (void) G_GNUC_CONST  G_GNUC_UNUSED ;
 G_GNUC_INTERNAL GType gee_future_source_func_array_element_get_type (void) G_GNUC_CONST  G_GNUC_UNUSED ;
 G_GNUC_INTERNAL GeeFutureSourceFuncArrayElement* gee_future_source_func_array_element_dup (const GeeFutureSourceFuncArrayElement* self);
 G_GNUC_INTERNAL void gee_future_source_func_array_element_free (GeeFutureSourceFuncArrayElement* self);
 G_GNUC_INTERNAL void gee_future_source_func_array_element_copy (const GeeFutureSourceFuncArrayElement* self,
                                                GeeFutureSourceFuncArrayElement* dest);
 G_GNUC_INTERNAL void gee_future_source_func_array_element_destroy (GeeFutureSourceFuncArrayElement* self);
static void _vala_GeeFutureSourceFuncArrayElement_array_free (GeeFutureSourceFuncArrayElement * array,
                                                       gssize array_length);
static gconstpointer gee_lazy_future_real_wait (GeeFuture* base,
                                         GError** error);
static void gee_lazy_future_do_eval (GeeLazyFuture* self);
static gboolean gee_lazy_future_real_wait_until (GeeFuture* base,
                                          gint64 end_time,
                                          gconstpointer* value,
                                          GError** error);
static void gee_lazy_future_real_wait_async_data_free (gpointer _data);
static void gee_lazy_future_real_wait_async (GeeFuture* base,
                                      GAsyncReadyCallback _callback_,
                                      gpointer _user_data_);
static gboolean gee_lazy_future_real_wait_async_co (GeeLazyFutureWaitAsyncData* _data_);
static gboolean _gee_lazy_future_real_wait_async_co_gsource_func (gpointer self);
 G_GNUC_INTERNAL void gee_future_source_func_array_element_init (GeeFutureSourceFuncArrayElement *self,
                                                GSourceFunc func,
                                                gpointer func_target,
                                                GDestroyNotify func_target_destroy_notify);
static void _vala_array_add1 (GeeFutureSourceFuncArrayElement* * array,
                       gint* length,
                       gint* size,
                       const GeeFutureSourceFuncArrayElement* value);
static void gee_lazy_future_wait_async_ready (GObject* source_object,
                                       GAsyncResult* _res_,
                                       gpointer _user_data_);
static void gee_lazy_future_finalize (GObject * obj);
static GType gee_lazy_future_get_type_once (void);
static void _vala_gee_lazy_future_get_property (GObject * object,
                                         guint property_id,
                                         GValue * value,
                                         GParamSpec * pspec);
static void _vala_gee_lazy_future_set_property (GObject * object,
                                         guint property_id,
                                         const GValue * value,
                                         GParamSpec * pspec);
static void gee_lazy_finalize (GeeLazy * obj);
static GType gee_lazy_get_type_once (void);
static void _vala_clear_GMutex (GMutex * mutex);
static void _vala_clear_GRecMutex (GRecMutex * mutex);
static void _vala_clear_GRWLock (GRWLock * mutex);
static void _vala_clear_GCond (GCond * mutex);

static inline gpointer
gee_lazy_get_instance_private (GeeLazy* self)
{
	return G_STRUCT_MEMBER_P (self, GeeLazy_private_offset);
}

GeeLazy*
gee_lazy_construct (GType object_type,
                    GType g_type,
                    GBoxedCopyFunc g_dup_func,
                    GDestroyNotify g_destroy_func,
                    GeeLazyFunc func,
                    gpointer func_target,
                    GDestroyNotify func_target_destroy_notify)
{
	GeeLazy* self = NULL;
	GeeLazyFunc _tmp0_;
	gpointer _tmp0__target;
	GDestroyNotify _tmp0__target_destroy_notify;
	self = (GeeLazy*) g_type_create_instance (object_type);
	self->priv->g_type = g_type;
	self->priv->g_dup_func = g_dup_func;
	self->priv->g_destroy_func = g_destroy_func;
	_tmp0_ = func;
	_tmp0__target = func_target;
	_tmp0__target_destroy_notify = func_target_destroy_notify;
	func = NULL;
	func_target = NULL;
	func_target_destroy_notify = NULL;
	(self->priv->_func_target_destroy_notify == NULL) ? NULL : (self->priv->_func_target_destroy_notify (self->priv->_func_target), NULL);
	self->priv->_func = NULL;
	self->priv->_func_target = NULL;
	self->priv->_func_target_destroy_notify = NULL;
	self->priv->_func = _tmp0_;
	self->priv->_func_target = _tmp0__target;
	self->priv->_func_target_destroy_notify = _tmp0__target_destroy_notify;
	(func_target_destroy_notify == NULL) ? NULL : (func_target_destroy_notify (func_target), NULL);
	func = NULL;
	func_target = NULL;
	func_target_destroy_notify = NULL;
	return self;
}

GeeLazy*
gee_lazy_new (GType g_type,
              GBoxedCopyFunc g_dup_func,
              GDestroyNotify g_destroy_func,
              GeeLazyFunc func,
              gpointer func_target,
              GDestroyNotify func_target_destroy_notify)
{
	return gee_lazy_construct (GEE_TYPE_LAZY, g_type, g_dup_func, g_destroy_func, func, func_target, func_target_destroy_notify);
}

GeeLazy*
gee_lazy_construct_from_value (GType object_type,
                               GType g_type,
                               GBoxedCopyFunc g_dup_func,
                               GDestroyNotify g_destroy_func,
                               gconstpointer item)
{
	GeeLazy* self = NULL;
	gpointer _tmp0_;
	self = (GeeLazy*) g_type_create_instance (object_type);
	self->priv->g_type = g_type;
	self->priv->g_dup_func = g_dup_func;
	self->priv->g_destroy_func = g_destroy_func;
	_tmp0_ = ((item != NULL) && (g_dup_func != NULL)) ? g_dup_func ((gpointer) item) : ((gpointer) item);
	((self->priv->_value == NULL) || (g_destroy_func == NULL)) ? NULL : (self->priv->_value = (g_destroy_func (self->priv->_value), NULL));
	self->priv->_value = _tmp0_;
	return self;
}

GeeLazy*
gee_lazy_new_from_value (GType g_type,
                         GBoxedCopyFunc g_dup_func,
                         GDestroyNotify g_destroy_func,
                         gconstpointer item)
{
	return gee_lazy_construct_from_value (GEE_TYPE_LAZY, g_type, g_dup_func, g_destroy_func, item);
}

void
gee_lazy_eval (GeeLazy* self)
{
	GeeLazyFunc _tmp0_;
	gpointer _tmp0__target;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_func;
	_tmp0__target = self->priv->_func_target;
	if (_tmp0_ != NULL) {
		GeeLazyFunc _tmp1_;
		gpointer _tmp1__target;
		gpointer _tmp2_;
		_tmp1_ = self->priv->_func;
		_tmp1__target = self->priv->_func_target;
		_tmp2_ = _tmp1_ (_tmp1__target);
		((self->priv->_value == NULL) || (self->priv->g_destroy_func == NULL)) ? NULL : (self->priv->_value = (self->priv->g_destroy_func (self->priv->_value), NULL));
		self->priv->_value = _tmp2_;
		(self->priv->_func_target_destroy_notify == NULL) ? NULL : (self->priv->_func_target_destroy_notify (self->priv->_func_target), NULL);
		self->priv->_func = NULL;
		self->priv->_func_target = NULL;
		self->priv->_func_target_destroy_notify = NULL;
		self->priv->_func = NULL;
		self->priv->_func_target = NULL;
		self->priv->_func_target_destroy_notify = NULL;
	}
}

gpointer
gee_lazy_get (GeeLazy* self)
{
	gconstpointer _tmp0_;
	gpointer _tmp1_;
	gpointer result;
	g_return_val_if_fail (self != NULL, NULL);
	gee_lazy_eval (self);
	_tmp0_ = self->priv->_value;
	_tmp1_ = ((_tmp0_ != NULL) && (self->priv->g_dup_func != NULL)) ? self->priv->g_dup_func ((gpointer) _tmp0_) : ((gpointer) _tmp0_);
	result = _tmp1_;
	return result;
}

gconstpointer
gee_lazy_get_value (GeeLazy* self)
{
	gconstpointer result;
	gconstpointer _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	gee_lazy_eval (self);
	_tmp0_ = self->priv->_value;
	result = _tmp0_;
	return result;
}

GeeFuture*
gee_lazy_get_future (GeeLazy* self)
{
	GeeFuture* result;
	GeeLazyFuture* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = gee_lazy_future_new (self->priv->g_type, (GBoxedCopyFunc) self->priv->g_dup_func, (GDestroyNotify) self->priv->g_destroy_func, self);
	result = (GeeFuture*) _tmp0_;
	return result;
}

static inline gpointer
gee_lazy_future_get_instance_private (GeeLazyFuture* self)
{
	return G_STRUCT_MEMBER_P (self, GeeLazyFuture_private_offset);
}

static GType
gee_lazy_future_state_get_type_once (void)
{
	static const GEnumValue values[] = {{GEE_LAZY_FUTURE_STATE_UNLOCK, "GEE_LAZY_FUTURE_STATE_UNLOCK", "unlock"}, {GEE_LAZY_FUTURE_STATE_EVAL, "GEE_LAZY_FUTURE_STATE_EVAL", "eval"}, {0, NULL, NULL}};
	GType gee_lazy_future_state_type_id;
	gee_lazy_future_state_type_id = g_enum_register_static ("GeeLazyFutureState", values);
	return gee_lazy_future_state_type_id;
}

static GType
gee_lazy_future_state_get_type (void)
{
	static volatile gsize gee_lazy_future_state_type_id__once = 0;
	if (g_once_init_enter (&gee_lazy_future_state_type_id__once)) {
		GType gee_lazy_future_state_type_id;
		gee_lazy_future_state_type_id = gee_lazy_future_state_get_type_once ();
		g_once_init_leave (&gee_lazy_future_state_type_id__once, gee_lazy_future_state_type_id);
	}
	return gee_lazy_future_state_type_id__once;
}

static void
_vala_GeeFutureSourceFuncArrayElement_array_free (GeeFutureSourceFuncArrayElement * array,
                                                  gssize array_length)
{
	if (array != NULL) {
		gssize i;
		for (i = 0; i < array_length; i = i + 1) {
			gee_future_source_func_array_element_destroy (&array[i]);
		}
	}
	g_free (array);
}

static gpointer
_gee_lazy_ref0 (gpointer self)
{
	return self ? gee_lazy_ref (self) : NULL;
}

static GeeLazyFuture*
gee_lazy_future_construct (GType object_type,
                           GType g_type,
                           GBoxedCopyFunc g_dup_func,
                           GDestroyNotify g_destroy_func,
                           GeeLazy* lazy)
{
	GeeLazyFuture * self = NULL;
	GeeLazy* _tmp0_;
	GeeFutureSourceFuncArrayElement* _tmp1_;
	g_return_val_if_fail (lazy != NULL, NULL);
	self = (GeeLazyFuture*) g_object_new (object_type, "g-type", g_type, "g-dup-func", g_dup_func, "g-destroy-func", g_destroy_func, NULL);
	self->priv->g_type = g_type;
	self->priv->g_dup_func = g_dup_func;
	self->priv->g_destroy_func = g_destroy_func;
	_tmp0_ = _gee_lazy_ref0 (lazy);
	_gee_lazy_unref0 (self->priv->_lazy);
	self->priv->_lazy = _tmp0_;
	_tmp1_ = g_new0 (GeeFutureSourceFuncArrayElement, 0);
	self->priv->_when_done = (_vala_GeeFutureSourceFuncArrayElement_array_free (self->priv->_when_done, self->priv->_when_done_length1), NULL);
	self->priv->_when_done = _tmp1_;
	self->priv->_when_done_length1 = 0;
	self->priv->__when_done_size_ = self->priv->_when_done_length1;
	return self;
}

static GeeLazyFuture*
gee_lazy_future_new (GType g_type,
                     GBoxedCopyFunc g_dup_func,
                     GDestroyNotify g_destroy_func,
                     GeeLazy* lazy)
{
	return gee_lazy_future_construct (GEE_LAZY_TYPE_FUTURE, g_type, g_dup_func, g_destroy_func, lazy);
}

static gconstpointer
gee_lazy_future_real_wait (GeeFuture* base,
                           GError** error)
{
	GeeLazyFuture * self;
	GeeLazy* _tmp0_;
	GeeLazyFunc _tmp1_;
	gpointer _tmp1__target;
	GeeLazy* _tmp2_;
	gconstpointer _tmp3_;
	gconstpointer result;
	self = (GeeLazyFuture*) base;
	g_mutex_lock (&self->priv->_mutex);
	_tmp0_ = self->priv->_lazy;
	_tmp1_ = _tmp0_->priv->_func;
	_tmp1__target = _tmp0_->priv->_func_target;
	if (_tmp1_ != NULL) {
		if (self->priv->_state == GEE_LAZY_FUTURE_STATE_EVAL) {
			while (TRUE) {
				if (!(self->priv->_state == GEE_LAZY_FUTURE_STATE_EVAL)) {
					break;
				}
				g_cond_wait (&self->priv->_eval, &self->priv->_mutex);
			}
			g_mutex_unlock (&self->priv->_mutex);
		} else {
			gee_lazy_future_do_eval (self);
		}
	} else {
		g_mutex_unlock (&self->priv->_mutex);
	}
	_tmp2_ = self->priv->_lazy;
	_tmp3_ = _tmp2_->priv->_value;
	result = _tmp3_;
	return result;
}

static gboolean
gee_lazy_future_real_wait_until (GeeFuture* base,
                                 gint64 end_time,
                                 gconstpointer* value,
                                 GError** error)
{
	GeeLazyFuture * self;
	gconstpointer _vala_value = NULL;
	GeeLazy* _tmp0_;
	GeeLazyFunc _tmp1_;
	gpointer _tmp1__target;
	GeeLazy* _tmp2_;
	gconstpointer _tmp3_;
	gboolean result;
	self = (GeeLazyFuture*) base;
	g_mutex_lock (&self->priv->_mutex);
	_tmp0_ = self->priv->_lazy;
	_tmp1_ = _tmp0_->priv->_func;
	_tmp1__target = _tmp0_->priv->_func_target;
	if (_tmp1_ != NULL) {
		if (self->priv->_state == GEE_LAZY_FUTURE_STATE_EVAL) {
			gboolean res = FALSE;
			res = TRUE;
			while (TRUE) {
				if (!(self->priv->_state == GEE_LAZY_FUTURE_STATE_EVAL)) {
					break;
				}
				res = g_cond_wait_until (&self->priv->_eval, &self->priv->_mutex, end_time);
				if (!res) {
					break;
				}
			}
			g_mutex_unlock (&self->priv->_mutex);
			if (!res) {
				_vala_value = NULL;
				result = FALSE;
				if (value) {
					*value = _vala_value;
				}
				return result;
			}
		} else {
			gee_lazy_future_do_eval (self);
		}
	} else {
		g_mutex_unlock (&self->priv->_mutex);
	}
	_tmp2_ = self->priv->_lazy;
	_tmp3_ = _tmp2_->priv->_value;
	_vala_value = _tmp3_;
	result = TRUE;
	if (value) {
		*value = _vala_value;
	}
	return result;
}

static void
gee_lazy_future_real_wait_async_data_free (gpointer _data)
{
	GeeLazyFutureWaitAsyncData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (GeeLazyFutureWaitAsyncData, _data_);
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static void
gee_lazy_future_real_wait_async (GeeFuture* base,
                                 GAsyncReadyCallback _callback_,
                                 gpointer _user_data_)
{
	GeeLazyFuture * self;
	GeeLazyFutureWaitAsyncData* _data_;
	GeeLazyFuture* _tmp0_;
	self = (GeeLazyFuture*) base;
	_data_ = g_slice_new0 (GeeLazyFutureWaitAsyncData);
	_data_->_async_result = g_task_new (G_OBJECT (self), NULL, _callback_, _user_data_);
	g_task_set_task_data (_data_->_async_result, _data_, gee_lazy_future_real_wait_async_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	gee_lazy_future_real_wait_async_co (_data_);
}

static gconstpointer
gee_lazy_future_wait_finish (GeeFuture* base,
                             GAsyncResult* _res_,
                             GError** error)
{
	gconstpointer result;
	GeeLazyFutureWaitAsyncData* _data_;
	_data_ = g_task_propagate_pointer (G_TASK (_res_), error);
	if (NULL == _data_) {
		return NULL;
	}
	result = _data_->result;
	_data_->result = NULL;
	return result;
}

static gboolean
_gee_lazy_future_real_wait_async_co_gsource_func (gpointer self)
{
	gboolean result;
	result = gee_lazy_future_real_wait_async_co (self);
	return result;
}

static void
_vala_array_add1 (GeeFutureSourceFuncArrayElement* * array,
                  gint* length,
                  gint* size,
                  const GeeFutureSourceFuncArrayElement* value)
{
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (GeeFutureSourceFuncArrayElement, *array, *size);
	}
	(*array)[(*length)++] = *value;
}

static void
gee_lazy_future_wait_async_ready (GObject* source_object,
                                  GAsyncResult* _res_,
                                  gpointer _user_data_)
{
	GeeLazyFutureWaitAsyncData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	gee_lazy_future_real_wait_async_co (_data_);
}

static gboolean
gee_lazy_future_real_wait_async_co (GeeLazyFutureWaitAsyncData* _data_)
{
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	g_mutex_lock (&_data_->self->priv->_mutex);
	_data_->_tmp0_ = _data_->self->priv->_lazy;
	_data_->_tmp1_ = _data_->_tmp0_->priv->_func;
	_data_->_tmp1__target = _data_->_tmp0_->priv->_func_target;
	if (_data_->_tmp1_ != NULL) {
		if (_data_->self->priv->_state == GEE_LAZY_FUTURE_STATE_EVAL) {
			memset (&_data_->_tmp2_, 0, sizeof (GeeFutureSourceFuncArrayElement));
			gee_future_source_func_array_element_init (&_data_->_tmp2_, _gee_lazy_future_real_wait_async_co_gsource_func, _data_, NULL);
			_vala_array_add1 (&_data_->self->priv->_when_done, &_data_->self->priv->_when_done_length1, &_data_->self->priv->__when_done_size_, &_data_->_tmp2_);
			_data_->_state_ = 1;
			gee_utils_async_yield_and_unlock (&_data_->self->priv->_mutex, gee_lazy_future_wait_async_ready, _data_);
			return FALSE;
			_state_1:
			gee_utils_async_yield_and_unlock_finish (_data_->_res_);
		} else {
			gee_lazy_future_do_eval (_data_->self);
		}
	} else {
		g_mutex_unlock (&_data_->self->priv->_mutex);
	}
	_data_->_tmp3_ = _data_->self->priv->_lazy;
	_data_->_tmp4_ = gee_lazy_get_value (_data_->_tmp3_);
	_data_->_tmp5_ = _data_->_tmp4_;
	_data_->result = _data_->_tmp5_;
	g_task_return_pointer (_data_->_async_result, _data_, NULL);
	if (_data_->_state_ != 0) {
		while (!g_task_get_completed (_data_->_async_result)) {
			g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
		}
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}

static void
gee_lazy_future_do_eval (GeeLazyFuture* self)
{
	GeeLazy* _tmp0_;
	GeeLazy* _tmp1_;
	GeeLazyFunc _tmp2_;
	gpointer _tmp2__target;
	gpointer _tmp3_;
	GeeLazy* _tmp4_;
	GeeFutureSourceFuncArrayElement* when_done = NULL;
	GeeFutureSourceFuncArrayElement* _tmp5_;
	gint _tmp5__length1;
	gint when_done_length1;
	gint _when_done_size_;
	g_return_if_fail (self != NULL);
	self->priv->_state = GEE_LAZY_FUTURE_STATE_EVAL;
	g_mutex_unlock (&self->priv->_mutex);
	_tmp0_ = self->priv->_lazy;
	_tmp1_ = self->priv->_lazy;
	_tmp2_ = _tmp1_->priv->_func;
	_tmp2__target = _tmp1_->priv->_func_target;
	_tmp3_ = _tmp2_ (_tmp2__target);
	((_tmp0_->priv->_value == NULL) || (self->priv->g_destroy_func == NULL)) ? NULL : (_tmp0_->priv->_value = (self->priv->g_destroy_func (_tmp0_->priv->_value), NULL));
	_tmp0_->priv->_value = _tmp3_;
	g_mutex_lock (&self->priv->_mutex);
	_tmp4_ = self->priv->_lazy;
	(_tmp4_->priv->_func_target_destroy_notify == NULL) ? NULL : (_tmp4_->priv->_func_target_destroy_notify (_tmp4_->priv->_func_target), NULL);
	_tmp4_->priv->_func = NULL;
	_tmp4_->priv->_func_target = NULL;
	_tmp4_->priv->_func_target_destroy_notify = NULL;
	_tmp4_->priv->_func = NULL;
	_tmp4_->priv->_func_target = NULL;
	_tmp4_->priv->_func_target_destroy_notify = NULL;
	self->priv->_state = GEE_LAZY_FUTURE_STATE_UNLOCK;
	g_cond_broadcast (&self->priv->_eval);
	g_mutex_unlock (&self->priv->_mutex);
	_tmp5_ = self->priv->_when_done;
	_tmp5__length1 = self->priv->_when_done_length1;
	self->priv->_when_done = NULL;
	self->priv->_when_done_length1 = 0;
	when_done = _tmp5_;
	when_done_length1 = _tmp5__length1;
	_when_done_size_ = when_done_length1;
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp6_ = FALSE;
			_tmp6_ = TRUE;
			while (TRUE) {
				GeeFutureSourceFuncArrayElement* _tmp8_;
				gint _tmp8__length1;
				GeeFutureSourceFuncArrayElement* _tmp9_;
				gint _tmp9__length1;
				GeeFutureSourceFuncArrayElement _tmp10_;
				GSourceFunc _tmp11_;
				gpointer _tmp11__target;
				if (!_tmp6_) {
					gint _tmp7_;
					_tmp7_ = i;
					i = _tmp7_ + 1;
				}
				_tmp6_ = FALSE;
				_tmp8_ = when_done;
				_tmp8__length1 = when_done_length1;
				if (!(i < _tmp8__length1)) {
					break;
				}
				_tmp9_ = when_done;
				_tmp9__length1 = when_done_length1;
				_tmp10_ = _tmp9_[i];
				_tmp11_ = _tmp10_.func;
				_tmp11__target = _tmp10_.func_target;
				_tmp11_ (_tmp11__target);
			}
		}
	}
	when_done = (_vala_GeeFutureSourceFuncArrayElement_array_free (when_done, when_done_length1), NULL);
}

static gboolean
gee_lazy_future_real_get_ready (GeeFuture* base)
{
	gboolean result;
	GeeLazyFuture* self;
	gboolean _result_ = FALSE;
	GeeLazy* _tmp0_;
	GeeLazyFunc _tmp1_;
	gpointer _tmp1__target;
	self = (GeeLazyFuture*) base;
	g_mutex_lock (&self->priv->_mutex);
	_tmp0_ = self->priv->_lazy;
	_tmp1_ = _tmp0_->priv->_func;
	_tmp1__target = _tmp0_->priv->_func_target;
	_result_ = _tmp1_ == NULL;
	g_mutex_unlock (&self->priv->_mutex);
	result = _result_;
	return result;
}

static GError*
gee_lazy_future_real_get_exception (GeeFuture* base)
{
	GError* result;
	GeeLazyFuture* self;
	self = (GeeLazyFuture*) base;
	result = NULL;
	return result;
}

static void
gee_lazy_future_class_init (GeeLazyFutureClass * klass,
                            gpointer klass_data)
{
	gee_lazy_future_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &GeeLazyFuture_private_offset);
	G_OBJECT_CLASS (klass)->get_property = _vala_gee_lazy_future_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_gee_lazy_future_set_property;
	G_OBJECT_CLASS (klass)->finalize = gee_lazy_future_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), GEE_LAZY_FUTURE_G_TYPE, g_param_spec_gtype ("g-type", "type", "type", G_TYPE_NONE, G_PARAM_STATIC_STRINGS | G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), GEE_LAZY_FUTURE_G_DUP_FUNC, g_param_spec_pointer ("g-dup-func", "dup func", "dup func", G_PARAM_STATIC_STRINGS | G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), GEE_LAZY_FUTURE_G_DESTROY_FUNC, g_param_spec_pointer ("g-destroy-func", "destroy func", "destroy func", G_PARAM_STATIC_STRINGS | G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), GEE_LAZY_FUTURE_READY_PROPERTY, gee_lazy_future_properties[GEE_LAZY_FUTURE_READY_PROPERTY] = g_param_spec_boolean ("ready", "ready", "ready", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), GEE_LAZY_FUTURE_EXCEPTION_PROPERTY, gee_lazy_future_properties[GEE_LAZY_FUTURE_EXCEPTION_PROPERTY] = g_param_spec_boxed ("exception", "exception", "exception", G_TYPE_ERROR, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE));
}

static GType
gee_lazy_future_gee_future_get_g_type (GeeLazyFuture* self)
{
	return self->priv->g_type;
}

static GBoxedCopyFunc
gee_lazy_future_gee_future_get_g_dup_func (GeeLazyFuture* self)
{
	return self->priv->g_dup_func;
}

static GDestroyNotify
gee_lazy_future_gee_future_get_g_destroy_func (GeeLazyFuture* self)
{
	return self->priv->g_destroy_func;
}

static void
gee_lazy_future_gee_future_interface_init (GeeFutureIface * iface,
                                           gpointer iface_data)
{
	gee_lazy_future_gee_future_parent_iface = g_type_interface_peek_parent (iface);
	iface->wait = (gconstpointer (*) (GeeFuture*, GError**)) gee_lazy_future_real_wait;
	iface->wait_until = (gboolean (*) (GeeFuture*, gint64, gconstpointer*, GError**)) gee_lazy_future_real_wait_until;
	iface->wait_async = (void (*) (GeeFuture*, GAsyncReadyCallback, gpointer)) gee_lazy_future_real_wait_async;
	iface->wait_finish = (gconstpointer (*) (GeeFuture*, GAsyncResult*, GError**)) gee_lazy_future_wait_finish;
	iface->get_g_type = (GType (*) (GeeFuture *)) gee_lazy_future_gee_future_get_g_type;
	iface->get_g_dup_func = (GBoxedCopyFunc (*) (GeeFuture *)) gee_lazy_future_gee_future_get_g_dup_func;
	iface->get_g_destroy_func = (GDestroyNotify (*) (GeeFuture *)) gee_lazy_future_gee_future_get_g_destroy_func;
	iface->get_ready = gee_lazy_future_real_get_ready;
	iface->get_exception = gee_lazy_future_real_get_exception;
}

static void
gee_lazy_future_instance_init (GeeLazyFuture * self,
                               gpointer klass)
{
	self->priv = gee_lazy_future_get_instance_private (self);
	g_mutex_init (&self->priv->_mutex);
	g_cond_init (&self->priv->_eval);
	self->priv->_state = GEE_LAZY_FUTURE_STATE_UNLOCK;
}

static void
gee_lazy_future_finalize (GObject * obj)
{
	GeeLazyFuture * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, GEE_LAZY_TYPE_FUTURE, GeeLazyFuture);
	_vala_clear_GMutex (&self->priv->_mutex);
	_vala_clear_GCond (&self->priv->_eval);
	_gee_lazy_unref0 (self->priv->_lazy);
	self->priv->_when_done = (_vala_GeeFutureSourceFuncArrayElement_array_free (self->priv->_when_done, self->priv->_when_done_length1), NULL);
	G_OBJECT_CLASS (gee_lazy_future_parent_class)->finalize (obj);
}

static GType
gee_lazy_future_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (GeeLazyFutureClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gee_lazy_future_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GeeLazyFuture), 0, (GInstanceInitFunc) gee_lazy_future_instance_init, NULL };
	static const GInterfaceInfo gee_future_info = { (GInterfaceInitFunc) gee_lazy_future_gee_future_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType gee_lazy_future_type_id;
	gee_lazy_future_type_id = g_type_register_static (G_TYPE_OBJECT, "GeeLazyFuture", &g_define_type_info, 0);
	g_type_add_interface_static (gee_lazy_future_type_id, GEE_TYPE_FUTURE, &gee_future_info);
	GeeLazyFuture_private_offset = g_type_add_instance_private (gee_lazy_future_type_id, sizeof (GeeLazyFuturePrivate));
	return gee_lazy_future_type_id;
}

static GType
gee_lazy_future_get_type (void)
{
	static volatile gsize gee_lazy_future_type_id__once = 0;
	if (g_once_init_enter (&gee_lazy_future_type_id__once)) {
		GType gee_lazy_future_type_id;
		gee_lazy_future_type_id = gee_lazy_future_get_type_once ();
		g_once_init_leave (&gee_lazy_future_type_id__once, gee_lazy_future_type_id);
	}
	return gee_lazy_future_type_id__once;
}

static void
_vala_gee_lazy_future_get_property (GObject * object,
                                    guint property_id,
                                    GValue * value,
                                    GParamSpec * pspec)
{
	GeeLazyFuture * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, GEE_LAZY_TYPE_FUTURE, GeeLazyFuture);
	switch (property_id) {
		case GEE_LAZY_FUTURE_READY_PROPERTY:
		g_value_set_boolean (value, gee_future_get_ready ((GeeFuture*) self));
		break;
		case GEE_LAZY_FUTURE_EXCEPTION_PROPERTY:
		g_value_set_pointer (value, gee_future_get_exception ((GeeFuture*) self));
		break;
		case GEE_LAZY_FUTURE_G_TYPE:
		g_value_set_gtype (value, self->priv->g_type);
		break;
		case GEE_LAZY_FUTURE_G_DUP_FUNC:
		g_value_set_pointer (value, self->priv->g_dup_func);
		break;
		case GEE_LAZY_FUTURE_G_DESTROY_FUNC:
		g_value_set_pointer (value, self->priv->g_destroy_func);
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_vala_gee_lazy_future_set_property (GObject * object,
                                    guint property_id,
                                    const GValue * value,
                                    GParamSpec * pspec)
{
	GeeLazyFuture * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, GEE_LAZY_TYPE_FUTURE, GeeLazyFuture);
	switch (property_id) {
		case GEE_LAZY_FUTURE_G_TYPE:
		self->priv->g_type = g_value_get_gtype (value);
		break;
		case GEE_LAZY_FUTURE_G_DUP_FUNC:
		self->priv->g_dup_func = g_value_get_pointer (value);
		break;
		case GEE_LAZY_FUTURE_G_DESTROY_FUNC:
		self->priv->g_destroy_func = g_value_get_pointer (value);
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
gee_value_lazy_init (GValue* value)
{
	value->data[0].v_pointer = NULL;
}

static void
gee_value_lazy_free_value (GValue* value)
{
	if (value->data[0].v_pointer) {
		gee_lazy_unref (value->data[0].v_pointer);
	}
}

static void
gee_value_lazy_copy_value (const GValue* src_value,
                           GValue* dest_value)
{
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = gee_lazy_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}

static gpointer
gee_value_lazy_peek_pointer (const GValue* value)
{
	return value->data[0].v_pointer;
}

static gchar*
gee_value_lazy_collect_value (GValue* value,
                              guint n_collect_values,
                              GTypeCValue* collect_values,
                              guint collect_flags)
{
	if (collect_values[0].v_pointer) {
		GeeLazy * object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = gee_lazy_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}

static gchar*
gee_value_lazy_lcopy_value (const GValue* value,
                            guint n_collect_values,
                            GTypeCValue* collect_values,
                            guint collect_flags)
{
	GeeLazy ** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = gee_lazy_ref (value->data[0].v_pointer);
	}
	return NULL;
}

GParamSpec*
gee_param_spec_lazy (const gchar* name,
                     const gchar* nick,
                     const gchar* blurb,
                     GType object_type,
                     GParamFlags flags)
{
	GeeParamSpecLazy* spec;
	g_return_val_if_fail (g_type_is_a (object_type, GEE_TYPE_LAZY), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}

gpointer
gee_value_get_lazy (const GValue* value)
{
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, GEE_TYPE_LAZY), NULL);
	return value->data[0].v_pointer;
}

void
gee_value_set_lazy (GValue* value,
                    gpointer v_object)
{
	GeeLazy * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, GEE_TYPE_LAZY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, GEE_TYPE_LAZY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		gee_lazy_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		gee_lazy_unref (old);
	}
}

void
gee_value_take_lazy (GValue* value,
                     gpointer v_object)
{
	GeeLazy * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, GEE_TYPE_LAZY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, GEE_TYPE_LAZY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		gee_lazy_unref (old);
	}
}

static void
gee_lazy_class_init (GeeLazyClass * klass,
                     gpointer klass_data)
{
	gee_lazy_parent_class = g_type_class_peek_parent (klass);
	((GeeLazyClass *) klass)->finalize = gee_lazy_finalize;
	g_type_class_adjust_private_offset (klass, &GeeLazy_private_offset);
}

static void
gee_lazy_instance_init (GeeLazy * self,
                        gpointer klass)
{
	self->priv = gee_lazy_get_instance_private (self);
	self->ref_count = 1;
}

static void
gee_lazy_finalize (GeeLazy * obj)
{
	GeeLazy * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, GEE_TYPE_LAZY, GeeLazy);
	g_signal_handlers_destroy (self);
	(self->priv->_func_target_destroy_notify == NULL) ? NULL : (self->priv->_func_target_destroy_notify (self->priv->_func_target), NULL);
	self->priv->_func = NULL;
	self->priv->_func_target = NULL;
	self->priv->_func_target_destroy_notify = NULL;
	((self->priv->_value == NULL) || (self->priv->g_destroy_func == NULL)) ? NULL : (self->priv->_value = (self->priv->g_destroy_func (self->priv->_value), NULL));
}

/**
 * Represents a lazy value. I.e. value that is computed on demand.
 *
 * This class is not thread-safe.
 */
static GType
gee_lazy_get_type_once (void)
{
	static const GTypeValueTable g_define_type_value_table = { gee_value_lazy_init, gee_value_lazy_free_value, gee_value_lazy_copy_value, gee_value_lazy_peek_pointer, "p", gee_value_lazy_collect_value, "p", gee_value_lazy_lcopy_value };
	static const GTypeInfo g_define_type_info = { sizeof (GeeLazyClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gee_lazy_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GeeLazy), 0, (GInstanceInitFunc) gee_lazy_instance_init, &g_define_type_value_table };
	static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
	GType gee_lazy_type_id;
	gee_lazy_type_id = g_type_register_fundamental (g_type_fundamental_next (), "GeeLazy", &g_define_type_info, &g_define_type_fundamental_info, 0);
	GeeLazy_private_offset = g_type_add_instance_private (gee_lazy_type_id, sizeof (GeeLazyPrivate));
	return gee_lazy_type_id;
}

GType
gee_lazy_get_type (void)
{
	static volatile gsize gee_lazy_type_id__once = 0;
	if (g_once_init_enter (&gee_lazy_type_id__once)) {
		GType gee_lazy_type_id;
		gee_lazy_type_id = gee_lazy_get_type_once ();
		g_once_init_leave (&gee_lazy_type_id__once, gee_lazy_type_id);
	}
	return gee_lazy_type_id__once;
}

gpointer
gee_lazy_ref (gpointer instance)
{
	GeeLazy * self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}

void
gee_lazy_unref (gpointer instance)
{
	GeeLazy * self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		GEE_LAZY_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}

static void
_vala_clear_GMutex (GMutex * mutex)
{
	GMutex zero_mutex = { 0 };
	if (memcmp (mutex, &zero_mutex, sizeof (GMutex))) {
		g_mutex_clear (mutex);
		memset (mutex, 0, sizeof (GMutex));
	}
}

static void
_vala_clear_GRecMutex (GRecMutex * mutex)
{
	GRecMutex zero_mutex = { 0 };
	if (memcmp (mutex, &zero_mutex, sizeof (GRecMutex))) {
		g_rec_mutex_clear (mutex);
		memset (mutex, 0, sizeof (GRecMutex));
	}
}

static void
_vala_clear_GRWLock (GRWLock * mutex)
{
	GRWLock zero_mutex = { 0 };
	if (memcmp (mutex, &zero_mutex, sizeof (GRWLock))) {
		g_rw_lock_clear (mutex);
		memset (mutex, 0, sizeof (GRWLock));
	}
}

static void
_vala_clear_GCond (GCond * mutex)
{
	GCond zero_mutex = { 0 };
	if (memcmp (mutex, &zero_mutex, sizeof (GCond))) {
		g_cond_clear (mutex);
		memset (mutex, 0, sizeof (GCond));
	}
}

