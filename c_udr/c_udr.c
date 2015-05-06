#include <mi.h>
#include <miami.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * Tracing-related macros
 */
#define TRACE_CLASS "Pointer"
#define TRACE_LEVEL 20

#define POINTER_TRACE_ENTER(fn) DPRINTF(TRACE_CLASS, TRACE_LEVEL, ("Enter " #fn))
#define POINTER_TRACE_EXIT(fn)  DPRINTF(TRACE_CLASS, TRACE_LEVEL, ("Exit " #fn))
#define POINTER_TRACE(args)     DPRINTF(TRACE_CLASS, TRACE_LEVEL, args)

typedef mi_unsigned_char1   mi_uchar;
typedef mi_unsigned_integer mi_uint;
typedef mi_double_precision mi_double;

/*
MI_DECL mi_pointer *
PointerRecieve (mi_sendrecv *data)
{
  mi_uchar    *datap;
  mi_pointer  *pointer;

  POINTER_TRACE_ENTER("PointerRecieve");

  bbox = mi_alloc (sizeof(mi_pointer));

  datap = (mi_uchar*) mi_get_vardata ((mi_lvarchar*) data);
  datap = mi_get_double_precision (datap, &(bbox->ll.x));
  datap = mi_get_double_precision (datap, &(bbox->ll.y));
  datap = mi_get_double_precision (datap, &(bbox->ll.z));
  datap = mi_get_double_precision (datap, &(bbox->ur.x));
  datap = mi_get_double_precision (datap, &(bbox->ur.y));
  datap = mi_get_double_precision (datap, &(bbox->ur.z));

  POINTER_TRACE_EXIT("PointerRecieve");

  return bbox;
}
*/
MI_DECL mi_sendrecv *
PointerSend (mi_pointer *pointer)
{
  mi_sendrecv *retval;
  mi_uchar    *datap;

  POINTER_TRACE_ENTER("PointerSend");

  retval = (mi_sendrecv*) mi_new_var (sizeof(mi_pointer));
  datap = (mi_uchar*) mi_get_vardata ((mi_lvarchar*) retval);

  datap = mi_put_bytes (datap, *pointer, sizeof(mi_pointer));

  POINTER_TRACE_EXIT("PointerSend");

  return retval;
}

MI_DECL mi_integer
tachyonCreate (mi_pointer *buf)
{

  FILE *f = fopen("/opt/informix/create.txt", "w");
  if (f == NULL)
  {
    printf("Error opening file!\n");
    return 1;
  }

  fprintf(f, "%lx \n", buf);
  fprintf(f, "%lx \n", *buf);

  //long *test = *buf;
  //MI_AM_TABLE_DESC * table = *buf;
 // fprintf(f, "%lx \n", *test);
  /* print some text */
  //mi_pointer *test = *buf;
  mi_string* tableName = mi_tab_name(buf);
  const char *text = "Write this to the file";
  fprintf(f, "Table name: %s\n", tableName);
  //fprintf(f, "test");
  //fprintf(f, "%lx", *buf);

  //MI_AM_TABLE_DESC test = **buf;

  //fprintf(f, "3: %lx", *buf2);


  fclose(f);

 /* long addrAsLong;
  char textbuf[100];
  MI_ROW *row;
  mi_integer result;
  MI_DATUM *value;
  int length;


  FILE *f = fopen("/opt/informix/file.txt", "w");
  if (f == NULL)
  {
  printf("Error opening file!\n");
  return 1;
  }


  POINTER_TRACE_ENTER("tachyonCreate");
  *//* establish server connection *//*
  MI_CONNECTION *conn = mi_open(NULL,NULL,NULL);
  sprintf (textbuf, "execute function createTableInTachyon(%lx);", *buf);
  result = mi_exec(conn, textbuf, MI_QUERY_BINARY);
  result = mi_get_result(conn);
  if (result != MI_NO_MORE_RESULTS) {
  row = mi_next_row(conn, &result);
  result = mi_value(row, 0, value, &length);
  }
  mi_query_finish(conn);
  mi_close(conn);
  POINTER_TRACE_EXIT("tachyonCreate");
  // return (mi_integer) *value;
  fprintf(f, "%lx", *value);
  return (long) *value;*/
  return 0;
}

MI_DECL mi_integer
tachyonDrop (mi_pointer *buf)
{
  return 0;
}

MI_DECL mi_integer
tachyonOpen (mi_pointer *buf)
    {
    FILE *f = fopen("/opt/informix/open.txt", "w");
    if (f == NULL)
    {
      printf("Error opening file!\n");
      return 1;
    }

    mi_integer rows = mi_tab_setniorows(buf, 1);
    fprintf(f, "mi_tab_setniorows return value %d\n", rows);

    fclose(f);

  return 0;

}

MI_DECL mi_integer
tachyonClose (mi_pointer *buf)
{
  return 0;
}

MI_DECL mi_integer
tachyonGetByid (mi_pointer *buf)
{
  return 0;
}

MI_DECL mi_integer
tachyonGetNext (mi_pointer *buf0, mi_pointer *buf1, mi_pointer *buf2)
{
  return 0;
}

MI_DECL mi_integer
tachyonInsert (mi_pointer *buf0, mi_pointer *buf1, mi_pointer *buf2)

{


FILE *f = fopen("/opt/informix/file.txt", "w");
  if (f == NULL)
  {
    printf("Error opening file!\n");
    return -1;
  }



  //mi_integer numcols;
  //mi_string *colname;

  //numcols = mi_column_count(buf1);

  //fprintf(f, "%lx  %lx", *buf0, *buf1);
  //fprintf(f, "Number of columns: %d\n", numcols);
/*
  int i = 0;
  while( i < numcols )
  {
    colname = mi_column_name(buf1, i);
    fprintf(f, " %s\t", colname);
    i++;
  }
*/


//olval = NULL;
//collen = 0;

//MI_ROW_DESC *rowdesc;
//rowdesc = mi_get_row_desc(buf1);

//mi_value(*buf1, 1, &colval, &collen);

/*switch( mi_value(*buf1, 1, &colval, &collen) )
{
case MI_ERROR:
        fprintf(f, "MI_ERROR");
case MI_NULL_VALUE:
        fprintf(f, "MI_NULL_VALUE");
        break;
case MI_NORMAL_VALUE:
        fprintf(f, "MI_NORMAL_VALUE");
        break;
case MI_ROW_VALUE:
        fprintf(f, "MI_ROW_VALUE");
        break;
default:
    fprintf(f, "DUNNO");

    return( -1 );
}*/


MI_ROW *row = NULL;
mi_integer rowid = 0;
mi_integer fragid = 0;

//fprintf(f, " %s\t", colname);
mi_integer nrows = mi_tab_niorows(buf0);
fprintf(f, "Number of rows: %d\n", nrows);

mi_integer x = mi_tab_nextrow(buf0, &row, &rowid, &fragid);
fprintf(f, "mi_tab_nextrow %d\n", x);


mi_integer numcols;

numcols = mi_column_count(row);
fprintf(f, "Number of columns: %d\n", numcols);

mi_string *colname;


mi_integer collen = 0;
MI_DATUM *colval = NULL;


mi_integer y = mi_value(row, 0, &colval, &collen);

int i = 0;
while( i < numcols )
{
    colname = mi_column_name(row, i);
    fprintf(f, " %s\t", colname);
    i++;
}


fprintf(f, "MI_NORMAL_VALUE: %d\n", MI_NORMAL_VALUE);
fprintf(f, "MI_ROW_VALUE: %d\n", MI_ROW_VALUE);
fprintf(f, "value length %d\n", collen);



int full_int = (mi_integer) colval;
fprintf(f, "value? %d\n", full_int);

y = mi_value(row, 1, &colval, &collen);
full_int = (mi_integer) colval;
fprintf(f, "value? %d", full_int);

fclose(f);

  return 0;
}


tachyonDelete (mi_pointer *buf0, mi_pointer *buf1, mi_pointer *buf2)
{
return 0;
}

tachyonUpdate (mi_pointer *buf0, mi_pointer *buf1, mi_pointer *buf2, mi_pointer *buf3, mi_pointer *buf4)
{

FILE *f = fopen("/opt/informix/update.txt", "w");
if (f == NULL)
{
    printf("Error opening file!\n");
    return -1;
}

fprintf(f, "update");

fclose(f);

return 0;
}

tachyonEndscan (mi_pointer *buf)
{
return 0;
}

tachyonBeginscan (mi_pointer *buf)
{
return 0;
}

MI_DECL mi_pointer *
PointerInput (mi_lvarchar *input_varchar)
{
  mi_pointer *buf;
  mi_char    *input_text;
  mi_integer  n;

  POINTER_TRACE_ENTER("PointerInput");

  /* Allocate space for the pointer being read in */
  buf = mi_alloc (2*sizeof(mi_pointer));
  (*buf) = buf + sizeof(mi_pointer);
  DPRINTF (TRACE_CLASS, TRACE_LEVEL, ("sizeof(mi_pointer) = %d", sizeof(mi_pointer)));

  /* Convert the input */
  input_text = mi_lvarchar_to_string (input_varchar);

  /* Use sscanf to read in the input */
  n = sscanf (input_text, "0x%lx", *buf);

/* Check for errors in the input */
if (n != 1) {
  mi_db_error_raise (NULL, MI_EXCEPTION, "Cannot parse input text", 0);
}

  POINTER_TRACE_EXIT("PointerInput");

  return *buf;
}

MI_DECL mi_lvarchar *
PointerOutput (mi_pointer *buf)
{
  mi_char textbuf[10];

  POINTER_TRACE_ENTER("PointerOutput");

  sprintf (textbuf, "%#lx", *buf);

  POINTER_TRACE_EXIT("PointerOutput");

  return mi_string_to_lvarchar (textbuf);
}
