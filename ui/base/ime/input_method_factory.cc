// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/base/ime/input_method_factory.h"

#include "ui/base/ime/input_method_delegate.h"

#if defined(HAVE_IBUS)
#include "ui/base/ime/input_method_ibus.h"
#else
#include "ui/base/ime/mock_input_method.h"
#endif

namespace ui {

InputMethod* CreateInputMethod(internal::InputMethodDelegate* delegate) {
#if defined(HAVE_IBUS)
  return new InputMethodIBus(delegate);
#else
  return new MockInputMethod(delegate);
#endif
}

}  // namespace ui
