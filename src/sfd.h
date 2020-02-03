/**
 * Copyright (c) 2017 rxi
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `sfd.c` for details.
 */

#ifndef SFD_H
#define SFD_H

#define SFD_VERSION "0.1.0"

#ifndef SFD_API
  #define SFD_API
#endif

typedef struct {
  const char *title;
  const char *path;
  const char *filter_name;
  const char *filter;
#ifdef _WIN32
  // If 0, then first visible root window of the same process is used.
  HWND parent;
#endif
} sfd_Options;

SFD_API const char* sfd_get_error(void);
SFD_API const char* sfd_open_dialog(sfd_Options *opt);
SFD_API const char* sfd_save_dialog(sfd_Options *opt);

#endif
