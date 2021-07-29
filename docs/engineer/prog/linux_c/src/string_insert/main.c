int xxx_util_str_insert_s(char *str, const char *raw, const int pos, const int max)
{

  size_t  new_len;
  char    first_part[max];
  char    second_part[max];
  char   *tmp = strndup(str, max);

  // counting with '\0'
  new_len = strnlen(str, UINT_MAX) + strnlen(raw, max) + 1;

  if (new_len > max)
  {
    SXC_LOG_ERR("cannot insert raw material due to out of memory\n");
    return (SXC_ERR_NO_MEMORY);
  }

  memset(str, '\0', max);
  memset(first_part, '\0', max);
  memset(second_part, '\0', max);

  strncpy(first_part, tmp, pos);
  strncpy(second_part, tmp + pos, strnlen(tmp, max) - pos);


  // insert raw material
  strncat(str, first_part, strnlen(first_part, max));
  strncat(str, raw, strnlen(raw, max));
  strncat(str, second_part, strnlen(second_part, max));

  //SXC_LOG_DEBUG("str: %s\n", str) ;
  return (SXC_NO_ERROR);

}

