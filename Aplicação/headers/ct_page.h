#ifndef CT_PAGE_H
#define CT_PAGE_H

// PLAIN TEXT EDITOR - PAGE STRUCTURE HEADER.

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "ct_definitions.h"


// MAIN STRUCTURES:

typedef struct sColumnNode
{
    char info;
    struct sColumnNode *next;
    struct sColumnNode *previous;

} COLUMN_NODE;

typedef struct sRowNode
{
    COLUMN_NODE *first_column;
    COLUMN_NODE *last_column;
    SHORT length;
    struct sRowNode *next;
    struct sRowNode *previous;

} ROW_NODE;

typedef struct sPage
{
    ROW_NODE *first_row;
    ROW_NODE *last_row;
    SHORT length;

} PAGE;


COLUMN_NODE *ct_allocate_column()
{
    return (COLUMN_NODE *) malloc(sizeof(COLUMN_NODE));
}

void ct_init_column(COLUMN_NODE *cptr, char c)
{
    cptr -> info = c;
    cptr -> next = NULL;
    cptr -> previous = NULL;
}

COLUMN_NODE *ct_create_column(char c)
{
    COLUMN_NODE *cptr = ct_allocate_column();

    if (cptr == NULL)
        return NULL;

    ct_init_column(cptr, c);

    return cptr;
}

ROW_NODE *ct_allocate_row()
{
    return (ROW_NODE *) malloc(sizeof(ROW_NODE));
}

void ct_init_row(ROW_NODE *rptr)
{
    rptr -> first_column = NULL;
    rptr -> last_column = NULL;
    rptr -> length = 0;
    rptr -> next = NULL;
    rptr -> previous = NULL;
}

ROW_NODE *ct_create_row()
{
    ROW_NODE *rptr = ct_allocate_row();

    if (rptr == NULL)
        return NULL;

    ct_init_row(rptr);

    return rptr;
}

PAGE *ct_allocate_page()
{
    return (PAGE *) malloc(sizeof(PAGE));
}

void ct_init_page(PAGE *pptr)
{
    pptr -> first_row = NULL;
    pptr -> last_row = NULL;
    pptr -> length = 0;
}

PAGE *ct_create_page()
{
    PAGE *pptr = ct_allocate_page();

    if (pptr == NULL)
        return NULL;

    ct_init_page(pptr);

    return pptr;
}

BOOL ct_empty_row(ROW_NODE *rptr)
{
    return (rptr -> length == 0) ? TRUE : FALSE;
}

BOOL ct_empty_page(PAGE *pptr)
{
    return (pptr -> length == 0) ? TRUE : FALSE;
}

F_STATUS ct_pushe_column(ROW_NODE *rptr, char value)
{
    COLUMN_NODE *new_column = ct_create_column(value);

    if (new_column == NULL)
        return F_ALLOCATION_ERROR;

    if (ct_empty_row(rptr))
    {
        rptr -> first_column = new_column;
        rptr -> last_column = new_column;
    }
    else
    {
        new_column -> previous = rptr -> last_column;
        rptr -> last_column -> next = new_column;
        rptr -> last_column = new_column;
    }

    (rptr -> length)++;

    return F_SUCCESS;
}

F_STATUS ct_pushe_row(PAGE *pptr)
{
    ROW_NODE *new_row = ct_create_row();

    if (new_row == NULL)
        return F_ALLOCATION_ERROR;

    if (ct_empty_page(pptr))
    {
        pptr -> first_row = new_row;
        pptr -> last_row = new_row;
    }
    else
    {
        new_row -> previous = pptr -> last_row;
        pptr -> last_row -> next = new_row;
        pptr -> last_row = new_row;
    }

    (pptr -> length)++;

    return F_SUCCESS;
}

ROW_NODE *ct_get_focus_row(PAGE *pptr, COORD cursor_pos)
{
    ROW_NODE *aux_search_row;
    SHORT offset;

    if ((SHORT) (cursor_pos.Y + 1) > pptr -> length)
        return NULL;

    if ((SHORT) (cursor_pos.Y + 1) > (pptr -> length) / 2)
    {
        aux_search_row = pptr -> last_row;
        offset = (pptr -> length) - cursor_pos.Y - (SHORT) 1;

        for (SHORT i = 0; i < offset; i++)
            aux_search_row = aux_search_row -> previous;
    }
    else
    {
        aux_search_row = pptr -> first_row;
        offset = cursor_pos.Y;

        for (SHORT i = 0; i < offset; i++)
            aux_search_row = aux_search_row -> next;
    }

    return aux_search_row;
}

#endif // CT_PAGE_H
