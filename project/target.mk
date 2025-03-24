PROJECT ?= example

ifeq ($(PROJECT), example)
include project/list/example/example.mk
endif

ifeq ($(PROJECT), oem)
include project/list/oem/oem.mk
endif

ifeq ($(PROJECT), orcali)
include project/list/orcali/orcali.mk
endif

ifeq ($(PROJECT), debug)
include project/list/debug/debug.mk
endif