#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <linux/module.h>	/* modulo */
#include <linux/kernel.h>	/* kernel */
#include <linux/proc_fs.h>	/* struct proc_dir_entry */
#include <linux/list.h>     /* listas del kernel */
#include <asm/uaccess.h>    /* function copy_from_user */
#include "clipstruct.h"     /* struct clipstruct */
#include "boolean.h"        /* boolean */

/* Declaracion de macros */
#define TAM_MAX_BUFFER 4096

/* Declaracion de funciones */
int leer_indice(char *buffer, char **buffer_location, off_t offset, int buffer_length, int *eof, void *data);
int leer_clipboard(char *buffer, char **buffer_location, off_t offset, int buffer_length, int *eof, void *data);
int modificar_indice(struct file *file, const char *buffer, unsigned long count, void *data);
int escribir_clipboard(struct file *file, const char *buffer, unsigned long count, void *data);

/* Declaracion de funciones auxiliares */
struct clipstruct* encontrar_clipboard(void);

#endif /* CLIPBOARD_H */
