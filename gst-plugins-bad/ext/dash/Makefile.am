
plugin_LTLIBRARIES = libgstdashdemux.la

libgstdashdemux_la_SOURCES =			\
	gstmpdparser.c				\
	gstdashdemux.c				\
	gstisoff.c				\
	gstplugin.c

# headers we need but don't want installed
noinst_HEADERS =        \
        gstmpdparser.h	\
	gstdashdemux.h	\
	gstisoff.h	\
	gstdash_debug.h

# compiler and linker flags used to compile this plugin, set in configure.ac
libgstdashdemux_la_CFLAGS = $(GST_PLUGINS_BAD_CFLAGS) \
	$(GST_PLUGINS_BASE_CFLAGS) \
	$(GST_BASE_CFLAGS) \
	$(GST_CFLAGS) \
	$(GIO_CFLAGS) \
	$(LIBXML2_CFLAGS)
libgstdashdemux_la_LIBADD = \
	$(top_builddir)/gst-libs/gst/uridownloader/libgsturidownloader-@GST_API_VERSION@.la \
	$(top_builddir)/gst-libs/gst/adaptivedemux/libgstadaptivedemux-@GST_API_VERSION@.la \
	$(GST_PLUGINS_BASE_LIBS) \
	-lgsttag-$(GST_API_VERSION) \
	$(GST_BASE_LIBS) \
	$(GST_LIBS) \
	$(GIO_LIBS) \
	-lgstnet-$(GST_API_VERSION) \
	$(LIBXML2_LIBS)
libgstdashdemux_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS)
libgstdashdemux_la_LIBTOOLFLAGS = --tag=disable-static

