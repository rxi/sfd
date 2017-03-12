# Simple File Dialog
A small C library for opening a file dialog on Windows and Linux.


## Usage
**[sfd.c](src/sfd.c?raw=1)** and **[sfd.h](src/sfd.h?raw=1)** should be dropped
into an existing project and compiled along with it — on Windows `comdlg32`
should be linked.

The library provides a function for *open* dialogs and one for *save* dialogs:

```c
sfd_Options opt = {
  .title        = "Open Image File",
  .filter_name  = "Image File",
  .filter       = "*.png|*.jpg",
};

const char *filename = sfd_open_dialog(&opt);

if (filename) {
  printf("Got file: '%s'\n", filename);
} else {
  printf("Open canceled\n");
}
```

Both functions accept a `sfd_Options` struct pointer with settings for
the file dialog — All fields of the `sfd_Options` struct are *optional*.

| Field           | Description
|-----------------|-------------------------------------------------------------
| `.title`        | Title for the file dialog window
| `.path`         | Default directory
| `.filter_name`  | Name used to describe the file filter
| `.filter`       | File filters separated by <code>&#124;</code>

If the file dialog is canceled or an error occurs `NULL` is returned.
`sfd_get_error()` will return an error string in the case of an error.


## License
This library is free software; you can redistribute it and/or modify it under
the terms of the MIT license. See [LICENSE](LICENSE) for details.
