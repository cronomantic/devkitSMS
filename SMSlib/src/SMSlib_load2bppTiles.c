/* **************************************************
   SMSlib - C programming library for the SMS/GG
   ( part of devkitSMS - github.com/sverx/devkitSMS )
   ************************************************** */

#include "SMSlib.h"
#include "SMSlib_common.c"

#pragma save
#pragma disable_warning 85
void SMS_load2bppTilesatAddr (const void *src, unsigned int dest, unsigned int size) __naked __z88dk_callee __preserves_regs(iyh,iyl) __sdcccall(1) {
  __asm
  ld c,#0xbf            ; VDP_CTRL_PORT
  set 6,d               ; set VRAM address for write
  di
  out (c),e             ; set VRAM destination address
  out (c),d
  ei

  pop bc                ; pop ret address
  pop de                ; pop size
  push bc               ; push ret address

  ld c,#0xbe            ; VDP_DATA_PORT

1$:
  ld a,(hl)                     ; 7 = 29
  out (c),a             ; 12
  inc hl                ; 6
  ld a,(hl)             ; 7
  nop                   ; 4 = 29
  out (c),a                     ; 12
  inc hl                        ; 6
  xor a                         ; 4
  dec de                        ; 6 = 28
  out (c),a             ; 12
  dec de                ; 6
  ld b,a                ; 4
  ld a,d                ; 4
  or e                  ; 4 = 30
  out (c),b                     ; 12
  jp nz,1$                      ; 10
  ret
  __endasm;
}
#pragma restore
