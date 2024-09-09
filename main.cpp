#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <windef.h>
#include <winuser.h>

int main (int argc, char *argv[]) {
  RegisterHotKey(NULL, 1, MOD_ALT | MOD_CONTROL, 0x42);
  RegisterHotKey(NULL, 2, MOD_ALT | MOD_CONTROL, 0x46);
  MSG msg = {0};

  while (1) {
    if(GetMessage(&msg, NULL, 0, 0) != 0){
      if(msg.message == WM_HOTKEY){
        switch (msg.wParam) {
          case 1:
            printf("CTRL ALT B\n");
            break;
          case 2:
            printf("CTRL ALT F\n");
            HWND win = GetFocus();
            printf("%s\n", GetWindowTextW(win, title, 500)); 
            break;
        }
      }
    } 
  }

  return 0;
}
