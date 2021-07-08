//  Copyright 2020-2021 Herald Project Contributors
//  SPDX-License-Identifier: Apache-2.0
//

#ifndef HERALD_BLUETOOTH_STATE_MANAGER_H
#define HERALD_BLUETOOTH_STATE_MANAGER_H

#include "../datatype/bluetooth_state.h"
#include "bluetooth_state_manager_delegate.h"

#include <memory>

namespace herald {
namespace ble {

using namespace herald::datatype;

// Tagging interface
class BluetoothStateManager {
public:
  BluetoothStateManager() = default;
  virtual ~BluetoothStateManager() = default;

  virtual void add(BluetoothStateManagerDelegate& delegate) = 0;
  virtual BluetoothState state() = 0;
};

} // end namespace
} // end namespace

#endif