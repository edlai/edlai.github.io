int xxx_util_str_append (char **buf, const char *format, ...)
{
  char *str = NULL;
  char *old_buf = NULL, *new_buf = NULL;

  va_list arg_ptr;
  va_start(arg_ptr, format);
  vasprintf(&str, format, arg_ptr);
  //va_end(arg_ptr);

  // save old string
  asprintf(&old_buf, "%s", (*buf == NULL ? "" : *buf));

  // calloc new string memory
  new_buf = (char *)calloc(strnlen(old_buf, UINT_MAX) + strnlen(str, UINT_MAX) + 1, sizeof(char));

  snprintf(new_buf, strnlen(old_buf, UINT_MAX) + strnlen(str, UINT_MAX) + 1, "%s%s", old_buf, str);

  if (*buf) free(*buf);
  *buf = new_buf;

  free(old_buf);
  free(str);

  return 0;
}
