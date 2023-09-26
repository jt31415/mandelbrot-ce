# ----------------------------
# Makefile Options
# ----------------------------

NAME = MAND
ICON = icon.png
DESCRIPTION = "CE C Toolchain Demo"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
