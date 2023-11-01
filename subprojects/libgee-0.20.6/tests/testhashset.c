/* testhashset.c generated by valac 0.56.3, the Vala compiler
 * generated from testhashset.vala, do not modify */

/* testhashset.vala
 *
 * Copyright (C) 2009  Didier Villevalois, Julien Peeters
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
 * 	Didier 'Ptitjes' Villevalois <ptitjes@free.fr>
 * 	Julien Peeters <contact@julienpeeters.fr>
 */

#include <glib-object.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

#if !defined(VALA_EXTERN)
#if defined(_MSC_VER)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

#define GEE_TYPE_TEST_CASE (gee_test_case_get_type ())
#define GEE_TEST_CASE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GEE_TYPE_TEST_CASE, GeeTestCase))
#define GEE_TEST_CASE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GEE_TYPE_TEST_CASE, GeeTestCaseClass))
#define GEE_IS_TEST_CASE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GEE_TYPE_TEST_CASE))
#define GEE_IS_TEST_CASE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GEE_TYPE_TEST_CASE))
#define GEE_TEST_CASE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GEE_TYPE_TEST_CASE, GeeTestCaseClass))

typedef struct _GeeTestCase GeeTestCase;
typedef struct _GeeTestCaseClass GeeTestCaseClass;
typedef struct _GeeTestCasePrivate GeeTestCasePrivate;

#define TYPE_COLLECTION_TESTS (collection_tests_get_type ())
#define COLLECTION_TESTS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_COLLECTION_TESTS, CollectionTests))
#define COLLECTION_TESTS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_COLLECTION_TESTS, CollectionTestsClass))
#define IS_COLLECTION_TESTS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_COLLECTION_TESTS))
#define IS_COLLECTION_TESTS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_COLLECTION_TESTS))
#define COLLECTION_TESTS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_COLLECTION_TESTS, CollectionTestsClass))

typedef struct _CollectionTests CollectionTests;
typedef struct _CollectionTestsClass CollectionTestsClass;
typedef struct _CollectionTestsPrivate CollectionTestsPrivate;

#define TYPE_SET_TESTS (set_tests_get_type ())
#define SET_TESTS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SET_TESTS, SetTests))
#define SET_TESTS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SET_TESTS, SetTestsClass))
#define IS_SET_TESTS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SET_TESTS))
#define IS_SET_TESTS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SET_TESTS))
#define SET_TESTS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SET_TESTS, SetTestsClass))

typedef struct _SetTests SetTests;
typedef struct _SetTestsClass SetTestsClass;
typedef struct _SetTestsPrivate SetTestsPrivate;

#define TYPE_HASH_SET_TESTS (hash_set_tests_get_type ())
#define HASH_SET_TESTS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_HASH_SET_TESTS, HashSetTests))
#define HASH_SET_TESTS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_HASH_SET_TESTS, HashSetTestsClass))
#define IS_HASH_SET_TESTS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_HASH_SET_TESTS))
#define IS_HASH_SET_TESTS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_HASH_SET_TESTS))
#define HASH_SET_TESTS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_HASH_SET_TESTS, HashSetTestsClass))

typedef struct _HashSetTests HashSetTests;
typedef struct _HashSetTestsClass HashSetTestsClass;
typedef struct _HashSetTestsPrivate HashSetTestsPrivate;
enum  {
	HASH_SET_TESTS_0_PROPERTY,
	HASH_SET_TESTS_NUM_PROPERTIES
};
static GParamSpec* hash_set_tests_properties[HASH_SET_TESTS_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _GeeTestCase {
	GObject parent_instance;
	GeeTestCasePrivate * priv;
};

struct _GeeTestCaseClass {
	GObjectClass parent_class;
	void (*set_up) (GeeTestCase* self);
	void (*tear_down) (GeeTestCase* self);
};

struct _CollectionTests {
	GeeTestCase parent_instance;
	CollectionTestsPrivate * priv;
	GeeCollection* test_collection;
};

struct _CollectionTestsClass {
	GeeTestCaseClass parent_class;
};

struct _SetTests {
	CollectionTests parent_instance;
	SetTestsPrivate * priv;
};

struct _SetTestsClass {
	CollectionTestsClass parent_class;
	void (*test_duplicates_are_ignored) (SetTests* self);
};

struct _HashSetTests {
	SetTests parent_instance;
	HashSetTestsPrivate * priv;
};

struct _HashSetTestsClass {
	SetTestsClass parent_class;
};

static gpointer hash_set_tests_parent_class = NULL;

VALA_EXTERN GType gee_test_case_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (GeeTestCase, g_object_unref)
VALA_EXTERN GType collection_tests_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (CollectionTests, g_object_unref)
VALA_EXTERN GType set_tests_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (SetTests, g_object_unref)
VALA_EXTERN GType hash_set_tests_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (HashSetTests, g_object_unref)
VALA_EXTERN void gee_test_case_set_up (GeeTestCase* self);
VALA_EXTERN void gee_test_case_tear_down (GeeTestCase* self);
VALA_EXTERN HashSetTests* hash_set_tests_new (void);
VALA_EXTERN HashSetTests* hash_set_tests_construct (GType object_type);
VALA_EXTERN SetTests* set_tests_construct (GType object_type,
                               const gchar* name);
static void hash_set_tests_real_set_up (GeeTestCase* base);
static void hash_set_tests_real_tear_down (GeeTestCase* base);
static GType hash_set_tests_get_type_once (void);

HashSetTests*
hash_set_tests_construct (GType object_type)
{
	HashSetTests * self = NULL;
	self = (HashSetTests*) set_tests_construct (object_type, "HashSet");
	return self;
}

HashSetTests*
hash_set_tests_new (void)
{
	return hash_set_tests_construct (TYPE_HASH_SET_TESTS);
}

static void
hash_set_tests_real_set_up (GeeTestCase* base)
{
	HashSetTests * self;
	GeeHashSet* _tmp0_;
	self = (HashSetTests*) base;
	_tmp0_ = gee_hash_set_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, (GDestroyNotify) g_free, NULL, NULL, NULL, NULL, NULL, NULL);
	_g_object_unref0 (((CollectionTests*) self)->test_collection);
	((CollectionTests*) self)->test_collection = (GeeCollection*) _tmp0_;
}

static void
hash_set_tests_real_tear_down (GeeTestCase* base)
{
	HashSetTests * self;
	self = (HashSetTests*) base;
	_g_object_unref0 (((CollectionTests*) self)->test_collection);
	((CollectionTests*) self)->test_collection = NULL;
}

static void
hash_set_tests_class_init (HashSetTestsClass * klass,
                           gpointer klass_data)
{
	hash_set_tests_parent_class = g_type_class_peek_parent (klass);
	((GeeTestCaseClass *) klass)->set_up = (void (*) (GeeTestCase*)) hash_set_tests_real_set_up;
	((GeeTestCaseClass *) klass)->tear_down = (void (*) (GeeTestCase*)) hash_set_tests_real_tear_down;
}

static void
hash_set_tests_instance_init (HashSetTests * self,
                              gpointer klass)
{
}

static GType
hash_set_tests_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (HashSetTestsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) hash_set_tests_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (HashSetTests), 0, (GInstanceInitFunc) hash_set_tests_instance_init, NULL };
	GType hash_set_tests_type_id;
	hash_set_tests_type_id = g_type_register_static (TYPE_SET_TESTS, "HashSetTests", &g_define_type_info, 0);
	return hash_set_tests_type_id;
}

GType
hash_set_tests_get_type (void)
{
	static volatile gsize hash_set_tests_type_id__once = 0;
	if (g_once_init_enter (&hash_set_tests_type_id__once)) {
		GType hash_set_tests_type_id;
		hash_set_tests_type_id = hash_set_tests_get_type_once ();
		g_once_init_leave (&hash_set_tests_type_id__once, hash_set_tests_type_id);
	}
	return hash_set_tests_type_id__once;
}

