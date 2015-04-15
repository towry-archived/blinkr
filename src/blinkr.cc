// Copyright (c) 2015, Towry Wang
// All rights reserved.
//
// Author(s): Towry Wang <tovvry@gmail.com>
// License: http://towry.me/mit-license/
//

#include <node.h>
#include <v8.h>
#include <windows.h>

using namespace v8;

Handle<Value> Method(const Arguments& args) {
  HandleScope scope;

  FLASHWINFO fi;
  fi.cbSize = sizeof(FLASHWINFO);
  fi.hwnd = GetConsoleWindow();
  fi.dwFlags = FLASHW_ALL | FLASHW_TIMERNOFG;
  fi.uCount = 0;
  fi.dwTimeout = 0;
  FlashWindowEx(&fi);

  return scope.Close(Undefined());
}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("blink"),
      FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(blinkr, init)
