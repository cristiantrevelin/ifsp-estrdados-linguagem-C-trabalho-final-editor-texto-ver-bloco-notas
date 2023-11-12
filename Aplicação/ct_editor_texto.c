#include "headers/ct_pteditor.h"

void main()
{
    WDimension WINDOW_DIMENSION;
    F_STATUS f_status;

    WINDOW_DIMENSION = ct_playpte_configw();
    f_status = ct_play_plaintext_editor(WINDOW_DIMENSION);
}
